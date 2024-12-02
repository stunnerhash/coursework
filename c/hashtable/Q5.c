#include<stdio.h>
#include<stdlib.h>
#define CAP 26

char* createMap()
{
	char* mp=(char*)malloc(sizeof(char)*CAP);
	for(int i=0;i<CAP;i++)
		mp[i]=0;
	return mp;
}

int hashFunction(char k)
{
	return k-'a';
}

void insert(char* mp, char k)
{
	int i=hashFunction(k);
	mp[i]++;
}

void insertHelper(char *mp, char *str)
{
	while(*str!='\0'){
		insert(mp,*str);
		str++;
	}
}

int search(char *mp, char k)
{
	int i=hashFunction(k);
	return mp[i]!=0;
}

void showMap(char *mp)
{
	for(int i=0;i<CAP;i++)
		printf("%c - %d\n",i+'a',mp[i]);
	printf("\n");
}

void printFreq(char *mp)
{
	for(int i=0;i<CAP;i++){
		if(mp[i])
			printf("%c %d ",i+'a',mp[i]);
	}
	printf("\n");
}

void deleteMap(char *mp)
{
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
	scanf("%c",&ch);	//buffer for \n
	for(int i=0;i<n;i++){
		char *mp=createMap();
		insertHelper(mp,lst[i]);
//		showMap(mp);
		printFreq(mp);
//		scanf("%c",&ch);
//		printf("%d\n",search(mp,ch));
		deleteMap(mp);
	}
	return 0;
}
