#include<stdio.h>
#include<stdlib.h>

int* createMap()
{
	int *mp=(int*)malloc(sizeof(int)*26);
	for(int i=0;i<26;i++)
		mp[i]=0;
	return mp;
}

void insertMap(int *mp, char *str)
{
	for(int i=0;str[i]!='\0';i++)
		mp[str[i]-'a']++;
}

void showMap(int *mp){
	for(int i=0;i<26;i++)
		printf("%c - %d\n",i+'a',mp[i]);
}

void printUnique(int *mp){
	for(int i=0;i<26;i++){
		if(mp[i])
			printf("%c ",i+'a');
	}
	printf("\n");
}

void deleteMap(int *mp){
	free(mp);
}

int main()
{
	int n;
	scanf("%d",&n);
	char *str=(char*)malloc(sizeof(char)*30);
	for(int i=0;i<n;i++){
		int *mp=createMap();
		scanf("%s",str);
		insertMap(mp,str);
		printUnique(mp);
		deleteMap(mp);
	}
	return 0;
}
