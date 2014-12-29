#include<cstdio>
#include<stack>

using namespace std;

struct node{
int value;
node* next;
};
//
//node* newNode(int x){
//
//node* ns = new node;
//ns->value=x;
//ns->next=NULL;
//return ns;
//}

void getList(node* &head,int n){
int x;
node* temp;
node* current;

while(n)
{
    temp = new node;
    scanf("%d",&x);
    temp->value = x;
    temp->next = NULL;

    if(head==NULL){
        head = temp;
        current = temp;
    }
    else
    {
        current->next = temp;
        current = current->next;
    }
    n--;
}

}

void printList(node* head)
{
    printf("\nList is: ");

    while(head!=NULL){
        printf("%d  ",head->value);
        head = head->next;
    }
}

void revList(node* head, int k)
{
    int i;
    stack <int> s;
    node* temp=head;
    while(temp!=NULL){
        node* beg;
        node* curr;
        beg = curr = temp;
        for(i=0;i<k&&curr!=NULL;i++,curr=curr->next){
            s.push(curr->value);
        }
        temp = curr;
        curr = beg;
        for(i=0;i<k&&curr!=NULL;i++,curr=curr->next){
            curr->value = s.top();
            s.pop();
        }
    }
}
main()
{

int n,k;
scanf("%d",&n);
node* head = NULL;
getList(head,n);

//printf("%d ",head->value);
printList(head);
printf("\n\nk: ");
scanf("%d",&k);

revList(head,k);
printList(head);
}
