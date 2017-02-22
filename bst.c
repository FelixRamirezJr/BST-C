#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int key;
	struct node* right;
	struct node* left;
} node_t;

void addNode(node_t * root, int data, int key);
void traverse(node_t * root);
void addNodeRecursive(node_t ** root, int data, int key);



int main()
{
	node_t * root = NULL;
	addNodeRecursive(&root,7,8);
	addNodeRecursive(&root,9,10);
	traverse(root);
	return 0;
}

void addNodeRecursive(node_t ** root, int data, int key)
{
	node_t * tempNode;
	if(*root == NULL)
	{
		tempNode = malloc(sizeof(node_t));
		tempNode->left = NULL;
		tempNode->right = NULL;
		tempNode->data = data;
		tempNode->key = key;
		*root = tempNode;
		return;
	}

	 if((*root)->key < key){
	 	addNodeRecursive(&(*root)->right,data,key);
	 }else{
	 	addNodeRecursive(&(*root)->left,data,key);
	 }
}


void addNode(node_t * root, int data,int key)
{
	// Instantiate tempnode
	node_t * tempNode = malloc(sizeof(node_t));
	tempNode->data = data;
	tempNode->key = key;
	tempNode->right = NULL;
	tempNode->left = NULL;

	node_t * current;

	current = root;
	node_t * parent;
	while(1)
	{
		parent = current;
		if(key < current->key)
		{
			current = current->left;
			if(current == NULL)
			{
				parent->left = tempNode;
				return;
			}
		}
		else
		{
			current = current->right;
			if(current == NULL)
			{
				parent->right = tempNode;
				return;
			}
		}
	}
}

void traverse(node_t * root)
{
	if(root != NULL)
	{
		traverse(root->left);
		printf("Data: %d ... Key: %d\n\n",root->data,root->key);
		traverse(root->right);
	}
}