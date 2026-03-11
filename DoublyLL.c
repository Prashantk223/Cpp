struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head, *tail;

int main()
{
	Reverse_DLL();
	
	
	return 0;
}

void Reverse_DLL()
{
	struct node *cur, *next;
	cur = head;
	while(cur != NULL)
	{
		next = cur->next;
		
		cur->next = cur->prev;
		cur->prev = next;
		
		cur = next;
	}
	cur = head;
	head = tail;
	tail = head;
	
}
