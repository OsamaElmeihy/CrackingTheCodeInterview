#include <bits/stdc++.h> 

using namespace std;

class Queue{
private:
	queue<char> q1;
	queue<char> q2;
public:
	void enqueue(char item)
	{
		q1.push(item);
	}
	char dequeueAny ()
	{
		char temp = q1.front();
		q1.pop();
		return temp;
	}
	char dequeueCat()
	{
		char temp = q1.front();
		while(!q1.empty() && temp!='C'){
			q2.push(temp);
			q1.pop();
			if(!q1.empty())
				temp = q1.front();
		}
		if(!q1.empty())
			q1.pop();
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		if(temp!='C')
			return 'E';
		return temp;
	}
	char dequeueDog ()
	{
		char temp = q1.front();
		while(!q1.empty() && temp!='D'){
			q2.push(temp);
			q1.pop();
			if(!q1.empty())
				temp = q1.front();
		}
		if(!q1.empty())
			q1.pop();
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}
		if(temp!='D')
			return 'E';
		return temp;
	}
};
int main(){
	
	Queue Animals;
	Animals.enqueue('C');
	Animals.enqueue('C');
	Animals.enqueue('D');
	Animals.enqueue('D');
	Animals.enqueue('D');
	cout<<Animals.dequeueAny()<<endl;
	cout<<Animals.dequeueDog()<<endl;
	cout<<Animals.dequeueCat()<<endl;
	cout<<Animals.dequeueCat()<<endl;
	cout<<Animals.dequeueAny()<<endl;
	cout<<Animals.dequeueDog()<<endl;
	cout<<Animals.dequeueDog()<<endl;
	return 0;
}
