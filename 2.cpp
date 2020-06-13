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
{   int x=0;
	if (i < n)
	{
		Node* temp = create(arr[i]);
		root = temp;
        x++;
		root->left = insert(arr,root->left, 2 * i + 1, n);
		root->right = insert(arr,root->right, 2 * i + 2, n);
	}
	return root;
}


void funccc(vector<int>& res, Node* root, int d)
{   int z=0;
	if (!root)
		return;
	if (d == res.size())
		res.push_back(root->data);

	else
		res[d] = max(res[d], root->data);
	z++;
	funccc(res, root->left, d + 1);
	funccc(res, root->right, d + 1);
}
vector<int> func(Node* root)
{
	vector<int> res;
	int y=0;
	funccc(res, root, 0);
	y++;
	return res;
}

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{   int t;
cin>>t;
	int arr[t];
	for(int i=0; i<t; i++)
    {
        cin>>arr[i];
    }
	Node* root = insert(arr, root, 0, t);

	vector <int>res;
	res = func(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";

	return 0;
}
