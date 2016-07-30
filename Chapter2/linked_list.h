#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
        int val;
        node *next;
};

int list_length(struct node *head) {
        struct node *temp;
        int count = 0;

        temp = head;
        while (temp) {
                count++;
                temp = temp->next;
        }
        return count;
}

void insert_node_front(struct node **head, int num) {
        struct node *temp;

        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = num;
        temp->next = NULL;
        if (! *head) {
                *head = temp;
        } else {
                temp->next = *head;
                *head = temp;
        }
}

void insert_node_back(struct node **head, int num) {
        struct node *temp, *kemp;

        temp = (struct node *)malloc(sizeof(struct node));
        temp->val = num;
        temp->next = NULL;
        if (! *head) {
                temp->val = num;
                *head = temp;
                return ;
        }
        kemp = *head;
        while (kemp->next) {
                kemp=kemp->next;
        }
        kemp->next = temp;
}

void print_list(struct node *head) {
        struct node *temp;

        temp = head;
        while (temp) {
                cout<<temp->val<<"      ";
                temp = temp->next;
        }
        cout<<"\n";
}

void free_list(struct node **head) {
        struct node *prev, *curr;

        if (! *head)
                return ;

        prev = *head;
        curr = prev->next;
        while (curr) {
                free(prev);
                prev = curr;
                curr = curr->next;
        }
}
