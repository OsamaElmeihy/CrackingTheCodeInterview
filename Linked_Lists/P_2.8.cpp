#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* LoopDetection(Node* head)
{
	unordered_set <Node*> ptrs;
	while(head->next){
		if(ptrs.find(head)==ptrs.end())
			ptrs.insert(head);
		else
			return head;
		head = head->next;
	}
	return NULL;
}

Node* hasCycle(Node *head) {
    Node* prev=NULL;
    Node* temp = new Node();
    temp->data = 5;
    while(head->next){
        prev = head;
        head=head->next;
        prev->next = temp;
        if(head==temp)
            return prev;
    }
    return NULL;
}
int main(){
	/***********for testing***********/
	Node* head = new Node();
	head->data =1;
	Node* temp =head;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 2;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 3;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 4;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 9;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 6;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	/*******************************/
	Node* h = hasCycle(head);
	if(head)
		cout<<h->data<<endl;
	else
		cout<<"No Loop"<<endl;
	return 0;
}