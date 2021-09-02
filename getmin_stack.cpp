#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct mystack
{
	stack<int>main_st;
	stack<int>aux_st;

	void push(int ele)
	{
		if(main_st.empty())
		{
			main_st.push(ele);
			aux_st.push(ele);
		}

		else
		{
			main_st.push(ele);
			if(aux_st.top()>=ele)
				aux_st.push(ele);
		}
	}

	int pop()
	{
		if(main_st.empty())
		{
			cout<<"\n stack is empty";
			return -1;
		}

		if(main_st.top()==aux_st.top())
			aux_st.pop();

		int val=main_st.top();
		main_st.pop();

		return val; 
	}

	int get_min()
	{
		return aux_st.top();
	}


};

struct mystack
{
	stack<int>main_st;
	int min=0;

	void push(int ele)
	{
		if(main_st.empty())
		{
			main_st.push(ele);
			min=ele;
		}

		else if(ele<=min)
		{
			st.push(2*ele-min); //push a pesudo num of curr min
			min=ele;//store current min 
		}

		else
			st.push(ele);
	}


	int pop()
	{
		int t=st.top();
		st.pop();

		if(t<=min)
		{
			int res=min; //the actual number is stored as curr min , hence retrived
			min=2*min-t; //resetting min to prev min
			return res; //returning the element
		}

		else
			return t;
	}


	int top() 
	{
		int t=s.top();
		return ((t<=min)? min : t);
   	
	}
    
 
	int getMin()
	{
		return min;
	} 

      
   


};

int main()
{
	mystack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<" Minimum Element from Stack: " <<s.get_min();
  
    return 0;
}