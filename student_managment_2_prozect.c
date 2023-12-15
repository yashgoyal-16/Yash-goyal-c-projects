#include <stdio.h>
#include <stdlib.h>
struct Node{
int data ;
 struct Node * next ;
};
void printelements(struct Node *ptr){
while(ptr != NULL){
    printf("Value is %d\n",ptr->data);
    ptr = ptr->next;
}
}
struct Node* insetatfirst(struct Node *head,int data){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node *));
ptr->next = head;
ptr->data= data;
return ptr;
 }
struct Node* insetatLast(struct Node *head,int data){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node *));
ptr->data = data;
struct  Node *p= head;
while(p->next!=NULL){
   p= p->next;
   }
    p->next=ptr;
    ptr->next= NULL;
    return head;
 }
struct Node* insertafterNode(struct Node*head,struct Node* prevNode , int data){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node *));
ptr->data = data;
ptr->next = prevNode->next;
prevNode->next = ptr;
return head;
};
struct Node *insertatindex(struct Node*head , int data,int index){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node *));
struct Node *p = head;
int i = 0;
while(i!=index-1){
    p = p->next;
    i++;
}
ptr->data=data;
ptr->next=p->next;
p->next = ptr;
return head;
};
struct Node *deletefirstElement(struct Node*head){
struct Node *ptr = (struct Node*)malloc(sizeof(struct Node *));
ptr = head;
head = head->next ;
free(ptr);
return head;
};

struct Node *deleteatIndex(struct Node*head,int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for(int i = 0;i<index-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
    }
struct Node *deletelast(struct Node*head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
    }
struct Node *deletewithValue(struct Node*head,int data){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=data && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(head->data==data){
    p->next = q->next;
    free(q);
    }
    return head;
    }
int main(){
struct Node *head;
struct Node *second;
struct Node*third;
struct Node*fourth;

head = (struct Node *)malloc(sizeof(struct Node));
second = (struct Node *)malloc(sizeof(struct Node));
third = (struct Node *)malloc(sizeof(struct Node));
fourth = (struct Node *)malloc(sizeof(struct Node));
head->data = 7;
head->next = second;
second->data = 15;
second->next = third;
third->data = 45;
third->next = fourth;
fourth->data=452;
fourth->next= NULL;
insetatLast(head,741258963);
head=insertafterNode(head,third,77400);

printelements(head);
printf("Deleting first Element\n");

head = deletefirstElement(head);
printelements(head);
printf("Deleting with index\n");
head = deleteatIndex(head,2);
printelements(head);
printf("Deleting last element\n");
head = deletelast(head);
printelements(head);
printf("Deleting with Value\n");
head = deletewithValue(head,15);
printelements(head);
return 0;
}
