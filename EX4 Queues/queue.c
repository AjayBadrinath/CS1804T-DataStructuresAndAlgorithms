/*implement queue datastructure*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;

}node;
node* head=NULL;
node* last;
node* createNode(int data){
	node* new=(node*)malloc(sizeof(node));
	new->data=data;
	new->next=NULL;
	return new;
}
void enqueue(int data){
node* new=createNode(data);
if (head==NULL){
	head=new;
	last=head;
	return;
}
node* tmp=head;
while(tmp->next!=NULL){
	tmp=tmp->next;
}
tmp->next=new;
last=new;

}
int dequeue(){
	if (head==NULL){
		printf("ERROR DEQUE \n");
		return -1;
	}
	int data;
	if (last==head){
		data=head->data;
		head=NULL;
		last=NULL;
		return data;
	}
	data=head->data;
	head=head->next;
	return data;
}
void peek(){
	if (head==NULL){
		printf("No elements in queue\n");
	}
	printf("%d\n",head->data);
}
void print(){
	node* tmp=head;
	while(tmp!=NULL){
		printf("%d\n",tmp->data);
		tmp=tmp->next;
	}
}
int main(){
enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
print();
printf("==\n");
dequeue();
dequeue();
dequeue();
dequeue();
dequeue();
print();
}