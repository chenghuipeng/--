#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define NULL 0

typedef struct LNode
{
	int num, pwd;
	struct LNode * next;

}LNode, *Linklist;

Linklist Createlist(Linklist head, int n)
{
	int i;
	Linklist p=NULL, q=NULL;
	head = (Linklist)malloc(sizeof(LNode));
	q = head;
	q->num = 1;
	q->pwd = rand() % 10 + 1;
	for (i = 2; i <= n;i++)
	{
		p = (Linklist)malloc(sizeof(LNode));
		p->num = i;
		p->pwd = rand() % 10 + 1;//产生1-10之间的数
		q->next = p;
		q = p;
	}
	p->next = head;//循环链表形成
	return head;
}
void Printt(Linklist head)
{
	Linklist p;
	p = head;
	printf("输出每个人的密码\n");
	while (p->next != head)
	{
		printf("第%d个人的密码是：%d\n",p->num,p->pwd);
		p = p->next;
	}
	printf("第%d个人的密码是：%d\n", p->num, p->pwd);
	printf("\n");
}
//输出出列次序
void OutList(Linklist head,int k)
{
	Linklist p, q;
	int m, i;
	p = head;
	m = head->pwd;
	for (i = 1; i < k;i++)//k 结点位置
		p = p->next;
	q = p;
	while (p)
	{
		for (i = 1; i < m;i++)
		{
			q = p;
			p = p->next;
		}
		m = p->pwd;
		printf("%3d%",p->num);
		q->next = p->next;
		free(p);
		p = q->next;
	}
	printf("%3d%", p->num);
	free(p);
	printf("\n\n");

}

int main1(int argc, char *argv[])
{
	int k, n;
	Linklist list, head;
	list = NULL;
	printf("---------约瑟夫问题------------\n");
	printf("\n请输入总人数和第几个人开始报数n,k:\n");
	scanf("%d%d",&n,&k);
	head = Createlist(list, n);
	Printt(head);
	printf("\n出队的次序是：\n");
	OutList(head, k);
	return 0;

}
