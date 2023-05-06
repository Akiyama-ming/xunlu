#include<stdio.h>
#include<stdlib.h>
#define N 50	//��󶥵���
#define Max 114514

typedef struct 
{
    int vexs[N];	//��������
    int arcs[N][N];		//�ڽӾ���
}MGraph;


int d[N][N],p[N][N];	//dΪ����Ȩֵ·���� pΪ·������ 

void CreateMGraph(MGraph *G,int n,int m)
{
    int i,j,k,w;
    for(i=0 ; i<n ; i++)	//���붥����Ϣ
        G->vexs[i]=i;
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<n ; j++)
        {
            if(i==j)
            {G->arcs[i][j]=0;} 
			else
			{G->arcs[i][j]=Max;}
		}	//��ʼ��һ���ڽӾ�������ֵΪ0������ֵΪmax 
    printf("���� %d ���ߵ���㣬�յ㼰����֮���Ȩֵ��\n",m);
    for(k=0 ; k<m ; k++)
    {
        scanf("%d %d %d",&i,&j,&w);		//����m���ߣ������ڽӾ���
        G->arcs[i][j]=w;
    }
    printf("Over! \n");
}

void Floyd(MGraph *G,  int n)
{
    int i, j, k;	//����ÿһ�Զ���֮���·������
    for(i=0 ; i<n ; j++)
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<n ; j++)
            {
                p[i][j]=j;	//��p�����ʼ�� 
                d[i][j]=G->arcs[i][j];    //��ͼ��Ȩֵ����д��·��Ȩֵ���� 
            }
	for(k=0 ; k<n ; k++)
    {	//��kΪ�м��㣬
        for(i=0 ; i<n ; i++)
        {
			for(j=0 ; j<n ; j++)
            {
                //�������i��k��k��j�ľ������iֱ�ӵ�j������i��j�ľ������辭��k������ת
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
    G=(MGraph *)malloc(sizeof(MGraph));     //��ʼ��ͼ
    printf("����ͼ�ж�������ͱߵĸ���n,e:");
    scanf("%d %d",&n,&m);
    if(m<n-1)
	{printf("��������ݲ�����\n");
	return 0;}
    CreateMGraph(G,n,m);    //��������ͼ�ṹ
    printf("----------------------\n");
    printf("���������������֮������·��\n");
    printf("-------------------\n");
    Floyd(G,n); 	//�������� 
    printf("������㣺");
    scanf("%d",&v);
    printf("�����յ㣺");
    scanf("%d",&w);
    k=p[v][w];     //kΪ��ת�Ķ��� 
    if(k==0)
    {
        printf("����%d �� %dû��·����\n",v,w);
        return 0;
    }
	else
    {
        printf("�Ӷ��� %d �� %d �����·���ǣ�%d ",v,w,v);
		while(k!=w)
        	{
        		printf("����> %d ",k);
       			k=p[k][w];
    		}
    printf("����%d",w);
    printf("·�����ȣ�%d\n",d[v][w]);
    }
    printf("��ѯ����\n");
    return 0;
}
