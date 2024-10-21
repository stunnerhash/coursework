#include<stdio.h>
#include<stdlib.h>

// structure of the node in c
struct node{
    int data;
    struct node* next;
};

// create new node
struct node* create(int newdata ){
    struct node* newnode= (struct node*) malloc(sizeof(struct node));

    newnode->data=newdata;
    newnode->next=NULL;

    return newnode;
}

// create node and insert at the end
void createnodeEnd(struct node** head,int newdata){
    //struct node* newnode=create(newdata);

    struct node* newnode= (struct node*) malloc(sizeof(struct node));

    newnode->data=newdata;
    newnode->next=NULL;


    if(*head==NULL){  // head value == NULL
        *head=newnode;
        return;

    }

    struct node* temp= *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;

}

void print(struct node* head){

    struct node* temp= head;

    while(temp!=NULL){
        printf("%d -> ",temp->data);

        temp=temp->next;
    }
    printf("NULL\n");
}


struct node* insertAtBegin(struct node* head, int val){

    struct node* tmp=create(val);
    tmp->next=head;

    return tmp;
    
}


struct node* insertAtPositionK(struct node* head,int val,int pos){

    struct node* tmp=head;
    while(--(pos)){
        if(tmp==NULL){
            tmp->next=create(val);
            return head;
        }
        tmp=tmp->next;

    }
    struct node* nextNext=tmp->next->next;
    tmp->next=create(val);
    tmp->next->next=nextNext;
    return head;

}


struct node* deleteATBegining(struct node* head){
    struct node* tmp=head;
    
    head=head->next;
    tmp->next=NULL;
    free(tmp);

    return head;
}

struct node* deleteATEnd(struct node* head){

    struct node* tmp=head;

    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }

    struct node* f=tmp->next;
    tmp->next=NULL;
    free(f);

    return head;

}


struct node* deleteAtPositionK(struct node* head, int pos){

    struct node* tmp=head;
    if(pos==1){
        tmp=tmp->next;
        free(head);
        return tmp;
    }

    if(pos==2){
        if(tmp->next->next==NULL){
            tmp->next=NULL;
        }else{
            tmp->next=tmp->next->next;
        }
        return tmp;
    }

    pos=pos-1;
    while(pos>1){
        tmp=tmp->next;
        pos--;

    }


    if(tmp->next->next==NULL){
        tmp->next=NULL;
    }else{
        tmp->next=tmp->next->next;
    }
    return head;


}



struct node* reverseLL(struct node* head){
    struct node* tmp=head;
    struct node* newHead=NULL;

    while(tmp!=NULL){
        newHead= insertAtBegin(newHead,tmp->data);
        tmp=tmp->next;
    }
    return newHead;

}

void MaxMinElement(struct node* head){
    struct node* tmp=head;

    int maxi=INT_MIN;
    int mini=INT_MAX;

    while(tmp!=NULL){
        if(maxi<tmp->data){
            maxi=tmp->data;
        }

        if(mini>tmp->data){
            mini=tmp->data;
        }

        tmp=tmp->next;
    }

    printf("max:%d   min:%d",maxi,mini);
}




void main(){
 struct node* head=NULL;
 int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        createnodeEnd(&head, data);
    }

    head=insertAtBegin(head,75);

    head=insertAtPositionK(head,100,3);

    head=deleteATBegining(head);

    printf("Linked List: ");
    print(head);

    head=deleteATEnd(head);

    printf("Linked List: ");
    print(head);

    head=reverseLL(head);

    printf("Linked List: ");
    print(head);


    MaxMinElement(head);
    printf("\n");


    head=deleteAtPositionK(head,7);
    print(head);

   // printf("%d",head->data);



}