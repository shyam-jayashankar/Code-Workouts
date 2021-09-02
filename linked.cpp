#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
    Node *next;
    
    Node(int x)
    {
    	data=x;
        next=NULL;
    }
};

void print_list(Node* head)
{
	Node *temp=head;
	while(temp!=NULL)
    {
    	cout<<" "<<temp->data;
        temp=temp->next;
    }
}

struct Node* insert_at_beginning(Node* head, int element)
{
	if(head==NULL)
    	head= new Node(element);
    else
    {
		Node *temp= new Node(element);
    	temp->next=head;
    	head=temp;
    }
    return head;
}

Node* insert_at_end(Node*head,int element)
{
	if(head==NULL)
    	head= new Node(element);
    else
    {
    	Node *curr=head;
        while(curr->next!=NULL)
        	curr=curr->next;
        curr->next=new Node(element);
    }
    return head;
}

Node* delete_at_beginning(Node* head)
{
	if(head==NULL)
    	return NULL;
    
    
    Node* temp=head->next;
    delete(head);
    head=temp;
    return head;
}

Node* delete_at_end(Node* head)
{
	if(head==NULL)
    	return NULL;
        
    if(head->next==NULL)
    {
    	delete(head);
        return NULL;
    }
    
   	Node* temp=head;
    while(temp->next->next==NULL)
    	temp=temp->next;
    delete(temp->next);
    temp->next=NULL;
    return head;
}
    
Node* insert_at_position(Node* head, int position, int element)
{
	Node* temp=new Node(element);
    if (position==1)
    {
    	temp->next=head;
        return temp;
    }
    
    Node *curr=head;
    
    for(int i=1;i<position-2&&curr!=NULL;i++)
    	curr=curr->next;
    
    if(curr==NULL)
    	return head;
        
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
 
int search_element_iterative(Node* head, int element)
{
	Node* temp=head;
    int pos=1;
    while(temp!=NULL)
    {
    	if(temp->data==element)
        	return pos;
    	
        pos+=1;
        temp=temp->next;
    }
    
    return -1;
}

int search_element_recursive(Node* curr, int element)
{
	if(curr==NULL)
    	return -1;
    if(curr->data==element)
    	return 1;
    int result=search_element_recursive(curr->next,element);
    
    if(result==-1)
    	return -1;
    else
    	return result+1;
}

int main()
{
	Node *head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    head=insert_at_beginning(head,40);
    head=insert_at_end(head,50);
    head=insert_at_position(head,2,60);
    print_list(head);
    
    int location=search_element_iterative(head,60);
    if(location==-1)
    	cout<<"\n element not found";
    else
    	cout<<"\n element found at position : "<<location;
    
    location=search_element_recursive(head,30);
    
    if(location==-1)
    	cout<<"\n element not found";
    else
    	cout<<"\n element found at position : "<<location;
    
    return 0;
}