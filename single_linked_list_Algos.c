#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}Node;

typedef struct slist
{
	Node* head;
}SLIST;

void init(SLIST* h)
{
	h->head = NULL;
}

Node* createNode(int d)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = d;
	p->next = NULL;
	return p;
}

void addNode(SLIST *h,int d)
{
	Node* p = createNode(d);
	p->next = h->head;
	h->head = p;
}

void display(SLIST *h)
{
	Node* tmp = h->head;
	if(h->head == NULL)
	{
		printf("List is empty!");
		return;
	}
	printf("Linked List : ");
	while(tmp != NULL)
	{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
}

void reverseList(SLIST* h)
{
	Node *prev = NULL;
	Node *current = h->head;
	Node *next = NULL;
	
	if(current == NULL)
	{
		printf("List is empty!");
		return;
	}
	while(current != NULL)
	{
		next = current->next;	//Store next node.
		current->next = prev;	//Reverse Current nodes pointer to previous node.\
		Now U have finished processing the single node so move to next node.
		prev = current;
		current = next;
	}
	h->head = prev;
}

void midptofList(SLIST *h)
{
	Node* slow = h->head;
	Node* fast = h->head;
	if(h->head == NULL)
	{
		printf("List is empty!");
		return;
	}
	while(fast)
	{
		fast = fast->next;	//fast ptr moves one step
		if(fast)fast = fast->next; //if fast ptr is not null then moves to next step
		if(fast)slow = slow->next; //After fast ptrs 2 steps slow ptr moves 1 step
	}
	
	printf("Mid-Point of List is : %d ",slow->data);
}

void KlastNode(SLIST* h,int cnt)
{
	Node* lead = h->head;
	Node* foll = h->head;
	int len = 0;
	if(h->head == NULL)
	{
		printf("List is empty!");
		return;
	}
	cnt = cnt - 1;
	if(cnt<=0)					//Case if Number is 0 or negative.
	{
		printf("Enter valid integer greater than 0");
		return;
	}
	while(cnt--)
	{
		lead = lead->next;
		len++;
		if(!lead)		//Case if kth last node is greater than the length of node.
		{
			printf("The lenght of list is %d",len);
			return;
		}
	}
	while(lead->next)
	{
		lead = lead->next;
		foll = foll->next; 
	}
	printf("Kth last node : %d",foll->data);   
}

void detectLoop(SLIST *h)
{
	if(h->head == NULL)
	{
		printf("List is empty");
		return;
	}
	Node *fast = h->head;
	Node *slow = h->head;
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast)fast = fast->next;
		if(fast)slow = slow->next;
		if(fast == slow)
		{
			if(fast == h->head)
				printf("Given list is a circulair linked list");
			else
				printf("Loop is present in the given list.");
			return;
		}
	}
	printf("Loop is not present in the given list.");
}

void positionofLoop(SLIST *h)
{
	if(h->head == NULL)
	{
		printf("List is empty");
		return;
	}
	Node *fast = h->head;
	Node *slow = h->head;
	Node *prev = h->head;
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast)fast = fast->next;
		if(fast)slow = slow->next;
		if(fast == slow)
			break;
	}
	if(fast == h->head)
	{
		printf("Given list is a circulair linked list");
		return;
	}	
	if(!fast)
		printf("Loop is not present in the list.");
	else
	{
		slow = h->head;
		while(fast!=slow)
		{
			prev = fast;
			fast = fast->next;
			slow = slow->next;
			
		}
		printf("Loop is present at node : %d",fast->data);
		prev->next = NULL;
	} 
}

//void removeLoop(SLIST* h)

int main()
{
	SLIST h;
	SLIST l;
	Node *t,*c;
	int cnt = 9;
	init(&h);
	init(&l);
	addNode(&h,4);
	addNode(&h,3);
	addNode(&h,2);
	addNode(&h,1);
//	reverseList(&h);		//Reverse a list.
//	midptofList(&h);		//find mid-point of list.
//	printf("\n");
//	KlastNode(&h,5);		//kth last node of list
//	printf("\n");
//	display(&h);
	
	printf("\n--------Linked List with LOOP ---------");
	addNode(&l,8);
	addNode(&l,7);
	addNode(&l,6);
	addNode(&l,5);
	addNode(&l,4);
	addNode(&l,3);
	addNode(&l,2);
	addNode(&l,1);
	//display(&l);

//Code to create to a linked list with loop.	
	t = l.head;
	while(t->next != NULL)
	{
		if(t->data == 3)
			c = t;
		t = t->next;
	}
	t->next = c;
	printf("\n");
	detectLoop(&l);			//detects if there is loop in list.
	printf("\n");
	positionofLoop(&l);		//detects if there is loop in list and tells the position of the loop and also removes the loop.
	printf("\n");
	display(&l);
////Code to print looped list.	
//	printf("\nLooped list data : ");
//	t=l.head;
//	while(cnt--)
//	{
//		printf("%d ",t->data);
//		t = t->next;
//	}

}
