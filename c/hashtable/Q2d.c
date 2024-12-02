#include<stdio.h>
#include<stdlib.h>
#define CAP 26

char* createMap()
{
	char *mp=(char*)malloc(sizeof(char)*CAP);
	for(int i=0;i<CAP;i++)
		mp[i]=-1;
	return mp;
}

int hashFunction(char key,int i)
{
	int m=10;
	int idx=(key%m + i)%CAP;
	return idx;
}

void insert(char *mp, char key)
{
	for(int i=0;i<CAP;i++){
		int idx=hashFunction(key,i);
		if(mp[idx]==-1 || mp[idx]==key){
			mp[idx]=key;
			return;
		}
	}
	printf("Table FULL!!!\n");
}

void insertHelper(char *mp, char *str)
{
	int j=0;
	while(str[j]!='\0'){
		insert(mp,str[j]);
		j++;
	}
}

int find(char *mp, char key)
{
	for(int i=0;i<CAP;i++){
		int idx=hashFunction(key,i);
		if(mp[idx]==key)
			return idx;
		else if(mp[idx]==-1)
			return -1;
	}
	return -1;
}

void showMap(char *mp){
	for(int i=0;i<CAP;i++)
		printf("%d - %c\n",i,mp[i]);
}

void printUnique(char *mp){
	for(int i=0;i<CAP;i++){
		if(mp[i]>0)
			printf("%c ",mp[i]);
	}
	printf("\n");
}

void delMap(char *mp){
	free(mp);
}

int main()
{
	int n;
	scanf("%d",&n);
	char *str=(char*)malloc(sizeof(char)*30);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		char *mp=createMap();
		insertHelper(mp,str);
//		showMap(mp);
		printUnique(mp);
		delMap(mp);
	}
	return 0;
}
