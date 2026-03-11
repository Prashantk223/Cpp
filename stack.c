//insertion and delletion possible only from one end
//LIFO or FILO
//insertion - push, deletion - pop
// top of stack is where push and pop happens
// all data shall be same i.e. int, float or derived ds
//pop -  read from stack and remove 
// push, pop, peek/top, isempty, isfull
// application - reverse a string, recursion, check balance of parenthesis, infix, prefix, postfix
#include<stdio.h>
#include<stdlib.h>

//stack using array

#define N 5
int stack[N];
ijt top = -1;
void display()
{
	for(int i = top; i >= 0; i--)
	{
		printf("%d , stack[top]");
		
	}
}
void peek()
{
	if(top == -1)
	{
		printf("underflow\n");
	}
	else{
		printf("poped data = %d\n, stack[top]");
	}
}
void pop()
{
	item pitem; 
	if(top == -1)
	{
		printf("underflow\n");
	}
	else{
		pitem = stack[top];
		top--;
		printf("poped data = %d\n, pitem");
	}
}
void push()
{
	 int x;
	 printf("Enter data\n");
	 scanf("%d", &x);
	 
	 //overflow
	 if(top == N-1)
	 {
		printf("overflow\n");
	 }
	 else
	 {
		 top++;
		 stack[top] = x;
	 }
}
int main()
{
	int choice = 0x0f;

	int Loop = 1;
	while(Loop)
	{	
	    printf("Enter 1 - push\n");
		printf("Enter 2 - pop\n");
		printf("Enter 3 - peek\n");
		printf("Enter 4 - isEmpty\n");
		printf("Enter 5 - isFree\n");
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


//stack using linked list
TOP
 |
 v
+----+------+
| 30 |  *---+---->+----+------+
+----+------+    | 20 |  *---+---->+----+------+
                  +----+------+    | 10 | NULL |
                                   +----+------+

struct node
{
	int datal;
	struct node *link;
};
struct node *top;

void push()
{
	struct node  *tmp = (struct node  *) malloc(sizeof(struct node));
	if(tmp != NULL)
	{
		printf("Enter node data");
		scanf("%d", &tmp->data);
		
		tmp->link = top;
		top = tmp;
	}
	else
	{
		printf("-ENOMEM");
	}
}

void display()
{
	struct node  *tmp = top;
	
	if(tmp != NULL)
	{
		while(tmp != NULL)
		{
			printf("%d ", tmp->data);
			tmp = tmp->link;
		}
	}
	else
	{
		printf("LL is empty");
	}
}
void peek()
{
	if(tmp != NULL)
	{
		printf("top element is %d", tmp->data);
	}
	else
	{
		printf("LL is empty");
	}
}
void pop()
{
	if(top != NULL)
	{
		struct node  *tmp = top;
		printf("poped element is %d", tmp->data);
		top = top->link;
		free(tmp);
	}
	else
	{
		printf("LL is empty");
	}
}


//infix prefix postfix
infix
precedence prio
{} {} []
^         - exponential or power associativity R->L
* /       - L->R
+ -       - L->R

prefix - Polish notation
a*b+c
*ab+c
+*abc

positfix - Reverse Polish notation
a*b+c
ab* + c
ab*c+

while evaluatinf prefix, postfix and infix what to to:
evluate the part of expression with highest precedence operator. add operator at beginihg(pre) or at end(post)



* Queue *
FIFO
insertion from rear or tail Deletion from head or front
insertion - enqueue, deletion - dequeue
operations - enqueue, dequeue, front/peek, isFull, isEmpty
all operations o(1)

queue using array - wastage of freed space. solution - circular queue
use - shared respurce sync. e.g. printer
#define N 5
int queue[N];
int front = -1, rear = -1;

void enqueue(int x)
{
	if(rear == N-1)
	{
		printf("Queue is full");	
	}
	else if(rear == -1 && front == -1 )
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else{
		rear++;
		queue[rear] = x;
	}
}
void dequeue()
{
	if(rear == -1 && front == -1 )
	{
		printf("Underfull");
	}
	else if(rear == front)
	{
		printf("dequeued data = %d", queue[front] );
		rear = -1;
		front = -1;
	}
	else
	{
		printf("dequeued data = %d", queue[front] );
		front++;
	}
}
void display()
{
	if(rear == -1 && front == -1 )
	{
		printf("Underfull");
	}
	else
	{
		for(int i = front; i <= rear; front++)4
		{	
			printf("%d ", queue[i]);
		}
	}
}
void front()
{
	if(rear == -1 && front == -1 )
	{
		printf("Underflow");
	}
	else
	{
		printf("peek is %d ", queue[front]);
	}
}
boolean isfull()
{
	if(front == N-1 )
	{
		return  true;
	}
	else
	{
		return false;
	}
}
void isEmpty()
{
	if(rear == -1 && front == -1 )
	{
		return  true;
	}
	else
	{
		return false;
	}
}

//circular queue using arrays
void enqueue(int x)
{
	if(((rear + 1) % N)== front)
	{
		printf("Queue is full");	
	}
	else if(rear == -1 && front == -1 )
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else
	{
		rear = (rear + 1) % N;
		queue[rear] = x;
	}
}
void dequeue()
{
	if(rear == -1 && front == -1 )
	{
		printf("Queue is empty");	
	}
	else if(rear == front)
	{
		//queue has only 1 element
		printf("%d", queue[front]);	
		rear = front = -1;
	}
	else
	{
		//queue has only 1 element
		printf("%d", queue[front]);
		front = (front + 1) % N;
	}
}
void isFull()
{
	if(((rear + 1) % N)== front)
	{
		printf("Queue is full");	
	}
}
void display()
{
	int i = front;
	while(i != rear)
	{
		printf("%d ", queue[i]);
		i = (i + 1) % N;
	}
	printf("%d ", queue[rear]);
}

//Queue using Linked list
struct node{
	int data;
	struct node* link;
};
struct node *front = NULL, *rear = NULL;
void enqueue(int x)
{
	struct node *tmp = malloc(sizeof(struct node));
	tmp->data = x;
	tmp->next = NULL:
	if(rear == NULL && front == NULL)
	{
		front = rear = tmp;
	}
	else
	{
		rear->next = tmp;
		rear = tmp;
	}
}
void display()
{
	struct node *tmp = front;
	if(rear == NULL && front == NULL)
	{
		printf("List is empty");
	}
	else
	{
		tmp = front;
		
		while(tmp != NULL)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
	}
}

void dequeue()
{
	struct node *tmp = front;
	if(rear == NULL && front == NULL)
	{
		printf("List is empty");
	}
	else if(front == rear)
	{
		printf("%d ", tmp->data);
		front = front-next;
		free(tmp);
		front = rear = NULL;
	}
	else
	{
		printf("%d ", tmp->data);
		front = front-next;
		free(tmp);
	}
}

void peek()
{
	if(rear == NULL && front == NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("peek = %d ", front->data);
	}
}

//circular queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int inData)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = inData;

    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        rear->link = front;   // circular link
    }
    else
    {
        rear->link = temp;
        rear = temp;
        rear->link = front;
    }
}

