/*
Bismillahir Rahmanir Rahim
Author: Md Nurul Amin
Information and Communication Engineering, NSTU
*/
#include <bits/stdc++.h>
using namespace std;

struct node {
    int roll;
    node *nextadd;
};

node *root, *tail;

///appending in O(1) time
void append(int val){
    if(root==NULL){
        root = new node();
        root->roll= val;
        root->nextadd= NULL;
        tail=root;
    }
    else{
        node *newnode= new node();
        newnode->roll=val;
        newnode->nextadd=NULL;
        tail->nextadd=newnode;
        tail=newnode;
    }
}


///appending in O(n) time
/*void append(int val){
    if(root==NULL){
        root = new node();
        root->roll=val;
        root->nextadd=NULL;
    }
    else{
        node *current_node=root;
        while(current_node->nextadd!=NULL){
            current_node=current_node->nextadd;
        }
        node *newnode = new node();
        newnode->roll = val;
        newnode->nextadd = NULL;
        current_node->nextadd= newnode;
    }
}
*/
void print(){
    node *current_node = root;
    while(current_node!=NULL){
        cout<<current_node->roll<<endl;
        current_node=current_node->nextadd;
    }
}

///print ith element

void printidx(int idx){
    node *current_node = root;
    int cnt=1;
    while(current_node!=NULL){
        if(cnt==idx)
        {
            cout<<current_node->roll<<endl;
            break;
        }
        current_node=current_node->nextadd;
        cnt++;
    }
}
/// delete element x from linked list.
void delete_node(int val){
    node *current_node = root;
    node *previous_node = NULL;
    while(current_node->roll!=val){
        previous_node=current_node;
        current_node = current_node->nextadd;
    }
    if(current_node==root){
        node *temp=root;
        root=root->nextadd;
        delete(temp);
    }
    else{
        previous_node->nextadd= current_node->nextadd;
        delete(current_node);
    }
}

///Add element in the middle in between x and y;
void add(int x, int y, int val){
    node *ager_node=root;
    node *porer_node=root;
    while(ager_node->roll!=x){
        ager_node=ager_node->nextadd;
    }
    while(porer_node->roll!=y){
        porer_node=porer_node->nextadd;
    }
    node *newnode = new node();
    newnode->roll=val;
    newnode->nextadd=porer_node;
    ager_node->nextadd=newnode;

}

void solve()
{

    append(5);
    append(6);
    append(7);
    append(9);

    print();

    cout<<endl;
    delete_node(6);
    print();

    cout<<endl;
    add(5,7,6);
    print();

}

int main()
{
    solve();
    return 0;
}

