#include<stdio.h>
#include<string.h>
#define loop(i,n) for (int i = 0;i<n;i++)

int isPalindrome(char c[]){
  int len = strlen(c);
  for(int i = 0;i<(len+1)/2;i++){
    if(c[i] != c[len-i-1]) return 0;
  }
  return 1;
}

int main(){
  int n; 
  scanf("%d", &n);
  char c[n][50];
  loop(i,n) scanf("%s",&c[i]);
  loop(i,n) printf(isPalindrome(c[i])?"yes\n":"no\n") ;
  return 0;
}
