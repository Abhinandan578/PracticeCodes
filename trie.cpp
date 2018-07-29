#include<bits/stdc++.h>
using namespace std;
struct TrieNode
{
	map<char,TrieNode*> child;
	bool endOfWord;
};
struct TrieNode* newTrieNode()
{
	TrieNode* Node=new TrieNode;
	Node->endOfWord=false;
	return Node;
}
void pushWord(TrieNode*& root,const char *str)
{
	if(root==NULL)
		root=newTrieNode();
	TrieNode* curr=root;
	for(int i=0;i<strlen(str);i++)
	{
		if(curr->child.find(str[i])==curr->child.end())
		{
			curr->child[str[i]]=newTrieNode();
		}
		curr=curr->child[str[i]];
	}
	curr->endOfWord=true;
}
bool haveChildren(TrieNode * curr)
{
	// don't use (curr->map).size() to check for children
	map<char,TrieNode*>::iterator it;
	for (it=curr->child.begin();it!=curr->child.end();it++)
	{	if (it->second != NULL)
			return true;
	}

	return false;
}
bool search(TrieNode* root,const char* str)
{
	if(root==NULL)
		return false;
	TrieNode* curr=root;
	while(*str)
	{
		curr=curr->child[*str];
		if(curr==NULL)
			return false;
		str++;
	}
	return curr->endOfWord;
}
bool deletion(TrieNode*& root,const char* str)
{
	if(root==NULL)
		return false;
	if(*str)
	{
		if(root!=NULL&&root->child.find(*str)!=root->child.end()&&deletion(root->child[*str],str+1)&&root->endOfWord==false)
		{
			if(!haveChildren(root))
			{
				delete root;
				root=NULL;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	if(*str=='\0'&&root->endOfWord)
	{
		if(!haveChildren(root))
		{
			delete root;
			root=NULL;
			return true;
		}
		else
		{
			root->endOfWord=false;
			return false;
		}
	}
	return false;
}
void DisplayContactsUtil(struct TrieNode* currNode,string prefix)
{
	if(currNode->endOfWord)
	{
		cout<<prefix<<endl;
	}
	for(char i='a';i<='z';i++)
	{
		TrieNode* nextNode;
		nextNode=currNode->child[(char)i];
		if(nextNode!=NULL)
		{
			DisplayContactsUtil(nextNode,prefix+(char)i);
		}
	}
}
void DisplayContacts(struct TrieNode* root,string str)
{
	TrieNode *prevNode=root;
	string prefix="";
	char lastChar;
	TrieNode *currNode;
	int i;
	for(i=0;i<str.size();i++)
	{
		prefix=prefix+str[i];
		lastChar=str[i];
		currNode=prevNode->child[lastChar];
		if(currNode==NULL)
		{
			cout<<"No suggestion found for "<<prefix<<endl;
			i++;
			break;
		}
		else
		{
			cout<<"Suggestion found for prefix "<<prefix<<" are "<<endl;
			DisplayContactsUtil(currNode,prefix);
		}
		prevNode=currNode;
	}
	for(;i<str.size();i++)
	{
		prefix+=str[i];
		cout<<"No suggestion found for "<<prefix<<endl;
	}
}

int main()
{
	TrieNode* root = NULL;

	pushWord(root,"hello");
	// cout << search(root, "hello") << " ";   	// print 1

	pushWord(root, "helloworld");
	// cout << search(root, "helloworld") << " ";  // print 1

	// cout << search(root, "helll") << " ";   	// print 0 (Not present)

	pushWord(root, "hell");
	// cout << search(root, "hell") << " ";		// print 1

	pushWord(root, "h");
	// cout << search(root, "h") << endl;  		// print 1 + newline

	// deletion(root, "hello");
	// cout << search(root, "hello") << " ";   	// print 0 (hello deleted)
	// cout << search(root, "helloworld") << " ";  // print 1
	// cout << search(root, "hell") << endl;   	// print 1 + newline

	// deletion(root, "h");
	// cout << search(root, "h") << " ";   		// print 0 (h deleted)
	// cout << search(root, "hell") << " ";		// print 1
	// cout << search(root, "helloworld") << endl; // print 1 + newline

	// deletion(root, "helloworld");
	// cout << search(root, "helloworld") << " ";  // print 0
	// cout << search(root, "hell") << " ";		// print 1

	// deletion(root, "hell");
	// cout << search(root, "hell") << endl;   	// print 0 + newline

	// if (root == NULL)
	// 	cout << "TrieNode empty!!\n";   			// Trie is empty now

	// cout << search(root, "hell");   			// print 0

	string query="helter";
	DisplayContacts(root,query);
	return 0;
}