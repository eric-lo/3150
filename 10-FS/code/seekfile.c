#include<stdio.h>
#include<stdlib.h>
struct Student{
	char sid[11];
	char name[20];
	int marks;
};

int main(int argc, char *argv[]){
	FILE *fp;
	int offset;
	struct Student stu;
	int i=0;
	fp = fopen("student.dat","rb");         

	if(fp == NULL){
		perror("fopen\n");
		exit(EXIT_FAILURE);
	}

	printf("Last record in file.\n");
	offset = -(sizeof(stu));
	fseek(fp,offset,SEEK_END);
	fread(&stu,sizeof(stu),1,fp);
	printf("\n\tStudent ID : %s",stu.sid);
	printf("\n\tName : %s",stu.name);
	printf("\n\tMarks : %d",stu.marks);
	printf("\nCurrent offset:%ld",ftell(fp));

	printf("\n\nFirst record in file.\n");
	fseek(fp,0,SEEK_SET);
	fread(&stu,sizeof(stu),1,fp);
	printf("\n\tStudent ID : %s",stu.sid);
	printf("\n\tName : %s",stu.name);
	printf("\n\tMarks : %d",stu.marks);
	printf("\nCurrent offset:%ld",ftell(fp));

	printf("\n\nSecond record in file.\n");
	fseek(fp,0,SEEK_CUR);
	fread(&stu,sizeof(stu),1,fp);
	printf("\n\tStudent ID : %s",stu.sid);
	printf("\n\tName : %s",stu.name);
	printf("\n\tMarks : %d",stu.marks);
	printf("\nCurrent offset:%ld",ftell(fp));
  
	fclose(fp);
	return 0;
}
