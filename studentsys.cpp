#include <stdio.h>
#include <stdlib.h>

// ����ѧ������Щ����
struct Student {
   int  id; // ѧ��
   char SName[20]; // ����
   float Score;  // ����
};
// ����70�˵�����
Student stu[70];

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
// ���ѧ����Ϣ������һ�����n��
void addStudent(Student *sp){
	char exit;
	int dataCount = 0, dataLine = 0, fileEnd = 0;
	FILE *fp = fopen("./data.txt", "a+");
	if(!fp){
	  perror("�ļ��򿪴���!");
	  return;
	}
	while(fscanf(fp, "%d%s%f", &(sp + dataLine)->id, &(sp + dataLine)->SName, &(sp + dataLine)->Score) != EOF){
	    dataLine++;
	}
	fileEnd = dataLine;
	do{
		printf("\t\t������������ݵ�����: ");
		scanf("%d", &dataCount);
		// д���ļ����ں���׷��
		for(int i = dataLine; i < dataCount + dataLine; i++){ 
			scanf("\t\t%d%s%f", &(sp + i) -> id, &(sp + i) -> SName, &(sp + i) -> Score);
		}
		dataLine = dataCount + dataLine;
		printf("\t\tҪ�˳���?(y/n) ");
		// �Ե�scanf�Ļس�
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	// д���ļ�,����һ���ļ�λ�ÿ�ʼд�롣
	for(int j = fileEnd; j < dataLine; j++){
		fprintf(fp, "%d %s %.2f\n", (sp + j) -> id, (sp + j) -> SName, (sp + j) -> Score);
	}
	fclose(fp);
}

// �˳�����
void exitSystem(){
    printf("\n\t\tллʹ��!\n");
	exit(0);
}

// ������,��������������ټ������
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
	// ���ò˵�ѡ������
	char selectMenu = menu();
	// ��ʼ���������
	initFeture(selectMenu, stu);

	/*char exit;
	do{
	  printf("\t\t����?y/n");
	  exit = getchar();
	  getchar();
	}while(exit == 'y');*/
}