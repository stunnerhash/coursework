#include<stdio.h>
#include<stdlib.h>
#define CAP 32		// c1 & c2 are contrained, and for 1/2 'm' should be pow of 2
			// for hash function to work
char* createMap()
{
	char *mp=(char*)malloc(sizeof(char)*CAP);
	for(int i=0;i<CAP;i++)
		mp[i]=-1;
	return mp;
}

//int hashFunction(char k,int i)
//{
//	int c1=3,c2=7;
//	int idx=(k%10+c1*i+c2*i*i)%CAP;
//	return idx;
//}

int hashFunction(char k, int i, int j)
// equivalent to h(k)+c1*i+c2*i*i; c1,c2=1/2
{
	j = (j+i)%CAP;
	return j;
}

void insert(char* mp, char k)
{
	int idx=0;
	for(int i=0;i<CAP;i++){
		idx=hashFunction(k,i,idx);
		if(mp[idx]==-1||mp[idx]==k){
			mp[idx]=k;
			return;
		}
	}
	printf("hash table FULL!\n");
}

void insertHelper(char *mp, char* str)
{
	int j=0;
	while(str[j]!='\0'){
		insert(mp,str[j]);
		j++;
	}
}

int find(char* mp,char k){
	int idx=0;
	for(int i=0;i<CAP;i++){
		idx=hashFunction(k,i,idx);
		if(mp[idx]==k)
			return idx;
		else if(mp[idx]==-1)
			return -1;
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
	for(int i=0;i<CAP;i++){
		if(mp[i]!=-1)
			printf("%c ",mp[i]);
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
	char *str=(char*)malloc(sizeof(char)*50);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		char *mp=createMap();
		insertHelper(mp,str);
//		showMap(mp);
		printUnique(mp);
		free(mp);
	}
	return 0;
}
