#include<stdio.h>
#include<malloc.h>
#include<string.h>
char* append(char* str,char c)
{
	int size=strlen(str);
	str[size]=c;
	str[size+1]='\0';
	return str;
}
typedef struct movie
{
	int freq;
	union node
	{
		struct intNode
		{
			struct movie* left;
			struct movie* right;
		} intNode;
		char name;
	} node;
	bool flag;
} movie;
void swap(movie* a,movie* b)
{
	movie temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(movie** arr,int i,int n)
{
	int left=2*i;
	int right=2*i+1;
	int minimum = i;
	if(left<=n&&arr[minimum]->freq>arr[left]->freq)
		minimum=left;
	if(right<=n&&arr[minimum]->freq>arr[right]->freq)
		minimum=right;
	if(minimum!=i)
	{
		swap(arr[minimum],arr[i]);
		heapify(arr,minimum,n);
	}
}
movie* ExtractMin(movie** arr,int* n)
{
	swap(arr[1],arr[*n]);
	(*n)--;
	heapify(arr,1,*n);
	return arr[(*n)+1];
}
void buildHeap(movie** arr,int n)
{
	for(int i=n/2;i>=1;i--)
	{
		heapify(arr,i,n);
	}
}
movie* newIntNode(int freq)
{
	movie *temp=(movie *)malloc(sizeof(movie));
	temp->freq=freq;
	temp->node.intNode.left=NULL;
	temp->node.intNode.right=NULL;
	temp->flag=true;
	return temp;
}
void percolateUp(movie** arr,int k)
{
	int parent=k/2;
	while(parent>=1&&arr[parent]->freq>arr[k]->freq)
	{
		swap(arr[parent],arr[k]);
		k=parent;
		parent=k/2;
	}
}
void insertIntoHeap(movie** arr,movie* m,int* k)
{
	(*k)++;
	arr[*k]=m;
	percolateUp(arr,*k);
}
int search(char name,char* index)
{
	int size=sizeof(index);
	int i;
	for(i=1;i<size;i++)
	{
		if(index[i]==name)
			return i;
	}
}
void inorder(movie* node,char *ans,char* str[100],char *index)
{
	if(node==NULL)
		return;
	movie* temp=node;
	if(temp->flag==false)
	{
		int ind=search(temp->node.name,index);
		strcpy(str[ind],ans);
	}
	else
	{
		char str1[100],str2[100];
		int len=strlen(ans);
		strcpy(str1,ans);
		str1[len]='\0';
		strcpy(str2,ans);
		str2[len]='\0';
		inorder(temp->node.intNode.left,append(str1,'0'),str,index);
		inorder(temp->node.intNode.right,append(str2,'1'),str,index);
	}
}
movie* Huffman(movie** arr,int n)
{
	buildHeap(arr,n);
	int k=n;
	while(k>1)
	{
		movie* m1=ExtractMin(arr,&k);
		movie* m2=ExtractMin(arr,&k);
		int freqSum=m1->freq+m2->freq;
		movie* m3=newIntNode(freqSum);
		if(m1->freq>m2->freq)
		{
			m3->node.intNode.left=m2;
			m3->node.intNode.right=m1;
		}
		else
		{
			m3->node.intNode.left=m1;
			m3->node.intNode.right=m2;	
		}
		if(k!=0)
			insertIntoHeap(arr,m3,&k);
		else
		{
			k++;
			arr[k]=m3;
		}
	}
	return arr[1];
}
int main()
{
	int n,i,j;
	printf("Enter the number of movies \n");
	scanf("%d",&n);
	movie** arr;
	char *index;
	index=(char *)malloc(sizeof(char)*(n+1));
	arr=(movie **)malloc(sizeof(movie *) * (n+1));
	for(int i=1;i<=n;i++)
	{
		arr[i]=(movie *)malloc(sizeof(movie));
	}
	printf("Enter the name of each movie \n");
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&(arr[i]->node.name));
		index[i]=arr[i]->node.name;
		arr[i]->flag=false;
	}
	printf("Enter the number of likes on each movie \n");
	for(j=1;j<=n;j++)
	{
		scanf("%d",&(arr[j]->freq));
	}
	movie* tree=Huffman(arr,n);
	char* ans;
	ans=(char *)malloc(sizeof(char)*100);
	char* str[100];
	for(i=1;i<=n;i++)
	{
		str[i]=(char*)malloc(sizeof(char *)*100);
	}
	inorder(tree,ans,str,index);
	for(i=1;i<=n;i++)
	{
		printf("Code for movie %c is %s\n",index[i],str[i]);
	}

	return 0;

}