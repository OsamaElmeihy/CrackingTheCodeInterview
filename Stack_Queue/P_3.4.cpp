#include <iostream>

using namespace std;

class Stack{
private:
	int it;
	int size;
	int* myStack;
	void CheckSpace()
	{
		if(it==size){
			size *=2;
			myStack = (int*)realloc(myStack,sizeof(int)*size);
		}

	}
public:
	Stack(int size = 10)
		:it(0)
	{
		this->size = size;
		myStack = new int[size];
	}
	void Push(int item)
	{
		CheckSpace();
		myStack[it++]=item;
	}
	int Peek()
	{
		if(isEmpty())
			return -1;
		return myStack[it-1];
	}
	void Pop()
	{
		if(!isEmpty()){
			it--;
		}
	}
	bool isEmpty()
	{
		if(it==0)
			return true;
		return false;
	}
};

class Queue{
private:
Stack* s1;
Stack* s2;

public:
	Queue(int size=10)
	{ 
		s1 = new Stack(size);
		s2 = new Stack(size);
	}
	void Push(int item)
	{
		s1->Push(item);
	}
	int Front()
	{
		int temp;
		while(!s1->isEmpty()){
			s2->Push(s1->Peek());
			s1->Pop();
		}
		temp = s2->Peek();
		while(!s2->isEmpty()){
			s1->Push(s2->Peek());
			s2->Pop();
		}
		return temp;
	}
	void Pop()
	{
		while(!s1->isEmpty()){
			s2->Push(s1->Peek());
			s1->Pop();
		}
		s2->Pop();
		while(!s2->isEmpty()){
			s1->Push(s2->Peek());
			s2->Pop();
		}
	}
	bool isEmpty()
	{
		return s1->isEmpty();
	}
};


int main(){
	Queue* q = new Queue();
	q->Push(10);
	q->Push(9);
	q->Push(8);
	q->Push(7);
	q->Push(7);
	q->Push(6);
	q->Push(5);
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	cout<<q->Front()<<endl;
	q->Pop();
	return 0;
}
