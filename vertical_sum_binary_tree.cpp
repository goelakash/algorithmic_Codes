#include<cstdio>
#include<map>
using namespace std;

struct node{
int value;
node* left;
node* right;
};

node* newNode(int x){
node* ns = new node();
ns->value = x;
ns->left=ns->right=NULL;
return ns;
}

void printMap(map <int,int>* m){
for(auto& x : *m)
    printf("%d : %d\n",x.first,x.second);
}

void VertSumUtil(node* root, int hd, map <int,int>* m){

if(root==NULL)
    return;

VertSumUtil(root->left,hd-1,m);
try{
    (*m).at(hd)+=root->value;
}
catch(exception out_of_range )
{
    using std::map;
    (*m).insert(pair<int,int>(hd,root->value));
}
VertSumUtil(root->right,hd+1,m);

}

void getVertSum(node* root){
if(root==NULL)
    return;
map <int,int> m;
VertSumUtil(root,0,&m);


    printMap(&m);
}


main()
{
node* root = newNode(5);
root->left=newNode(3);
root->right=newNode(2);
root->left->left = newNode(4);
root->left->right=newNode(2);
root->right->left = newNode(1);
root->right->right = newNode(7);
getVertSum(root);
}
