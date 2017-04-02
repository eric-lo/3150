/*
** viewRoot.c - For viewing root directory contents
** Usage: ./viewRoot <device file>
*/
#include <stdio.h>
#include <stdlib.h>
#include <linux/msdos_fs.h>
#include <stdint.h>
#include <string.h>
#define FAT_EOF 0x0ffffff8
#define FAT_DAMAGED 0x0ffffff7
#define FAT_UNALLOCATED 0x0

struct DiskInfo {
    FILE *fp;
    off_t fat_offset;
    off_t root_entry_offset;
    uint8_t num_fats;
    uint32_t fat_size;
    uint32_t bpc;
    uint32_t bps;
    uint8_t spc;
    uint16_t reserved_sectors;
    uint32_t root_cluster;
};
int open_disk(const char *device_name, struct DiskInfo *disk_info);
void info(struct DiskInfo *disk_info);
void listRoot(struct DiskInfo *disk_info);
off_t get_cluster_offset(off_t root_entry_offset, uint32_t cluster_number,
                         uint32_t bytes_per_cluster) ;
void convert_83filename(const uint8_t *raw, char *filename);
uint32_t get_dir_first_cluster(struct msdos_dir_entry *dir_entry);
uint32_t next_cluster(FILE *fp, off_t fat_offset, uint32_t current_cluster);

int main(int argc,char *argv[])
{
  if(argc != 2)
  {
    printf("./diskinfo <device>\n");
    return -1;
  }
  struct DiskInfo disk_info;
  char *dev = argv[1];
  printf("Device : [%s]\n",dev);
  open_disk(dev,&disk_info);
  info(&disk_info);
  printf("\n\n");
  listRoot(&disk_info);
  fclose(disk_info.fp);

  return 0;
}

int open_disk(const char *device_name, struct DiskInfo *disk_info) {
    FILE *fp = NULL;
    struct fat_boot_sector boot_entry;

    fp = fopen(device_name, "r+");
    if(fp == NULL)
        exit(-1);
    uint32_t boot_entry_size = fread(&boot_entry, 1, sizeof(struct fat_boot_sector), fp);
    if(boot_entry_size != sizeof(struct fat_boot_sector))
        exit(-1);
    //  Bytes per sector. Allowed values include 512, 1024, 2048, and 4096
    uint16_t bps = boot_entry.sector_size[0] + ((uint16_t) boot_entry.sector_size[1] << 8);
    off_t root_entry_offset = ( boot_entry.reserved +
                                boot_entry.fats * boot_entry.fat32.length) * bps;
    uint32_t bpc = bps * boot_entry.sec_per_clus;
    off_t fat_offset = bps * boot_entry.reserved;

    disk_info->fp = fp;
    disk_info->root_entry_offset = root_entry_offset;
    disk_info->bpc = bpc;
    disk_info->bps = bps;
    disk_info->spc = boot_entry.sec_per_clus;
    disk_info->reserved_sectors = boot_entry.reserved;
    disk_info->fat_offset = fat_offset;
    disk_info->num_fats = boot_entry.fats;
    disk_info->fat_size = boot_entry.fat32.length;
    disk_info->root_cluster = boot_entry.fat32.root_cluster;

    return 1;
}

void info(struct DiskInfo *disk_info) {
    printf("Number of FATs = %d\n", disk_info->num_fats);
    printf("Number of bytes per sector = %d\n", disk_info->bps);
    printf("Number of sectors per cluster = %d\n", disk_info->spc);
    printf("Number of reserved sectors = %d\n", disk_info->reserved_sectors);
    printf("First FAT starts at byte = %ld\n", disk_info->fat_offset);
    printf("Data area starts at byte = %ld\n", disk_info->root_entry_offset);
}
void listRoot(struct DiskInfo *disk_info)
{
  FILE *fp = disk_info->fp;
  off_t root_entry_offset = disk_info->root_entry_offset;
  uint32_t bpc = disk_info->bpc;
  uint32_t current_cluster_number = 2;
  uint32_t idx = 1;

  uint32_t target_dir_cluster = disk_info->root_cluster;
  uint32_t next_cluster_number = target_dir_cluster;

  while(next_cluster_number < FAT_EOF && next_cluster_number != FAT_DAMAGED &&
        next_cluster_number != FAT_UNALLOCATED) {
          current_cluster_number = next_cluster_number;
          off_t cluster_offset =
              get_cluster_offset(root_entry_offset, current_cluster_number, bpc);
          fseek(fp, cluster_offset, SEEK_SET);
          for(uint32_t i = 0; i < bpc / sizeof(struct msdos_dir_entry); i++) {
              struct msdos_dir_entry dir_entry;
              size_t ret = fread(&dir_entry, 1, sizeof(struct msdos_dir_entry), fp);
              if(dir_entry.name[0] != 0x00) {
                  if(dir_entry.attr != 0x0f) {
                      if(dir_entry.name[0] == 0xe5) {
                          dir_entry.name[0] = '?';
                      }
                      char filename[14] = { 0 };
                      convert_83filename(dir_entry.name, filename);
                      //  printf("%d\t%d", dir_entry.starthi, dir_entry.start);
                      uint32_t dir_first_cluster = get_dir_first_cluster(&dir_entry);
                      if((dir_entry.attr & 0x10) != 0) {
                          strcat(filename, "/");
                      }
                      printf("%d, ", idx++);
                      printf("%s, ", filename);
                      printf("%d, ", dir_entry.size);
                      printf("%d", dir_first_cluster);
                      printf("\n");
                  }
                  else {
                      printf("%d, LFN entry\n", idx++);
                  }
              }
          }
          next_cluster_number =
              next_cluster(fp, disk_info->fat_offset, current_cluster_number);
        }
}
off_t get_cluster_offset(off_t root_entry_offset, uint32_t cluster_number,
                         uint32_t bytes_per_cluster) {
    return root_entry_offset + (cluster_number - 2) * bytes_per_cluster;
}
void convert_83filename(const uint8_t *raw, char *filename) {
    int i, j = 0;
    char name[9] = { 0 };
    char ext[4] = { 0 };

    for(i = 0, j = 0; i < 8; i++) {
        if(raw[i] != ' ')
            name[j++] = raw[i];
        else
            break;
    }

    for(i = 8, j = 0; i < 11; i++) {
        if(raw[i] != ' ')
            ext[j++] = raw[i];
        else
            break;
    }

    strncpy(filename, name, 8);
    if(j != 0) {
        strncat(filename, ".", 1);
        strncat(filename, ext, 3);
    }
}
uint32_t get_dir_first_cluster(struct msdos_dir_entry *dir_entry) { return dir_entry->start + ((uint32_t) dir_entry->starthi << 16); }
uint32_t next_cluster(FILE *fp, off_t fat_offset, uint32_t current_cluster) {
    uint32_t next_cluster_number = 0;
    fseek(fp, fat_offset + current_cluster * sizeof next_cluster_number,
          SEEK_SET);
    size_t ret = fread(&next_cluster_number, 1, sizeof next_cluster_number, fp);

    return next_cluster_number;
}
