/*Author : Md Nurul Amin
ICE, NSTU*/
#include<bits/stdc++.h>
using namespace std;

///sum of a list of integer using linkedlist

struct node{
    int val;
    node *next;
};
node *root, *tail;

void append(int e){
    if(root==NULL){
        root= new node();
        root->val=e;
        root->next=NULL;
        tail=root;
    }
    else{
        node *newnode= new node();
        newnode->val=e;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}

int sum(){
    int ans=0;
    node *currentNode=root;
    while(currentNode->next!=NULL){
        ans+=currentNode->val;
        currentNode= currentNode->next;
    }
    ans+=currentNode->val;
    return ans;
}

int main(){
    int n; cin>>n;
    while(n--){
        int val; cin>>val;
        append(val);
    }
    int ans=sum();
    cout<<ans<<endl;

    return 0;
}

