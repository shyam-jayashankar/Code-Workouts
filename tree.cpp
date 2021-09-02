#include<iostream>
#include<queue>
#include<stack>
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

void inorder_traversal(Node* root)
{
	if(root!=NULL)
	{
		inorder_traversal(root->left);
		cout<<root->data<<" ";
		inorder_traversal(root->right);
	}
}

void preorder_traversal(Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void postorder_traversal(Node* root)
{
	if(root!=NULL)
	{
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		cout<<root->data<<" ";
	}
}

int height_of_tree(Node *root)
{
	if(root==NULL)
		return 0;
	int height= 1+ max(height_of_tree(root->left),height_of_tree(root->right));
	return height;
}

void node_at_distance_k(Node *root,int k)
{

	if(root==NULL)
		return;

	if(k==0)
		cout<<root->data<<" ";

	else
	{
		node_at_distance_k(root->left,k-1);
		node_at_distance_k(root->right,k-1);
	}
}

void level_order_traversal(Node* root)
{
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
		
		cout<<temp->data<<" ";
		q.pop();

	}
}


void line_by_line_level_order_traversal(Node* root)
{
	queue<Node*>q;
	q.push(root);
	q.push(NULL);

	while(q.size()>1)
	{
		Node* temp=q.front();
		q.pop();

		if(temp==NULL)
		{
			cout<<"\n";
			q.push(NULL);
			continue;
		}

		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);	

	}
}


void line_by_line_another_level_order_traversal(Node* root)
{
	queue<Node*>q;
	q.push(root);

	while(!q.empty())
	{
		int curr_level_size=q.size();
		int i;

		for(i=0;i<curr_level_size;i++)
		{
			Node* temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}

		cout<<"\n";
	}
}

int number_of_nodes(Node* root)
{
	queue<Node*>q;
	int count=0;
	q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		count+=1;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);

	}
	return count;
}

int number_of_nodes_recursive(Node* root)
{
	if(root==NULL)
		return 0;
	return 1+ number_of_nodes_recursive(root->left)+number_of_nodes_recursive(root->right);
}

int maximum_in_tree(Node* root)
{
	if(root==NULL)
		return INT_MIN;
	return max(root->data, max(maximum_in_tree(root->left),maximum_in_tree(root->right)));
}

void left_view(Node* root)
{
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		int curr_level_size=q.size();
		for(int i=0;i<curr_level_size;i++)
		{
			Node* temp=q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);

			if(i==0)
				cout<<temp->data<<" ";


		}
	}
}

int max_level=0;
void left_view_recursive(Node* root,int level)
{
	if(root==NULL)
		return;
	if(max_level<level)
	{
		cout<<root->data<<" ";
		max_level=level;
	}
	left_view_recursive(root->left,level+1);
	left_view_recursive(root->right,level+1);
	

}

bool children_sum_property(Node* root)
{
	if(root==NULL)
		return true;
	if(root->left==NULL&&root->right==NULL)
		return true;

	int sum=0;
	if(root->left)
		sum+=root->left->data;
	if(root->right)
		sum+=root->right->data;
	return (root->data==sum && children_sum_property(root->left) && children_sum_property(root->right));

}


int is_balanced(Node* root)
{

	if(root==NULL)
	{
		return 0;
	}

	int lh=is_balanced(root->left);
	if(lh==-1)
		return -1;
	int rh=is_balanced(root->right);
	if(rh==-1)
		return -1;

	if(abs(lh-rh)>1)
		return -1;
	else
		return 1+max(lh,rh);

}	

