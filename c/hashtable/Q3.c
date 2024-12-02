#include<stdio.h>
#include<stdlib.h>
#define CAP 10

struct Node {
	char *key;
	struct Node *next;
};

void copyStr(char *str1, char* str2)
{
	int i=0;
	while(str1[i]!='\0'){
		str2[i]=str1[i];
		i++;
	}
	str2[i]='\0';
}

struct Node* createNode(char *key)
{
	struct Node *new=(struct Node*)malloc(sizeof(struct Node));
	new->key=(char*)malloc(sizeof(char)*20);
	copyStr(key,new->key);
	new->next=NULL;
	return new;
}

struct Node** createMap()
{
	struct Node **mp=(struct Node**)malloc(sizeof(struct Node*)*CAP);
	for(int i=0;i<CAP;i++){
		mp[i]=(struct Node*)malloc(sizeof(struct Node));
		mp[i]=NULL;
	}
	return mp;
}

int hashFunction(char *key)
{
	int i=0,sum=0;
	while(key[i]!='\0')
		sum=(sum+key[i++])%10;
	return sum;
}

int compareStr(char *str1, char *str2)
{
	int i=0;
	while(str1[i]&&str2[i]&&str1[i]==str2[i])
		i++;
	if(str1[i]=='\0'&&str2[i]=='\0')
		return 1;
	return 0;
}

void insert(struct Node **mp, char *key)
{
	int i=hashFunction(key);
	struct Node *temp=mp[i];
	if(mp[i]==NULL)
		mp[i]=createNode(key);
	else{
		while(temp->next!=NULL){
			if(compareStr(key,temp->key))
					return;
			temp=temp->next;
		}
		if(compareStr(key,temp->key))
			return;
		temp->next=createNode(key);
	}
}

void deleteMap(struct Node **mp)
{
	struct Node *temp,*d;
	for(int i=0;i<CAP;i++){
		temp=mp[i];
		while(temp!=NULL){
			d=temp;
			temp=temp->next;
			free(d->key);
			free(d);
		}
	}
	free(mp);
}

void showMap(struct Node **mp)
{
	for(int i=0;i<CAP;i++){
		printf("%d:\t",i);
		struct Node *temp=mp[i];
		while(temp!=NULL){
			printf("%s->",temp->key);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

int printUnique(struct Node **mp)
{
	int sum=0;
	for(int i=0;i<CAP;i++){
		struct Node *temp=mp[i];
		while(temp!=NULL){
			sum++;
			temp=temp->next;
		}
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	struct Node **mp=createMap();
	char *data=(char*)malloc(sizeof(data)*20);
	for(int i=0;i<n;i++){
		scanf("%s",data);
		insert(mp,data);
	}
	showMap(mp);
	printf("%d\n",printUnique(mp));
	return 0;
}
