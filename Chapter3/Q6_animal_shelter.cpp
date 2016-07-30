#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct node {
	int type; /*cat or dog*/
	int timer;
	struct node *next; /*pointing to next node*/
}*cat_head, *cat_last, *dog_head, *dog_last;

int curr_time = 0;

struct node *allocate_node() {
	struct node *temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
}

void free_node(struct node *temp) {
	free(temp);
}

void enqueue(int type) {
	struct node *temp;

	temp = allocate_node();
	temp->type = type;
	if (type == 1) { /*cat*/
		curr_time++;
		temp->timer = curr_time;
		if (!cat_head)
			cat_head = cat_last = temp;
		else {
			cat_last->next = temp;
			cat_last = temp;
		}
	} else if (type == 2) { /*dog*/
		curr_time++;
		temp->timer = curr_time;
		if (!dog_head)
			dog_head = dog_last = temp;
		else {
			dog_last->next = temp;
			dog_last = temp;
		}
	}
}

void dequeueAny() {
	struct node *temp;

	if (cat_head && dog_head) {
		if (cat_head->timer < dog_head->timer) {
			temp = cat_head;
			cat_head = cat_head->next;
		} else {
			temp = dog_head;
                        dog_head = dog_head->next;
		}
		free(temp);
	} else if (cat_head) {
		temp = cat_head;
		cat_head = cat_head->next;
		free(temp);
	} else if (dog_head) {
		temp = dog_head;
		dog_head = dog_head->next;
		free(temp);	
	} else
		cout<<"Queue is empty\n";
}

void dequeueCat() {
	struct node *temp;

	if (cat_head) {
                temp = cat_head;
                cat_head = cat_head->next;
                free(temp);
	} else
		cout<<"Cat Queue is empty\n";
}

void dequeueDog() {
        struct node *temp;

        if (dog_head) {
                temp = dog_head;
                dog_head = dog_head->next;
                free(temp);
        } else
                cout<<"Dog Queue is empty\n";
}


int main() {

	enqueue(1);
	enqueue(2);
	enqueue(1);
	enqueue(2);
	enqueue(1);
	enqueue(2);
	dequeueCat();
	dequeueCat();
	dequeueCat();
	dequeueCat();
	dequeueAny();
	dequeueAny();
	dequeueAny();
	dequeueAny();
return 0;
}
