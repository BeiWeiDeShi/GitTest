#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20      /*定义最大顶点数*/
typedef int Vertex;

typedef struct ArcNode{       /*表结点*/
    int adjvex;               /*邻接点域*/
    ArcNode *next; /*指向下一个表结点*/
}ArcNode,EdgeNode;

typedef struct VertexNode{           /*头结点*/
    Vertex vertex;                   /*顶点域*/
    ArcNode *edgenext;               /*指向第一个表结点*/
}VertexNode,AdjList[MAX_VERTEX_NUM]; /*AdjList是数组类型*/

typedef struct { 
    AdjList adjlist;            /*邻接表中数组定义*/
    int vexnum,arcnum;          /*图中当前顶点数和边数*/
} AdjMatrix;                    /*图类型*/

typedef enum{FALSE,TRUE} Boolean;

Boolean visited[MAX_VERTEX_NUM]={FALSE};/*定义标志向量，为全局变量*/

void CreateALGraph(AdjMatrix* G){/* 创建图并且将Visited初始化为false;*/
    int i,j,k;
    EdgeNode *s;
    printf("Please enter the number of vertices and edges:\n");
    scanf("%d%d",&G->vexnum,&G->arcnum);
    printf("Create vertex table\n");

    for (i=0;i<G->vexnum;i++){
        //fflush(stdin);  
        //如果 stream 指向输入流（如 stdin），那么 fflush 函数的行为是不确定的。
        //故而使用 fflush(stdin) 是不正确的。
        getchar(); 
        printf("Please enter the information of the %d vertex:",i+1);
        G->adjlist[i].vertex=getchar();
        G->adjlist[i].edgenext=NULL;
    }

    //前插法
    printf("Create side table\n");
    for (k=0;k<G->arcnum;k++){
       printf("Enter the connected vertex number:");
       scanf("%d%d",&i,&j);
       //对于直接相连的进行编入(即对输入“0 1”时，在0对应的边表中编入1) 
       s=(EdgeNode*)malloc(sizeof(EdgeNode));
       s->adjvex=j;//边表赋值
       s->next=G->adjlist[i].edgenext;
       G->adjlist[i].edgenext=s;
       //对于间接相连的进行编入(即对输入“0 1”时，在1对应的边表中编入0)
       s=(EdgeNode*)malloc(sizeof(EdgeNode));
       s->adjvex=i;
       s->next=G->adjlist[j].edgenext;
       G->adjlist[j].edgenext=s;
    }

}

void DispGraph(AdjMatrix *G){
    int i;
    for (i=0;i<G->vexnum;i++){
        printf("%d->",i);
        while(1){
            if(G->adjlist[i].edgenext==NULL){
                printf("^");
                break;
            }
            printf("%d->",G->adjlist[i].edgenext->adjvex); 
            G->adjlist[i].edgenext=G->adjlist[i].edgenext->next;  
        }  
        printf("\n");
    }
}

void BFS(AdjMatrix *G,int v){
    int q[G->vexnum],front=0,rear=0;
    printf(" %d",v);
    visited[v]=TRUE;
    q[rear]=v;
    rear++;
    while (front != rear){
        int now = q[front];
        front++;
        ArcNode *p = G->adjlist[now].edgenext;
        while(p != NULL){
            if(visited[p->adjvex] == 0){
                printf(" %d",p->adjvex);
                visited[p->adjvex] = TRUE;
                q[rear] = p->adjvex;
                rear++;
            }
            p = p->next;
        }
    }
} 

void DFTGraphAdjList(AdjMatrix* graph,int vexIndex)
{
    //访问过不再访问
    if (visited[vexIndex] == TRUE)
        return;

    visited[vexIndex] = TRUE;
    printf("%d ",graph->adjlist[vexIndex].edgenext->adjvex);

    EdgeNode* node = graph->adjlist[vexIndex].edgenext;
    while (node)
    {
        DFTGraphAdjList(graph, node->adjvex);
        node = node->next;
    }
    return;
}
 
//深度优先遍历邻接表
void TraverseGraphAdjList(AdjMatrix* graph)
{
    int i;
    if (NULL == graph)
        return;

    for(i=0; i < graph->vexnum; i++)
        visited[i] = FALSE;

    for(i=0; i < graph->vexnum; i++){
        if(visited[i] == FALSE){
            DFTGraphAdjList(graph,i);
        }
    }

    return;
}


int main()
{
    AdjMatrix* G= (AdjMatrix*)malloc(sizeof(AdjMatrix));
    CreateALGraph(G);
    // DispGraph(G);
    printf("\n");

    // Vertex v;

    // scanf("%d", &v);
    // printf("BFS from %d:",v);
    // BFS(G,v);
    // printf("\n\n");

    printf("DFS: ");
    TraverseGraphAdjList(G);
    printf("\n");

    return 0;
}
