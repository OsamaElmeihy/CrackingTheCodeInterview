#include <bits/stdc++.h> 
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* Intersection(Node* h1,Node* h2)
{
	int h1Length=0,h2Length=0;
	Node * temp1 = h1;
	Node * temp2 = h2;
	while(temp1){
		h1Length++;
		temp1 =temp1->next;
	}
	while(temp2){
		h2Length++;
		temp2 =temp2->next;
	}
	if(h1Length>h2Length){
		while(h1Length-h2Length){
			h1 = h1->next;
			h1Length--;
		}
	}else if(h2Length>h1Length){
		while(h2Length-h1Length){
			h2 = h2->next;
			h2Length--;
		}
	}
	while(h1){
		if(h1==h2)
			return h1;
		h1 = h1->next;
		h2 = h2->next;
	}
	return NULL;
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

	Node* head = Intersection(h1,h2);
	if(head)
		cout<<head->data<<endl;
	else
		cout<<"No Intersection"<<endl;
	return 0;
}