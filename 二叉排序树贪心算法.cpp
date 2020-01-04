#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

typedef struct Node
{
    int data;
    Node *lchild,*rchild;
}Node,*Root;

typedef struct BiSearchTree
{
    int num,height;
    Root root;
}BiSearchTree;

Root assignNode()
{
    Root p;
    p=(Root)malloc(sizeof(Node));
    return p;
}

int getMax(int a,int b)
{
    return a>b?a:b;
}

bool checkTree(int h, int n)
{
	if(n<=pow(2,h)-1 && n>=h)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

bool insertNode(Root &root, int h,int m, int n)
{
    if(h>0)
    {
        root=assignNode();
        root->data=getMax(m,n-(pow(2,h-1)-1));
            
        root->lchild=root->rchild=NULL;
        if(root->data==m)
        {
            root->lchild=NULL;
        }
        else
        {
            insertNode(root->lchild, h-1, m, (root->data)-1);
        }
        insertNode(root->rchild, h-1, (root->data)+1, n);
    }
    return true;
}

void Traverse(Root root)
{
    if(root)
    {
        printf("%d ",root->data);
        Traverse(root->lchild);
        Traverse(root->rchild);
    }
}

bool initBiTree(BiSearchTree &tree)
{
    scanf("%d%d",&tree.num, &tree.height);
    tree.root=NULL;
    if(tree.num==0 && tree.height==0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

int main()
{
    BiSearchTree tree;
    bool tag,flag=true;
    int count=1;
 
    while(flag)
    {
    	flag=initBiTree(tree);
    	if(!flag)
    		break;
    	else
    	{
    		tag=checkTree(tree.height, tree.num);
        	if(tag)
        	{
        		insertNode(tree.root, tree.height, 1, tree.num);
            	printf("case %d:",count++);
            	Traverse(tree.root);
        	}
        	else
        	{
            	printf("case %d:impossible.",count++);
        	}
       		printf("\n");
		}
    }

    getch();
    return 0;
}
