#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define eps 0.00001

typedef struct Elemtype
{
	double ceof;  //系数
	int expn;  //指数
}Elemtype;

typedef struct Node
{
	Elemtype data;
	struct Node *next;
}Node;

Node* Build() //建立头结点
{
	Node* t;
	t=(Node *)malloc(sizeof(Node));
	t->next=NULL;
	return t;
}

void CreateList(Node* head,int n)
{
	Node *t,*hd;
	int i;
	double a;
	printf("请输入%d个结点(系数 指数):\n",n);
	for(i=0;i<n;i++)
	{
		t=(Node *)malloc(sizeof(Node));
		scanf("%lf%d",&t->data.ceof,&t->data.expn);
		if(t->data.ceof==0)
			continue;
		for(hd=head;hd->next && t->data.expn > hd->next->data.expn; )
			hd=hd->next;
		if(hd->next==NULL || hd->next->data.expn > t->data.expn)
		{
			t->next=hd->next;
			hd->next=t;
		}
		else
		{
			a=hd->next->data.ceof+t->data.ceof;
			if(fabs(a-0)<eps)
				hd->next=hd->next->next;
			else
				hd->next->data.ceof=a;
		}
	}
}

void Compare(Node *ha,Node *hb)
{
	Node *pa1=ha,*pa2=ha->next,*pb=hb->next,*t,*p;
	double a;
	while(pa2 && pb && pa2->data.expn > pb->data.expn)
	{
		t=(Node *)malloc(sizeof(Node));
		t->data.ceof=pb->data.ceof;
		t->data.expn=pb->data.expn;
		t->next=ha->next;
		pa1->next=t;
		pa1=pa1->next;
		pb=pb->next;
	}
	while(pa2->next && pb ) 
	{
		if(pa2->data.expn==pb->data.expn)
		{
			pa2->data.ceof+=pb->data.ceof;
			if(pa2->data.ceof==0)
			{
				pa1->next=pa2->next;
				p=pa1;  //p指向pa2前面的结点
			}
		}
		else
		{
			while(pa2->next && pb && pb->data.expn > pa2->next->data.expn)  //找到插入点的位置
				pa2=pa2->next;
			if(pa2->next==NULL || pa2->next->data.expn > pb->data.expn)
			{
				t=(Node *)malloc(sizeof(Node));
				t->data.ceof=pb->data.ceof;
				t->data.expn=pb->data.expn;
				t->next=pa2->next;
				pa2->next=t;
				
			}
			else
			{
				a=pa2->next->data.ceof+pb->data.ceof;
				if(fabs(a-0)<eps)
					pa2->next=pa2->next->next;
				else
					pa2->next->data.ceof=a;
			}
			p=pa2;    //此时p指向pa2结点
		}
		pa2=pa2->next;   //pa2后移
		pb=pb->next;
	}
	if(pb)
	{
		while(pa2->data.expn>pb->data.expn)
		{
			t=(Node *)malloc(sizeof(Node));
			t->data.ceof=pb->data.ceof;
			t->data.expn=pb->data.expn;
			t->next=pa2;
			p->next=t;
			p=p->next;
			pb=pb->next;
		}
		if(pa2->data.expn==pb->data.expn)
		{
			a=pa2->data.ceof+pb->data.ceof;
			if(fabs(a-0)<eps)
				p->next=pb->next;
			else
				pa2->data.ceof=a;
			pb=pb->next;
		}
		pa2->next=pb;
	}
}

void ShowList(Node* head)
{
	Node *t=head;
	while(t->next)
	{
		printf("%.3lf^%d",t->next->data.ceof,t->next->data.expn);
		if(t->next->next && t->next->next->data.ceof>0 )
			printf("+");
		t=t->next;
	}
	printf("\n");
}

int main()
{
	Node *ha,*hb;
	ha=Build();
	hb=Build();
	CreateList(ha,5);
	ShowList(ha);
	CreateList(hb,4);
	ShowList(hb);
	Compare(ha,hb);
	printf("相加后的多项式：\n");
	ShowList(ha);

	return 0;
}
		
/*

  5 3
  0 2
  -2 4
  -5 3
  3 1

  -3 1
  2 2
  2 4
  5 5

*/

/*
0 1
-2 3
3 6
-3 6
4 7

  -2 3
  -4 7
  -4 3
  2 1
  */
