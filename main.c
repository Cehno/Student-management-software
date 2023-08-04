#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//界面
int ui() {
	//system("title 学生管理程序");//设置cmd窗口标题
	//system("mode con cols=50 lines=50");//窗口宽度高度
	//system("color 0B");
	//system("date /T");
	//system("TIME /T");
	printf("******************学生管理系统*****************\n");
	printf("╔===============╧╧============╧╧==============╗\n");
	printf("║************** ※1.增加学生信息 **************║\n");
	printf("║************** ※2.输出学生信息 **************║\n");
	printf("║************** ※3.查询学生信息 **************║\n");
	printf("║************** ※4.修改学生信息 **************║\n");
	printf("║************** ※5.删除学生信息 **************║\n");
	printf("║************** ※6.学生成绩排序 **************║\n");
	printf("║************** ※7.保存学生信息 **************║\n");
	printf("║************** ※8.读取学生信息 **************║\n");
	printf("║***************** ※0.退出系统 ***************║\n");
	printf("╚=============================================╝\n");
	return;
}

//添加信息功能
struct tj {
	char mz[10];
	int xh;
	float cj;
}xusheng[100] = { 0 };
int zs = 0;
void tjxx() {
	printf("输入学生信息\n按 姓名+学号+成绩 录入\n");
	scanf("%s %d %f", &xusheng[zs].mz, &xusheng[zs].xh, &xusheng[zs].cj);
	zs++;
}


//输出
void sc(void) {
	int i;
	for (i = 0; i < zs; i++)
	{
		printf("学生名字：%s  学生序号：%d  学生成绩：%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
		
	}getchar();
}

//查找功能
int cz(void) {
	int n, i, c;
	char m[10],b[10]="0";
a:
	rewind(stdin);
	printf("请选择查找模式：\n1.名字查找    2.学号查找\n");
	scanf("%d", &n);
	if (n == 1) {
	b:
		printf("输入姓名：\n"); rewind(stdin);
		scanf("%s", m);
		for (i = 0; i < zs; i++) {
			if (strcmp(xusheng[i].mz, m) == 0)
			{ 
				printf("查询学生为：\n姓名:%s  学号：%d成绩：%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
				getchar();
				return i;
			}
			if (strcmp(b, m) == 0)
			{
				printf("满足隐藏退出功能\n");
				return;
			}
			
		}
		 printf("没有这个学生\n");
		goto b;
	}
	else if (n == 2)
	{
	c:
		printf("输入学号：\n"); rewind(stdin);
		scanf("%d", &c);
		printf("c=%d  人数%d\n",c,zs);
		printf("xh=%d\n", xusheng[1].xh);
		for (i = 0; i < zs; i++)
		{
			if (c == xusheng[i].xh)
			{
				printf("查询学生为：\n姓名：%s  学号：%d 成绩：%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
				return i;
			}
			if (c ==0)
			{
				printf("满足隐藏退出功能\n");
				return;
			}
		}
		 printf("没有这个学生\n");
		goto c;
	}
	else
	{
		printf("选择错误！！！\n");
		goto a;
	}
}
//修改
void xg(void) {
	int n;
	char c=0;
	n = cz();
	printf("是否确认修改?  y/n \n");
	scanf("%c ",&c);
	if (c == 'y') {
		getchar();
		printf("输入名字 学号 成绩\n");
		scanf("%s %d %f", &xusheng[n].mz, &xusheng[n].xh, &xusheng[n].cj);
	}

}

//删除
void sanc(void) {
	int i,n;
	char c = 0;
	n = cz();
	printf("是否确认删除?  y/n \n");
	scanf("%c",&c);
	if (c == 'y') {
		for (i = n; i < zs; i++) {
			//xusheng[i].mz = xusheng[i+1].mz;//数组定义完成后不能整体赋值，只能单个赋值；或者使用strcpy函数复制；
			strcpy(xusheng[i].mz , xusheng[i + 1].mz);
		}
		printf("删除成功！\n"); 
		zs--; 
		return 0;
	}
	printf("删除取消 \n");
	
}

//成绩排序
void px() {
	struct tj t;
	int i, j,c;
	printf("请选择排序方式：\n1.由高至低    2.由低至高\n"); rewind(stdin);
	scanf("%d", &c);
	if (c == 2) {
		for (i = 0; i < zs; i++) {
			for (j = 0; j < zs - i - 1; j++) {
				if (xusheng[j].cj > xusheng[j + 1].cj) {
					t = xusheng[j];
					xusheng[j] = xusheng[j + 1];
					xusheng[j + 1] = t;
				}
			}
		}
		printf("排序完毕\n");
		return;
	}
	if (c == 1) {
		for (i = 0; i < zs; i++) {
			for (j = 0; j < zs - i - 1; j++) {
				if (xusheng[j].cj < xusheng[j + 1].cj) {
					t = xusheng[j];
					xusheng[j] = xusheng[j + 1];
					xusheng[j + 1] = t;
				}
			}
		}
		printf("排序完毕\n");
		return;
	}
	
}

//保存功能
void bc() {
	FILE* p;
	int i, j, n;
	p = fopen("D:/学习/C语言学习/学生管理/学生数据/xs.rtf", "w");
	fseek(p, 0, 0);
	for (i = 0; i < zs; i++) {
		fprintf(p, "%s %d %.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
	}
	fclose(p);
	printf("保存完毕\n");
}

//读取功能
void dq() {
	FILE* p;//读 
	int n;
	p = fopen("D:/学习/C语言学习/学生管理/学生数据/xs.rtf", "r");
	fseek(p, 0, 0); //光标偏移
	while (fscanf(p, "%s %d %f", &xusheng[zs].mz, &xusheng[zs].xh, &xusheng[zs].cj) != -1) {
		printf("读取学生信息为：\n姓名：%s  学号：%d 成绩：%.2f\n", xusheng[zs].mz, xusheng[zs].xh, xusheng[zs].cj);
		zs++;
	}
	printf("执行读取完毕\n");
	fclose(p);

}



//主函数
int main() {
	int x=10;
	while (x) {
		ui();
		printf("请输入选项:\n");
		scanf("%d", &x);
		switch (x) {
		case 1:tjxx(); break;
		case 2:sc(); break;
		case 3:cz(); break;
		case 4:xg(); break;
		case 5:sanc(); break;
		case 6:px(); break;
		case 7:bc(); break;
		case 8:dq(); break;
		case 0:exit(0); break;
		default:printf("选项错误！！！\n"); break;
		}
	}
	while (1);
}