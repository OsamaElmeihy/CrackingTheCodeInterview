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
	virtual void Push(int item)
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

class SortedStack{
private:
	Stack* s1;
	Stack* s2;
public:
	SortedStack(int size = 10)
	{
		s1 = new Stack(size);
		s2 = new Stack(size);
	}
	void Push (int item)
	{
		if(s1->isEmpty() || s1->Peek()>=item)
			s1->Push(item);
		else{
			int temp = s1->Peek();
			while(temp<item){
				s2->Push(temp);
				s1->Pop();
				temp = s1->Peek();
			}
			s1->Push(item);
			while(!s2->isEmpty()){
				s1->Push(s2->Peek());
				s2->Pop();
			}
		}
	}
	int Peek()
	{
		return s1->Peek();
	}
};
int main(){
	
	SortedStack* s = new SortedStack(10);
	s->Push(10);
	cout<<s->Peek()<<endl;
	s->Push(4);
	cout<<s->Peek()<<endl;
	s->Push(3);
	cout<<s->Peek()<<endl;
	s->Push(5);
	cout<<s->Peek()<<endl;
	s->Push(1);
	cout<<s->Peek()<<endl;
	s->Push(2);
	cout<<s->Peek()<<endl;
	s->Push(6);
	cout<<s->Peek()<<endl;
	return 0;
}
