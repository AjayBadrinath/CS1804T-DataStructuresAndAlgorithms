#include <stdio.h>
#include <stdlib.h>
typedef struct  Node
{
	int data;
	struct Node * next;

}node;

node* head=NULL;

void delete(node*head,int idx){
	node*last=head;
	for(int i=0;i<idx-3;i++){
	last=last->next;

	}
	last->next=last->next->next;

}

void append(node*head,int data){
	node*temp=(node*)malloc(sizeof(node));
	node *last=head;
	temp->data=data;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return;
	}
	while (last->next!=NULL){
		last=last->next;
	}
	last->next=temp;


}


void print(node*head){
	/*
	node*last=head;
	while(last!=NULL){
		printf("%d\n",last->data);
		last=last->next;
	}
*/
	printf("%d\n",head->data);
	if(head->next!=NULL){
		print(head->next);
		}
	return ;
}
int search(node*head,int data){
	int i=0;
	node*last=head;
	while(last!=NULL){
		if (last->data==data){
			return i;
			break;
		}
		last=last->next;
		i++;
	}
	return -1;
}

void insert(node*head, int data,int idx){

node* temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;
node *last=head;
for(int i=0;i<idx-2;i++){
	last=last->next;

}
temp->next=last->next;
last->next=temp;


}


int main(){
node*head=(node*)malloc(sizeof(node));

/*
append(head,3);
insert(head,122,1);
delete(head,1);
print(head);
printf("%d\n",search(head,122));
*/
int i,headval;
printf("Enter head val");
scanf("%d",&headval);
printf("\n");
head->data=headval;
head->next=NULL;
while(1==1){
	printf("\n1.append\n2.insert\n3.Deletion\n4.Search\n5.Display\n");
	scanf("%d",&i);
	if(i==1){
		int data;
		printf("Enter element to append");
		scanf("%d",&data);
		append(head,data);


	}
	else if(i==2){
		int data,pos;
		printf("Enter element to insert");
		scanf("%d",&data);
		printf("Enter index ");
		scanf("%d",&pos);
		insert(head,data,pos);

	}
	else if(i==3){
		int idx;
		printf("Enter index to delete");
		scanf("%d",&idx);
		delete(head,idx);
	}
	else if(i==4){
		int data;
		printf("Enter element to search ");
		scanf("%d",&data);
		int pos=search(head,data);
		if(pos!=-1){
			printf("element in %d\n" ,pos);
		}
		else{
			printf("Element  not found");
		}
	}
	else{
		print(head);
		
	}
	

}
}