int dequeue()
{
    int ret;
    
    if(front == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    
    if(front == rear)
    {
        ret = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front;
        ret = temp->data;
        front = front->link;
        rear->link = front;
        free(temp);
    }

    return ret;
}

void peek()
{
	if(rear == NULL && front == NULL)
	{
		printf("List is empty");
	}
	else
	{
		printf("%d ", front->data);
	}
}

void display()
{
	
	struct node *tmp = front;
	if(rear == NULL && front == NULL)
	{
		printf("List is empty");
	}
	else
	{
		while(tmp->next != front)
		{
			printf("%d ", tmp->data);
			tmp = tmp->next;
		}
		printf("%d ", tmp->data);
	}
}

implement a Queue using two Stacks
#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;
void enqueue(int x)
{
	push(x);
	count++;
}
void dequeue()
{
	if(top1 == -1 && top2 == -1)
	{
		printf("empty")
	}
	else
	{
		for(int i = 0; i < count; i++)
		{
			int a = pop1();
			push2(a);
		}
		int b = pop2();
		printf(b);
		count--;
		for(int i = 0; i < count; i++)
		{
			int a = pop2();
			push1(a);
		}
	}
}
void push1(int data)
{
	if(top1 = N-1)
	{
		printf("Full")
	}
	else
	{
		top1++;
		s1[top1] = data;
	}
}
int pop1()
{
	int ret;
	ret = s1[top1];
	top--;
	return ret;
}

int pop2()
{
	return s2[top2++];
}

void display()
{
	
	for(i = 0; i < top1; i++)
	{
		printf(s1[i]);
	}
}

Double ended Queue Deque
//insertion and deletion allowqed from both ends

