#include<iostream>

using namespace std; 

struct heapu
{
	int size, capacity;
	int * arr;

	heapu(int n)
	{
		size=0;
		capacity=n;
		arr=new int[n];
	}

	int left(int i)
	{
		return (2*i+1);
	}

	int right(int i)
	{
		return (2*i+2);
	}

	int parent(int i)
	{
		return (i-1)/2;
	}

	void insert(int val)
	{
		if(size==capacity)
			return;
		size++;
		arr[size-1]=val;
		for(i=size-1;i!=0 && arr[parent[i]]>arr[i])
		{
			swap(arr[i],arr[parent[i]]);
			i=parent[i];
		}
	}

	void heapify(int idx)
	{
		int lc=(idx*2)+1;
		int rc=(idx*2)+2;
		int smallest;
		if(arr[lc]<arr[idx]&&lc<n)
			smallest=lc;
		if(arr[rc]<arr[idx]&&rc<n)
			smallest=rc;
		if(largest!=idx)
		{
			swap(arr[i],arr[smallest]);
			heapify(smallest);
		}

	}

	int extract()
	{
		if(size==0)
			return INT_MIN;
		if(size==1)
		{
			size--;
			return arr[size];
		}

		swap(arr[0],arr[size-1]);
		size--;
		heapify(0);
	}

	void decrease_key(int idx, int val)
	{
		arr[idx]=val;

		while(parent[idx]!=0 && arr[parent[idx]]>arr[idx])
		{
			swap(arr[idx],arr[parent[idx]]);
			idx=parent[idx];
		}
	}

	void delete_key(int idx)
	{
		decrease_key(idx,INT_MIN);
		extract();
	}

	void build_heap()
	{
		for(i=size-2/2;i>=0;i--)
			heapify(i);
	}


};


