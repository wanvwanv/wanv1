#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#define N 100

struct zggz
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
}zggz[100];

void menu();
void add();
void write(int);
void list();
void del();
void find();
void modify();
float grsds(float);  //定义各函数

void menu()   //菜单函数
{
    system("cls");//清屏
    printf("\n");
    printf("职工工资管理系统\n");
    printf("1.查询职工信息\n");
    printf("2.修改职工信息\n");
    printf("3.添加职工信息\n");
    printf("4.删除职工信息\n");
    printf("5.保存职工信息\n");
    printf("6.浏览职工信息\n");
    printf("7.退出\n");
    printf("\n");
    
}

void main()
{
	int n,flag;
	while(1)
	{ 
		
		do
		{
			menu(); 
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
				system("pause");
			}
		}while(flag==0);
		switch(n)
		{
		case 1:printf("查询职工信息\n");printf("\n");system("cls");find();break;
		case 2:printf("修改职工信息\n");printf("\n");system("cls");modify();break;
		case 3:printf("添加职工信息\n");printf("\n");system("cls");add();break; 
		case 4:printf("删除职工信息\n");printf("\n");system("cls");del();break;
		case 5:printf("保存职工信息\n");printf("\n");system("cls");write(0);break;
		case 6:printf("浏览职工信息\n");printf("\n");system("cls");list();break;
		case 7:goto la;
		default :break;
		}
		
	}
la:
	system("cls");   
	printf("已成功退出\n");
}

void add()   //录入函数
{
	int i,m;
	system("cls");
	printf("请输入需要创建信息的职工人数(1--100):\n");
	scanf("%d",&m);
	
	for (i=0;i<m;i++)
	{
		printf("请输入工号：");
		scanf("%s",&zggz[i].gonghao);
		printf("请输入姓名：");
		scanf("%s",zggz[i].name);
		printf("请输入岗位工资：");
		scanf("%f",&zggz[i].gangwei);
		printf("请输入薪级工资：");
		scanf("%f",&zggz[i].xinji);
		printf("请输入职务津贴：");
		scanf("%f",&zggz[i].zhiwu);
		printf("请输入绩效工资：");
		scanf("%f",&zggz[i].jixiao);
		zggz[i].yingfa=(zggz[i].gangwei+zggz[i].xinji+zggz[i].zhiwu+zggz[i].jixiao);
		zggz[i].sui=grsds(zggz[i].yingfa);
		zggz[i].shifa=zggz[i].yingfa-zggz[i].sui;
		printf("\n");
		write(m); 
	}
	printf("\n创建完毕!\n");
	getchar();system("cls");
}

void write(int m)  //保存函数
{
	int i;
	FILE*fp; //声明fp是指针，用来指向FILE类型的对象
	if ((fp=fopen("e:\\gz.dat","wb"))==NULL)  //创建文件并判断是否能打开
	{
		printf ("打开失败\n");
		exit(0);
	}
	
	for (i=0;i<m;i++) //内存中职工的信息输出到磁盘文件中去
		if (fwrite(&zggz,sizeof(struct zggz),1,fp)!=1)
			printf("文件读写错误\n");
		fclose(fp);//缓冲区内最后剩余的数据输出到磁盘文件中，并释放文件指针和有关的缓冲区
}

int read()  //读取函数
{
	FILE*fp;
	int i=0;
	if((fp=fopen("e:\\gz.dat","rb"))==NULL)
	{
		printf ("不能打开\n");
		exit(0);
		getchar();system("cls");
	}
	else 
	{
		do 
		{
			fread(&zggz[i],sizeof(struct zggz),1,fp);
			i++;
		}
		while(feof(fp)==0);
	}
	
	fclose(fp);
	return(i-1);
}

void find() //查询函数
{	
	char gonghao[10];
	int i;
	int m=read();
	printf("请输入要查找的工号:\n");
	scanf("%s",gonghao);
	for(i=0;i<m;i++)
		if(strcmp(zggz[i].gonghao,gonghao)==0)
		{
			printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
			printf("\n%s %s %f %f %f %f %f %f %f\n",zggz[i].gonghao,zggz[i].name,zggz[i].gangwei,zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao,zggz[i].yingfa,zggz[i].sui,zggz[i].shifa);
			system("pause");
		}
		if(i==m)
			printf("\n查无此人\n");
		    system("pause");
		    printf("\n");
}

void list()  //浏览函数
{
	int i;
	int m=read();
	system("cls");
	printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
	for(i=0;i<m;i++)
		printf("\n%s %s %f %f %f %f %f %f %f\n",zggz[i].gonghao,zggz[i].name,zggz[i].gangwei,zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao,zggz[i].yingfa,zggz[i].sui,zggz[i].shifa); 
	system("pause");
	printf("返回主菜单\n");
	getchar();system("cls");
}


