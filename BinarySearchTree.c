#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BSTNode.h"

node* createNode(int value);
node* insertTree(node* root, int value);
bool searchTree(node* root, int searchValue);
void display(node* root);

int main(int argc, char **argv)
{
	int number;
	char ch;
	node* root = NULL;
	
	while(ch != 'n')
	{
		printf("Enter the value: ");
		scanf("%d", &number);
		root= insertTree(root,number);
		printf("\n");
		printf("Are you want to continue(y/n): ");
		scanf("\n%c", &ch);
		printf("\n");
	}
	display(root);
	
	int searchValue;
	printf("\n");
	printf("Which value you want to search: ");
	scanf("%d", &searchValue);
	
	if(searchTree(root,searchValue) == true)
	{
		printf("Found the search value.\n");
	}
	else
	{
		printf("Your given value not exist this tree.\n");
	}
}

node* createNode(int value)
{
	node* newNode=NULL;
	newNode = (node*)malloc(sizeof(node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

node* insertTree(node* root, int value)
{
	if(root == NULL)
	{
		root = createNode(value);
	}
	else if (value <= root->value)
	{
		root->left = insertTree(root->left, value);
	}
	else
	{
		root-> right = insertTree(root->right,value);
	}
	return root;
}

void display(node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->value);
		display(root->left);
		display(root->right);
	}
}

bool searchTree(node* root, int searchValue)
{
	if(root == NULL)
	{
		return false;
	}
	else if(root->value == searchValue)
	{
		return true;
	}
	else if(searchValue <= root->value)
	{
		return searchTree(root->left, searchValue);
	}
	else 
	{
		return searchTree(root->right, searchValue);
	}
	
} 