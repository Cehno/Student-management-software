#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//����
int ui() {
	//system("title ѧ���������");//����cmd���ڱ���
	//system("mode con cols=50 lines=50");//���ڿ�ȸ߶�
	//system("color 0B");
	//system("date /T");
	//system("TIME /T");
	printf("******************ѧ������ϵͳ*****************\n");
	printf("�X===============�k�k============�k�k==============�[\n");
	printf("�U************** ��1.����ѧ����Ϣ **************�U\n");
	printf("�U************** ��2.���ѧ����Ϣ **************�U\n");
	printf("�U************** ��3.��ѯѧ����Ϣ **************�U\n");
	printf("�U************** ��4.�޸�ѧ����Ϣ **************�U\n");
	printf("�U************** ��5.ɾ��ѧ����Ϣ **************�U\n");
	printf("�U************** ��6.ѧ���ɼ����� **************�U\n");
	printf("�U************** ��7.����ѧ����Ϣ **************�U\n");
	printf("�U************** ��8.��ȡѧ����Ϣ **************�U\n");
	printf("�U***************** ��0.�˳�ϵͳ ***************�U\n");
	printf("�^=============================================�a\n");
	return;
}

//�����Ϣ����
struct tj {
	char mz[10];
	int xh;
	float cj;
}xusheng[100] = { 0 };
int zs = 0;
void tjxx() {
	printf("����ѧ����Ϣ\n�� ����+ѧ��+�ɼ� ¼��\n");
	scanf("%s %d %f", &xusheng[zs].mz, &xusheng[zs].xh, &xusheng[zs].cj);
	zs++;
}


//���
void sc(void) {
	int i;
	for (i = 0; i < zs; i++)
	{
		printf("ѧ�����֣�%s  ѧ����ţ�%d  ѧ���ɼ���%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
		
	}getchar();
}

//���ҹ���
int cz(void) {
	int n, i, c;
	char m[10],b[10]="0";
a:
	rewind(stdin);
	printf("��ѡ�����ģʽ��\n1.���ֲ���    2.ѧ�Ų���\n");
	scanf("%d", &n);
	if (n == 1) {
	b:
		printf("����������\n"); rewind(stdin);
		scanf("%s", m);
		for (i = 0; i < zs; i++) {
			if (strcmp(xusheng[i].mz, m) == 0)
			{ 
				printf("��ѯѧ��Ϊ��\n����:%s  ѧ�ţ�%d�ɼ���%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
				getchar();
				return i;
			}
			if (strcmp(b, m) == 0)
			{
				printf("���������˳�����\n");
				return;
			}
			
		}
		 printf("û�����ѧ��\n");
		goto b;
	}
	else if (n == 2)
	{
	c:
		printf("����ѧ�ţ�\n"); rewind(stdin);
		scanf("%d", &c);
		printf("c=%d  ����%d\n",c,zs);
		printf("xh=%d\n", xusheng[1].xh);
		for (i = 0; i < zs; i++)
		{
			if (c == xusheng[i].xh)
			{
				printf("��ѯѧ��Ϊ��\n������%s  ѧ�ţ�%d �ɼ���%.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
				return i;
			}
			if (c ==0)
			{
				printf("���������˳�����\n");
				return;
			}
		}
		 printf("û�����ѧ��\n");
		goto c;
	}
	else
	{
		printf("ѡ����󣡣���\n");
		goto a;
	}
}
//�޸�
void xg(void) {
	int n;
	char c=0;
	n = cz();
	printf("�Ƿ�ȷ���޸�?  y/n \n");
	scanf("%c ",&c);
	if (c == 'y') {
		getchar();
		printf("�������� ѧ�� �ɼ�\n");
		scanf("%s %d %f", &xusheng[n].mz, &xusheng[n].xh, &xusheng[n].cj);
	}

}

//ɾ��
void sanc(void) {
	int i,n;
	char c = 0;
	n = cz();
	printf("�Ƿ�ȷ��ɾ��?  y/n \n");
	scanf("%c",&c);
	if (c == 'y') {
		for (i = n; i < zs; i++) {
			//xusheng[i].mz = xusheng[i+1].mz;//���鶨����ɺ������帳ֵ��ֻ�ܵ�����ֵ������ʹ��strcpy�������ƣ�
			strcpy(xusheng[i].mz , xusheng[i + 1].mz);
		}
		printf("ɾ���ɹ���\n"); 
		zs--; 
		return 0;
	}
	printf("ɾ��ȡ�� \n");
	
}

//�ɼ�����
void px() {
	struct tj t;
	int i, j,c;
	printf("��ѡ������ʽ��\n1.�ɸ�����    2.�ɵ�����\n"); rewind(stdin);
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
		printf("�������\n");
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
		printf("�������\n");
		return;
	}
	
}

//���湦��
void bc() {
	FILE* p;
	int i, j, n;
	p = fopen("D:/ѧϰ/C����ѧϰ/ѧ������/ѧ������/xs.rtf", "w");
	fseek(p, 0, 0);
	for (i = 0; i < zs; i++) {
		fprintf(p, "%s %d %.2f\n", xusheng[i].mz, xusheng[i].xh, xusheng[i].cj);
	}
	fclose(p);
	printf("�������\n");
}

//��ȡ����
void dq() {
	FILE* p;//�� 
	int n;
	p = fopen("D:/ѧϰ/C����ѧϰ/ѧ������/ѧ������/xs.rtf", "r");
	fseek(p, 0, 0); //���ƫ��
	while (fscanf(p, "%s %d %f", &xusheng[zs].mz, &xusheng[zs].xh, &xusheng[zs].cj) != -1) {
		printf("��ȡѧ����ϢΪ��\n������%s  ѧ�ţ�%d �ɼ���%.2f\n", xusheng[zs].mz, xusheng[zs].xh, xusheng[zs].cj);
		zs++;
	}
	printf("ִ�ж�ȡ���\n");
	fclose(p);

}



//������
int main() {
	int x=10;
	while (x) {
		ui();
		printf("������ѡ��:\n");
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
		default:printf("ѡ����󣡣���\n"); break;
		}
	}
	while (1);
}