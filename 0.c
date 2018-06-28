#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
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
void modify();
float grsds();  /*���������*/

void menu()   /*�˵�����*/
{
    system("cls");//����
    system("color 1E"); //����������ɫΪ��ɫ ����ɫ��ɫ
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

void add()   /*¼�뺯��*/
{
   int i,m;
   system("cls");
   printf("��������Ҫ������Ϣ��ְ������(1--100):\n");
   scanf("%d",&m);

   for (i=0;i<m;i++)
   {
  printf("�����빤�ţ�");
  scanf("%s",&em[i].gonghao);
  printf("������������");
  scanf("%s",em[i].name);
  printf("�������λ���ʣ�");
  scanf("%f",&em[i].gangwei);
  printf("������н�����ʣ�");
  scanf("%f",&em[i].xinji);
  printf("������ְ�������");
  scanf("%f",&em[i].zhiwu);
  printf("�����뼨Ч���ʣ�");
  scanf("%f",&em[i].jixiao);
  grsds(); //����˰��ʵ������
  printf("\n");
   }
  printf("\n�������!\n");system("cls");
  write(m); //����ְ������m
  getchar();system("cls");
}

void write(int m)  /*���溯��*/
{
   int i;
   FILE*fp; //����fp��ָ�룬����ָ��FILE���͵Ķ���
   if ((fp=fopen("employee_list","wb"))==NULL)  //�����ļ����ж��Ƿ��ܴ�
   {
     printf ("��ʧ��\n");
     exit(0);
   }

   for (i=0;i<m;i++) //�ڴ���ְ������Ϣ����������ļ���ȥ
   if (fwrite(&em,sizeof(struct employee),1,fp)!=1)
   printf("�ļ���д����\n");
   fclose(fp);// �����������ʣ�����������������ļ��У����ͷ��ļ�ָ����йصĻ�����
}

int read()  /*��ȡ����*/
{
     FILE*fp;
     int i=0;
     if((fp=fopen("gz.dat","rb"))==NULL)
         {
           printf ("cannot open file\n");
           exit(0);
         }
else 
{
  do 
  {
        fread(&em[i],sizeof(struct employee),1,fp);
        i++;
  }
  while(feof(fp)==0);
}

fclose(fp);
return(i-1);
}
  
void find() /*��ѯ����*/
{
  char gonghao[10];
  int i;
  int m=read();
  printf("������Ҫ���ҵĹ���:\n");
  scanf("%s",gonghao);
  for(i=0;i<m;i++)
    if(strcmp(em[i].gonghao,gonghao)==0)
{
    printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
    printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);
}
   if(i==m)
   printf("\n���޴���\n");
   printf("\n");
}

void list()  /*�������*/
{
int i;
int m=read();
system("cls");
printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
for(i=0;i<m;i++) /*mΪ���벿�ֵ�ְ������*/
printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa); 

printf("�������˵�\n");
getchar();system("cls");
}
 
 
void del()   /*ɾ������*/
{
  
int m=read();
int i,j,n,t,flag;
char gonghao[10];
printf("\nԭ����ְ����Ϣ:\n");
    list();   /* �����������*/
    printf("\n");
printf("������Ҫɾ����ְ���Ĺ���:\n");
scanf("%s",gonghao);
for(flag=1,i=0;flag&&i<m;i++) //��������ȷ��button==1ʱ�������ſ��Ա�����
{
  if(strcmp(em[i].gonghao,gonghao)==0)
  {
   printf("\n����ԭʼ��¼Ϊ:\n");
       printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
   printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
       printf("\n 1ȷ��ɾ�� 0��ɾ��\n");
   scanf("%d",&n);
            if(n==1)   /*���ɾ��������������Ϣ��������һ��*/
     {
     for(j=i;j<m-1;j++)
        {
          em[j]=em[j+1];
        }
      flag=0;
     }
  }
}
if(!flag)
    m=m-1;
else
    printf("\n�Բ��𣬲��޴���!\n");
    printf("\nĿǰ����ְ����Ϣ:\n");
    write(m);    /*���ñ��溯��*/
    list();     /*�����������*/
printf("\n����ɾ���밴1������ɾ���밴0\n");
scanf("%d",&t);
switch(t)
{
    case 1:del();break;
    case 0:break;
    default :break;
}
}
 

