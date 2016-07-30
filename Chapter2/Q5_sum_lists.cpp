#include "linked_list.h"
#include <iostream>

using namespace std;

struct node *sum_list(struct node *head1, struct node *head2) {
	struct node *t1, *t2, *head = NULL;
	int temp, carry = 0, rem, div;

	t1 = head1;
	t2 = head2;

	while (t1 && t2) {
		temp = t1->val + t2->val + carry;
		div = temp/10;
		rem = temp%10;
		insert_node_back(&head, rem);
		carry = div;
		t1 = t1->next;
		t2 = t2->next;
	}

	if (!t1 && !t2) {
		if (carry)
			insert_node_back(&head, rem);
		goto out;
	} else if (t1 && !t2) {
		while (t1) {
			temp = t1->val + carry;
			div = temp/10;
			rem = temp%10;
			insert_node_back(&head, rem);
			carry = div;
			t1 = t1->next;
		}
	} else if (!t1 && t2) {
		while (t2) {
			temp = t2->val + carry;
			div = temp/10;
			rem = temp%10;
			insert_node_back(&head, rem);
			carry = div;
			t2 = t2->next;
		}
	}
	if (carry)
		insert_node_back(&head, carry);
out :
	return head;
}

int sum_list_recur(struct node *head1, struct node *head2, struct node **head) {
	int carry = 0, rem, div, temp;


	if (!head1->next && !head2->next) {
		temp = head1->val + head2->val;
		rem = temp%10;
                div = temp/10;
                insert_node_front(head, rem);
                return div;
	} else if (head1->next && head2->next) {
		carry = sum_list_recur(head1->next, head2->next, head);
		temp = head1->val + head2->val + carry;
		rem = temp%10;
		div = temp/10;
		insert_node_front(head, rem);
		return div;
	}
	return 0;
}


int main() {
	struct node *head1 = NULL, *head2 = NULL, *head3;
	int carry = 0;
	int len1, len2, diff, i = 1;

	insert_node_back(&head1, 9);
	insert_node_back(&head1, 9);
	insert_node_back(&head1, 9);

	insert_node_back(&head2, 9);
	insert_node_back(&head2, 9);
	insert_node_back(&head2, 9);


	len1 = list_length(head1);
	len2 = list_length(head2);

	if (len1 < len2) {
		diff = len2 - len1;
		while (i <= diff) {
			insert_node_front(&head1, 0);
			i++;
		}
	} else if (len2 < len1) {
		diff = len1 - len2;
		while (i <= diff) {
                        insert_node_front(&head2, 0);
                        i++;
                }
	}
	print_list(head1);
	print_list(head2);
	carry = sum_list_recur(head1, head2, &head3);
	if (carry)
		insert_node_front(&head3, carry);
	print_list(head3);
return 0;
}
