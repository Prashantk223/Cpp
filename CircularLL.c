#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *head, *tail;

int main()
{

	create_DLL();
	Traverse_Circular_DLL();
	Insert_Circular_DLL();
	return 0;
}
void Insert_Circular_DLL()
{
	//begining or end
	struct node *newnode, *temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = 0;
	newnode->next = 0;
	if(choice == 1)
	{
		if(tail == 0)
		{
			tail = newnode;
			tail->next = newnode;	
		}
		else{
			newnode->next = tail->next;
			tail->next = newnode;
			tail = newnode;
		}
	}
	else{
		// insert at position
		//position
		int pos = 3, count = 0;
		temp = tail;
		do{
			temp = temp->next;
			count++;
		}while(temp->next != tail)
			
		if(pos < 0 || pos > count)
		{
			printf("invalid position");
		}
		
		//get head node 
		temp = tail->next;
		int i = 1;//insert excactly at position. i = 1 will stopn loop excactly before the position
		while(i < pos-1)
		{
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	

}
void create_DLL()
{
	struct node *newnode, *temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->data = 0;
	newnode->next = 0;
	
	if(head == 0)
	{
		head=tail=newnode;
		head->next = head;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
		tail->next = head;
	}
}

void Traverse_Circular_DLL ()
{
	struct node *temp = head;
	
	while(temp->next != head)
	{
		printf("%d", temp->data);
		temp->next = temp;
	}
	
	printf("%d", temp->data);
	
	//or use do-while loop
}