float grsds() /*˰����*/
{
int i;
float gangwei;
float xinji;
float zhiwu;
float jixiao;
float yingfa;
float sui;
float shifa;

em[i].yingfa=( em[i].gangwei + em[i].xinji + em[i].zhiwu + em[i].jixiao );

if(em[i].yingfa<=500)
{
	em[i].sui=(em[i].yingfa)*0.05;
}
else if(em[i].yingfa>500)
{
	em[i].sui=(em[i].yingfa)*0.1;
}
else if(em[i].yingfa>2000)
{
	 em[i].sui=(em[i].yingfa)*0.15;
}
else if(em[i].yingfa>5000)
{
	em[i].sui=(em[i].yingfa)*0.2;
}
else if(em[i].yingfa>20000)
{
	em[i].sui=(em[i].yingfa)*0.3;
}
else if(em[i].yingfa>40000)
{
	em[i].sui=(em[i].yingfa)*0.35;
}
else if(em[i].yingfa>60000)
{
	em[i].sui=(em[i].yingfa)*0.4;
}
else if(em[i].yingfa>100000);
{
	em[i].sui=(em[i].yingfa)*0.45;
}
else printf("����������\n");


em[i].shifa=em[i].yingfa-em[i].sui;
}
 
 
void modify() /*�޸ĺ���*/
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
int b,c,i,n,t,flag; 
int m=read(); /*�����ļ��ڵ���Ϣ*/
    printf("\n ԭ����ְ����Ϣ:\n");
    list();   /* �����������*/
    printf("\n");
    printf("������Ҫ�޸ĵ�ְ���Ĺ���:\n");
scanf("%s",gonghao);
for(flag=1,i=0;flag&&i<m;i++)
{
  if(strcmp(em[i].gonghao,gonghao)==0)
  {
   printf("\n���˼�¼Ϊ��\n");
   printf("\n����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
   printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
   printf("\n 1ȷ���޸� 0���޸� \n");
   scanf("%d",&n);
            if(n==1)
			{
               printf("\n��Ҫ�����޸ĵ�ѡ��\n 1.���� 2.���� 3.��λ���� 4.н������ 5.ְ����� 6.��Ч����\n");  
               printf("�����������޸ĵ���һ�����:\n");  
               scanf("%d",&c);  
               if(c>6||c<1)  
               printf("\nѡ�����������ѡ��!\n");  
             }
         flag=0;
  }
        
}
    if(flag==1)
    printf("\n���޴���\n"); 

    do
		{
           switch(c)
           {  
           case 1:printf("���Ÿ�Ϊ: ");
                  scanf("%s",&gonghao);
                  strcpy(em[i-1].gonghao,gonghao);
                  break;  
           case 2:printf("������Ϊ: ");
                  scanf("%s",&name);
                  strcpy(em[i-1].name,name); 
                  break;  
           case 3:printf("��λ���ʸ�Ϊ: ");
                  scanf("%f",&gangwei);
                  em[i-1].gangwei=gangwei;
				  grsds();
                  break;  
           case 4:printf("н�����ʸ�Ϊ: ");
                  scanf("%f",&xinji);
                  em[i-1].xinji=xinji;
				  grsds();
                  break;  
           case 5:printf("ְ�������Ϊ: ");
                  scanf("%d",&zhiwu);
                  em[i-1].zhiwu=zhiwu;
				  grsds();
                  break;  
           case 6:printf("��Ч���ʸ�Ϊ: ");
                  scanf("%f",&jixiao);
				  em[i-1].jixiao=jixiao; 
				  grsds();
                  break;
		   } 
  printf("\n");
  printf("\n 1.ȷ���޸� 2.�����޸� \n"); 
  scanf("%d",&b);
}  
   while(b==2);
   grsds();
   printf("\n�޸ĺ��ְ����Ϣ:\n");
   printf("\n");
   write(m);
   list();
   printf("\n�����޸��밴1�������޸��밴0\n");
   scanf("%d",&t);
   switch(t)
   {
    case 1:modify();break;
    case 0:break;
    default :break;
   }
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
    if(n>=1&&n<=6)
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
       case 2:printf("�޸�ְ����Ϣ\n");printf("\n");system("cls");modify();break;
       case 3:printf("���ְ����Ϣ\n");printf("\n");system("cls");add();break; 
       case 4:printf("ɾ��ְ����Ϣ\n");printf("\n");system("cls");del();break;
	   case 5:printf("���ְ����Ϣ\n");printf("\n");system("cls");list();break;
       case 6:goto la;
       default :break;
          }
  
}
la:
   system("cls");   
   printf("�ѳɹ��˳�\n");
}