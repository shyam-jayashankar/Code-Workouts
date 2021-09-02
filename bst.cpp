#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;

	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}

};


bool search_recursive(Node* root,int value)
{
	if(root==NULL)
		return false;

	if(value==root->data)
		return true;

	if(value<root->data)
		return search_recursive(root->left,value);
	else
		return search_recursive(root->right,value);
}

bool search_iterative(Node* root, int value)
{
	if(root==NULL)
		return false;
	
	while(root!=NULL)
	{
		if(root->data==value)
			return true;
		else if(root->data<value)
			root=root->right;
		else
			root=root->left;
	}

	return false;

}

Node* insert_iterative(Node* root, int value)
{
	
	Node* temp=new Node(value);

	if(root==NULL)
		return temp;

	Node* prev=NULL;
	Node* curr=root;

	while(curr!=NULL)
	{
		prev=curr;

		if(curr->data==value)
			return root;

		else if(curr->data<value)
			curr=curr->right;
		else
			curr=curr->left;
		
	}


	
	if(prev->data<value)
		prev->right=temp;
	else
		prev->left=temp;

	return root;
}


Node* insert_recursive(Node* root, int value)
{
	if(root==NULL)
		return new Node(value);
	if(root->data<value)
		root->right=insert_recursive(root->right,value);
	else
		root->left=insert_recursive(root->left,value);

	return root;

}

Node* get_successor(Node* curr)
{
	curr=curr->right;
	while(curr!=NULL&&curr->left!=NULL)
		curr=curr->left;
	return curr;
}

Node* delete_node(Node* root, int value)
{
	if(root==NULL)
		return root;
	else if(root->data<value)
		root->right=delete_node(root->right,value);
	else if(root->data>value)
		root->left=delete_node(root->left,value);
	else
	{
		if(root->left==NULL)
		{
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* succ=get_successor(root);
			root->data=succ->data;
			root->right=delete_node(root->right,succ->data);
		}
		return root;
	}
}

Node* floor_bst(Node* root, int value)
{
	Node* prev=NULL;
	//if current node is empty, then return prev stored pointer. 
	if(root==NULL)
		return prev;

	//if current node is available, check for the value in the node, if its lower, store it else skip storing and traverse
	while(root!=NULL)
	{
		//if value equals root's value, then that's the floor
		if(root->data==value)
			return root;

		//else as you bypass every lower value than the asked value, keep storing their node information in prev
		else if(root->data<value)
		{
			prev=root;
			root=root->right;
		}
		else
			root=root->left;
	}

	//return floor node data
	return prev;

} 

Node* ceil_bst(Node* root, int value)
{
	Node* prev=NULL;

	if(root==NULL)
		return prev;
	while(root)
	{
		if(root->data==value)
			return root;
		else if(root->data>value)
		{
			prev=root;
			root=root->left;
		}
		else
			root=root->right;
	}

	return prev;
	


}

void ceiling_on_left(int arr[],int n)
{
	set<int>s;
	
	for(int i=0;i<n;i++)
	{
		int value=(s.upper_bound(arr[i])==s.end())?-1:*(s.upper_bound(arr[i]));
		cout<<value<<" ";
		s.insert(arr[i]);
	}
}

bool check_bst(Node* root,int min,int max)
{
	if(root==NULL)
		return true;
	return(root->data>=min && root->data<=max && check_bst(root->left,min,root->data) && check_bst(root->right,root->data,max));
}

int prevv=INT_MIN;

bool check_opt_bst(Node* root)
{
	if(root==NULL)
		return true;
	if(!check_opt_bst(root->left))
		return false;
	if(prevv>=root->data)
		return false;
	prevv=root->data;
	return check_opt_bst(root->right);
}

bool check_pair_sum(Node* root, unordered_set <int> &s, int total)
{
	if(root==NULL)
		return false;
	if(s.find(total-(root->data))!=s.end())
		return true;
	else
		s.insert(root->data);
	return (check_pair_sum(root->left,s,total)||check_pair_sum(root->right,s,total));
}

void vertical_sum(Node* root, int vertical_val, map<int,int>&mp)
{
	if(root==NULL)
		return;
	vertical_sum(root->left,vertical_val-1,mp);
	mp[vertical_val]+=root->data;
	vertical_sum(root->right,vertical_val+1,mp);
}

void vsum(Node* root)
{
	map<int,int> mp;

	vertical_sum(root,0,mp);

	cout<<"\n\n";

	for(auto it: mp)
		cout<<it.second<<" ";
}



void vertical_view(Node* root) //do level order traversal and store nodes according to horizontal distance
{
	map<int,vector<int>> mp;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty())
	{
		auto p=q.front();
		Node* temp=p.first;
		int val=p.second;
		map[val].push_back(temp->data);
		if(temp->left)
			q.push({temp->left,val-1});
		if(temp->right)
			q.push({temp->right,val+1});
		q.pop();

	}

	
	for(auto it: mp)
	{
		for(int x: it.second)
			cout<<x<<" ";
		cout<<endl;
	}
}

void top_view(Node* root)
{
	//print top node at every vertically inclined node set

	map<int,int> mp; //not fixing vectors as values as only top values need to be stored

	queue<pair<Node*,int>>q; 

	q.push({root,0});

	while(!q.empty())
	{
		auto p=q.front();
		Node* temp=p.first;
		int vval= p.second;
		if(mp.find(vval)==mp.end()) //first vlevel value
			mp[vval]=temp->key;
		if(temp->left)
			q.push({temp->left,vval-1});
		if(temp->right)
			q.push({temp->right,vval+1});
		q.pop();

	}

	for(auto it: mp)
	{
		cout<<it.second<<" ";
	}

}

void bottom_view(Node* root)
{
	//print top node at every vertically inclined node set

	map<int,int> mp; //not fixing vectors as values as only top values need to be stored

	queue<pair<Node*,int>>q; 

	q.push({root,0});

	while(!q.empty())
	{
		auto p=q.front();
		Node* temp=p.first;
		int vval= p.second;
		mp[vval]=temp->key;
		if(temp->left)
			q.push({temp->left,vval-1});
		if(temp->right)
			q.push({temp->right,vval+1});
		q.pop();

	}

	for(auto it: mp)
	{
		cout<<it.second<<" ";
	}

}

int main()
{
	Node* root=new Node(20);
	root->left=new Node(15);
	root->right=new Node(30);
	root->left->left=new Node(12);
	root->left->right=new Node(18);
	root->left->left->left=new Node(7);
	root->right->right=new Node(40);
	root->right->right->left=new Node(35);
	root->right->right->right=new Node(50);
	root->right->right->right->right=new Node(80);

	if(search_recursive(root,7))
		cout<<"\n element found ";
	else
		cout<<"\n element not found";

	cout<<"\n\n checking floor of 19 in bst\n";
	cout<<floor_bst(root,19)->data;

	cout<<"\n\n checking ceil of 19 in bst\n";
	cout<<ceil_bst(root,19)->data<<"\n";

	int arr[6]={2,8,30,15,25,12};

	ceiling_on_left(arr,6);

	vsum(root);

	return 0;

}