// The object of this code is to accept a singly linked list of alphabetic characters (lowercase only) and
//place the vowels at the front of the queue. The relative order of the vowels and the consonants must be
//maintained.

#include<iostream>

using namespace std;

struct node{
char ch;
node* next = NULL;
};

bool isVowel(char ch){
if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;
return false;
}

void removeHead(node* &head){
head = head->next;
}

void insertVowel(node* &new_l, char ch){
new_l->next = new node;
new_l->next->ch=ch;
new_l=new_l->next;
}

void reArrange(node* &head){

if(head==NULL)
    return ;

char ch;
ch=head->ch;
node* l_start, *l_rear;
l_start = l_rear = NULL;

while(isVowel(ch)){
    removeHead(head);
    if(l_start==NULL)
    {
        l_start = new node;
        l_start->ch = ch;
        l_rear=l_start;
    }
    else insertVowel(l_rear,ch);
    if(head==NULL){
    head = l_start;
    return;
    }

    ch=head->ch;
}

node* vow=head;
if(vow->next==NULL){
    l_rear->next = head;
    head = l_start;
    return;
}
while(vow->next!=NULL){
    ch=(vow->next)->ch;
    while(!isVowel(ch)){
        vow=vow->next;
        if(vow->next==NULL)
            return;
        ch=vow->next->ch;
    }
    insertVowel(l_rear,ch);
    node* temp = vow->next;
    vow->next = temp->next;


}
//merge the two
l_rear->next = head;
head = l_start;

}

main()
{
    int n;
    node* head = new node;
    cin>>n;
    char ch;
    cin>>ch;
    head->ch=ch;
    node* temp = head;
    for(int i=1;i<n;i++){
        head->next = new node;
        head=head->next;
        cin>>ch;
        head->ch=ch;
    }
    head= temp;
    while(head){
        cout<<head->ch<<"->";
        head=head->next;
    }
    cout<<"NULL\n\n";
    head = temp;
    reArrange(head);
    while(head){
        cout<<head->ch<<"->";
        head=head->next;
    }
    cout<<"NULL";

}
