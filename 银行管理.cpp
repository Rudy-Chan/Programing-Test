#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

#define SIZE 5

using namespace std;

//1.实现单链表的常用操作

typedef string datatype;

typedef struct LinkNode{
    datatype account;
	datatype name;
	datatype password;
	datatype phonenumber;
	datatype money;
    struct LinkNode *pNext;
}LinkNode,*LinkNodePtr;//节点

//链表头结点
typedef struct {
LinkNodePtr pListHead;
int s32CurrentLen;
}LinkListHead;//头节点


//追加
//在pList的紧挨当前最后一个元素的下一个位置存放element，返回element的真实索引
int push(LinkListHead *pList,datatype message[])
{
	//尾插法
    LinkNodePtr p=new LinkNode;
    p->account=message[0];
	p->name=message[1];
	p->password=message[2];
	p->phonenumber=message[3];
	p->money=message[4];
	p->pNext=NULL;
	if(pList->pListHead==NULL)
	{
		pList->pListHead=p;
	}
	else
	{
		LinkNodePtr t=pList->pListHead;
		while(t->pNext!=NULL)
		{
			t=t->pNext;
		}
		t->pNext=p;
	}
	pList->s32CurrentLen++;
	return pList->s32CurrentLen;
}

//插入
//在pList的s32Position处插入element，若s32Position大于当前最后一个元素索引，则本函数功能同push,返回element的真实索引
int insert(LinkListHead *pList,int s32Position,datatype message[])
{
	int i;
    LinkNodePtr t=pList->pListHead;
    LinkNodePtr p=new LinkNode;
    p->account=message[0];
	p->name=message[1];
	p->password=message[2];
	p->phonenumber=message[3];
	p->money=message[4];
	if(s32Position<=1)
	{
		p->pNext=t;
		pList->pListHead=p;
	}
	else
	{
		for(i=2;i<s32Position && t->pNext!=NULL;i++)
		{
			t=t->pNext;
		}
		p->pNext=t->pNext;
		t->pNext=p;
    }
    pList->s32CurrentLen++;
	return i;
}  


//删除
//删除s32Position位置的元素，返回被删除位置的索引，如果s32Position无元素返回-1（比如表里有3个元素，s32Position是5时），链表删除时要释放该节点
int remove(LinkListHead *pList,int s32Position)
{
    LinkNodePtr p=pList->pListHead;
    int i;
	if(s32Position<=0 || s32Position>pList->s32CurrentLen)
	{
		return -1;
	}
	if(s32Position==1)
	{
		if(pList->pListHead==NULL)
		{
			return -1;
		}
		else
		{
			pList->pListHead=p->pNext;
			delete p;
			return s32Position;
		}
	}
	LinkNodePtr t=p->pNext;
    for(i=2;i<s32Position;i++)
    {
    	p=t;
    	t=t->pNext;	
    }
    p->pNext=t->pNext;
    delete t;
    pList->s32CurrentLen--;
	return i;
}


//获取元素
//返回pList中s32Position处的元素，不存在时返回NULL（比如表里有3个元素，s32Position是5时）
datatype* get(LinkListHead *pList,int s32Position)
{
    LinkNodePtr t=pList->pListHead;
	if(t==NULL || s32Position<=0 || s32Position>pList->s32CurrentLen)
    {
        return NULL;
    }
	else
	{
		for(int i=1;i<s32Position && i<=pList->s32CurrentLen;i++)
		{
			t=t->pNext;
		}
		datatype* str=new datatype[5]{t->account,t->name,t->password,t->phonenumber,t->money};
		return str;
	}
}

//元素个数
//返回pList元素个数
int  getLength(LinkListHead *pList)
{
    return pList->s32CurrentLen;
}

int showMenu()
{
	cout<<"                 银行管理系统                 "<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"  1.添加账户\t\t\t2.显示账户"<<endl; 
	cout<<"----------------------------------------------"<<endl;
	cout<<"请选择操作:"; 
	int a;
	cin>>a;
	while(1!=a && 2!=a)
	{
		cout<<"输入操作选项错误，请重新输入操作：";
		cin.clear();
		cin>>a;
	}
	return a;
}

int main()
{
	//初始化
	LinkListHead *head=new LinkListHead;
	head->pListHead=NULL;
	head->s32CurrentLen=0;
	
	while(true)
	{
		int a=showMenu();
		switch(a)
		{
		case 1:
			{
				datatype message[5];
				cout<<"请依次输入账号，用户名，密码，电话号码，余额："<<endl;
				for(int i=0;i<5;i++)
				{
					cin>>message[i];
				}
				//添加数据
				push(head,message);
				cout<<"用户添加成功！"<<endl;
			};break;
		case 2:
		{
			//获取节点个数
			int num=getLength(head);
			cout<<"当前存在"<<num<<"个用户..."<<endl;
			if(num>0)
			{
				cout<<left<<setw(12)<<"账号"<<setw(12)<<"用户名"<<setw(12)<<"密码"<<setw(12)<<"电话号码"<<setw(12)<<"余额"<<endl;
				//获取数据
				for(int i=1;i<=head->s32CurrentLen;i++) 
				{
					datatype* str=get(head,i);
					//输出信息
					for(int i=0;i<5;i++)
					{
						cout<<left<<setw(12)<<str[i];
					}
					cout<<endl;
				}	
			}
		};break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
