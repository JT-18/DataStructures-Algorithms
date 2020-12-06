#include<bits/stdc++.h>
using namespace std;
int max(int i,int j)
{
	return (i>j)?i:j;
}

typedef struct node
{
	int data;
	struct node *left,*right;
}Node;

Node *newNode(int d)			//Creates a node and returns a pointer to the node.
{
	Node *p =(Node *)malloc(sizeof(Node));
	p->data = d;
	p->left = p->right = NULL;
	return p;
}

void printBoundaryLeft(Node *root)
{
	if(root == NULL)
		return;
	if(root->left)		//if and else if any 1 will get executed in a particular call
	{
		printf("%d ",root->data);		
		printBoundaryLeft(root->left);
	}
	else if(root->right)
	{
		printf("%d ",root->data);
		printBoundaryLeft(root->right);
	}
}

void printBoundaryRight(Node* root)
{
	if(root == NULL)
		return;
	
	if(root->right)				//if and else if any 1 will get executed in a particular call
	{
		printBoundaryRight(root->right);
		printf("%d ",root->data);
	}
	
	else if(root->left)
	{
		printBoundaryRight(root->left);
		printf("%d ",root->data);
	}
}

void printLeaf(Node* root)
{
	if(root == NULL)
		return;
	printLeaf(root->left);
	if(!root->left && !root->right)
		printf("%d ",root->data);
	printLeaf(root->right);
}

void boundaryofTree(Node *root) 
{
	printf("Circumference of given tree : %d ",root->data);
	printBoundaryLeft(root->left);			//prints non leaf Nodes of circumference of left sub tree
	printLeaf(root->left);					//prints leaf nodes of left subtree
	printLeaf(root->right);					//prints leaf nodes of right subtree
	printBoundaryRight(root->right);		//prints non leaf nodes of circumference of right sub tree form bottom to top.
	
}

void mirrorTree(Node* root)
{
	if(root == NULL || (root->left == NULL && root->right == NULL))	//Detects leaf node or NULL node.
	{
		return;
	}
	//Traverse in post order fashion because after processing both childs you need to swap them.
	mirrorTree(root->left);
	mirrorTree(root->right);
	Node *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

void preOrder(Node* root)
{
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void iter_inOrder(Node *root)
{
	Node *curr = root;
	stack<Node *> s;
	while(curr != NULL || !s.empty())
	{
		if(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		else
		{
			curr = s.top();
			s.pop();
			printf("%d ",curr->data);
			curr = curr->right;
		}	
	}
}

void iter_postOrder(Node* root)
{
  stack<Node* > s,out;
  s.push(root);
  while(!s.empty())
  {
    Node* curr = s.top();
    s.pop();
    out.push(curr);
    if(curr->left)
        s.push(curr->left);
    if(curr->right)
        s.push(curr->right);
  }

  while(!out.empty())
  {
      cout<<out.top()->data<<" ";
      out.pop();
  }
}

int diameter = 0;
int treeDiameter(Node* root)
{
	if(!root)
		return 0;
	int lnode = treeDiameter(root->left);
	int rnode = treeDiameter(root->right);
	diameter = max((lnode + rnode + 1),diameter);
	return max(lnode,rnode) + 1;
		
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(6);
	root->left->right->left = newNode(7);
	root->left->right->left->right = newNode(8);
	root->right = newNode(3);
   	treeDiameter(root);
   	printf("Diameter : %2d\n",diameter-1);
	printf("\nPreorder : ");
	preOrder(root);
	printf("\nInorder : ");
	iter_inOrder(root);
	boundaryofTree(root);
	mirrorTree(root);
	printf("\n ----Mirror Tree----\n");
	preOrder(root);
	printf("\n");
    iter_inOrder(root);
    cout<<endl;
    iter_postOrder(root);
	return 0;
}
