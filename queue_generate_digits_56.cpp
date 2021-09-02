#include<iostream>
#include<queue>

using namespace std;

void generate_digits(int n)

{
	queue<string>q;
	q.push("5");
	q.push("6");
	cout<<"\n";

	for(int i=0;i<n;i++)
	{
		string curr=q.front();
		cout<<curr<<" ";
		q.pop();
		q.push(curr+"5");
		q.push(curr+"6");
	}

	return;

}


int main()
{
	int n=9;
	generate_digits(n);
	return 0;
}