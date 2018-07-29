#include<stdio.h>
#include<stdbool.h>
int min(int a,int b)
{
	return a>b?b:a;
}
int MCM(int arr[],int n)
{
	int mat[n][n];
	int S[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[i][j]=0;
			S[i][j]=0;
		}
	}
	for(int l=2;l<=n-1;l++)
	{
		for(int i=1;i<=n-l;i++)
		{
			int j=i+l-1;
			int q=6000;
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
	return mat[1][n-1];
}
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the size of matrix\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Minimum cost of multiplication is ");
	int ans=MCM(arr,n);
	printf("%d\n",ans);
}