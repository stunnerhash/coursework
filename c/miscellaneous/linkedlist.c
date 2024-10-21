#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert(int val,struct Node* head){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return head;
    }
    struct Node* tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newnode;
    return head;
}

void print(struct Node* head){
    struct Node* tmp=head;
    while(tmp!=NULL){
        printf("%d->",tmp->data);
        tmp=tmp->next;
    }
    printf("NULL\n");
}

int gcd(int a, int b){
    if(a>b){
        int tmp=a;
        a=b;
        b=tmp;
    }

    for(int i=2;i<=a;i++){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

int main(){
    struct Node* head=NULL;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        head=insert(a,head);
    }


    struct Node* cur=head;
    struct Node* f=NULL;
    struct Node* fl=NULL;


    while(cur->next!=NULL){

        f=cur;
        fl=cur->next;
        while(fl!=NULL){

            //gcd check
            int a=gcd(cur->data,fl->data);
            printf("%d  %d\n",cur->data,fl->data);
            printf("%d\n",a);
            int t=0;
            if(a>1){
                cur->data=a;
                f->next=fl->next;
                f=f;
                t=1;
                printf("%d\n",f->data);
            }
            
            fl=fl->next;
            if(t==0){
                f=f->next;
            }

        }
        cur=cur->next;
        if(cur==NULL){
            break;
        }

    }



    printf("%d\n",head->data);
    print(head);

    free(head);



    return 0;
}