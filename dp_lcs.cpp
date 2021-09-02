#include<iostream>
#include<string>

using namespace std; 

int longest_cs[1000][1000];

int lcs(string s1,string s2, int i, int j)
{
	if(longest_cs[i][j]!=-1)
		return longest_cs[i][j];

	if(i==0||j==0)
		longest_cs[i][j]=0;

	else
	{
		if(s1[i-1]==s2[j-1])
			longest_cs[i][j]=1+lcs(s1,s2,i-1,j-1);
		else
			longest_cs[i][j]=max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));


	}
	
	return longest_cs[i][j];
}


int lcs_tabulation(string s1,string s2, int i, int j)
{
	int longest_cs_tab[i+1][j+1];
	int row,col;

	for(row=0;row<i;row++)
		longest_cs_tab[row][0]=0;
	for(col=0;col<j;col++)
		longest_cs_tab[0][col]=0;

	for(row=1;row<=i;row++)
	{
		for(col=1;col<=j;col++)
		{
			if(s1[row-1]==s2[col-1])
				longest_cs_tab[row][col]=1+longest_cs_tab[row-1][col-1];
			else
				longest_cs_tab[row][col]=max(longest_cs_tab[row-1][col],longest_cs_tab[row][col-1]);
		}
	}

	return longest_cs_tab[i][j];


}


int main()
{
	string s1="sthrylazmp";
	string s2="zyxsbhklqam";
	memset(longest_cs,-1,sizeof(longest_cs));

	cout<<"\n Longest common subsequence is of length: "<<lcs(s1,s2,s1.length(),s2.length());

	cout<<"\n Longest common subsequence (tabulation) is of length: "<<lcs_tabulation(s1,s2,s1.length(),s2.length());
	return 0;

}