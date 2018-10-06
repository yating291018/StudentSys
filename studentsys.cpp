#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	system("cls");
	char c;
	printf(" �q�T�T�T�T�T�T�T�T�T���������T�T�T�r\n");  
	printf("��         ѧ����Ϣ����ϵͳ         ��\n");  
	printf("�t�T�T�T���������T�T�T�T�T�T�T�T�T�T�s\n");  
	printf("   ����������������������������-��\n");  
	printf("   �� 1. ��Ӽ�¼    2. ��Ϣ��ѯ ��\n");  
	printf("   ��                            ��\n");  
	printf("   �� 3. ��Ϣ�޸�    4. ��Ϣɾ�� ��\n");  
	printf("   ��                            ��\n");  
	printf("   �� 5. ��Ϣ����    0. �˳����� ��\n");  
	printf("   ��                            ��\n"); 
	printf("   ����������������������������-��\n");  
	printf("����ѡ��(0-6):"); 
	c = getchar();
	return c;
}
void initFeture(char selectMenu, Student *sp);
void initEnter(Student *sp);
// ���ѧ����Ϣ������һ�����n��
void addStudent(Student *sp, int dataLine, int fileEnd){
	char exit;
	int dataCount = 0;
	FILE *fp = fopen("./data.txt", "a+");
	if(!fp){
	  perror("�ļ��򿪴���!");
	  return;
	}
	do{
		printf("������������ݵ�����: ");
		scanf("%d", &dataCount);
		// д���ļ����ں���׷��
		for(int i = dataLine; i < dataCount + dataLine; i++){ 
			scanf("%d%s%f", &(sp + i) -> id, &(sp + i) -> SName, &(sp + i) -> Score);
		}
		dataLine = dataCount + dataLine;
		printf("Ҫ�˳���?(y/n) ");
		// �Ե�scanf�Ļس�
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	// д���ļ�,����һ���ļ�λ�ÿ�ʼд�롣
	for(int j = fileEnd; j < dataLine; j++){
		fprintf(fp, "%d %s %.2f\n", (sp + j) -> id, (sp + j) -> SName, (sp + j) -> Score);
	}
	fclose(fp);
	getchar();
	initEnter(stu);
}

// �˳�����
void exitSystem(){
    printf("\nллʹ��!\n");
	exit(0);
}

// ɾ��һ������
void deleteData(Student *sp, int length){
	char exit;
	do{
		printf("����Ҫɾ��������1.id 2.name, ��������1\n");
		// ���Ե����
		int keyIndex;
		scanf("%d", &keyIndex);
		// Ҫɾ����id������
		int deleteId;
		char deleteName[20];
		if (keyIndex == 1) {
			printf("����Ҫɾ����id\n");
			scanf("%d", &deleteId);
		} else if(keyIndex == 2){
			printf("����Ҫɾ��������\n");
			scanf("%s", deleteName);
		}
		FILE *fp = fopen("./temp.txt", "w");
		if (!fp){
			printf("���ļ�����!\n");
			return;
		}
		for(int i = 0;i < length; i++){
			// �ҵ�Ҫɾ��������
			if((sp+i) -> id != deleteId && strcmp((sp+i) -> SName, deleteName) != 0){
				fprintf(fp, "%d %s %.2f\n", (sp+i) -> id, (sp+i) -> SName, (sp+i) -> Score);
			}
		}
		fclose(fp);
		remove("./data.txt");
		rename("./temp.txt", "./data.txt");
		printf("ɾ���ɹ�!\n");
		printf("Ҫ�˳���?y/n\n");
		getchar();
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	getchar();
	initEnter(stu);
}

// �޸�����
void updateData(Student *sp, int length){
	char exit;
	do{
		printf("����Ҫ�޸ĵ�����1.id 2.name, ��������1\n");
		// ���Ե����
		int keyIndex;
		scanf("%d", &keyIndex);
		// Ҫɾ����id������
		int deleteId;
		char deleteName[20];
		if (keyIndex == 1) {
			printf("����Ҫ�޸ĵ�id\n");
			scanf("%d", &deleteId);
		} else if(keyIndex == 2){
			printf("����Ҫ�޸ĵ�����\n");
			scanf("%s", deleteName);
		}
		for(int i = 0;i < length; i++){
			// �ҵ�Ҫɾ��������
			if((sp+i) -> id == deleteId || strcmp((sp+i) -> SName, deleteName) == 0){
				printf("�޸�һ������%d %s %.2f\n", (sp+i) -> id, (sp+i) -> SName, (sp+i) -> Score);
				printf("�޸�id\n");
				scanf("%d", &(sp+i) -> id);
				printf("�޸�����\n");
				scanf("%s", &(sp+i) -> SName);
				printf("�޸ĳɼ�\n");
				scanf("%f", &(sp+i) -> Score);
			}
		}
		getchar();
		printf("�Ƿ�Ҫ�˳��޸�?y/n\n");
		exit = getchar();
	}while(exit == 'y' || exit == 'Y');
	FILE *fp = fopen("./data.txt", "w");
	if (!fp){
		printf("���ļ�����!\n");
		return;
	}
	for(int j = 0;j < length; j++){
		fprintf(fp, "%d %s %.2f\n", (sp+j) -> id, (sp+j) -> SName, (sp+j) -> Score);
	}
	fclose(fp);
	printf("�޸ĳɹ�!");
	getchar();
	initEnter(stu);
}

// ������,��������������ټ������
void initFeture(char selectMenu, Student *sp){
	// ��ʼ������
	int dataLine = 0, fileEnd = 0;
	FILE *fp = fopen("./data.txt", "r");
	if(!fp){
	  perror("�ļ��򿪴���!");
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
	// ���ò˵�ѡ������
	char selectMenu = menu();
	// ��ʼ���������
	initFeture(selectMenu, sp);
}
void main () {
	initEnter(stu);
}