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

Node* insert_sorted(Node* head, int element)
{
    Node* temp=new Node(element);
    if(head==NULL)
        return temp;
    //if given element is smaller than head, it must be the first node
    if(element<head->data)
    {
        temp->next=head;
        return temp;
    }

    Node* prev=NULL;
    Node* curr=head;
//while the list is non empty and every element is smaller than the given element, keep traversing.
    while(curr!=NULL && curr->data<element)
    {
        prev=curr;
        curr=curr->next;
    }
// if curr==NULL, all elements in the list are smaller than the input element, 
//so input element must be the last node
    if(curr==NULL)
    {
        prev->next=temp;
        return head;
    }
//else input element must fall between prev and curr
    else
    {
        prev->next=temp;
        temp->next=curr;
        return head;
    }
}

Node* find_middle(Node* head)
{
    if(head==NULL)
        return NULL;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

}

Node* find_nth(Node* head,int n)
{
    if(head==NULL)
        return NULL;
    Node* slow=head;
    Node* fast=head;
    for(int i=1;i<n;i++)
        fast=fast->next;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;

}

Node* reverse_list(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* prev=head;
    Node* curr=head->next;
    Node* temp=NULL;

    prev->next=NULL; //since upon reversal this would be the last node

    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }

    head=prev;
    return head;
}

Node* recursive_reverse_list(Node* curr, Node* prev)
{
    if(curr==NULL)
        return prev;

    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;

    return recursive_reverse_list(curr,prev);

}

Node* remove_duplicates(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* prev=head;
    Node* curr=head->next;

    while(curr!=NULL)
    {
        if(curr->data==prev->data)
        {
            Node *temp=curr->next;
            prev->next=temp;
            delete(curr);
            curr=temp;
        }
        
        else
        {
            prev=curr;
            curr=curr->next;
        }

    }

    return head;
}

Node* reverse_group_k(Node* head, int k)
{
    
    Node* previous_first=NULL;
    
    Node* curr=head;
    
    bool first_shift=true;

    while(curr!=NULL)
    {
        Node* first=curr; 
        Node* prev=NULL;

        int i=0;

        while(curr!=NULL && i<k)        
        {
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            i++;
        }

        if(first_shift)
        {
            head=prev;
            first_shift=false;
        }

        else
        {
            previous_first->next=prev;
        }

        previous_first=first;

    }
    

    return head;


}

Node* recursive_reverse_k(Node* head, int k)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* temp=NULL;
    int i=0;
    while(i<k && curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        i++;
    }
    if(temp!=NULL)
    {
        Node* rest_head=recursive_reverse_k(temp,k);
        head->next=rest_head;
    }
    return prev;
    
}

Node* detect_and_remove_loop(Node* head)
{
    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next)
    {
        if(slow==fast)
            break;
        slow=slow->next;
        fast=fast->next->next;
    }

    if(slow==fast)
        cout<<"\n loop is present";
    else
        cout<<"\n loop isnt present";

    if(fast==NULL||fast->next==NULL)
        return head;

    slow=head;

    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }

    fast->next=NULL; //remove the loop link

    return head;

}

Node* segregate_even_and_odd(Node * head)
{
    Node* even_head=NULL;
    Node* odd_head=NULL;

    Node* even=NULL;
    Node* odd=NULL;

    Node* curr=head;

    while(curr!=NULL)
    {
        if((curr->data)%2==0)
        {
            if(even_head==NULL)
            {
                even_head=curr;
                even=curr;
            }
            else
            {
               even->next=curr;
               even=curr;  
            }
           
        }

        else
        {
            if(odd_head==NULL)
            {
                odd_head=curr;
                odd=curr;
            }
            else
            {
                odd->next=curr;
                odd=curr;   
            }
            
        }

        curr=curr->next;
    }

    if(odd_head==NULL||even_head==NULL)
        return head;
    //merge even and odd
    even->next=odd_head;
    odd->next=NULL;
    head=even_head;

    return head;

}

int get_count(Node* head)
{
    int count=0;
    Node* curr=head;
    while(curr!=NULL)
    {
        count+=1;
        curr=curr->next;
    }
    return count;
}

int intersection(int diff,Node* head1,Node* head2)
{
    for(int i=0;i<diff;i++)
    {
        if(head1==NULL)
            return -1;
        head1=head1->next;
    }

    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data==head2->data)
            return head1->data;
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}

int get_intersection(Node* head1, Node* head2)
{
    int c1=get_count(head1);
    int c2=get_count(head2);
    int result,d;
    if(c1>c2)
    {
        d=c1-c2;
        result=intersection(d,head1,head2);
    }
    else
    {
        d=c2-c1;
        result=intersection(d,head2,head1);

    }

    return result;

    
}

