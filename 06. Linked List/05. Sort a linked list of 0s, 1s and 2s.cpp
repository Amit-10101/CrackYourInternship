void sortLinkedList(ListNode* head) {
	vector<int> count(3, 0);

	ListNode* dummy = head;
	while (dummy != NULL) {
		count[dummy->val]++;
		dummy = dummy->next;
	}

	dummy = head;
	int i = 0;
	while (dummy != NULL) {
		if (count[i] != 0) {
			dummy->val = i;
			count[i]--;
			dummy = dummy->next;
		} else {
			i++;
		}
	}
}