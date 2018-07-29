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
void findPosn(int i,int posQueen[],int n,bool *ret)
{
	if(i==n)
	{
		*ret=true;
		return;
	}
	int j;
	for(j=0;j<n&&(*ret==false);j++)
	{
		if(compatibility(posQueen,i,j))
		{
			findPosn(i+1,posQueen,n,ret);
		}
	}
}
int main()
{
	printf("Enter the size of Checkboard\n");
	int n,i;
	scanf("%d",&n);
	int posQueen[100];
	bool ret=false;
	printf("Ans is \n");
	if(n<4)
	{
		printf("not possible \n");
	}
	else
	{	findPosn(0,posQueen,n,&ret);
		for(i=0;i<n;i++)
		{
			printf("%d ",posQueen[i] );
		}
		printf("\n");
	}
}