#include<stack>
#include<iostream>

using namespace std;

struct mystack
{
	int *arr;
	int top1,top2,cap;

	mystack (int capacity)
	{
		cap=capacity;
		arr=new int[cap];
		top1=-1;
		top2=cap;
	}

	void push1(int value)
	{
		if(top1<top2-1)
		{
			top1++;
			arr[top1]=value;
		}

		else
			cout<<"\n stack capacity full";	
	}

	void push2(int value)
	{
		if(top1<top2-1)
		{
			top2--;
			arr[top2]=value;
		}

		else
			cout<<"\n stack capacity full";	
	}

	int pop1()
	{
		if(top1==-1)
			cout<<"\n stack already empty";
		int result=arr[top1];
		top1--;
		return result;
	}

	int pop2()
	{
		if(top2==cap)
			cout<<"\n stack already empty";
		int result=arr[top2];
		top2++;
		return result;
	}

	int peek1()
	{
		if(top1==-1)
			cout<<"\n stack already empty";
		return arr[top1];
	}

	int peek2()
	{
		if(top2==cap)
			cout<<"\n stack already empty";
		
		return arr[top2];
	}

	int size1()
	{
		return (top1+1);
	}

	int size2()
	{
		return (cap-top2);
	}

	bool empty1()
	{
		return(top1==-1);
	}

	bool empty2()
	{
		return(top2==cap);
	}



};

int main()
{
	mystack ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2(); 
    return 0; 
}