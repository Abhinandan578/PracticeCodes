#include<bits/stdc++.h>
using namespace std;
void printSequence(int S[100][100], int i, int j)
{
	// cout<<"Value of i and j is "<<i<<" "<<j<<endl;
	if(i==j)
	{	
		// cout<<"inside"<<endl;
		cout<<"A"<<i;
	}

	else
	{
		cout<<"(";
		printSequence(S,i,S[i][j]);
		printSequence(S,S[i][j]+1,j);
		cout<<")";
	}
}
long long int MCMProblem(int arr[],int i,int j)
{
	if(i==j)
		return 0;
	long long int q=INT_MAX;
	for(int k=i;k<j;k++)
	{
		q=min(MCMProblem(arr,i,k)+MCMProblem(arr,k+1,j)+arr[i-1]*arr[k]*arr[j],q);
	}
	return q;
}
long long int DpMCM(int arr[],int n)
{
	cout<<"Inside dp"<<endl;
	long long int mat[n][n];
	int S[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j]=0;
			S[i][j]=0;
		}
	}
	for(int i=1;i<n;i++)
	{
		mat[i][i]=0;//1
	}
	for(int l=2;l<=n-1;l++)
	{
		for(int i=1;i<=n-l;i++)
		{
			int j=i+l-1;
			int x;
			long long int q=INT_MAX;
			for(int k=i;k<j;k++)
			{
				if(q>(mat[i][k]+mat[k+1][j]+arr[i-1]*arr[k]*arr[j]))//()
				{
					q=(mat[i][k]+mat[k+1][j]+arr[i-1]*arr[k]*arr[j]);
					S[i][j]=k;
				}
			}
			mat[i][j]=q;
			
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",S[i][j] );
		}
		printf("\n");
	}
	printSequence(S,1,n-1);
	return mat[1][n-1];

}
int main()
{
	cout<<"Enter the Size of Order array"<<endl;
	int n;
	cin>>n;
	int arr[n];
	cout<<"Enter the values"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long int sum=DpMCM(arr,n);
	long long int sum2=MCMProblem(arr,1,n-1);
	cout<<"Min cost is "<<sum<<endl;
	cout<<"Min cost is in second case"<<sum2<<endl;

}