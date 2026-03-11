ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

	ListNode *temp = malloc(sizeof(ListNode));
	ListNode *retlink = temp;
	int carry = 0;
	int sum = 0;
	while(l1 != NULL || l2 != NULL || carry)
	{
		sum = 0;
		if(l1 != NULL)
		{
			sum = l1->val;
			l1 = l1->next;
		}
		if(l2 != NULL)
		{
			sum += l2->val;
			l2 = l2->next;
		}
		
		sum = sum + carry;
		
		carry = sum/10;
		ListNode *newNode =  malloc(sizeof(ListNode));
		newNode->val = sum % 10;
		newNode->next = NULL:
		temp->next = newNode;
		temp = temp->Next;
	}
	return retlink->next;
}

swap nodes 24
ListNode* swapPairs(ListNode* head) {
	ListNode* first = NULL;
	ListNode* second = NULL;
	
	ListNode* temp = malloc(ListNode);
	temp->next = head;
	while(temp->next != NULL && temp->next->next != NULL)
	{
		first = temp->next ;
		second = temp->next->next;
		temp->next = second;
		first->next = second->next;
		second->next = first;
		temp = temp->next->next;
		
	}
	return temp->next;
}