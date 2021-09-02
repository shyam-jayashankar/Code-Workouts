#include<iostream>

using namespace std;

int non_empty_station(int petrol[], int distance[], int n)
{

	int curr_petrol=0,prev_petrol=0,i,start=0;

	for(i=0;i<n;i++)
	{
		curr_petrol+=petrol[i]-distance[i];
		
		if(curr_petrol<0)
		{
			start=i+1;
			prev_petrol+=curr_petrol;
			curr_petrol=0;
		}

	}

	return (curr_petrol+prev_petrol>=0)?start+1:-1;


}






int main()
{
	int petrol[4]={50,10,60,100};

	int distance[4]={30,20,100,10};

	int n=sizeof(petrol)/sizeof(petrol[0]);

	int petrol_station=non_empty_station(petrol,distance,n);

	if(petrol_station==-1)
		cout<<"\n no such petrol station found wherein you can cover all the other bunks";

	else
		cout<<"\n Found station : "<<petrol_station<<" as a start point to fulfill a total coverage";

	return 0;
}