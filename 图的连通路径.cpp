#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <algorithm>

#define MAX_VERTEX_NUM 100
#define ACCURACY 10e6

typedef struct ArcNode {
	int adjvex;
	struct ArcNode *next;
} ArcNode;

typedef struct Point {
	int x;
	int y;
} Point;

typedef struct VNode {
	Point p;
	ArcNode* firstarc;
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum,adjnum;
} ALGraph;

typedef struct Distance {
	int index;
	double distance;
	Point p;
} Distance;

bool initGraph(ALGraph &gra) {
	int num;
	Point p;
	scanf("%d",&num);
	gra.vexnum=num;
	if(num==2) {
		gra.adjnum=1;
	} else if(num>2 && num<=MAX_VERTEX_NUM) {
		gra.adjnum=2*num;
	} else {
		return false;
	}
	for(int i=0; i<num; i++) {
		scanf("%d%d",&p.x,&p.y);
		gra.vertices[i].p=p;
		gra.vertices[i].firstarc=NULL;
	}
	return true;
}

bool cmp(Distance d1, Distance d2) {
	if(d1.distance!=d2.distance) {
		return d1.distance<d2.distance;
	} else if(d1.p.x!=d2.p.x) {
		return d1.p.x<d2.p.x;
	} else {
		return d1.p.y<d2.p.y;
	}
}

void createGraph(ALGraph &gra) {
	double len;
	Distance dis[gra.vexnum-1];
	int degree;
	if(gra.vexnum>2)
		degree=2;
	else
		degree=1;

	for(int i=0; i<gra.vexnum; i++) {
		int k=0;
		for(int j=0; j<gra.vexnum; j++) {
			if(j==i)
				continue;
			len=sqrt(pow(abs(gra.vertices[i].p.x-gra.vertices[j].p.x),2)+pow(abs(gra.vertices[i].p.y-gra.vertices[j].p.y),2));
			len=int(len*ACCURACY)/ACCURACY;
			dis[k].distance=len;
			dis[k].index=j;
			dis[k].p=gra.vertices[j].p;
			k++;
		}
		//  Distance按关键字排序
		std::sort(dis, dis+gra.vexnum-1,cmp);
		//	for(int j=0;j<gra.vexnum-1;j++)
		//	printf("%d,%lf,%d,%d\n",dis[j].index,dis[j].distance,dis[j].p.x,dis[j].p.y);
		for(int j=0; j<degree; j++) {
			ArcNode *arc;
			arc=(ArcNode *)malloc(sizeof(ArcNode));
			arc->adjvex=dis[j].index;
			arc->next=NULL;
			if(!gra.vertices[i].firstarc) {
				gra.vertices[i].firstarc=arc;
			} else {
				gra.vertices[i].firstarc->next=arc;
			}
		}
	}
}

void getResult(bool tag) {
	if(tag) {
		printf("All stations are reachable.\n");
	} else {
		printf("There are stations that are unreachable.\n");
	}
}

bool DFS(const ALGraph &gra, int k ,int *visited) {
	ArcNode *ptr;
	visited[k]=1;
	ptr=gra.vertices[k].firstarc;
	while(ptr) {
		if(visited[ptr->adjvex]==0)
			DFS(gra, ptr->adjvex,visited);
		ptr=ptr->next;
	}
	for(int i=0; i<gra.vexnum; i++) {
		if(visited[i]==0)
			return false;
	}
	return true;
}

int main() {
	ALGraph graph;
	bool tag,flag;
	while(1) {
		flag=initGraph(graph);
		if(graph.vexnum!=0 && flag) {
			int visited[MAX_VERTEX_NUM]={0};
			createGraph(graph);
			tag=DFS(graph,0,visited);
			//深度优先搜索 ，返回是否包含所有节点
			getResult(tag);
		} else {
			break;
		}
	}

	getch();
	return 0;
}

/*********
4
1 0 0 1 -1 0 0 -1
8
1 0 1 1 0 1 -1 1 -1 0 -1 -1 0 -1 1 -1
6
0 3 0 4 1 3 -1 3 -1 -4 -2 -5
*********/
