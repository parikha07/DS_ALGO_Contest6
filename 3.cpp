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


struct Node *func(struct Node* root, int m, int n)
{   int b=0;
	if (root == NULL) return NULL;
	if (root->data== m || root->data == n)
    return root;
	Node *l = func(root->left, m, n);
	Node *r = func(root->right, m, n);
    b++;
	if (l && r)
    return root;
	if(l != NULL)
    return l;
    else
    return r;
}

int main()
{   int t, m, n;
cin>>t;
	int arr[t];
	for(int i=0; i<t; i++)
    {
        cin>>arr[i];
    }
	Node* root = insert(arr, root, 0, t);
	cin>>m>>n;
	cout <<  func(root, m,n)->data;
}

