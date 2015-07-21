/*
Hopcroft Karp Algorithm for maximal bipartite matching in a graph with boolean edges
Input : Set of edges from set 1 to 2 (weight is 1)
        u v  ->    u is set 1 and v is set 2

Output : Maximal no. of matchings
*/

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

const int MAXV = 1001;
int vert;
vector <int> level,matched;
typedef vector <map <int,int> > Graph;
Graph f;

bool dfs(int u);

int bipartite()
{
    fill(matched.begin(),matched.end(),0);
    int match=0;
    REP(i,vert)
    {
        int u=i+1;
        if(level[u]==1&&!matched[u]&&dfs(u))
            {
                cout<<u<<endl;
                match++;
            }
    }
    return match;
}

bool dfs(int u)
{
    if(level[u]==2&&!matched[u])
            return matched[u]=1;
    else
    {
        for(auto it = f[u].begin();it!=f[u].end();it++)
        {
            if(f[u][it->first]&&dfs(it->first))
            {
                f[u][it->first] = 0;
                f[it->first][u] = 1;
                matched[u]=1;
                return 1;
            }
        }
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>vert;
    f.resize(vert+1);
    level.resize(vert+1);
    matched.resize(vert+1);
    int a,b;
    cin>>a>>b;
    while(a)
    {
        level[a]=1;
        level[b]=2;
        f[a][b]=1;
        f[b][a]=0;
        cin>>a>>b;
    }
    cout<<bipartite();
}

