#include<iostream>
#include<bits/stdc++.h>


using namespace std;


//initializing a structure for a node

struct Node
{
	int data; //to hold the value
	Node* next; //to hold forward pointer
	Node* prev; //to hold the reverse pointers

	Node(int x) //calling constructor to fit in the data
	{
		data=x;
		next=NULL; 
		prev=NULL;
	}


};

void print_list(Node* head) //function to print the linked list
{
	Node* curr=head;
	while(curr!=NULL)
	{
		cout<< " "<<curr->data;
		curr=curr->next;
	}
	cout<<endl;
}

Node* insert_at_beginning(Node* head, int value)
{
	Node* temp=new Node(value);

	if(head==NULL)
	{
		head=temp;
		
	}
	else
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;

	}
	return head;

}

Node* insert_at_end(Node* head, int value)
{
	Node* temp=new Node(value);
	if(head==NULL)
		head=temp;
	
	else
	{
		Node* curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		temp->prev=curr;

	}
	return head;

}

Node* reverse_list(Node* head)
{
	if(head==NULL||head->next==NULL)
		return head;
	Node* curr=head;
	Node* last=NULL;

	while(curr!=NULL)
	{
		last=curr->prev;
		curr->prev=curr->next;
		curr->next=last;
		curr=curr->prev;

	}
	
	head=last->prev;
	return head;

}

Node* delete_beginning(Node* head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete(head);
		return NULL;
	}
	
	Node* temp=head->next;
	temp->prev=NULL;
	delete(head);
	head=temp;

	return head;


}

Node* delete_end(Node* head)
{
	if(head==NULL)
		return NULL;
	if(head->next==NULL)
	{
		delete(head);
		return NULL;
	}
	
	Node* curr=head;

	while(curr->next!=NULL)
		curr=curr->next;

	(curr->prev)->next=NULL;
	delete(curr);
	return head;

}

int main()
{

//initializing the node values

	Node* head=new Node(10);
	Node* temp=new Node(20);
	Node* temp2=new Node(5);

//fixing the pointers

	head->next=temp;
	temp->prev=head;
	temp->next=temp2;
	temp2->prev=temp;

//calling the print function
	print_list(head);

//calling insert at start and end functions

	head=insert_at_beginning(head,45);
	head=insert_at_end(head,80);
	print_list(head);

//calling delete at start and end functions
	head=delete_beginning(head);
	head=delete_end(head);
	print_list(head);


	return 0;

}

