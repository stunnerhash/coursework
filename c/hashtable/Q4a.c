#include<stdio.h>
#include<stdlib.h>
#define CAP 3

struct Node{
	char k;
	struct Node *next;
};

struct Node *createNode(char k)
{
	struct Node *new=(struct Node*)malloc(sizeof(struct Node));
	new->k=k;
	new->next=NULL;
	return new;
}

struct Node **createMap()
{
	struct Node **mp=(struct Node**)malloc(sizeof(struct Node*)*CAP);
	for(int i=0;i<CAP;i++){
//		mp[i]=(struct Node*)malloc(sizeof(struct Node));
		mp[i]=NULL;
	}
	return mp;
}

int hashFunction(char k)
{
	return k%CAP;
}

void insertMap(struct Node **mp, char k)
{
	int i=hashFunction(k);
	if(mp[i]==NULL)
		mp[i]=createNode(k);
	else{
		struct Node *temp=mp[i];
		while(temp->next!=NULL){
			if(temp->k==k)
				return;
			else
				temp=temp->next;
		}
		if(temp->k!=k)
			temp->next=createNode(k);
	}
}

void insertHelper(struct Node **mp, char *str)
{
	while(*str!='\0'){
		switch(*str){
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'A': case 'E': case 'I': case 'O': case 'U':
				insertMap(mp,*str);
		}
		str++;
	}
}

int searchMap(struct Node **mp, char k)
{
	int i=hashFunction(k);
	struct Node *temp=mp[i];
	while(temp!=NULL){
		if(temp->k==k)
			return i;
		temp=temp->next;
	}
	return -1;
}

void showMap(struct Node **mp)
{
	for(int i=0;i<CAP;i++){
		printf("%d:\t",i);
		struct Node *temp=mp[i];
		while(temp!=NULL){
			printf("%c->",temp->k);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

void printUnique(struct Node **mp)
{
	int printed=0;
	for(int i=0;i<CAP;i++){
		struct Node *temp=mp[i];
		while(temp!=NULL){
			printf("%c ",temp->k);
			temp=temp->next;
			printed=1;
		}
	}
	if(!printed)
		printf("none");
}

void deleteMap(struct Node **mp)
{
	for(int i=0;i<CAP;i++){
		struct Node *temp=mp[i],*d=NULL;
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
	char **lst=(char**)malloc(sizeof(char*)*n);
	for(int i=0;i<n;i++){
		lst[i]=(char*)malloc(sizeof(char)*30);
		scanf("%s",lst[i]);
	}
	char ch;
	scanf("%c",&ch);			//for \n buffer
	for(int i=0;i<n;i++){
//		printf("\n%s\n",lst[i]);
		struct Node **mp=createMap();
		insertHelper(mp,lst[i]);
//		showMap(mp);
		printUnique(mp);
//		scanf("%c",&ch);
//		printf("%d",searchMap(mp,ch));
		deleteMap(mp);
		printf("\n");
	}
	return 0;
}

