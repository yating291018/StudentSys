#include <stdio.h>
#include <stdlib.h>

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
	char c;
	printf("\t\t ╭═════════■□■□═══╮\n");  
	printf("\t\t│         学生信息管理系统         │\n");  
	printf("\t\t╰═══■□■□══════════╯\n");  
	printf("\t\t   ┌─────────────-┐\n");  
	printf("\t\t   │ 1. 添加记录    2. 信息查询 │\n");  
	printf("\t\t   │                            │\n");  
	printf("\t\t   │ 3. 信息修改    4. 信息删除 │\n");  
	printf("\t\t   │                            │\n");  
	printf("\t\t   │ 5. 信息排序    0. 退出程序 │\n");  
	printf("\t\t   │                            │\n"); 
	printf("\t\t   └─────────────-┘\n");  
	printf("\t\t请您选择(0-6):"); 
	c = getchar();
	return c;
}
// 添加学生信息，可以一次添加n条
void addStudent(Student *sp){
	char exit;
	int dataCount = 0, dataLine = 0, fileEnd = 0;
	FILE *fp = fopen("./data.txt", "a+");
	if(!fp){
	  perror("文件打开错误!");
	  return;
	}
	while(fscanf(fp, "%d%s%f", &(sp + dataLine)->id, &(sp + dataLine)->SName, &(sp + dataLine)->Score) != EOF){
	    dataLine++;
	}
	fileEnd = dataLine;
	do{
		printf("\t\t请输入添加数据的条数: ");
		scanf("%d", &dataCount);
		// 写入文件，在后面追加
		for(int i = dataLine; i < dataCount + dataLine; i++){ 
			scanf("\t\t%d%s%f", &(sp + i) -> id, &(sp + i) -> SName, &(sp + i) -> Score);
		}
		dataLine = dataCount + dataLine;
		printf("\t\t要退出吗?(y/n) ");
		// 吃掉scanf的回车
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	// 写入文件,从上一次文件位置开始写入。
	for(int j = fileEnd; j < dataLine; j++){
		fprintf(fp, "%d %s %.2f\n", (sp + j) -> id, (sp + j) -> SName, (sp + j) -> Score);
	}
	fclose(fp);
}

// 退出功能
void exitSystem(){
    printf("\n\t\t谢谢使用!\n");
	exit(0);
}

// 功能项,如果有其他的项再继续添加
void initFeture(char select, Student *sp){
	switch(select){
	  case '0':
		  exitSystem();
		  break;
	  case '1':
		  addStudent(sp);
		  break;
	}
}

void main () {
	// 调用菜单选择功能项
	char selectMenu = menu();
	// 初始化功能入口
	initFeture(selectMenu, stu);

	/*char exit;
	do{
	  printf("\t\t输入?y/n");
	  exit = getchar();
	  getchar();
	}while(exit == 'y');*/
}