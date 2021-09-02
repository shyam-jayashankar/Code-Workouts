#include<iostream>
#include<queue>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int val)
	{
		data=val;
		next=NULL;
	}
};

struct myqueue
{
	Node* front;
	Node* rear;
	int size;

	myqueue()
	{
		front=rear=NULL;
	}

	void enQueue(int val)
	{
		Node* temp=new Node(val);
		if(rear==NULL)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
	}

	int deQueue()
	{
		if(front==NULL)
			return -1;
		
		int val=front->data;
		Node*temp=front;
		front=front->next;
		
		if(front==NULL)
			rear=NULL;

		delete(temp);
		return val;
	}


};

int main()
{
	myqueue q; 
	q.enQueue(10); 
	q.enQueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.deQueue(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 

	return 0;
}