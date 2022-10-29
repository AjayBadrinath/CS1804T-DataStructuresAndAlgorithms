/*
Linked List  implementation of Lists 

Operations:
	1.Insertion
	2.Deletion
	3.Search
	4.Display
Done in 43:33:22
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}node;
node* head=NULL;
node* Create_Node(int data){
	node*tmp=(node*)malloc(sizeof(node));
	tmp->next=NULL;
	tmp->data=data;
	return tmp;
}
void append(int data){

	if (head==NULL){
		head=Create_Node(data);
		return;
	}
	node* tmp=head;
	while(tmp->next!=NULL)tmp=tmp->next;
	tmp->next=Create_Node(data);

}
void insert(int idx,int data){
	node* tmp=head;
	for(int i=0;i<idx-1;i++){
		tmp=tmp->next;
	}
	node* next=tmp->next;
	tmp->next=Create_Node(data);
	tmp->next->next=next;
}
void delete(int idx){
	node* tmp=head;
	for (int i=0;i<idx-1;i++){
		tmp=tmp->next;
	}
	tmp->next=tmp->next->next;
}
void search(int val){
	node* tmp=head;
	int i=0;
	while(tmp->next!=NULL){
		if(tmp->data==val){
			printf("FOUND at %d\n",i);
			return;
		}
		tmp=tmp->next;
		i++;
	}
	printf("NOT FOUND\n");
}
void print(node* head){
	if (head==NULL){
		printf("No Elements to print\n");
		return;
	}
	node* tmp=head;
	while(tmp!=NULL){
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}
}


int main(){
	append(3);
	append(4);
	append(5);
	append(535);

	append(53);
	insert(2,54);
	
	print(head);
	printf("===\n");
	delete(1);
	print(head);
	search(5);

}