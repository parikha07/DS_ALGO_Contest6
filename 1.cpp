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
Node* insert(int arr[], Node* root,
					int i, int n)
{
	if (i < n)
	{
		Node* temp = create(arr[i]);
		root = temp;

		root->left = insert(arr,root->left, 2 * i + 1, n);

		root->right = insert(arr,root->right, 2 * i + 2, n);
	}
	return root;
}
int solve(Node* root,int res)
{ int b=0;
	if (root == NULL)
        return INT_MIN;
	 int left = solve(root->left, res);
	int right = solve(root->right, res);
	//cout << left + right;
	int temp = max(left, max(right, left + right)) + root->data;
	res = max(res, temp);
	res = max(res, root->data);
  b++;
	return max(left +  root->data, max(right +  root->data,  root->data));
}
int maxPathSum(Node* root) {
	int res;
  int a=0;
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    return root->data;
	solve(root, res);
  a++;
	int ans = (int)res;
    return ans;
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
	cout <<  solve(root,0);
}