void del()   //删除函数
{
	
	int m=read();
	int i,j,n,t,flag;
	char gonghao[10];
	printf("\n原来的职工信息:\n");
    list();   //调用浏览函数
    printf("\n");
	printf("请输入要删除的职工的工号:\n");
	scanf("%s",gonghao);
	for(flag=1,i=0;flag&&i<m;i++) 
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)
		{
			printf("\n此人原始记录为:\n");
			printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
			printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",zggz[i].gonghao,zggz[i].name,zggz[i].gangwei,zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao,zggz[i].yingfa,zggz[i].sui,zggz[i].shifa);  
			printf("\n 1确定删除 0不删除\n");
			scanf("%d",&n);
            if(n==1)   //如果删除，则其他的信息都往上移一行
			{
				for(j=i;j<m-1;j++)
				{
					zggz[j]=zggz[j+1];
				}
				flag=0;
			}
		}
	}
	if(!flag)
		m=m-1;
	else
		printf("\n查无此人!\n");
    printf("\n目前所有职工信息:\n");
    write(m);
    list();
	printf("\n继续删除请按1，不再删除请按0\n");
	scanf("%d",&t);
	switch(t)
	{
    case 1:del();break;
    case 0:break;
    default :break;
	}
}


float grsds(float m) //税函数
{
	float sui1;
	float tmp;
	sui1=0;
	
	if(m<=500)
	{
		sui1=m*(float)0.05;
	}
	else if(m<=2000)
	{
		sui1=(m-500)*(float)0.1+25;
	}
	else if(m<=5000)
	{
		sui1=(m-2000)*(float)0.15+175;
	}
	else if(m<=20000)
	{
		sui1=(m-5000)*(float)0.2+625;
	}
	else if(m<=40000)
	{
		sui1=(m-20000)*(float)0.25+3625;
	}
	else if(m<=60000)
	{
		sui1=(m-40000)*(float)0.3+8625;
	}
	else if(m<=80000)
	{
		sui1=(m-60000)*(float)0.35+14625;
	}
	else if(m<=100000)
	{
		sui1=(m-80008)*(float)0.4+21625;
	}
	else
	{
		sui1=(m-100008)*(float)0.45+29625;
	}
	tmp=sui1;
	return(tmp);
}


void modify() //修改函数
{
	char gonghao[10];
	char name[10];
	float gangwei;
	float xinji;
	float zhiwu;
	float jixiao;
	int b,c,i,n,t,flag; 
	int m=read(); //导入文件内的信息
    printf("\n 原来的职工信息:\n");
    list();
    printf("\n");
    printf("请输入要修改的职工的工号:\n");
	scanf("%s",gonghao);
	for(flag=1,i=0;flag&&i<m;i++)
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)
		{
			printf("\n此人记录为：\n");
			printf("\n工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
			printf("\n%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",zggz[i].gonghao,zggz[i].name,zggz[i].gangwei,zggz[i].xinji,zggz[i].zhiwu,zggz[i].jixiao,zggz[i].yingfa,zggz[i].sui,zggz[i].shifa);  
			printf("\n 1确定修改此人资料 0返回上层 \n");
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
			strcpy(zggz[i-1].gonghao,gonghao);
			break;  
		case 2:printf("姓名改为: ");
			scanf("%s",&name);
			strcpy(zggz[i-1].name,name); 
			break;  
		case 3:printf("岗位工资改为: ");
			scanf("%f",&gangwei);
			zggz[i-1].gangwei=gangwei;
			zggz[i].yingfa=(zggz[i-1].gangwei+zggz[i].xinji+zggz[i].zhiwu+zggz[i].jixiao);
			zggz[i].sui=grsds(zggz[i].yingfa);
			zggz[i].shifa=zggz[i].yingfa-zggz[i].sui;
			break;  
		case 4:printf("薪级工资改为: ");
			scanf("%f",&xinji);
			zggz[i-1].xinji=xinji;
			zggz[i].yingfa=(zggz[i].gangwei+zggz[i-1].xinji+zggz[i].zhiwu+zggz[i].jixiao);
			zggz[i].sui=grsds(zggz[i].yingfa);
			zggz[i].shifa=zggz[i].yingfa-zggz[i].sui;
			break;  
		case 5:printf("职务津贴改为: ");
			scanf("%d",&zhiwu);
			zggz[i-1].zhiwu=zhiwu;
			zggz[i].yingfa=(zggz[i].gangwei+zggz[i].xinji+zggz[i-1].zhiwu+zggz[i].jixiao);
			zggz[i].sui=grsds(zggz[i].yingfa);
			zggz[i].shifa=zggz[i].yingfa-zggz[i].sui;
			break;  
		case 6:printf("绩效工资改为: ");
			scanf("%f",&jixiao);
			zggz[i-1].jixiao=jixiao; 
			zggz[i].yingfa=(zggz[i].gangwei+zggz[i].xinji+zggz[i].zhiwu+zggz[i-1].jixiao);
			zggz[i].sui=grsds(zggz[i].yingfa);
			zggz[i].shifa=zggz[i].yingfa-zggz[i].sui;
			break;
		} 
		printf("\n");
		printf("\n 1.确定修改 2.重新修改 \n"); 
		scanf("%d",&b);
	}  
	while(b==2);
	printf("\n修改后的职工信息:\n");
	printf("\n");
	write(m);
	list();
	printf("\n继续修改请按1，不再修改请按0\n");
	scanf("%d",&t);
	switch(t)
	{
    case 1:modify();break;
    case 0:break;
    default :break;
	}
	
}
