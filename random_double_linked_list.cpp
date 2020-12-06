#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
	struct node* rand;
}Node;

typedef struct dlist
{
	Node *head;
}DLIST;

void init(DLIST *h)
{
	h->head = NULL;
}

Node* createNode(int d)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = d;
	p->next = NULL;
	p->rand = NULL;
	return p;
}

Node * addNode(DLIST *h,int d)
{
	Node *p = createNode(d);
	p->next = h->head;
	h->head = p;
}

void display(DLIST *h,int i)
{
	Node* tmp = h->head;
	if(h->head == NULL)
	{
		printf("List is empty!");
		return;
	}

	if(i==1)
	{
		printf("Linked List : ");
		while(tmp != NULL)
		{
			printf("%d ",tmp->data);
			tmp = tmp->next;
		}
	}
	else
	{
		printf("Linked List random pointers : ");
		while(tmp != NULL)
		{
			printf("%d ",tmp->rand);
			tmp = tmp->next;
		}
	}
		
}

int main()
{
	DLIST h;
	DLIST d;
	map<int,Node *> m;
	init(&h);
	for(int i=4;i>0;i--)
	{
		addNode(&h,i);
	}
	display(&h,1);
	Node* tmp = h.head;
	for(int i=1;i<5;i++)
	{
		m[i] = tmp;
		tmp = tmp->next;
	}
	map<int,Node*>::iterator i;
	cout<<"\nMap of random pointers"<<endl;
	for(i = m.begin();i!=m.end();i++)
	{
		printf("%d %d\t",i->first,i->second);
	}
	m[1]->rand = m[3];
	m[2]->rand = m[1];
	m[3]->rand = m[3];
	m[4]->rand = m[2];
	cout<<"\n";
	display(&h,2);
	
	tmp = h.head;
	Node* n = tmp->next;
	//Inserted the same node after each node E.g : 1->1->2->2 so on.
	while(1)
	{
		n = tmp->next;
		if(n == NULL)
		{
			tmp->next = createNode(tmp->data);
			break;
		}
		tmp->next = createNode(tmp->data);
		tmp->next->next = n;
		tmp = n;
	}
	tmp = h.head;
	//Updating the random pointer. Eg : 1'->rand = 1->rand and so on.
	while(tmp != NULL)
	{
		tmp->next->rand = tmp->rand->next;
		tmp = tmp->next->next;
	}
	tmp = h.head;
	tmp = tmp->next;
	d.head = tmp;
	cout<<endl;
	display(&h,2);
	while(tmp->next != NULL)
	{
		tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	cout<<endl;
	display(&d,2);
	display
}