int maximum_width(Node* root)
{
	int max=INT_MIN;
	queue<Node*>q;

	q.push(root);
	while(!q.empty())
	{
		int curr_level_size=q.size();
		max=(max<curr_level_size)?curr_level_size:max;

		for(int i=0;i<curr_level_size;i++)
		{
			Node* temp=q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
	return max;
}




Node* binary_to_dll(Node* root)
{
	if(root==NULL)
		return root;

	static Node* prev=NULL;

	Node* head=binary_to_dll(root->left);

	if(prev==NULL)
	{
		head=root;
		
	}

	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;

	binary_to_dll(root->right);

	return head;


}

int pre_index=0;

Node* in_pre_binary_tree(int in[],int pre[],int in_start,int in_end)
{
	
	int index;

	if(in_start>in_end)
		return NULL;
	
	Node* root=new Node(pre[pre_index++]);

	for(int i=in_start;i<=in_end;i++)
	{
		if(in[i]==root->data)
		{
			index=i;
			break;
		}

	}

	root->left=in_pre_binary_tree(in,pre,in_start,index-1);
	root->right=in_pre_binary_tree(in,pre,index+1,in_end);

	return root;

}

void print_list(Node* head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->right;
	}

}

void tree_traversal_in_spiral(Node* root)
{
	if(root==NULL)
		return;

	stack<Node*>s1,s2;

	s1.push(root);
	
	while(!s1.empty()||!s2.empty())
	{
		while(!s1.empty())
		{
			Node* temp=s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s2.push(temp->left);
			if(temp->right)
				s2.push(temp->right);
		}
		cout<<"\n";

		while(!s2.empty())
		{
			Node* temp=s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s1.push(temp->right);
			if(temp->left)
				s1.push(temp->left);
		}
		

		cout<<"\n";
	}
}

int res=0;

int diameter_of_tree(Node* root)
{
	if(root==NULL)
		return 0;
	int lh=diameter_of_tree(root->left);
	int rh=diameter_of_tree(root->right);
	res=max(res,1+lh+rh);

	return 1+max(lh,rh);
}

Node* lca(Node* root, int n1,int n2)
{

	if(root==NULL)
		return NULL;

	if(root->data==n1||root->data==n2)
		return root;

	Node* lca_left=lca(root->left,n1,n2);
	Node* lca_right=lca(root->right,n1,n2);
	

	if(lca_left!=NULL && lca_right!=NULL)
		return root;

	return (lca_left!=NULL)?lca_left:lca_right;
		
}

int left_height(Node* root)
{
	if(root==NULL)
		return 0;
	return 1+left_height(root->left);
}

int right_height(Node* root)
{
	if(root==NULL)
		return 0;
	return 1+right_height(root->right);
}

int count_binary_tree(Node* root)
{
	if(root==NULL)
		return 0;
	int lh=left_height(root->left);
	int rh=right_height(root->right);
	if(lh==rh)
		return pow(2,lh)-1;
	else
		return 1+count_binary_tree(root->left)+count_binary_tree(root->right);
}


void serialize(Node* root, vector<int> &arr)
{
	if(root==NULL)
	{
		arr.push_back(-1);
		return;
	}

	arr.push_back(root->data);
	serialize(root->left,arr);
	serialize(root->right,arr);
}

int ind=0;

Node* deserialize(vector<int>&arr,int &ind)
{
	if(ind==arr.size())
		return NULL;

	int val=arr[ind++];
	
	if(val==-1)
		return NULL;
	
	Node* root=new Node(val);
	root->left=deserialize(arr,ind);
	root->right=deserialize(arr,ind);
	

	return root;

}

void iterative_inorder(Node* root)
{
	stack<Node*> st;

	//st.push(root);

	Node* curr=root;

	while(curr!=NULL||!(st.empty()))
	{
		while(curr!=NULL)
		{
			st.push(curr);
			curr=curr->left;
		}

		curr=st.top();
		st.pop();
		cout<<curr->data<<" ";
		curr=curr->right;
		
	}
}

void iterative_preorder(Node* root)
{
	stack<Node*>st;

	Node* curr=root;
	
	st.push(root);

	while(!(st.empty()))
	{
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			if(curr->right)
				st.push(curr->right);
			curr=curr->left;
		}
		curr=st.top();
		st.pop();
	}
}


int main()
{
	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->right->left=new Node(70);
	root->left->right->right=new Node(80);
	root->right->right=new Node(60);

	cout<<"\n\n INORDER TRAVERSAL \n";
	inorder_traversal(root);

	cout<<"\n\n PREORDER TRAVERSAL \n";
	preorder_traversal(root);

	cout<<"\n\n POSTORDER TRAVERSAL \n";
	postorder_traversal(root);

	cout<<"\n\n Height of the binary tree: "<<height_of_tree(root);

	cout<<"\n\n NODES AT DISTANCE K \n";

	node_at_distance_k(root,2);

	cout<<"\n\n LEVEL ORDER TRAVERSAL \n";

	level_order_traversal(root);

	cout<<"\n\n LINE BY LINE LEVEL ORDER : METHOD 1 \n";

	line_by_line_level_order_traversal(root);

	cout<<"\n\n LINE BY LINE LEVEL ORDER : METHOD 1 \n";

	line_by_line_another_level_order_traversal(root);

	cout<<"\n\n Number of nodes in the tree: "<<number_of_nodes(root);

	cout<<"\n\n Number of nodes in the tree ->recursive method:  "<<number_of_nodes_recursive(root);

	cout<<"\n\n Maximum value in tree ->recursive method: "<<maximum_in_tree(root);

	cout<<"\n\n LEFT VIEW : ITERATIVE \n";

	left_view(root);

	cout<<"\n\n LEFT VIEW : RECURSIVE \n";

	left_view_recursive(root,1);

	cout<<"\n\n Checking for children sum property in the tree: \n";
	if(children_sum_property(root))
		cout<<"\n\n there is a pair of nodes that obey children_sum_property\n";
	else
		cout<<"\n\n No such pair of nodes that obey children_sum_property\n";


	cout<<"\n checking for balanced subtree\n";

	if(is_balanced(root))
		cout<<"\n\n tree is balanced \n";
	else
		cout<<"\n\n tree is not balanced \n";

	cout<<"\n\n Maximum width of the binary tree:  "<<maximum_width(root);

	cout<<"\n\n Converting binary tree to dll: \n";

	print_list(binary_to_dll(root));


	cout<<"\n\n Construction of tree from inorder and preorder arrays\n";

	int in[]={40,20,70,50,80,10,30,60};
	int pre[]={10,20,40,50,70,80,30,60};
	int n=sizeof(in)/sizeof(in[0]);
	
	root=in_pre_binary_tree(in, pre, 0, n-1);


	inorder_traversal(root);

	cout<<"\n\n Spiral traversal of tree \n";

	tree_traversal_in_spiral(root);

	int root_diameter_height=diameter_of_tree(root);

	cout<<"\n diameter of tree: "<<res;

	cout<<"\n\n Lowest common ancestor: \n";

	root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->right->left=new Node(70);
	root->left->right->right=new Node(80);
	root->right->right=new Node(60);

	Node* temp=lca(root,70,40);

	cout<<"LCA: "<<temp->data;

	cout<<"\n\n ITERATIVE PREORDER TRAVERSAL \n";
	iterative_preorder(root);

	return 0;

}