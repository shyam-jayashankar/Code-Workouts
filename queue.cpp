#include<iostream>
#include<queue>

using namespace std;

struct myqueue
{
	int cap, size,front,rear;
	int *arr;

	myqueue(int val)
	{
		cap=val;
		size=0;
		front=0,rear=-1;
		arr=new int[cap];
	}

	void enqueue(int val)
	{
		if(isfull())
			return;
		rear=(rear+1)%cap;
		arr[rear]=val;
		
		size++;


	}

	int deque()
	{
		if(isempty())
			return -1;

		int val=arr[front];
		front=(front+1)%cap;
		size--;

		return val;


	}

	int get_front()
	{
		if(isempty())
			return -1;

		return arr[front];
	}

	int get_rear()
	{
		if(isempty())
			return -1;

		return arr[rear];
	}

	int get_size()
	{
		return size;
	}

	int isfull()
	{
		return (size==cap);
	}

	int isempty()
	{
		return (size==0);
	}


};



int main()
{
	myqueue s(5); 

	s.enqueue(10); 
	s.enqueue(20); 
	s.enqueue(30); 
	s.enqueue(40); 

	cout << s.deque() 
		<< " dequeued from queue\n"; 

	cout << "Front item is "
		<< s.get_front() << endl; 
	cout << "Rear item is "
		<< s.get_rear() << endl; 

	return 0; 
}