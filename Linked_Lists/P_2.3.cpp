#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
void deleteMiddle(Node* head)
{
	int temp = head->next->data;
	head->data = temp;
	head->next = head->next->next;
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
	Node * t = temp;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 6;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	/*******************************/

	Print(head);
	deleteMiddle(t);
	Print(head);
	return 0;
}