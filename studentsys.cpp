#include <stdio.h>
#include <stdlib.h>
/*
  �˵�ѡ��
  �����Ӧ�����֣����뵽��Ӧ�Ĺ���
*/

char menu() {
	char c;
	printf("\t\t �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
	printf("\t\t��         ѧ����Ϣ����ϵͳ         ��\n");  
	printf("\t\t�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
	printf("\t\t   ����������������������������-��\n");  
	printf("\t\t   �� 1. ��Ӽ�¼    2. ��Ϣ��ѯ ��\n");  
	printf("\t\t   ��                            ��\n");  
	printf("\t\t   �� 3. ��Ϣ�޸�    4. ��Ϣɾ�� ��\n");  
	printf("\t\t   ��                            ��\n");  
	printf("\t\t   �� 5. ��Ϣ����    0. �˳����� ��\n");  
	printf("\t\t   ��                            ��\n"); 
	printf("\t\t   ����������������������������-��\n");  
	printf("\t\t����ѡ��(0-6):"); 
	c = getchar();
	return c;
}
// ���繦�ܷ�װ����
void addStudent(){
	system("cls");
    printf("��ӭ�������ѧ����Ϣ����\n");
}

// �˳�����
void exitSystem(){
    printf("\n\t\tллʹ��!\n");
	exit(0);
}

// ������,��������������ټ������
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
	// ����ѧ������Щ����
	struct Student {
	   int  id; // ѧ��
       char SName[20]; // ����
	   float Score;  // ����
	};
	// ����70�˵�����
	Student stu[70];
	char selectMenu = menu();
	// ��ʼ���������
	initFeture(selectMenu);
}