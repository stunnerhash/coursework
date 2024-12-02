#include<stdio.h>
#include<stdlib.h>
#define CAP 10

char* createMap()
{
	char *mp=(char*)malloc(sizeof(char)*CAP);
	for(int i=0;i<CAP;i++)
		mp[i]=-1;
	return mp;
}

int hashFunction(char k, int i)
{
	int idx=(k%3+i)%CAP;
	return idx;
}

void insert(char *mp, char k)
{
	for(int i=0;i<CAP;i++){
		int idx=hashFunction(k,i);
		if(mp[idx]==-1 || mp[idx]==k){
			mp[idx]=k;
			return;
		}
	}
	printf("hash table FULL!!!\n");
}

void insertHelper(char *mp, char *str)
{
	while(*str!='\0'){
		switch(*str){
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'A': case 'E': case 'I': case 'O': case 'U':
				insert(mp,*str);
		}
		str++;
	}
}

int search(char *mp, char k)
{
	for(int i=0;i<CAP;i++){
		int idx=hashFunction(k,i);
		if(mp[idx]==k || mp[idx]==-1)
			return idx;
	}
	return -1;
}

void showMap(char *mp)
{
	for(int i=0;i<CAP;i++)
		printf("%d - %c\n",i,mp[i]);
}

void printUnique(char *mp)
{
	int printed=0;
	for(int i=0;i<CAP;i++){
		if(mp[i]!=-1){
			printf("%c ",mp[i]);
			printed=1;
		}
	}
	if(!printed)
		printf("none");
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
	scanf("%c",&ch);		//buffer for \n
	for(int i=0;i<n;i++){
		char *mp=createMap();
		insertHelper(mp,lst[i]);
//		showMap(mp);
		printUnique(mp);
//		scanf("%c",&ch);
//		printf("%d\n",search(mp,ch));
		deleteMap(mp);
	}
	return 0;
}
