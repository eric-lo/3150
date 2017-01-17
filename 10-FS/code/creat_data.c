/*creat_data.c*/
#include <stdlib.h>
#include <stdio.h>
struct Student{
	char sid[11];
	char name[20];
	int marks;
};
int main(int argc, char *argv[]){
	int i=9;
	struct Student stu;
	FILE *fp;
	fp = fopen("student.dat","wb");
	while((i--)>0){
		printf("Student ID(10 digits):\n");
		scanf("%s",stu.sid);
		printf("Student Name:\n");
		scanf("%s",stu.name);
		printf("Marks:\n");
		scanf("%d",&stu.marks);
		fwrite(&stu,sizeof(struct Student),1,fp);
	}
	fclose(fp);
	return 0;
}
