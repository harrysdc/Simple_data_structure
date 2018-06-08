#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *nextptr;
};
typedef struct node NODE;

NODE *creatList(int data[], int );
void printList(NODE *);
void freeList(NODE *);
void insertNode(NODE *, int , int );
// NODE *searchNode(NODE *, int );
NODE *deleteNode(NODE *, int );

int main(void)
{
	NODE *first = NULL;
	int data[5]={1,5,9,13,17};
	
	first = creatList(data,5);
	printList(first);
	insertNode(first, 1, 3);
	insertNode(first, 13, 15);
	printList(first);
	
	first = deleteNode(first, 87);
	first = deleteNode(first, 17);
	printList(first);
	
	freeList(first);
	
	system("pause");
	return 0;
}

NODE *creatList(int data[], int length)
{
	int i;
	NODE *current, *previous, *first;
	
	for(i=0 ; i<length ; i++)
	{
		current = (NODE *)malloc(sizeof(NODE));
		
		current->data = data[i];				//set data
		
		if(i==0)								//link data
			first = current;
		else
			previous->nextptr = current;
		
		current->nextptr = NULL;				//nextptr
		previous = current;						//for the next current reference 
	}
	return first;
}

void printList(NODE *first)
{
	NODE *current = first;
	
	if(first == NULL)
	{
		printf("the list is empty!!!");
	}
	else
	{
		while(current != NULL)
		{
			printf("%d ",current->data);
			current = current->nextptr;
		}
		printf("\n");	
	}
}

void freeList(NODE *first)
{
	NODE *current = first, *temp;
	
	while(current != NULL)
	{
		temp = current;
		current = current->nextptr;
		free(temp);
	}
}
/*
NODE *searchNode(NODE *first, int data)
{
	NODE *current = first;
	
	while(current != NULL)
	{
		if(current->data == data)
			return current;
		else
			current = current->nextptr;
	}
	printf("no matched data in this linked list!!!");
	return NULL;
}
*/
void insertNode(NODE *first, int location, int data)
{
	NODE *newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;

	if(first == NULL)
	{
		first->data = newNode->data;
		first->nextptr = NULL;
	}
	else
	{
		NODE *current = first;
		while(current->data != location)
			current = current->nextptr;	
		newNode->nextptr = current->nextptr;
		current->nextptr =newNode;		
	}	
}

NODE *deleteNode(NODE *first, int data)
{	
	if(first == NULL)					//case 0:nothing in the list
	{
		printf("nothing to delete");
		return NULL;
	}
	
	if(first->data == data)            //case 1:deleteNode is first node
	{
		NODE *node = first;
		first = first->nextptr;
		free(node);
	}	
	else 								//case 2:deleteNode is in the middle of the list
	{
		NODE *node=first, *nodePrevious=first;
		while(node->data != data)			//find node containing the data
		{
			node = node->nextptr;
			if(node == NULL)
			{
				printf("no matched data (%d) to delete!!!\n",data);
				return first;
			}
		}	
		while(nodePrevious->nextptr != node)    //find node whose nextptr is storing the data's address
			nodePrevious = nodePrevious->nextptr;
			
		nodePrevious->nextptr = node->nextptr;
		free(node);
	}	
	return first;
}
