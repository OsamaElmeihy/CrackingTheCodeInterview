#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* SumLists(Node* h1,Node* h2)
{
	int carry=0;
	Node* head= new Node();
	Node* h3 = head;
	while(h1 && h2){
		h3->data = (h1->data + h2->data + carry)%10;
		carry = (h1->data + h2->data + carry)/10;
		h1=h1->next;
		h2=h2->next;
		if(h1||h2){
			h3->next = new Node();
			h3=h3->next;
		}
	}
	while(h1){
		h3->data = (h1->data+ carry)%10;
		carry = (h1->data + carry)/10;
		h1=h1->next;
		if(h1){
			h3->next = new Node();
			h3=h3->next;
		}
	}
	while(h2){
		h3->data = (h2->data+ carry)%10;
		carry = (h2->data + carry)/10;
		h2=h2->next;
		if(h2){
			h3->next = new Node();
			h3=h3->next;
		}
	}
	if(carry){
		h3->next = new Node();
		h3=h3->next;
		h3->data = carry;
	}
	return head;
}
Node* SumLists2(Node* h1,Node* h2)
{
	Node* head= new Node();
	Node* h3 = head;
	int sum = 0;
	int tens = 1;
	while(h1 && h2){
		sum = (sum*10) + h1->data + h2->data;
		h1=h1->next;
		h2=h2->next;
		tens *=  10;
	}
	cout<<sum<<endl;
	cout<<tens<<endl;
	while(sum){
		if(sum<tens)
			tens /= 10;
		h3->data = sum /tens;
		sum = sum%tens;
		if(sum){
			h3->next = new Node();
			h3 = h3->next;
		}
	}
	return head;
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
	Node* h1 = new Node();
	h1->data =6;
	Node* temp =h1;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 1;
	temp->next = new Node();
	temp = temp->next;
	temp->data = 7;
	temp->next = NULL;

	Node* h2 = new Node();
	h2->data =5;
	Node* t2 =h2;
	t2->next = new Node();
	t2 = t2->next;
	t2->data = 9;
	t2->next = new Node();
	t2 = t2->next;
	t2->data = 5;
	t2->next = NULL;

	/*******************************/

	Node* head = SumLists2(h1,h2);
	Print(head);
	return 0;
}