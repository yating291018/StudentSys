#include <stdio.h>
#include <stdlib.h>
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
// 比如功能封装函数
void addStudent(){
	system("cls");
    printf("欢迎来到添加学生信息功能\n");
}

// 退出功能
void exitSystem(){
    printf("\n\t\t谢谢使用!\n");
	exit(0);
}

// 功能项,如果有其他的项再继续添加
void initFeture(char select){
	switch(select){
	  case '0':
		  exitSystem();
		  break;
	  case '1':
		  addStudent();
		  break;
	}
}

void main () {
	// 定义学生有哪些属性
	struct Student {
	   int  id; // 学号
       char SName[20]; // 姓名
	   float Score;  // 分数
	};
	// 定义70人的数组
	Student stu[70];
	char selectMenu = menu();
	// 初始化功能入口
	initFeture(selectMenu);
}