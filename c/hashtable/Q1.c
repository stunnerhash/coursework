#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *friend;
};

struct Node* createNode(int data)
{
	struct Node *new=(struct Node*)malloc(sizeof(struct Node));
	new->data=data;
	new->next=NULL;
	new->friend=NULL;
	return new;
}

struct Node* createLL(int n)
{
	struct Node *head=createNode(0),*temp=head;
	for(int i=1;i<n;i++){
		temp->next=createNode(0);
		temp=temp->next;
	}
	int data,friend,count=1;
	struct Node *t=head;
	temp=head;
	while(temp!=NULL){
		t=head;
		count=1;
		scanf("%d%d",&data,&friend);
		temp->data=data;
		while(t!=NULL && count<friend){
			t=t->next;
			count++;
		}
		temp->friend=t;
		temp=temp->next;
	}
	return head;
}

void showLL(struct Node *head)
{
	while(head!=NULL){
		printf("%d_%d->",head->data,head->friend->data);
		head=head->next;
	}
	printf("NULL\n");
}

int main()
{
	int n;
	scanf("%d",&n);
	struct Node *head=createLL(n);
	showLL(head);
	return 0;
}
