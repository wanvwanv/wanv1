#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#define N 100

struct employee
{
char gonghao[10];
char name[10];
float gangwei;
float xinji;
float zhiwu;
float jixiao;
float yingfa;
float sui;
float shifa;
}em[100];

void menu();
void add();
void write(int);
void list();
void del();
void find();
void modify();  /*���������*/

void menu()   /*�˵�����*/
{
    printf("\n");
    printf("ְ�����ʹ���ϵͳ\n");
    printf("1.��ѯְ����Ϣ\n");
    printf("2.�޸�ְ����Ϣ\n");
    printf("3.���ְ����Ϣ\n");
    printf("4.ɾ��ְ����Ϣ\n");
    printf("5.����ְ����Ϣ\n");
    printf("6.���ְ����Ϣ\n");
    printf("7.�˳�\n");
    printf("\n");
    
}

void main()
{
   int n,flag;
   char a;
while(1)
{ 
do
  {
    menu(); /*���ò˵�����*/
    printf("��ѡ����Ҫִ�еĲ���(1-7):\n");
    scanf("%d",&n);
    if(n>=1&&n<=7)
    {
    flag=1;
    break;
    }
    else
    {
     flag=0;
     printf("û�����ѡ��");
    }
}while(flag==0);
   
      switch(n)
          {
       case 1:printf("��ѯְ����Ϣ\n");printf("\n");system("cls");find();break;
       case 2:printf("�޸�ְ����Ϣ\n");printf("\n");system("cls");mofify();break;
       case 3:printf("���ְ����Ϣ\n");printf("\n");add();break; 
       case 4:printf("ɾ��ְ����Ϣ\n");printf("\n");system("cls");del();break;
       case 5:printf("����ְ����Ϣ\n");printf("\n");system("cls");write();break;
	   case 6:printf("���ְ����Ϣ\n");printf("\n");system("cls");list();break;
       case 7:goto la;
       default :break;
          }
  
}
la:
   system("cls");   
   printf("�ѳɹ��˳�\n");
}

int read()  /*��ȡ����*/
{
     FILE*fp;
     int i=0;
     if((fp=fopen("employee_list","rb"))==NULL)
         {
     printf ("cannot open file\n");
     exit(0);
         }
else 
{
  do 
  {
        fread(&em,sizeof(struct employee),1,fp);
        i++;
  }
  while(feof(fp)==0);
}
fclose(fp);
return(i-1);
}


void write(int m)  /*���溯��*/
{
   int i;
   FILE*fp;
   if ((fp=fopen("employee_list","wb"))==NULL)  /*�����ļ����ж��Ƿ��ܴ�*/
   {
     printf ("cannot open file\n");
     exit(0);
   }
   for (i=0;i<m;i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
   if (fwrite(&em,sizeof(struct employee),1,fp)!=1)
   printf("file write error\n");
   fclose(fp);
}


void find() /*��ѯ����*/
{
  char gonghao1[10];
  int i,t;
  int m=read();
  printf("������Ҫ���ҵĹ���:\n");
  scanf("%s",gonghao1);
  for(i=0;i<m;i++)
    if(strcmp(gonghao1,em[i].gonghao)==0)
{
    printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
    printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
    break;
}
   if(i==m)  
   printf("\n���޴���\n");
   printf("\n");


void list()  /*�������*/
{
int i;
int m=read();
printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
for(i=0;i<m;i++) /*mΪ���벿�ֵ�ְ������*/
printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa"); 

printf("�������˵�\n");
getchar();system("cls");
}

void modify() /*�޸ĺ���*/
