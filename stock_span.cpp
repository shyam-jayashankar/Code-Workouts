#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define R 4
#define C 4

void stockspan_generate(int rate[], int n)
{
	stack<int>st;
	
	//first day->default=1

	cout<<"\n 1 ";

	st.push(0);

	for(int i=1;i<n;i++)
	{
		
		while(st.empty()==false && rate[st.top()]<=rate[i])
		{
			st.pop();
		}


		int span=(st.empty())?i+1:i-st.top();
		
		cout<<span<<" ";

		//push the current day for future computation
		st.push(i);


	}

	//return;

}


void previous_greater (int elements[], int n)
{
	stack<int>st;
	
	//first day->default=1

	cout<<"\n -1 ";

	st.push(elements[0]);

	for(int i=1;i<n;i++)
	{
		
		while(st.empty()==false && st.top()<=elements[i])
		{
			st.pop();
		}


		int prev_gr=(st.empty())?-1:st.top();
		
		cout<<prev_gr<<" ";

		//push the current day for future computation
		st.push(elements[i]);


	}

	//return;

}

void next_greater (int elements[], int n)
{
	stack<int>st;

	int next_greater_element[n];
	
	//first day->default=1

	next_greater_element[n-1]=-1;

	st.push(elements[n-1]);

	for(int i=n-2;i>=0;i--)
	{
		
		while(st.empty()==false && st.top()<=elements[i])
		{
			st.pop();
		}


		next_greater_element[i]=(st.empty())?-1:st.top();

		//push the current day for future computation
		st.push(elements[i]);


	}

	cout<<"\n";

	for(int x: next_greater_element)
		cout<<x<<" ";

	//return;

}


int largest_rectangular_area_histogram(int arr[], int n)
{
	int previous_smallest[n];
	int next_smallest[n];
	int res=0,curr,i;

	stack<int>st;

	previous_smallest[0]=-1;

	st.push(0);

	for(i=1;i<n;i++)
	{
		while(st.empty()==false && arr[st.top()]>=arr[i])
			st.pop();

		previous_smallest[i]=(st.empty())?-1:st.top();
		st.push(i);
	}

	//now clear the stack for next_smallest processing

	while(st.empty()==false)
		st.pop();

	next_smallest[n-1]=-1;
	st.push(n-1);

	for(i=n-2;i>=0;i--)
	{
		while(st.empty()==false && arr[st.top()]>=arr[i])
			st.pop();

		next_smallest[i]=(st.empty())?n:st.top();
		st.push(i);
	}


	for(i=0;i<n;i++)
	{
		curr=arr[i];
		curr+=(i-previous_smallest[i]-1)*arr[i];
		curr+=(next_smallest[i]-i-1)*arr[i];

		res=(res<curr)?curr:res;
	}

	return res;


}


int largest_1s_rectangle(int arr[][C])
{
	int global_max=largest_rectangular_area_histogram(arr[0],C);

	for(int i=1;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(arr[i][j])
				arr[i][j]+=arr[i-1][j];
		}

		int local_max=largest_rectangular_area_histogram(arr[i],C);
		cout<<"\n max area for row: "<<i<<" is "<<local_max;
		global_max=(global_max<local_max)?local_max:global_max;
	}

	return global_max;
}


int main()
{
	int rates[]={13,15,12,14,16,8,6,4,10,30};

	int ele[]={15,10,18,12,4,6,2,8};

	int arr[]={6,2,5,4,1,5,6};

	int len=sizeof(arr)/sizeof(arr[0]);

	int length=sizeof(rates)/sizeof(rates[0]);

	int length2=sizeof(ele)/sizeof(ele[0]);


	stockspan_generate(rates,length);

	previous_greater(ele,length2);

	next_greater(ele,length2);

	int max_area=largest_rectangular_area_histogram(arr,len);

	cout<<"\n max rect area: "<<max_area<<endl;

	int mat[][C] = { 
        { 0, 1, 1, 0 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 1, 1 }, 
        { 1, 1, 0, 0 }, 
    }; 
  
    cout << "\n Area of maximum rectangle is " << largest_1s_rectangle(mat); 

	return 0;
}
