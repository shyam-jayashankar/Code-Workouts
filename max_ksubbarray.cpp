#include<iostream>
#include<deque>

using namespace std;

void maximum_in_k_elements(int arr[], int n, int k)
{
	deque<int>dq;

	int i;

	for(i=0;i<k;i++)
	{
		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}

	for(i=k;i<n;i++)
	{
		cout<<arr[dq.front()]<<" ";

		while(!dq.empty() && dq.front()<=i-k)
			dq.pop_front();

		while(!dq.empty() && arr[i]>=arr[dq.back()])
			dq.pop_back();

		dq.push_back(i);
	}

	cout<<arr[dq.front()];

}

int main()
{
	int arr[5]={20,40,30,10,60};

	int length=sizeof(arr)/sizeof(arr[0]);

	maximum_in_k_elements(arr,length,3);

	return 0;
}