#include<stdio.h>
#include<stdlib.h>
#define CAP 10
struct Node {
	char key;
	int val;
	struct Node *next;
};

struct Node* createNode(char key)
{
	struct Node *new=(struct Node*)malloc(sizeof(struct Node));
	new->key=key;
	new->val=0;
	new->next=NULL;
	return new;
}

struct Node* createLL(int n)
{
	struct Node *head=NULL,*temp;
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		if(head==NULL){
			head=createNode(data);
			temp=head;
		}
		else{
			temp->next=createNode(data);
			temp=temp->next;
		}
	}
	return head;
}

int hashFunction(char key)
{
	int mod=key%CAP;
	return mod;
}

struct Node ** createMap()
{
	struct Node **mp=(struct Node**)malloc(sizeof(struct Node *)*CAP);
	for(int i=0;i<CAP;i++){
		mp[i]=(struct Node*)malloc(sizeof(struct Node));
		mp[i]=NULL;
	}
	return mp;
}

struct Node* find(struct Node **mp,char key)
{
	int i=hashFunction(key);
	struct Node *temp=mp[i];
	while(temp!=NULL && temp->key!=key)
		temp=temp->next;
	return temp;
}

void insert(struct Node **mp,char* str)
{
	int j=0;
	while(str[j]!='\0'){
		char key=str[j++];
		struct Node *temp=find(mp,key);
		if(temp)
			(temp->val)++;
		else{
			int i=hashFunction(key);
			if(!mp[i]){
				mp[i]=createNode(key);
				(mp[i]->val)++;
			}
			else{
				struct Node *new=createNode(key);
				(new->val)++;
				new->next=mp[i];
				mp[i]=new;
			}
		}
	}
}

void showMap(struct Node **mp)
{
	struct Node *temp;
	for(int i=0;i<CAP;i++){
		printf("%d:\t",i);
		temp=mp[i];
		while(temp!=NULL){
			printf("%c_%d->",temp->key,temp->val);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

void printUnique(struct Node **mp)
{
	struct Node *temp;
	for(int i=0;i<CAP;i++){
		temp=mp[i];
		while(temp!=NULL){
			printf("%c ",temp->key);
			temp=temp->next;
		}
	}
	printf("\n");
}

void delMap(struct Node **mp)
{
	struct Node *temp,*d;
	for(int i=0;i<CAP;i++){
		temp=mp[i];
		while(temp!=NULL){
			d=temp;
			temp=temp->next;
			free(d);
		}
	}
	free(mp);
}

int main()
{
	int n;
	scanf("%d",&n);
	char **arr=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++)
		arr[i]=(char*)malloc(sizeof(char)*20);
	for(int i=0;i<n;i++)
		scanf("%s",arr[i]);
	for(int i=0;i<n;i++){
		struct Node **mp=createMap();
		insert(mp,arr[i]);
		showMap(mp);
		printUnique(mp);
		delMap(mp);
	}
	return 0;
}
