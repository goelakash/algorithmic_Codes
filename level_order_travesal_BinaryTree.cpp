#include<bits/stdc++.h>
#include<queue>

using namespace std;

struct node{
int value;
node* left;
node* right;
};

node* NewNode(int i){

node* nd = new node();
    nd->value = i;
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

queue <node*> q;
void printLevelOrder(node* root){
if(root == NULL)
    return;
node* temp_node = root;
while(temp_node!=NULL){
    printf("%d  ",temp_node->value);
    if(temp_node->left)
        q.push(temp_node->left);
    if(temp_node->right)
        q.push(temp_node->right);
        temp_node = q.front();
        q.pop();
}
}


main(){
node* root = NewNode(1);
root->left = NewNode(2);
root->right = NewNode(3);
(root->left)->left = NewNode(4);
(root->right)->right = NewNode(5);

printLevelOrder(root);
}
