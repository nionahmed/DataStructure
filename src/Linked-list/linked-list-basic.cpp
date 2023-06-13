/*
Bismillahir Rahmanir Rahim
Author: Md Nurul Amin
Information and Communication Engineering, NSTU
*/


#include <bits/stdc++.h>
using namespace std;

struct node{
    int roll;
    node *next;
};
node *root=NULL;
void append(int roll){
    if(root==NULL){ /// if the list is empty.
        root = new node();
        root->roll=roll;
        root->next=NULL;
    }
    else{
        node *curr_node=root;
        while(curr_node->next!=NULL){ /// find the last node
            curr_node=curr_node->next;
        }
        node *newnode=new node(); /// create a node
        newnode->roll=roll;
        newnode->next=NULL;
        curr_node->next=newnode; /// link the last node with new node
    }
}

void print(){
    node *curr_node=root;
    while(curr_node!=NULL){
        cout<<curr_node->roll<<endl;
        curr_node=curr_node->next;
    }
}

int main(){

    append(1);
	append(2);
	append(6);
	print();
    return 0;

}
