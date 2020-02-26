#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
void RemoveDuplicatesWithBuffer(Node* head)
{
	Node* prev=NULL;
	unordered_set<int> d;
	while(head){
		if(d.find(head->data)==d.end()){
			d.insert(head->data);
			prev=head;
		}else{
			prev->next = head->next;
		}
		head=head->next;
	}
}
void RemoveDuplicatesNoBuffer(Node* head)
{
	Node* temp = NULL;
	while(head){
		temp=head;
		while(temp->next){
			if(head->data==temp->next->data){
				temp->next = temp->next->next;
			}else
				temp=temp->next;
		}
		head=head->next;
	}

}
void Print(Node* head)
{
	while(head){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main(){
	/***********for testing***********/
	Node* head = new Node();
	head->data =5;
	Node* temp =head;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 6;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 6;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	/*******************************/
	Print(head);
	RemoveDuplicatesNoBuffer(head);
	Print(head);
	return 0;
}