Node* pairwise_swap_data(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* prev=head;
    Node* curr=head->next;

    while(prev!=NULL && curr!=NULL)
    {
        Node* temp=curr->next;
        int val=curr->data;
        curr->data=prev->data;
        prev->data=val;
        if(temp==NULL)
        {
            curr=NULL;
        }
        else
        {
            prev=temp;
            curr=temp->next;
        }
        
    }

    return head;
}

Node* pairwise_swap_link(Node* head)
{
    if(head==NULL||head->next==NULL)
        return head;

    Node* prev=head;
    Node* curr=head->next->next;
    head=head->next;
    head->next=prev;

    while(curr!=NULL && curr->next!=NULL)
    {
        prev->next=curr->next;
        prev=curr;
        Node* next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }

    prev->next=curr;
    return head;

}

Node* clone_random(Node* head)
{
    //step01: create copy nodes after every original node
    for(Node* curr=head;curr!=NULL;)
    {
        Node* temp=new Node(curr->data);
        temp->next=curr->next;
        curr->next=temp;
        curr=curr->next->next;
    }

    //now replicate random links into copy nodes as the original nodes

    for(Node* curr=head;curr!=NULL;curr=curr->next->next)
    {
        curr->next->random=(curr->random==NULL)?NULL:curr->random->next;
    } 

    Node* original=head;
    Node* copy=head->next;
    Node* tempo=copy;

    while(original && copy)
    {
        original->next=(original->next!=NULL)?original->next->next:NULL;
        copy->next=(copy->next!=NULL)?copy->next->next:NULL;

        original=original->next;
        copy=copy->next;

    }

    return tempo;


}

Node* clone_random_hash(Node* head)
{
    //create a hashmap
    unordered_map<Node*,Node*>hm;

    //traverse the original list and create nodes

    for(Node* curr=head;curr!=NULL;curr=curr->next)
        hm[curr]=new Node(curr->data);
    
    for(Node* curr=head;curr!=NULL;curr=curr->next)
    {
        Node* clone_curr=hm[curr];
        clone_curr->next=hm[curr->next];
        clone_curr->random=hm[curr->random];
    }

    Node* head2=hm[head];

    return head2;
       
}

Node* merge_two_sorted(Node* head1, Node* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;

    Node* temp1=head1;
    Node* temp2=head2;

    head=(temp1->data<temp2->data)?temp1:temp2;
    tail=(temp1->data<temp2->data)?temp1:temp2;

    if(temp1->data<temp2->data)
        temp1=temp1->next;
    else
        temp2=temp2->next;

    while(temp1!=NULL && temp2-!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            tail->next=temp1;
            tail=temp1;
            temp1=temp1->next;
        }

        else
        {
            tail->next=temp2;
            tail=temp2;
            temp1=temp2->next;
        }
    }

    if(temp1!=NULL)
    {
        tail->next=temp2;
    }

    else 
    {
        tail->next=temp1;
    }

    return head;

}

bool is_palindrome(Node* head)
{
    //check for empty or single element list
    if(head==NULL||head->next==NULL)return true;

    //first find the middle of the list
    Node *slow=head,*fast=head;

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    //reverse the second half of list, compare it with first

    Node* second_half=reverse_list(slow);
    Node* first_half=head;

    while(second_half!=NULL)
    {
        if(second_half->data!=first_half->data)
            return false;
        first_half=first_half->next;
        second_half=second_half->next;
    }

    return true;

}

int main()
{
    Node *head= new Node(10);
    head->next= new Node(10);
    head->next->next= new Node(20);
    head=insert_sorted(head,25);
    head=insert_sorted(head,25);
    head=insert_sorted(head,35);
    print_list(head);

    Node* middle=find_middle(head);
    cout<<"\n the middle of the linkedlist is : "<<middle->data;

    Node* nth=find_nth(head,2);
    cout<<"\n the middle of the linkedlist is : "<<nth->data<<"\n";

    head=reverse_list(head);
    print_list(head);

    cout<<"\n trying reversing on recursive attempt \n";

    head=recursive_reverse_list(head,NULL);
    print_list(head);

    cout<<"\n Trying to remove duplicates";

    head=remove_duplicates(head);
    print_list(head);

    cout<<"\n Trying to reverse_group_k";

    cout<<"\n";

    head=reverse_group_k(head,2);
    print_list(head);

    cout<<"\n Trying to reverse_group_k recursively \n";
    head=recursive_reverse_k(head,2);
    print_list(head);

    cout<<"\n trying to segregate even n odd \n";

    head= segregate_even_and_odd(head);
    print_list(head);


    Node *head2= new Node(45);
    head2->next= new Node(25);
    head2->next->next= new Node(35);

    int intersection_value=get_intersection(head,head2);

    cout<<"\n intersection point of 2 linked list is :"<<intersection_value<<"\n";

    cout<<"\n pairwise swap attempt \n";

    head=pairwise_swap_data(head2);
    print_list(head);




    return 0;

}