#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

int n=0; //定义全局变量职工人数

void read();
void write();
void find();
void list();
void modify();
void del();
void add();
float grsd(float m); //声明各函数

struct zhigong		//职工数据结构体
{   
char number[10];
char name[10];
float post_wage;		//岗位工资
float pay_salary;		//薪级工资
float duty_allowance;	//职务津贴
float merit_pay;		//绩效工资
float gross_pay;		//应发工资
float income_tax;		//个人所得税
float payroll;			//实发工资
}zggz[100];

void read()		//读取函数
{
    FILE*Read=fopen("gz.dat","ab+");
    if(Read)
    {   
        while(!feof(Read))
        {
            char lock=fgetc(Read);		
            if(lock!=EOF)
            {
                fscanf(Read,"%s%s%f%f%f%f%f%f%f",
					&zggz[n].number,
					&zggz[n].name,
					&zggz[n].post_wage,
					&zggz[n].pay_salary,
					&zggz[n].duty_allowance,
					&zggz[n].merit_pay,
					&zggz[n].gross_pay,
					&zggz[n].income_tax,
					&zggz[n].payroll);
                n++;
            }
        }
        fclose(Read);
    }
    else
    {
        printf("\n不能打开 ");
    }
    
}


void write()		//保存函数
{
    FILE*DF_05=fopen("gz.dat","wb");
    if(DF_05)
    {   
		for(int i=0;i<n;i++)
        {
            fprintf(DF_05,"\t%-10s%-10s%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f\t%-10f",
				zggz[i].number,zggz[i].name,zggz[i].post_wage,
                zggz[i].pay_salary,zggz[i].duty_allowance,zggz[i].merit_pay,
				zggz[i].gross_pay,zggz[i].income_tax,zggz[i].payroll);
        }
        fclose(DF_05);
        printf("\n保存成功");
    }
    else
    {
        printf("\n保存失败");
    }
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void find()		//查询函数
{	
	int i;
    char gonghao[10];
    printf("\n请输入查询的工号:");
    scanf("%s",gonghao);
    for(i=0;i<n;i++)
    {   
        if(strcmp(gonghao,zggz[i].number)==0)
        {
            printf("该职工工资信息如下：\n");
			printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
			printf("\n%s %s %f %f %f %f %f %f %f\n",
                zggz[i].number,
				zggz[i].name,
				zggz[i].post_wage, 
                zggz[i].pay_salary,
				zggz[i].duty_allowance,
				zggz[i].merit_pay, 
                zggz[i].gross_pay,
				zggz[i].income_tax,
				zggz[i].payroll);
        }
    }
    if(!i)
    {
		printf("\n您输入的工号有误");
    }
	
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
    
}

void list()		//浏览函数
{
	if(n==0)
	{
		printf("暂无职工信息");
	}
    else
	{
		printf("全体职工工资信息：\n");
		printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
		for(int i=0;i<n;i++)
		{
			
			printf("\n%s %s %f %f %f %f %f %f %f\n",
				zggz[i].number, 
				zggz[i].name, 
				zggz[i].post_wage, 
				zggz[i].pay_salary, 
				zggz[i].duty_allowance, 
				zggz[i].merit_pay, 
				zggz[i].gross_pay, 
				zggz[i].income_tax, 
				zggz[i].payroll);
		}
	}
	
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void modify()	//修改函数
{
    char gonghao[10];
    printf("\n请输入想要修改的职工工号:");
    scanf("%s",gonghao);
	
	int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            printf("该职工工资信息如下：");
			printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
			printf("\n%s %s %f %f %f %f %f %f %f\n",
				zggz[i].number, 
				zggz[i].name,
				zggz[i].post_wage, 
				zggz[i].pay_salary,
				zggz[i].duty_allowance,
				zggz[i].merit_pay, 
				zggz[i].gross_pay,
				zggz[i].income_tax,
				zggz[i].payroll);        
			
            printf("请输入该职工新的岗位工资：");
            scanf("%f",&zggz[i].post_wage);
            printf("\n请输入该职工新的薪级工资：");
            scanf("%f",&zggz[i].pay_salary);
            printf("\n请输入该职工新的政务津贴：");
            scanf("%f",&zggz[i].duty_allowance);
            printf("\n请输入该职工新的绩效工资：");
            scanf("%f",&zggz[i].merit_pay);
			
            zggz[i].gross_pay=zggz[i].post_wage+zggz[i].pay_salary+zggz[i].duty_allowance+zggz[i].merit_pay; //计算实发工资
            zggz[i].income_tax=grsd(zggz[i].gross_pay);    //调用税函数计算个人所得税
            zggz[i].payroll=zggz[i].gross_pay-zggz[i].income_tax;    //计算应发工资
			
            printf("该职工修改后的工资信息如下\n");
			printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
			printf("\n%s %s %f %f %f %f %f %f %f\n",
				zggz[i].number,
				zggz[i].name, 
				zggz[i].post_wage, 
				zggz[i].pay_salary, 
				zggz[i].duty_allowance, 
				zggz[i].merit_pay, 
				zggz[i].gross_pay, 
				zggz[i].income_tax, 
				zggz[i].payroll);  
			i=1;
        }
    }
	
	if(!i)
    {
		printf("您所输入的工号有误");
    }
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

void del()		//删除函数
{
    char gonghao[10];
	printf("请输入要删除的职工号：");
    scanf("%s",gonghao);
	
	int i,flg;

    for(i=0;i<n;i++)
    {
        if(strcmp(zggz[i].number,gonghao)==0)
        {
            printf("\n查到该职工工资信息如下：\n");;
			printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
			printf("\n%s %s %f %f %f %f %f %f %f\n",
                zggz[i].number,
                zggz[i].name, 
				zggz[i].post_wage, 
				zggz[i].pay_salary, 
				zggz[i].duty_allowance, 
				zggz[i].merit_pay, 
				zggz[i].gross_pay,
				zggz[i].income_tax, 
				zggz[i].payroll);

            printf("1.确认删除 2.重新输入\n");
            scanf("%d",&flg);

            if(flg==1)
            {
                for(int j=i=1;j<n-1;j++)
                {
                    zggz[j]=zggz[j+1];	//将职工工资信息往前移
                }
                strcpy(zggz[n-1].number, " "); 
                strcpy(zggz[n-1].name, " "); 
                zggz[n-1].post_wage=0; 
                zggz[n-1].pay_salary=0;
                zggz[n-1].duty_allowance=0; 
                zggz[n-1].merit_pay=0;
                zggz[n-1].gross_pay=0;
                zggz[n-1].income_tax=0;
                zggz[n-1].payroll=0;	//将最后一个职工工资信息清零
                n=n-1;
                printf("已成功删除");
            }
            
			else if(flg==2)
            {
                del();
            }
        }

    }

	
	if(!i)
    {
		printf("您所输入的职工工号有误");
	}
	
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        system("cls");
        return;
    }
    
}

