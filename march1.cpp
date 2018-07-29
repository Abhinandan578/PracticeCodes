#include<bits/stdc++.h>
using namespace std;
bool findfront(long int hand[],long int glove[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(hand[i]>glove[i])
			return false;
	}
	return true;
}
bool findback(long int hand[],long int glove[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(hand[i]>glove[n-1-i])
			return false;
	}
	return true;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long int hand[n],glove[n];
		for(int i=0;i<n;i++)
		{
			cin>>hand[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>glove[i];
		}
		bool front=findfront(hand,glove,n);
		bool back=findback(hand,glove,n);
		if(front&&back)
			cout<<"both"<<endl;
		else if(front)
			cout<<"front"<<endl;
		else if(back)
			cout<<"back"<<endl;
		else
			cout<<"none"<<endl;
	}
	return 0;
}
			
