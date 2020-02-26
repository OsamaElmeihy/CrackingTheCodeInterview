#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
void Partition(Node* head,int k)
{
	Node* n = NULL;
	int temp;
	while(head){
		n = head;
		if(head->data >=k){
			while(n->next && n->data >=k){
				n = n->next;
			}
			temp = n->data;
			n->data = head->data;
			head->data = temp;
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
	head->data =3;
	Node* temp =head;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 8;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 10;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 2;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 1;
	/*******************************/

	Print(head);
	Partition(head,5);
	Print(head);
	return 0;
}