void add()		//添加职工工资信息函数
{
    n=n+1;		//职工人数加一
    printf("请输入工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资\n");
    scanf("%s%s%f%f%f%f",
		&zggz[n-1].number,&zggz[n-1].name,&zggz[n-1].post_wage,
		&zggz[n-1].pay_salary,&zggz[n-1].duty_allowance,&zggz[n-1].merit_pay);
	
    zggz[n-1].gross_pay=zggz[n-1].post_wage + zggz[n-1].pay_salary + zggz[n-1].duty_allowance + zggz[n-1].merit_pay;    //计算实发工资
    zggz[n-1].income_tax=grsd(zggz[n-1].gross_pay);    //调用税函数计算个人所得税
    zggz[n-1].payroll=zggz[n-1].gross_pay - zggz[n-1].income_tax;    //计算应发工资
	
    printf( "所添加的职工信息为：\n");
	printf("\n工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
	printf("\n%s %s %f %f %f %f %f %f %f\n",
		zggz[n-1].number,zggz[n-1].name,zggz[n-1].post_wage,
		zggz[n-1].pay_salary,zggz[n-1].duty_allowance,zggz[n-1].merit_pay,
		zggz[n-1].gross_pay,zggz[n-1].income_tax,zggz[n-1].payroll);
	
    printf("\n按任意键返回主菜单");
    if(getch())
    {   
        return;
    }
}

float grsd(float m)		//计算个人所得税
{
    float sui1;
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

	return(sui1);
}

void main()		//主函数
{
	
    
    read();
	
    while(1)
    {
		system("cls");		//清屏操作
        printf("        ### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n\n");
        printf("        ==============================================================\n");
        printf("        :                     1、 查询职工工资记录                   :\n");
        printf("        :                     2、 修改职工工资记录                   :\n");
        printf("        :                     3、 添加职工工资记录                   :\n");
        printf("        :                     4、 删除职工工资记录                   :\n");
        printf("        :                     5、 保存职工工资记录                   :\n");
        printf("        :                     6、 浏览职工工资记录                   :\n");
        printf("        :                     7、 退出系统                           :\n");
        printf("        ==============================================================\n");
        printf("\n");
        printf("\n");
        printf("		          请输入你想进行的操作[ ]\b\b");
		
		int flg;
        scanf("%d",&flg);
        if(flg>=1&&flg<=7)
        {
            switch(flg)
            {
			case 1:find();break;
			case 2:modify();break;
			case 3:add();break;
			case 4:del();break;
			case 5:write();break;
            case 6:list();break;
            case 7:exit(0);
            }
        }
        else
        {
            printf("没有这个选择");
            getch();
            system("cls");
        }
    }
    
}
