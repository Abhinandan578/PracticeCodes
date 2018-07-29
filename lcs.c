#include<stdio.h>
#include<malloc.h>
#include<string.h>
void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}
char* printLCS(int** mat,char* str1,char* str2)
{
	printf("Inside Print lcs");
	// char* common;
	char* common=(char*)malloc(sizeof(char)*100);
	int s1=strlen(str1);
	int s2=strlen(str2);
	int i,j;
	for(i=s1;i>0;)
	{
		for(j=s2;j>0&&i>0; )
		{
			if(mat[i][j]==mat[i-1][j])
			{
				i--;
			}
			else if(mat[i][j]==mat[i][j-1])
			{
				j--;
			}
			else if(mat[i][j]==mat[i-1][j-1]+1)
			{
				append(common,str1[i-1]);
				i--;
				j--;
			}
		}
	}
	return common;
}
int LCS(char* str1,char* str2)
{
	int s1=strlen(str1);
	int s2=strlen(str2);
	int** mat;
	int i,j;
	printf("1\n");
	mat=(int**) malloc(sizeof(int *)*(s1+1));
	for(i=0;i<=s1;i++)
	{
		mat[i]=(int*)malloc(sizeof(int)*(s2+1));
	}
	printf("244\n");
	for(i=0;i<=s1;i++)
	{
		for(j=0;j<=s2;j++)
		{
			if(i==0||j==0)
			{
				mat[i][j]=0;
			}
			else
			{
				if(str1[i-1]==str2[j-1])
				{
					mat[i][j]=1+mat[i-1][j-1];
				}
				else
				{
					if(mat[i-1][j]>=mat[i][j-1])
					{
						mat[i][j]=mat[i-1][j];
					}
					else
					{
						mat[i][j]=mat[i][j-1];
					}
				}
			}
		}
	}
	printf("Break\n");
	char* common =(char*)malloc(sizeof(char)*100);
	printf("nandu\n");
	common=printLCS(mat,str1,str2);
	printf("The Longest Common Subsequence is ");
	for(i=strlen(common)-1;i>=0;i--)
	{
		printf("%c",common[i]);
	}
	printf("\n"); 
	return mat[s1][s2];
}
int main()
{
	char* str1;
	char* str2;
	str1=(char *)malloc(sizeof(char)*100);
	str2=(char *)malloc(sizeof(char)*100);
	printf("Enter the string1\n");
	scanf("%s",str1);
	printf("Enter the string2\n");
	scanf("%s",str2);
	int ans=LCS(str1,str2);
	printf("Length of longest Common Substring is %d",ans);
	return 0;
}