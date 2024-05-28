#include<stdio.h>
#include<stdlib.h>
 
 struct node{
   int data;
   struct node*next;
 };

 //transverse and print value
 void linkedlisttranversal(struct node* ptr){
    while(ptr!=NULL){
        printf("Element= %d \n",ptr->data);
        ptr=ptr->next;
    }
 } 

 //insertion at first position
 struct node * insertionfirst(struct node * head,int Data){
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=Data;
    return ptr;
 }

 //insertion at index
 struct node * insertionatindex(struct node *head,int Data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;

    while(i=index-1){
        p=p->next;
        i++;
    }
    ptr->data=Data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
 }

 //insertion at end
 struct node * insertionatend(struct node *head,int Data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=Data;
    struct node *p=head;
    while(p!=NULL){
        p=p->next;
        p++;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
 }

 //insertion after a node
 struct node * insertionafternode(struct node * head,struct node * prenode,int Data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data= Data;
    ptr->next=prenode->next;
    prenode->next=ptr;
    return head;
 }

 //Deleting the first element from the linked list
 struct node * deleteFirst(struct node * head){
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
 }

 //Deleting the element at a given index from the linked list
 struct node * deleteAtIndex(struct node * head, int index){
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
 }

 // Deleting the last element
 struct node * deleteAtLast(struct node * head){
    struct node *p = head;
    struct node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
 }

 //Deleting the element with a given value from the linked list
 struct node * deleteByValue(struct node * head, int value){
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
 }

 struct node* searchNode(struct node* head, int key) {
    struct node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == key) {
            return ptr;// Node found
        }
        ptr = ptr->next;
    }
    return NULL; // Node not found
}

 int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    // allocate memory for nodes in the linked list in the heap
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node)); 
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node)); 

    //link first and second nodes
    head->data=7;
    head->next=second;

    //link second and third nodes
    second->data=11;
    second->next=third;

    //link second and third nodes
    third->data=66;
    third->next=fourth;
    
    //link third and fourth nodes
    fourth->data=56;
    fourth->next=NULL;

    //linkedlisttranversal(head);
    //head=insertionfirst(head,66);
    //head=insertionatindex(head,56,1);
    //head=insertionatend(head,56);
    //head=insertionafternode(head,second,45);
    //head=deleteFirst(head);
    //head=deleteAtIndex(head, 2);
    //head=deleteAtLast(head);
    //head=deleteByValue(head,11);
    int key= 11;
    struct node* result = searchNode(head, key);
    if (result != NULL) {
        printf("Node with data %d found.\n", key);
    } else {
        printf("Node with data %d not found.\n", key);
    }
    linkedlisttranversal(head);

    return 0;
 }
