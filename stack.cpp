#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct mystack
{
	int* arr;
	int cap;
	int top;

	mystack(int c)
	{
		cap=c;
		top=-1;
		arr=new int[cap];
	}

	void push(int val)
	{
		if(top==cap-1)
		{
			cout<<"\n stack full";
			return;
		}
		top++;
		arr[top]=val;
	}

	int pop()
	{
		if(top==-1)
		{
			cout<<"\n stack empty";
			return -1;
		}
		int result=arr[top];
		top--;
		return result;

	}

	int peek()
	{
		if(top==-1)
		{
			cout<<"\n stack empty";
			return -1;
		}

		return arr[top];
	}

	int size()
	{
		return(top+1);
	}

	bool is_empty()
	{
		return(top==-1);
	}



};


struct mystack_vector
{
	vector<int>v;


	void push(int val)
	{
		v.push_back(val);
	}

	int pop()
	{
		if(v.empty())
			return -1;
		int result=v.back();
		v.pop_back();
		return result;

	}

	int peek()
	{
		if(v.empty())
			return -1;
		return v.back();
	}

	int size()
	{
		return v.size();
	}

	bool is_empty()
	{
		return v.empty();
	}



};

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

struct mystack_linked_list
{
	Node* head;
	int sz;

	mystack_linked_list()
	{
		head=NULL;
		sz=0;
	}

	void push(int val)
	{
		Node* temp=new Node(val);
		
		temp->next=head;
		head=temp;
		sz++;
	}

	int pop()
	{
		if(head==NULL)
			return -1;

		int result=head->data;
		Node* temp=head;
		head=head->next;
		delete(temp);
		sz--;
		return result;

	}

	int peek()
	{
		if(head==NULL)
			return -1;
		return head->data;
	}

	int size()
	{
		return sz;
	}

	bool is_empty()
	{
		return (head==NULL);
	}



};

void stack_stl()
{
	stack<int>st;
	st.push(2);
	st.push(3);
	cout<<"\n"<<st.top();
	st.push(4);
	int res=st.top();
	st.pop();
	cout<<"\n"<<res;
	cout<<"\n size: "<<st.size();
	if(st.empty())
		cout<<"\n stack empty";
	else
		cout<<"\n stack isnt empty";
	return;
}
int main()
{
	cout<<"\n Array as stack \n";
	mystack s(5);
	s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.is_empty()<<endl;

	cout<<"\n VECTOR as stack \n";
    mystack_vector s1;
	s1.push(65);
    s1.push(110);
    s1.push(240);
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.peek()<<endl;
    cout<<s1.is_empty()<<endl;

	cout<<"\n Linked LIST as stack \n";
    mystack_linked_list s2;
	s2.push(135);
    s2.push(430);
    s2.push(640);
    cout<<s2.pop()<<endl;
    cout<<s2.size()<<endl;
    cout<<s2.peek()<<endl;
    cout<<s2.is_empty()<<endl;
  
  	cout<<"\n Stack-stl\n";
  	stack_stl();
    return 0; 
}