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
void modify();  /*定义各函数*/

void menu()   /*菜单函数*/
{
    printf("\n");
    printf("职工工资管理系统\n");
    printf("1.查询职工信息\n");
    printf("2.修改职工信息\n");
    printf("3.浏览职工信息\n");
    printf("4.删除职工信息\n");
    printf("5.保存职工信息\n");
    printf("6.浏览职工信息\n");
    printf("7.退出\n");
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
    menu(); /*调用菜单函数*/
    printf("请选择你要执行的操作(1-7):\n");
    scanf("%d",&n);
    if(n>=1&&n<=7)
    {
    flag=1;
    break;
    }
    else
    {
     flag=0;
     printf("没有这个选项");
    }
}while(flag==0);
   
      switch(n)
          {
       case 1:printf("查询职工信息\n");printf("\n");system("cls");find();break;
       case 2:printf("修改职工信息\n");printf("\n");system("cls");mofify();break;
       case 3:printf("添加职工信息\n");printf("\n");add();break; 
       case 4:printf("删除职工信息\n");printf("\n");system("cls");del();break;
       case 5:printf("保存职工信息\n");printf("\n");system("cls");write();break;
	   case 6:printf("浏览职工信息\n");printf("\n");system("cls");list();break;
       case 7:goto la;
       default :break;
          }
  
}
la:
   system("cls");   
   printf("已成功退出\n");
}

int read()  /*读取函数*/
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


void write(int m)  /*保存函数*/
{
   int i;
   FILE*fp;
   if ((fp=fopen("employee_list","wb"))==NULL)  /*创建文件并判断是否能打开*/
   {
     printf ("cannot open file\n");
     exit(0);
   }
   for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/
   if (fwrite(&em,sizeof(struct employee),1,fp)!=1)
   printf("file write error\n");
   fclose(fp);
}


void find() /*查询函数*/
{
  char gonghao1[10];
  int i,t;
  int m=read();
  printf("请输入要查找的工号:\n");
  scanf("%s",gonghao1);
  for(i=0;i<m;i++)
    if(strcmp(gonghao1,em[i].gonghao)==0)
{
    printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
    printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
    break;
}
   if(i==m)  
   printf("\n查无此人\n");
   printf("\n");


void list()  /*浏览函数*/
{
int i;
int m=read();
printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
for(i=0;i<m;i++) /*m为输入部分的职工人数*/
printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa"); 

printf("返回主菜单\n");
getchar();system("cls");
}

void modify() /*修改函数*/
