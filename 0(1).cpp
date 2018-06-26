#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
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
       case 3:printf("添加职工信息\n");printf("\n");system("cls");add();break; 
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
printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa); 

printf("返回主菜单\n");
getchar();system("cls");
}
 
 

void gsrsd() /*税函数*/

{

em[i].yingfa=em[i].gangwei + em[i].xinji + em[i].zhiwu + em[i]jixiao

if(em[i].yingfa<=500)
{em[i].sui=em[i].yingfa*0.05;}
else 
if(em[i].yingfa>500)
{em[i].sui=em[i].yingfa*0.1;}
else
 if(em[i].yingfa>2000)
{em[i].sui=em[i].yingfa*0.15;}
else 
if(em[i].yingfa>5000)
{em[i].sui=em[i].yingfa*0.2;}
else 
if(em[i].yingfa>20000)
{em[i].sui=em[i].yingfa*0.3;}
else 
if(em[i].yingfa>40000)
{em[i].sui=em[i].yingfa*0.35;}
else 
if(em[i].yingfa>60000)
{em[i].sui=em[i].yingfa*0.4;}
else 
if(em[i].yingfa>100000);
{em[i].sui=em[i].yingfa*0.45;}
else {printf("输入金额有误\n")}
 
em[i].shifa=em[i].yingfa-em[i].sui;
}



void del()   /*删除函数*/
{
  
    int m=read();
int i,j,n,t,flag;
char gonghao1[10];
printf("\n 原来的职工信息:\n");
    list();   /* 调用浏览函数*/
    printf("\n");
printf("请输入要删除的职工的工号:\n");
scanf("%s",gonghao1);
for(flag=1,i=0;flag&&i<m;i++)
{
  if(strcmp(em[i].gonghao,gonghao1)==0)
  {
   printf("\n已找到此人，原始记录为：\n");
            printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
   printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
            printf("\n确实要删除此人信息请按1,不删除请按0\n");
   scanf("%d",&n);
            if(n==1)   /*如果删除，则其他的信息都往上移一行*/
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
    printf("\n对不起，查无此人!\n");
    printf("\n 目前所有职工信息:\n");
    save(m);    /*调用保存函数*/
    list();  /*调用浏览函数*/
printf("\n继续删除请按1，不再删除请按0\n");
scanf("%d",&t);
switch(t)
{
    case 1:del();break;
    case 0:break;
    default :break;
}system("cls");
}
 
 
void add()   /*录入函数*/
{
   int i,m;
   printf("请输入需要创建信息的职工人数(1--100):\n");
   scanf("%d",&m);
   for (i=0;i<m;i++)
   {
  printf("请输入工号：");
  scanf("%s",&em[i].gonghao);
  printf("请输入姓名：");
  scanf("%s",em[i].name);
  printf("请输入岗位工资：");
  scanf("%f",&em[i].zhicheng);
  printf("请输入薪级工资：");
  scanf("%d",&em[i].jiben);
  printf("请输入职务津贴：");
  scanf("%d",&em[i].jiangjin);
  printf("请输入绩效工资：");
  scanf("%d",&em[i].baoxian);
  grsds();
  printf("\n");
   }
  printf("\n创建完毕!\n");system("cls");
  save(m);
}

void modify() /*修改函数*/
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
int m=read(); /*导入文件内的信息*/
    printf("\n 原来的职工信息:\n");
    list();   /* 调用浏览函数*/
    printf("\n");
    printf("请输入要修改的职工的工号:\n");
scanf("%s",gonghao);
for(flag=1,i=0;flag&&i<m;i++)
{
  if(strcmp(em[i].gonghao,gonghao)==0)
  {
   printf("\n此人记录为：\n");
   printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
   printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",em[i].gonghao,em[i].name,em[i].gangwei,em[i].xinji,em[i].zhiwu,em[i].jixiao,em[i].yingfa,em[i].sui,em[i].shifa);  
   printf("\n确实要修改此人信息请按1 ; 不修改请按0\n");
   scanf("%d",&n);
            if(n==1)
			{
               printf("\n需要进行修改的选项\n 1.工号 2.姓名 3.岗位工资 4.薪级工资 5.职务津贴 6.绩效工资\n");  
               printf("请输入你想修改的那一项序号:\n");  
               scanf("%d",&c);  
               if(c>6||c<1)  
               printf("\n选择错误，请重新选择!\n");  
             }
         flag=0;
  }
        
}
    if(flag==1)
    printf("\n查无此人\n");  
    do
		{
           switch(c)
           {  
           case 1:printf("工号改为: ");
                  scanf("%s",&gonghao);
                  strcpy(em[i-1].gonghao=gonghao);
                  break;  
           case 2:printf("姓名改为: ");
                  scanf("%s",&name);
                  strcpy(em[i-1].name,name); 
                  break;  
           case 3:printf("岗位工资改为: ");
                  scanf("%f",&gangwei);
                  em[i-1].gangwei=gangwei;
                  break;  
           case 4:printf("薪级工资改为: ");
                  scanf("%f",&xinji);
                  em[i-1].xinji=xinji;
                  break;  
           case 5:printf("职务津贴改为: ");
                  scanf("%d",&zhiwu);
                  em[i-1].zhiwu=zhiwu; 
                  break;  
           case 6:printf("绩效工资改为: ");
                  scanf("%f",&jixiao);
				  em[i-1].jixiao=jixiao; 
                  break;
		   } 
  printf("\n");
  printf("\n是否确定所修改的信息?\n 1.确定修改 \n 2.重新修改 \n"); 
  scanf("%d",&b);
}  
   while(b==2);
   grsde();
   printf("\n修改后的职工信息:\n");
   printf("\n");
   save(m);
   list();
   printf("\n继续修改请按1，不再修改请按0\n");
   scanf("%d",&t);
   switch(t)
{
    case 1:modify();break;
    case 0:break;
    default :break;
}system("cls");
}
}