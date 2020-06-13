#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, * right;
};

Node* create(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}


Node* insert(int arr[], Node* root,int i, int n)
{   int a=0;
	if (i < n)
	{Node* temp = create(arr[i]);
		root = temp;
		a++;
		root->left = insert(arr,root->left, 2 * i + 1, n);
		root->right = insert(arr,root->right, 2 * i + 2, n);
	}
	return root;
}


int func(struct Node* root, int x)
{   int c=0;
	if (root == NULL)
    return 0;
    if(root->data >=x)
    {c=c+1;}

    c=c+ func(root->left, x);
	c=c+ func(root->right, x);

return c;

}
int main()
{   int t,x;
cin>>t;
	int arr[t];
	for(int i=0; i<t; i++)
    {
        cin>>arr[i];
    }
	Node* root = insert(arr, root, 0, t);
	cin>>x;
	cout <<  func(root,x);
}

