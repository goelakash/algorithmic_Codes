#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include <stack>
#define MAXV 1000
using namespace std;

struct edgenode  {
int y; /* adjacency info */
int weight; /* edge weight, if any */
struct edgenode *next; /* next edge in list */
} ;

struct graph{
edgenode *edges[MAXV+1]; /* adjacency info */
int degree[MAXV+1]; /* outdegree of each vertex */
int nvertices; /* number of vertices in graph */
int nedges; /* number of edges in graph */
bool directed; /* is the graph directed? */
} ;

void initialize_graph(graph *g, bool directed)
{
int i; /* counter */
g -> nvertices = 0;
g -> nedges = 0;
g -> directed = directed;
for (i=1; i<=MAXV; i++) g->degree[i] = 0;
for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, bool directed)
{
edgenode *p; /* temporary pointer */
p = new edgenode; /* allocate edgenode storage */
p->weight = 0;
p->y = y;
p->next = g->edges[x];
g->edges[x] = p; /* insert at head of list */
g->degree[x] ++;
if (directed == false)
insert_edge(g,y,x,true);
else
g->nedges ++;
}

void read_graph(graph *g, bool directed)
{
int i; /* counter */
int m; /* number of edges */
int x, y; /* vertices in edge (x,y) */
initialize_graph(g, directed);
cout<<"\ngetting no of vertices and edges: \n";
scanf("%d %d",&(g->nvertices),&m);
cout<<"\ngetting pair of vertices: \n";
for (i=1; i<=m; i++) {
scanf("%d %d",&x,&y);
insert_edge(g,x,y,directed);
}
}

void print_graph(graph *g)
{
int i; /* counter */
edgenode *p; /* temporary pointer */
for (i=1; i<=g->nvertices; i++) {
printf("%d: ",i);
p = g->edges[i];
while (p != NULL) {
printf(" %d",p->y);
p = p->next;
}
printf("\n");
}
}


int index;
int stk_no;
int entry[MAXV+1], low[MAXV+1], in_stk[MAXV+1];
vector < vector<int> > stk;
stack <int> s;
void stronglyconnect(graph* g,int v);

void strong_comp(graph* g)
{
    cout<<"\n\n--------Now calc strng comp--------\n\n";
    stk.resize(g->nvertices+1);
    for(int i=0;i<=g->nvertices;i++)
        stk[i].resize(g->nvertices+1);
    index=1;
    stk_no=0;
    while(!s.empty()){
        s.pop();
    }
    cout<<"  stack emptied\n\n\n";
    int i;

    for(i=0;i<=g->nvertices;i++){
        entry[i] = -1;
        in_stk[i] = 0;
    }
        cout<<"  done initializing arrays\n\n\n";
    for(i=1;i<=g->nvertices;i++){

        if(entry[i]==-1){
            cout<<"\n\nchecking for vertex in loop\n\n"<<i;
            stronglyconnect(g,i);
            }
    }


}


void stronglyconnect(graph* g,int v){
cout<<"________________________________________";
cout<<"  inside stronglyconnect\n\n";
    entry[v]=index;
    low[v] = v;
    index++;
    s.push(v);
    in_stk[v]=1;
    edgenode* p = new edgenode;
    p = g->edges[v];
while(p){
    int y = p->y;
    cout<<" checking vertex "<<y;

        if(entry[y]==-1){
            stronglyconnect(g,y);
            low[v]=min(low[v],low[y]);
        }
        if(in_stk[y])
            low[v]=min(low[v],entry[y]);

        p = p->next;
        }

cout<<"\n\n concluded while\n";

if(low[v]==entry[v])
{
    cout<<"\nready to make scc stack\n";
    int x;
    do{
        x = s.top();
        s.pop();
        cout<<" \npushed  in scc "<<x;
        stk[stk_no].push_back(x);
    }while(x!=v );
    stk_no++;

}
cout<<"________________________________________";
}

void print_strong_comp(){
for(int i=0;i<stk_no;i++)
{
    printf("\n\nStrongly connected component no. %d: ",i+1);
    for(int j=0;j<stk[i].size();j++)
        printf("%d  ",stk[i][j]);
}
}

main()
{
printf("Directed graph? ");
bool directed;
char ch;
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
    directed = true;
else
    directed = false;
graph *g= new graph;
initialize_graph(g,directed);
read_graph(g,directed);
strong_comp(g);

print_strong_comp();
}
