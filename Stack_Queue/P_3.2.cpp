#include <iostream>

using namespace std;

class Stack{
private:
	int it;
	int itMin;
	int size;
	int* myStack;
	int* minStack;
	void CheckSpace()
	{
		if(it==size){
			size *=2;
			myStack = (int*)realloc(myStack,sizeof(int)*size);
		}

	}
public:
	Stack(int size = 10)
		:it(0),itMin(0)
	{
		this->size = size;
		myStack = new int[size];
		minStack = new int[size];
	}
	void Push(int item)
	{
		CheckSpace();
		if(isEmpty()||minStack[itMin-1]>=item)
			minStack[itMin++]=item;
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
			if(myStack[it-1]==minStack[itMin-1]){
				itMin--;
			}
			it--;
		}
	}
	bool isEmpty()
	{
		if(it==0)
			return true;
		return false;
	}
	int Min(){
		if(isEmpty())
			return -1;
		return minStack[itMin-1];
	}
};



int main(){
	Stack s(20);
	s.Push(5);
	cout<<s.Min()<<endl;
	s.Push(9);
	cout<<s.Min()<<endl;
	s.Push(2);
	cout<<s.Min()<<endl;
	s.Push(2);
	cout<<s.Min()<<endl;
	s.Push(4);
	cout<<s.Min()<<endl;
	s.Push(1);
	cout<<s.Min()<<endl;
	s.Pop();
	cout<<s.Min()<<endl;
	s.Push(10);
	cout<<s.Min()<<endl;
	s.Push(1);
	cout<<s.Min()<<endl;
	return 0;
}
