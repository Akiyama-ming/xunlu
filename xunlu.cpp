#include<stdio.h>
#include<stdlib.h>
#define N 50	//最大顶点数
#define Max 114514

typedef struct 
{
    int vexs[N];	//顶点数组
    int arcs[N][N];		//邻接矩阵
}MGraph;


int d[N][N],p[N][N];	//d为顶点权值路径阵 p为路径矩阵 

void CreateMGraph(MGraph *G,int n,int m)
{
    int i,j,k,w;
    for(i=0 ; i<n ; i++)	//存入顶点信息
        G->vexs[i]=i;
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++)
        {
            if(i==j)
            {G->arcs[i][j]=0;} 
			else
			{G->arcs[i][j]=Max;}
		}	//初始化一个邻接矩阵，自身值为0，其他值为max 
    printf("输入 %d 条边的起点，终点及他们之间的权值：\n",m);
    for(k=0 ; k<m ; k++)
    {
        scanf("%d %d %d",&i,&j,&w);		//存入m条边，建立邻接矩阵
        G->arcs[i][j]=w;
    }
    printf("Over! \n");
}

void Floyd(MGraph *G,  int n)
{
    int i, j, k;	//储存每一对顶点之间的路径距离
    for(i=0 ; i<n ; j++)
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
            {
                p[i][j]=j;	//将p矩阵初始化 
                d[i][j]=G->arcs[i][j];    //将图的权值数据写入路径权值矩阵 
            }
	for(k=0 ; k<n ; k++)
    {	//令k为中间结点，
        for(i=0 ; i<n ; i++)
        {
			for(j=0 ; j<n ; j++)
            {
                //如果顶点i到k，k到j的距离大于i直接到j距离则i到j的距离则需经过k顶点中转
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[i][k];
                }
            }
        }
    }
}

int main()
{
    MGraph *G;
    int n,m,v,w,k;
    G=(MGraph *)malloc(sizeof(MGraph));     //初始化图
    printf("输入图中顶点个数和边的个数n,e:");
    scanf("%d %d",&n,&m);
    if(m<n-1)
	{printf("输入的数据不合理\n");
	return 0;}
    CreateMGraph(G,n,m);    //建立有向图结构
    printf("----------------------\n");
    printf("求任意的两个城市之间的最短路径\n");
    printf("-------------------\n");
    Floyd(G,n); 	//弗洛伊德 
    printf("输入起点：");
    scanf("%d",&v);
    printf("输入终点：");
    scanf("%d",&w);
    k=p[v][w];     //k为中转的顶点 
    if(k==0)
    {
        printf("顶点%d 到 %d没有路径！\n",v,w);
        return 0;
    }
	else
    {
        printf("从顶点 %d 到 %d 的最短路径是：%d ",v,w,v);
		while(k!=w)
        	{
        		printf("——> %d ",k);
       			k=p[k][w];
    		}
    printf("——%d",w);
    printf("路径长度：%d\n",d[v][w]);
    }
    printf("查询结束\n");
    return 0;
}
