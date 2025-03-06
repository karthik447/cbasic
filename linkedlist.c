// #include<stdio.h>
// #define size 100
// typedef struct
// {
//     int arr[size];
//     int rear,front;
// }nodes;
// void enque(nodes *s,int value){
//     if(s->rear==size-1){
//         printf("overflow");
//     }else{
//         s->arr[++s->rear]=value;
//         if(s->front==-1){
//             s->front=0;
//         }
//     }
// }
// int deque(nodes *s){
//     if(s->front==-1 || s->front>s->rear){
//         printf("underflow");
//     }else{
//         if (s->front > s->rear) {
//             s->front = s->rear = -1;
//         }
//         return s->arr[s->front++];
//     }
// }
// int peek(nodes *s){
//     if(s->front==-1 || s->front>s->rear){
//         printf("overflow");
//     }else{
//         return s->arr[s->front];
//     }
// }
// void display(nodes *s){
//     if(s->front==-1 || s->front>s->rear){
//         printf("underflow");
//     }else{
//         for(int i=s->front;i<=s->rear;i++){
//             printf("%d --",s->arr[i]);
//         }printf("\n");
//     }
// }
// int main(){
//     nodes s;
//     s.front=s.rear=-1;
//     enque(&s,10);
//     enque(&s,20);
    
//     display(&s);
//     deque(&s);
//     printf("display after delete\n");
//     display(&s);
//     enque(&s,40);
//     enque(&s,50);
//     display(&s);
//     printf("peek value %d",peek(&s));
    
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int data;
//     struct node *next;
//     struct node *prev;
// } node;

// void insert_begin(node **head, int data) {
//     node *newnode = (node*)malloc(sizeof(node));
//     newnode->data = data;
//     newnode->next = *head;
//     newnode->prev = NULL;
    
//     if (*head != NULL) {
//         (*head)->prev = newnode;
//     }
    
//     *head = newnode;
// }

// void display(node *head) {
//     node *temp = head;
//     if (head == NULL) {
//         printf("List is empty");
//     } else {
//         while (temp != NULL) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// int main() {
//     node *head = NULL;
    
//     insert_begin(&head, 20);
//     insert_begin(&head, 10);
//     insert_begin(&head, 5);
    
//     display(head);
//     insert_begin(&head,90);
//     display(head);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct node {
//     int data;
//     struct node *next;
//     struct node *prev;
// } node;

// // Fixed: Passing head as node ** to modify the actual head in main
// void insert_begin(node **head, int data) {
//     node *newnode = (node*)malloc(sizeof(node));
//     newnode->data = data;
//     newnode->next = NULL;
//     newnode->prev = NULL;
//     if (*head == NULL) {
//         *head = newnode;
//     } else {
//         (*head)->prev = newnode;
//         newnode->next = *head;
//         *head = newnode;
//     }
// }

// // Fixed: Display function now prints before moving to next node
// void display(node *head) {
//     node *temp = head;
//     if (head == NULL) {
//         printf("List is empty\n");
//     } else {
//         while (temp != NULL) {
//             printf("%d -> ", temp->data);
//             temp = temp->next;
//         }
//         printf("NULL\n");
//     }
// }

// int main() {
//     node *head = NULL;
    
//     insert_begin(&head, 20); // Passing address of head to modify actual head
//     insert_begin(&head, 10);
//     insert_begin(&head, 5);
    
//     display(head); // Passing head directly as display expects node *
//     insert_begin(&head,90);
//     display(head);
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *top=NULL;
void push(int value){
    node *newnode=(node*)malloc(sizeof(node));
    if(!newnode){
        printf("erroe");
    }else{
        newnode->data=value;
        newnode->next=top;
        top=newnode;
    }//printf("%d value piushed",value);
}
int pop(){
    if(top==NULL){
        printf("empty");
    }else{
        node *temp=top;
        int value=temp->data;
        top=top->next;
        free(temp);
        return value;
    }
}
void peek(){
    if(top==NULL){
        printf("satck empty");
        
    }
    return top->data;
}
void display(){
    if(top==NULL){
        printf("stack empty");
    }else{
        node *temp=top;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    push(20);
    push(30);
    display();
    printf("peek value is \n");
    peek();
}