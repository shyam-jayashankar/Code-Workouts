#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int x)
	{
		data=x;
		next=NULL;
	}
};

void print_list(Node* head)
{
	if(head==NULL)
		return;
	Node* temp=head;

	do
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head);

	cout<<endl;

}

Node* insert_at_beginning(Node* head, int element)
{
	Node *temp=new Node(element);
	if(head==NULL)
	{
		temp->next=temp;
		head=temp;
		return head;
	}
	
	temp->next=head;
	Node *curr=head;
	while(curr->next!=head)
		curr=curr->next;
	curr->next=temp;
	head=temp;
	return head;
}

Node* insert_at_end(Node* head, int element)
{
	Node *temp=new Node(element);
	if(head==NULL)
	{
		temp->next=temp;
		return temp;
	}
	else
	{
		temp->next=head->next;
		head->next=temp;
		int t=head->data;
		head->data=temp->data;
		temp->data=t;
		return temp;
	}
}

Node* delete_head(Node* head)
{
	if(head==NULL)
		return NULL;
	if(head->next==head)
	{
		delete(head);
		return NULL;
	}
	else
	{
		temp=head->next;
		head->data=temp->data;
		head->next=temp->next;
		delete(temp);
		return head;
	}
}

Node* delete_k(Node* head, int position)
{
	if(head==NULL)
		return NULL;
	if(position==1)
		delete_head(head);
	Node* curr=head;
	for(int i=0;i<position-2;i++)
		curr=curr->next;
	Node* temp=curr->next;
	curr->next=temp->next;
	delete(temp);
	return head;

}

int main()
{
	Node* head=new Node(20);
	head->next=new Node(30);
	head->next->next=new Node(45);
	(head->next->next)->next=head;
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