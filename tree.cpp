#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void preOrder(node *root)
{
    cout << root->data << ' ';

    if(root->left != NULL)
        preOrder(root->left);

    if(root->right != NULL)
        preOrder(root->right);
}

void postOrder(node *root)
{
    if(root->left != NULL)
        postOrder(root->left);

    if(root->right != NULL)
        postOrder(root->right);

    cout << root->data << ' ';
}

void inOrder(node *root)
{
    if(root->left != NULL)
        inOrder(root->left);

    cout << root->data << ' ';

    if(root->right != NULL)
        inOrder(root->right);
}

int height(node *root)
{
    if(root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}

int findMin(node *root)
{
    int minEle = min(findMin(root->left), findMin(root->right));
    minEle = min(minEle, root->data);
    return minEle;
}

int findMax(node *root)
{
    int maxEle = min(findMax(root->left), findMax(root->right));
    maxEle = min(maxEle, root->data);
    return maxEle;
}

void levelOrder(node *root)
{
    if(root == NULL)
        return;

    queue<node*> q;

    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        cout << root->data << ' ';
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
}

node* insertNode(node* root, int value)                 //bst
{
    node *temp = new node, *current = root;
    temp->data = value;
    temp->left = temp->right = NULL;

    if(root == NULL)
        return temp;

    while(1)
    {
        if(value < current->data)
        {
            if(current->left == NULL)
            {
                current->left = temp;
                break;
            }
            else
                current = current->left;
        }
        else
        {
            if(current->right == NULL)
            {
                current->right = temp;
                break;
            }
            else
                current = current->right;
        }
    }
    return root;
}

node* lowestCommonAncestor(node* root, int v1, int v2)  //bst
{
    while(1)
    {
        if(root->data < v1 && root->data < v2)
            root = root->right;
        else if(root->data > v1 && root->data > v2)
            root = root->left;
        else
            return root;
    }
}

bool checkBST(node* root, int min_data = INT_MIN, int max_data = INT_MAX)
{
    if(root == NULL)
        return 1;
    if(root->data <= min_data || root->data >= max_data)
        return 0;
    return checkBST(root->left, min_data, root->data)
        && checkBST(root->right, root->data, max_data);
}

node* deleteNode(node *root, int data)                  //bst
{
	if(root == NULL)
        return root;
	else if(data < root->data)
        root->left = deleteNode(root->left, data);
	else if(data > root->data)
        root->right = deleteNode(root->right,data);
	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root->left == NULL)
		{
			node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			node *temp = root;
			root = root->left;
			delete temp;
		}
		else
		{
			node *temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            //temp is now the minimum element in the right subtree
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

int main()
{
    return 0;
}
