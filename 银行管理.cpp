#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

#define SIZE 5

using namespace std;

//1.ʵ�ֵ�����ĳ��ò���

typedef string datatype;

typedef struct LinkNode{
    datatype account;
	datatype name;
	datatype password;
	datatype phonenumber;
	datatype money;
    struct LinkNode *pNext;
}LinkNode,*LinkNodePtr;//�ڵ�

//����ͷ���
typedef struct {
LinkNodePtr pListHead;
int s32CurrentLen;
}LinkListHead;//ͷ�ڵ�


//׷��
//��pList�Ľ�����ǰ���һ��Ԫ�ص���һ��λ�ô��element������element����ʵ����
int push(LinkListHead *pList,datatype message[])
{
	//β�巨
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

//����
//��pList��s32Position������element����s32Position���ڵ�ǰ���һ��Ԫ���������򱾺�������ͬpush,����element����ʵ����
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


//ɾ��
//ɾ��s32Positionλ�õ�Ԫ�أ����ر�ɾ��λ�õ����������s32Position��Ԫ�ط���-1�����������3��Ԫ�أ�s32Position��5ʱ��������ɾ��ʱҪ�ͷŸýڵ�
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


//��ȡԪ��
//����pList��s32Position����Ԫ�أ�������ʱ����NULL�����������3��Ԫ�أ�s32Position��5ʱ��
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

//Ԫ�ظ���
//����pListԪ�ظ���
int  getLength(LinkListHead *pList)
{
    return pList->s32CurrentLen;
}

int showMenu()
{
	cout<<"                 ���й���ϵͳ                 "<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"  1.����˻�\t\t\t2.��ʾ�˻�"<<endl; 
	cout<<"----------------------------------------------"<<endl;
	cout<<"��ѡ�����:"; 
	int a;
	cin>>a;
	while(1!=a && 2!=a)
	{
		cout<<"�������ѡ��������������������";
		cin.clear();
		cin>>a;
	}
	return a;
}

int main()
{
	//��ʼ��
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
				cout<<"�����������˺ţ��û��������룬�绰���룬��"<<endl;
				for(int i=0;i<5;i++)
				{
					cin>>message[i];
				}
				//�������
				push(head,message);
				cout<<"�û���ӳɹ���"<<endl;
			};break;
		case 2:
		{
			//��ȡ�ڵ����
			int num=getLength(head);
			cout<<"��ǰ����"<<num<<"���û�..."<<endl;
			if(num>0)
			{
				cout<<left<<setw(12)<<"�˺�"<<setw(12)<<"�û���"<<setw(12)<<"����"<<setw(12)<<"�绰����"<<setw(12)<<"���"<<endl;
				//��ȡ����
				for(int i=1;i<=head->s32CurrentLen;i++) 
				{
					datatype* str=get(head,i);
					//�����Ϣ
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
