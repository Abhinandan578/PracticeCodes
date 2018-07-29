#include<stdio.h>
bool compatibility(int posQueen[],int i,int j)
{
	if(i==0)
	{
		posQueen[i]=j;
		return true;
	}
	else
	{
		for(int k=0;k<i;k++)
		{
			if(posQueen[k]==j)
			{
				return false;
			}
			else if(posQueen[k]+k==i+j)
			{
				return false;
			}
			else if(posQueen[k]-k==(j-i))
			{
				return false;
			}
		}
		posQueen[i]=j;
		return true;	
	}
}
void findPosn(int i,int posQueen[],int n)
{
	if(i==n)
		return;
	int j;
	for(j=0;j<n;j++)
	{
		if(compatibility(posQueen,i,j))
		{
			if(i==n-1)
			{
				for(i=0;i<n;i++)
				{
					printf("%d ",posQueen[i] );
				}
				printf("\n");
			}
			else
			findPosn(i+1,posQueen,n);
		}
	}
}
int main()
{
	printf("Enter the size of Checkboard\n");
	int n,i;
	scanf("%d",&n);
	int posQueen[100];
	printf("Ans is \n");
	if(n<4)
	{
		printf("not possible \n");
	}
	else
	{	
		findPosn(0,posQueen,n);
	}
}