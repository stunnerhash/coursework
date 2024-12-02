#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAP 7

char** createMap()
{
	char** mp=(char**)malloc(sizeof(char*)*CAP);
	for(int i=0;i<CAP;i++){
		mp[i]=(char*)malloc(sizeof(char)*20);
		mp[i][0]=-1;
	}
	return mp;
}

int hash(char *key,int i)
{
	int m1=CAP,m2=m1-1,k=0,j=0;
	while(key[j]!='\0')
		k+=key[j++];
	int h1=k%m1;
	int h2=1+(k%m2);	// this will generate between 1 to CAP, 0 is skipped
	return (h1+i*h2)%m1;	// 0 will not be able to update h1, resulting in error
}

void insertKey(char** mp,char *key)
{
	for(int i=0;i<CAP;i++){
		int idx=hash(key,i);
		if(mp[idx][0]<0){
			strcpy(mp[idx],key);
			return;
		}
	}
	printf("TABLE FULL!!!\n");
}

int searchKey(char** mp,char *key)
{
	for(int i=0;i<CAP;i++){
		int idx=hash(key,i);
		if(mp[idx][0]==-1){
			printf("Key Not Found!\n");
			return -1;
		}
		else{
			if(strcmp(mp[idx],key)==0)
				return idx;
		}
	}
	return -1;
}

void removeKey(char **mp, char *key)
{
	int idx=searchKey(mp,key);
	if(idx==-1)
		printf("Key Not Found!\n");
	else
		mp[idx][0]=-2;
}

void printMap(char** mp)
{
	for(int i=0;i<CAP;i++)
		printf("%2d -> %s\n",i,mp[i]);
}

void deleteMap(char** mp)
{
	for(int i=0;i<CAP;i++)
		free(mp[i]);
	free(mp);
}

int main()
{
	char** mp=createMap();
	char* name=(char*)malloc(sizeof(char)*20);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",name);
		insertKey(mp,name);
	}
	printMap(mp);
	scanf("%s",name);
	printf("%d\n",searchKey(mp,name));
	for(int i=0;i<4;i++){
		scanf("%s",name);
		removeKey(mp,name);
	}
	printMap(mp);
	scanf("%s",name);
	insertKey(mp,name);
	printMap(mp);
	scanf("%s",name);
	printf("%d\n",searchKey(mp,name));
	return 0;
}
