// Alunos:	IGOR PAIM e PEDRO MATOS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct Node
{
	struct Node *p;
	struct Node *left; //sempre os menores
	struct Node *right; //sempre os maiores
	int key;
} Node;

typedef struct Tree
{
  Node *root;
} Tree;


void percorre(Node* no, FILE* arq, int alt, int* flag);
Node *iterativeTreeSearch(Node *x, int key);
Node *treeMinimum(Node *x);
Node *treeMaximum(Node *x);
Node *treeSuccessor(Node *x);
Node *treePredecessor(Node *x);
void treeInsert(Tree *t, Node *z);
void treeDelete(Tree *t, Node *z);
void initNode(Node *n);
void initTree(Tree *t);
Node *createNode(int key);
Tree *createTree();
int calculateNodeHeight (Node *root ,Node *target );
int altura(Node* no, int key, int alt);

void percorre(Node* no, FILE* arq, int alt, int* flag){
  if(no == NULL) return;
  percorre(no->left, arq, alt+1, flag);
  if(*flag != 0) fprintf(arq, " ");
  *flag += 1;
  fprintf(arq, "%d (%d)", no->key, alt); 
  percorre(no->right, arq, alt+1, flag);
}

Node *iterativeTreeSearch(Node *x, int key)
{
	while (x != NULL && x->key != key)
	{
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

Node *treeMinimum(Node *x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

Node *treeMaximum(Node *x)
{
	while (x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

Node *treeSuccessor(Node *x)
{
	Node *y;

	if (x->right != NULL)
	{
		return treeMinimum(x->right);
	}
	y = x->p;
	while (y != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}

Node *treePredecessor(Node *x)
{
	Node *y;
	if (x->left != NULL)
	{
		return treeMaximum(x->left);
	}
	y = x->p;
	while (y != NULL && x == y->left)
	{
		x = y;
		y = y->p;
	}
	return y;
}

void treeInsert(Tree *t, Node *z)
{
	Node *y = NULL;
	Node *x = t->root;
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->p = y;
	if (y == NULL)
	{
		t->root = z;
	}
	else
	{
		if (z->key < y->key)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}
}

void treeDelete(Tree *t, Node *z)
{
	Node *y;
	Node *x;
	if (z->left == NULL || z->right == NULL)
	{
		y = z;
	}
	else
	{
		y = treeSuccessor(z);
	}

	if (y->left != NULL)
	{
		x = y->left;
	}
	else
	{
		x = y->right;
	}

	if (x != NULL)
	{
		x->p = y->p;
	}

	if (y->p == NULL)
	{
		t->root = x;
	}
	else
	{
		if (y->p->left == y)
		{
			y->p->left = x;
		}
		else
		{
			y->p->right = x;
		}
	}
	if (y != z)
	{
		z->key = y->key;
	}
}

void initNode(Node *n)
{
	n->p = NULL;
	n->left = NULL;
	n->right = NULL;
}

void initTree(Tree *t)
{
	t->root = NULL;
}

Node *createNode(int key)
{
	Node *res = malloc(sizeof(Node));
	initNode(res);
	res->key = key;
	return res;
}

Tree *createTree()
{
	Tree *res = malloc(sizeof(Tree));
	initTree(res);
	return res;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}