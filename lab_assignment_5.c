#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node * temp = head;
	int len = 0;
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node * temp = head;
	if(temp == NULL){
		puts("Linked List is empty.");
		return 0;
	}
	char * str = (char *)calloc(length(temp), 1);
	while(temp != NULL){
		str = strncat(str, &temp->letter, 1);
		temp = temp->next;
	}
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node * temp = (*pHead);
  node * new = malloc(sizeof(node));
	new->letter = c;
	new->next = NULL;
  
	if((*pHead) == NULL){
		(*pHead) = new;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node * nextNode = NULL;
	while((*pHead)->next != NULL){
		nextNode = (*pHead)->next;
		free((*pHead));
		(*pHead) = nextNode;
	}
	free((*pHead));
	(*pHead) = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
      if(head == NULL) puts("1");
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}