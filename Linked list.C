#include <libc.h>

typedef struct node
{
	int data;
	node *next;
} node;

node *create_node(int data)
{
	node *new_node = (node *)malloc(sizeof(node));
	if (!new_node)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void add_node(node *head, int data)
{
	node *tmp = head;
	node *new_node = create_node(data);
	if (!new_node)
		return;
	head->next = new_node;
}

void push_node(node **head, int data)
{
	node **tmp = head;
	node *new_node = create_node(data);
	if (!new_node)
		return;
	new_node->next = *head;
	*head = new_node;
}

void increment(node *a)
{
	a->data+=1;
}


int main(int argc, char *argv[])
{
	node box3 = {.data=3,.next=NULL};
	node box2 = {.data=2,.next=&box3};
	node box = {.data=1,.next=&box2};
	increment(&box);
	printf("%d",box.data);
	return 0;
}
