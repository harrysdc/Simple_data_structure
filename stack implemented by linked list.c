#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nextptr;
};
typedef struct node NODE;

NODE *push(NODE *, int );
NODE *pop(NODE *,int *);
void printList(NODE *);
int isEmpty(NODE *);

int main(void)
{
	NODE *head = NULL;
	int data = 0;
		
	head = push(head, 1);
	head = push(head, 3);
	head = push(head, 5);
	head = push(head, 7);
	head = push(head, 9);
	printList(head);
	head = pop(head,&data);
	printf("poped data:%d\n",data);
	head = pop(head,&data);
	printf("poped data:%d\n",data);
	head = pop(head,&data);
	printf("poped data:%d\n",data);
	printList(head);
	
	system("pause");
	return 0;
}

NODE *push(NODE *head, int data)
{
	NODE *newNode;
	newNode = (NODE *)malloc(sizeof(NODE));
	
	newNode->data = data;
	newNode->nextptr = head;         //now both newNode & first nextptr is pointed to second node
	head = newNode;					 //update newNode	
	
	return head;
}

NODE *pop(NODE *head, int *data)     // *data is the container to store what's popped out
{	
	*data = head->data;
	
	NODE *temp = head;
	head = head->nextptr;
	free(temp);
	
	return head;
}

void printList(NODE * head)
{
	if(head == NULL)
		printf("nothing to print");
		
	NODE *current = head;
	
	printf("stack: ");
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->nextptr;
	}
	printf("\n");
}

int isEmpty(NODE *head)
{
	return (head == NULL)? 1 : 0;
}
