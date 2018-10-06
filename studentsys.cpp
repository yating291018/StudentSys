#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生有哪些属性
struct Student {
   int  id; // 学号
   char SName[20]; // 姓名
   float Score;  // 分数
};
// 定义70人的数组
Student stu[70];

/*
  菜单选择，
  输入对应的数字，进入到对应的功能
*/
char menu() {
	system("cls");
	char c;
	printf(" ╭═════════■□■□═══╮\n");  
	printf("│         学生信息管理系统         │\n");  
	printf("╰═══■□■□══════════╯\n");  
	printf("   ┌─────────────-┐\n");  
	printf("   │ 1. 添加记录    2. 信息查询 │\n");  
	printf("   │                            │\n");  
	printf("   │ 3. 信息修改    4. 信息删除 │\n");  
	printf("   │                            │\n");  
	printf("   │ 5. 信息排序    0. 退出程序 │\n");  
	printf("   │                            │\n"); 
	printf("   └─────────────-┘\n");  
	printf("请您选择(0-6):"); 
	c = getchar();
	return c;
}
void initFeture(char selectMenu, Student *sp);
void initEnter(Student *sp);
// 添加学生信息，可以一次添加n条
void addStudent(Student *sp, int dataLine, int fileEnd){
	char exit;
	int dataCount = 0;
	FILE *fp = fopen("./data.txt", "a+");
	if(!fp){
	  perror("文件打开错误!");
	  return;
	}
	do{
		printf("请输入添加数据的条数: ");
		scanf("%d", &dataCount);
		// 写入文件，在后面追加
		for(int i = dataLine; i < dataCount + dataLine; i++){ 
			scanf("%d%s%f", &(sp + i) -> id, &(sp + i) -> SName, &(sp + i) -> Score);
		}
		dataLine = dataCount + dataLine;
		printf("要退出吗?(y/n) ");
		// 吃掉scanf的回车
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	// 写入文件,从上一次文件位置开始写入。
	for(int j = fileEnd; j < dataLine; j++){
		fprintf(fp, "%d %s %.2f\n", (sp + j) -> id, (sp + j) -> SName, (sp + j) -> Score);
	}
	fclose(fp);
	getchar();
	initEnter(stu);
}

// 退出功能
void exitSystem(){
    printf("\n谢谢使用!\n");
	exit(0);
}

// 删除一条数据
void deleteData(Student *sp, int length){
	char exit;
	do{
		printf("输入要删除的属性1.id 2.name, 比如输入1\n");
		// 属性的序号
		int keyIndex;
		scanf("%d", &keyIndex);
		// 要删除的id和名字
		int deleteId;
		char deleteName[20];
		if (keyIndex == 1) {
			printf("输入要删除的id\n");
			scanf("%d", &deleteId);
		} else if(keyIndex == 2){
			printf("输入要删除的名称\n");
			scanf("%s", deleteName);
		}
		FILE *fp = fopen("./temp.txt", "w");
		if (!fp){
			printf("打开文件错误!\n");
			return;
		}
		for(int i = 0;i < length; i++){
			// 找到要删除的数据
			if((sp+i) -> id != deleteId && strcmp((sp+i) -> SName, deleteName) != 0){
				fprintf(fp, "%d %s %.2f\n", (sp+i) -> id, (sp+i) -> SName, (sp+i) -> Score);
			}
		}
		fclose(fp);
		remove("./data.txt");
		rename("./temp.txt", "./data.txt");
		printf("删除成功!\n");
		printf("要退出吗?y/n\n");
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	getchar();
	initEnter(stu);
}

// 修改数据
void updateData(Student *sp, int length){
	char exit;
	do{
		printf("输入要修改的属性1.id 2.name, 比如输入1\n");
		// 属性的序号
		int keyIndex;
		scanf("%d", &keyIndex);
		// 要删除的id和名字
		int deleteId;
		char deleteName[20];
		if (keyIndex == 1) {
			printf("输入要修改的id\n");
			scanf("%d", &deleteId);
		} else if(keyIndex == 2){
			printf("输入要修改的名称\n");
			scanf("%s", deleteName);
		}
		for(int i = 0;i < length; i++){
			// 找到要删除的数据
			if((sp+i) -> id == deleteId || strcmp((sp+i) -> SName, deleteName) == 0){
				printf("修改一下数据%d %s %.2f\n", (sp+i) -> id, (sp+i) -> SName, (sp+i) -> Score);
				printf("修改id\n");
				scanf("%d", &(sp+i) -> id);
				printf("修改姓名\n");
				scanf("%s", &(sp+i) -> SName);
				printf("修改成绩\n");
				scanf("%f", &(sp+i) -> Score);
			}
		}
		getchar();
		printf("是否要退出修改?y/n\n");
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	FILE *fp = fopen("./data.txt", "w");
	if (!fp){
		printf("打开文件错误!\n");
		return;
	}
	for(int j = 0;j < length; j++){
		fprintf(fp, "%d %s %.2f\n", (sp+j) -> id, (sp+j) -> SName, (sp+j) -> Score);
	}
	fclose(fp);
	printf("修改成功!");
	getchar();
	initEnter(stu);
}

// 功能项,如果有其他的项再继续添加
void initFeture(char selectMenu, Student *sp){
	// 初始化数据
	int dataLine = 0, fileEnd = 0;
	FILE *fp = fopen("./data.txt", "r");
	if(!fp){
	  perror("文件打开错误!");
	  return;
	}
	while(fscanf(fp, "%d%s%f", &(sp + dataLine)->id, &(sp + dataLine)->SName, &(sp + dataLine)->Score) != EOF){
	    dataLine++;
	}
	fclose(fp);
	fileEnd = dataLine;
	switch(selectMenu){
	  case '0':
		  exitSystem();
		  break;
	  case '1':
		  addStudent(sp, dataLine, fileEnd);
		  break;
	  case '3':
		  updateData(sp, dataLine);
		  break;
	  case '4':
		  deleteData(sp, dataLine);
		  break;
	}
}
void initEnter(Student *sp){
	// 调用菜单选择功能项
	char selectMenu = menu();
	// 初始化功能入口
	initFeture(selectMenu, sp);
}
void main () {
	initEnter(stu);
}