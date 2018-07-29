#include<bits/stdc++.h>
using namespace std;
vector< int> Prefix(string pat)
{
	int i=1;int j=0;
	vector<int > F(pat.size());
	F[0]=0;
	while(i<pat.size())
	{
		if(pat[i]==pat[j])
		{
			F[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=F[j-1];
		}
		else
		{
			F[i]=0;
			i++;
		}
	}
	return F;
}
int KMP(string str,string pat)
{
	int n=str.size();
	int m= pat.size();
	vector<int> prefix=Prefix(pat);
	int i=0;
	int j=0;
	while(i<n)
	{
		if(str[i]==pat[j])
		{
			if(j==m-1)
				return i-j;
			else
			{
				i++;
				j++;
			}
		}
		else if(j>0)
		{
			j=prefix[j-1];
		}
		else
		{
			i++;
		}
	}
	return -1;

}
int main()
{
	string str="Abhinandan Sanduja";
	string pat="naNdan";
	cout<<KMP(str,pat)<<endl;
	return 0;
}
