#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};

int kToLastElement(Node* head,int k)
{
	Node* runner = head;
	while(k--){
		runner = runner->next;
	}
	while(runner->next){
		head = head->next;
		runner = runner->next;
	}
	return head->data;
}

int kToLastElementRecursivly(Node* head,int k)
{
	if(head==NULL)
		return 0;
	int i=kToLastElementRecursivly(head->next,k);
	if(i==k)
		cout<<head->data<<endl;
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
	temp->data = 5;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 6;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	/*******************************/

	cout<<kToLastElement(head,3)<<endl;
	//kToLastElementRecursivly(head,0);
	return 0;
}