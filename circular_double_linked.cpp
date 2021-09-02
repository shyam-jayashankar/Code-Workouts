#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;

	Node(int x)
	{
		data=x;
		next=NULL;
		prev=NULL;
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

Node* insert_beginning(Node* head, int element)
{
	Node* temp=new Node(element);
	if(head==NULL)
	{
		temp->prev=temp;
		temp->next==temp;
		return temp;
	}

	temp->prev=head->prev;
	(head->prev)->next=temp;
	head->prev=temp;
	temp->next=head;
	head=temp;
	return head;

}

