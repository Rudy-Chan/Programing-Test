#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int num;
	struct Node* next;
}Node;

void Showlist(Node *head)
{
	Node *p=head;
	while(p)
	{
		printf("%-3d",p->num);
		p=p->next;
	}
	printf("\n");
}
/*
Node* Build()
{
	Node *t;
	t=(Node *)malloc(sizeof(Node));
	t->next=NULL;
	return t;
}
*/
void Insert(Node *&head,int v)
{
	Node *t,*p;
	t=(Node *)malloc(sizeof(Node));
	t->num=v;

	if(head==NULL)
	{
		t->next=NULL;
		head=t;
	}
	else if(t->num<head->num)
	{
		t->next=head;
		head=t;
	}
	else
	{
		p=head;
		while(p)
		{
			if(p->next==NULL)
			{
				p->next=t;
				t->next=NULL;
				break;
			}
			else if(p->num<=t->num && p->next->num>=t->num)
			{
				t->next=p->next;
				p->next=t;
				break;
			}
			else
				p=p->next;
		}
	}
}

Node* Combine(Node* ha,Node* hb)
{
	Node *pa=ha,*pb=hb,*head,*t,*hd;
	if(ha->num>hb->num)
	{
		head=(Node *)malloc(sizeof(Node));
		hd=head;
		head->num=hb->num;
		head->next=ha;
		pb=pb->next;
		while(pa->num>pb->num && pb)
		{
			t=(Node *)malloc(sizeof(Node));
			t->num=pb->num;
			t->next=pa;
			hd->next=t;
			hd=hd->next;
			pb=pb->next;
		}
	}
	else
	{
		head=ha;
	}
	while(pa->next&&pb)
	{
		if(pa->num==pa->next->num)
			pa->next=pa->next->next;
		else if(pa->next->num<pb->num)
			pa=pa->next;
		else if(pa->next->num==pb->num)
		{
			pa=pa->next;
			pb=pb->next;
		}
		else
		{
			t=(Node *)malloc(sizeof(Node));
			t->num=pb->num;
			t->next=pa->next;
			pa->next=t;
			pb=pb->next;
		}
	}
	if(pb)
	{
		while(pb)
		{
			if(pa->num==pb->num)
				pb=pb->next;
			else
			{
				t=(Node *)malloc(sizeof(Node));
				t->num=pb->num;
				t->next=NULL;
				pa->next=t;
				pb=pb->next;
				pa=pa->next;
			}
		}
	}
	else 
	{
		if(pa->num==pa->next->num)
			pa->next=pa->next->next;
	}
	return head;
}

int main()
{
	Node *ha=NULL,*hb=NULL,*hd;
	int i,n,v;
	printf("建立A链表：\n");
	printf("请输入A表待插入的节点个数：\n");
	scanf("%d",&n);
	printf("请输入%d个节点数值：\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v);
		Insert(ha,v);
	}
	printf("A链表:");
	Showlist(ha);
	printf("\n");
	printf("建立B链表：\n");
	printf("请输入B表待插入的节点个数：\n");
	scanf("%d",&n);
	printf("请输入%d个节点数值：\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v);
		Insert(hb,v);
	}
	printf("B链表:");
	Showlist(hb);
	hd=Combine(ha,hb);
	printf("\n重组后的链表:\n");
	Showlist(hd);



	return 0;
}