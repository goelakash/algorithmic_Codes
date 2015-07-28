/*

Efficient Trie implementation
Author : Akash Goel
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
#define INF			 1000*1000*1000
/*
bool comp(const node& a, const node& b)
{

}
*/
struct trie_node
{
    int leaf=0;
    map <char,trie_node*> next;
};

void insert_trie(string word, int pos,trie_node* root)
{
    if(pos==word.size())
    {
        root->leaf=1;
        return;
    }

    if(root->next.find(word[pos])==(root->next.end()))
    {
        root->next[word[pos]] = new trie_node;
        insert_trie(word,pos+1,root->next[word[pos]]);
    }
    else
        insert_trie(word,pos+1,root->next[word[pos]]);
}

int search_trie(string word, int pos, trie_node* root)
{
    if(pos==word.size())
        if(root->leaf==1)
            return 1;
        else
            return 0;
//    cout<<"finding  ";
    if(root->next.find(word[pos])==root->next.end())
        return 0;
    else
        return search_trie(word,pos+1,root->next[word[pos]]);
}

int delete_trie(string word, int pos, trie_node* root)
{
    if(pos==word.size())
        if(root->leaf==1)
        {
        root->leaf=0;
        if(root->next.empty())
            return 1;
        else
            return -1;
        }
        else
            return 0;

    if(root->next.find(word[pos])==root->next.end())
        return 0;
    else
    {
        int val = delete_trie(word,pos+1,root->next[word[pos]]);
        if(val==1)
            if(root->leaf==0)
                root->next.erase(word[pos]);
            else
                val=-1;
        return val;
    }
}

ll mod = INF+7;
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter n (no if insertions, search and deletions: \n";
    int n;
    cin>>n;
    cout<<"\n"<<n<<" words to insert: \n";
    string word;
    trie_node* root = new trie_node;
    REP(i,n)
    {
        cin>>word;
        insert_trie(word,0,root);
    }
    cout<<"\n"<<n<<" words to search: \n";
    REP(i,n)
    {
        cin>>word;
        if(search_trie(word,0,root))
            cout<<"Found\n";
        else
            cout<<"Not found\n";
    }
    cout<<"\n"<<n<<" words to delete: \n";
    REP(i,n)
    {
        cin>>word;
        int val = delete_trie(word,0,root);
        if(val==1)
            cout<<"Deleted from till leaf\n";
        else if(val==-1)
            cout<<"Deleted and adjusted\n";
        else
            cout<<"Not found\n";
    }
    cout<<"\n"<<n<<" words to search: \n";
    REP(i,n)
    {
        cin>>word;
        if(search_trie(word,0,root))
            cout<<"Found\n";
        else
            cout<<"Not found\n";
    }

}
