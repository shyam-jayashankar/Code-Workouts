#include<iostream>

using namespace std; 

//subset problem 

//task -> given an array: [20,10,2,4], find if a subset exists contributing a sum 's'
//say if s =12, yes [10,2] is a subset that contributes to sum 12
//say if s=25, no subset contributes to it.

bool subset_sum(int arr[],int checksum, int n)
{
	//no number->no sum->return false
	if(n==0)
		return false;
	if(checksum==0) //means we have arrived at a subset
		return true;
	if(arr[n-1]<=checksum)//then we can attempt selecting/deselecting the element as a part of our subset
		return (subset_sum(arr,checksum-arr[n-1],n-1)||subset_sum(arr,checksum,n-1));
	else
		return subset_sum(arr,checksum,n-1);

}

bool t[n+1][checksum+1];

bool subset_sum(int arr[],int checksum, int n)
{
	for(i=0;i<n;i++)
		arr[i][0]=true;
	
	for(i=0;i<checksum;i++)
		arr[0][i]=false;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=checksum;j++)
		{
			if(arr[i-1]<=j)
				arr[i][j]=arr[i-1][j-arr[i-1]]||arr[i-1][j];
			else
				arr[i][j]=arr[i-1][j];
		}
	}

	return arr[n][checksum];
}

bool equal_partition(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	if(sum%2!=0)
		return false; //since odd array sum can never split into two equal partitions
	else
		return subset_sum(arr,sum/2,n);
}