/*
max flow for DAGs
*/

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
#define FORIT(a,b)   for (__typeof((b).begin()) (a)=(b).begin(); (a)!=(b).end(); (a)++)
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)

#define RESET(a,b)   memset(a,b,sizeof(a))
#define SYNC         ios_base::sync_with_stdio(0);
#define SIZE(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define input(in)    freopen(in,"r",stdin)
#define output(out)  freopen(out,"w",stdout)
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define SIZE(a)      (int)(a.size())
#define LEN(a)       (int)(a.length())

#define FIN(x)       freopen(x,"r",stdin)
#define FOUT(x)      freopen(x,"w",stdout)
#define FCLOSE       {fclose(stdin); fclose(stdout);}

#define ull           unsigned long long
#define ll           long long
#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define pi           pair<int,int>

/*
bool comp(const node& a, const node& b)
{

}
*/

struct edge
{
int dest;
int w;
};

typedef vector< vector<edge> > Graph;
int v;
const int INF = 1000000000;
const int MAXV = 1000;
int level[MAXV],f[MAXV][MAXV];
int bfs(Graph g,int s,int t);
int dfs(Graph g,int s,int t,int flow);

int dinitz(Graph g, int s,int t)
{
    int flow=0,pushed;
    while(bfs(g,s,t))
    {
        pushed = dfs(g,s,t,INF);
        if(pushed)
        {
            flow+=pushed;
        }
    }
    return flow;
}

int bfs(Graph g,int s,int t)
{
    memset(level,-1,sizeof level);
    level[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto it=g[curr].begin();it!=g[curr].end();it++)
        {

            if( level[it->dest]==-1 && f[curr][it->dest]>0)
            {
                level[it->dest] = level[curr]+1;
                q.push(it->dest);
            }
        }
    }
    return (level[t]!=-1);
}

int dfs(Graph g,int s,int t,int flow)
{
    if(s==t)
        return flow;
    if(!flow)
        return 0;
    int res=0;
    for(auto it = g[s].begin();it!=g[s].end();it++)
    {
        if(f[s][it->dest])
        {
            int pushed = dfs(g,it->dest,t,min(flow,f[s][it->dest]));
            if(pushed)
            {
                res += pushed;
                f[s][it->dest] -= pushed;
                f[it->dest][s] += pushed;
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>v;
    Graph g(v+1);
    cout<<"Enter (u v w):\n";
    int a,b,w;
    cin>>a>>b>>w;

    while(a)
    {
        g[a].push_back(edge{b,w});
        f[a][b] = w;
//            cout<<i<<" "<<a<<" "<<f[i][a]<<endl;
        cin>>a>>b>>w;

    }
    int s=1,t=v;
    cout<<dinitz(g,s,t);
}

