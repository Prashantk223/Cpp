#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *head;

void LinkedList_AddNode();
void LinkedList_ShowNodes();
void LinkedList_InsertNode();
void LinkedList_DeleteNode();
void LinkedList_ReverseByIteration();
int main()
{
	int choice = 0x0f;

	int Loop = 1;
	while(Loop)
	{	
	    printf("Enter 1 - Add node to linked list\n Enter 0 - to exit\n Enter 2 - Show nodes\n");
		printf("Enter 3 - Insert node to linked list\n");
		printf("Enter 4 - Delete node from   linked list\n");
		printf("Enter 5 - Reverse a linked list\n");
	    scanf("%d", &choice);
	    
    	switch(choice)
    	{
    		case 0:
    			Loop = 0;
    			break;
    		case 1:
    			LinkedList_AddNode();
    			break;
    		case 2:
    			LinkedList_ShowNodes();
    			break;
    		case 3:
    			LinkedList_InsertNode();
    			break;
    		case 4:
    			LinkedList_DeleteNode();
    			break;
    		case 5:
    			LinkedList_ReverseByIteration();
    			break;
    		default:
    			printf("Wrong choice");
    	}
		
	}
return 0;
}
void LinkedList_ReverseByIteration()
{
	struct node *prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	
	while(cur !=0)
	{
		next = cur->next;
		cur->next = prev;
		
		prev = cur;
		cur = next	
	}
}
void LinkedList_DeleteNode()
{
	struct node *temp, *newnode, *del = NULL, *prev;
	int pos = 0;
	int count = 0, i = 0;
	
	printf("Press 1 to delete at begining\n");
	printf("Press 2 to delete at end\n");
	printf("Press 3 to delete at position\n");
	scanf("%d", &pos);
	
	if(pos == 1)
	{
		if(head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
	}
	else if(pos == 2)
	{
		temp = head;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next; //important
		}
		
		if(prev == NULL)
		{
			head = NULL;
			free(temp);
		}
		else
		{
			prev->next = NULL;
			free(temp);
		}
	}
	else if(pos == 3)
	{
		temp = head;
		while(temp != NULL)
		{
			temp = temp->next;
		    count++;
		}
		
		printf("Enter position");
		scanf("%d", &pos);
		
		if(pos>count)
		{
			printf("position is higher than node count");
			return;
		}
		
		temp = head;
		// rech till
		i = 0;
		while(i<pos-1)
		{
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		free(temp);
		
	}
	else
	{
		printf("wrong choice");
	}
	
}
void LinkedList_InsertNode()
{
	struct node *temp, *newnode;
	int pos = 0;
	int count = 0, i = 0;
	newnode = malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Mem allocation failed");
		return;
	}
	printf("Enter value");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	
	printf("Press 1 to add at begining\n");
	printf("Press 2 to add at end\n");
	printf("Press 3 to add at position\n");
	scanf("%d", &pos);
	
	if(pos == 1)
	{
		newnode->next = head;
		head = newnode;
	}
	else if(pos == 2)
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next; //important
		}
		
		temp->next = newnode;
	}
	else if(pos == 3)
	{
		temp = head;
		while(temp != NULL)
		{
			temp = temp->next;
		    count++;
		}
		
		printf("Enter position after which node shall be entered");
		scanf("%d", &pos);
		
		if(pos>count)
		{
			printf("position is higher than node count");
			return;
		}
		
		temp = head;
		//temp temp pints to position after which node shall be added
		while(i<pos-1)
		{
			temp = temp->next;
			i++;
		}
		
		newnode->next = temp->next;
		temp->next = newnode;
		
	}
	else
	{
		printf("wrong choice");
	}


	
}
void LinkedList_AddNode()
{
	struct node *newnode, *temp;
	int AddLoop = 1;
	while(AddLoop)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		if (newnode == NULL)
		{
			printf("Memory allocation failed\n");
			return;
		}
		printf("Enter node value\n");
		scanf("%d", &newnode->data);
		newnode->next = NULL;
		
		if(head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = temp->next ;
		}
		printf("Enter 1 - Add node to inked list\n Enter 0 - to exit\n");
		scanf("%d", &AddLoop);
	}
}

void LinkedList_ShowNodes()
{
	struct node *temp;
	temp = head;
	
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}



inser at given index
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert_at_index(struct node *head, int data, int index)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node)
        return head;

    new_node->data = data;
    new_node->next = NULL;

    // Insert at beginning
    if (index == 0) {
        new_node->next = head;
        return new_node;
    }

    struct node *temp = head;
    int i = 0;

    // Traverse to node before desired index
    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Index out of range\n");
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int detect_loop(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps

        if (slow == fast) {
            return 1;   // Loop found
        }
    }

    return 0;   // No loop
}


insert at nth position
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insertAtNth(struct Node *head, int data, int pos)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node *temp = head;

    for(int i = 1; i < pos-1; i++)
    {
        temp = temp->next;

        if(temp == NULL)
        {
            printf("Position out of range\n");
            return head;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void printList(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    head = insertAtNth(head, 10, 1);
    head = insertAtNth(head, 20, 2);
    head = insertAtNth(head, 30, 3);
    head = insertAtNth(head, 25, 3); // insert at position 3

    printList(head);

    return 0;
}

//find previous node - 
for(int i = 1; i < pos-1; i++)
{
//find excact node
for(int i = 0; i < pos-1; i++)
{
	
	
//this can also be done by
 ListNode* dummy = new ListNode(); //important
 dummy->next = head;
 ListNode* ptr1 = dummy;
 //excact node
for(int i = 0; i < n; i++)
{
	ptr1 = ptr1->next;
}

//previous node
//excact node
for(int i = 0; i < n - 1; i++)
{
	ptr1 = ptr1->next;
}