/* viewDisk.c
** Usage: viewDisk <Device file>
*/

#include <stdio.h>
#include <stdlib.h>
#include <linux/msdos_fs.h>
#include <stdint.h>
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
};
int open_disk(const char *device_name, struct DiskInfo *disk_info);
void info(struct DiskInfo *disk_info);
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
