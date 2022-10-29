/*

A group of soldiers are surrounded by an overwhelming group of enemy forces. There
is no hope for victory without reinforcement, but there is a single horse available for
escape. The soldiers agree to a pact to determine which one of them is to escape and
summon help. They stand in a circle and each one chooses a positive integer. One of
their names and a positive integer ‘n’ are chosen. Starting with the person whose name
is chosen, they count around the circle clockwise and eliminate the nth person. The
positive integer which that person chose is then used to continue the count, but this time
in the anticlockwise direction. Each time that a person is eliminated, the number the
person chose is used to determine the next person to be eliminated and the direction of
traversal is opposite to that of the previous one. i.e. the counting alternates between
clockwise and anti-clockwise direction.
For example, suppose that the 5 soldiers are A, B, C, D, and E. They chose integers
4,5,6,7, and 8 respectively. The name C and integer 2 are initially chosen. Then the
order in which the soldiers are eliminated from the circle is D, A, B, and E leaving C
as the last one and C will be signalled to escape.
Write a program in C for the above problem and analyse the time complexity. Make
use of circular doubly linked list

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	int idx;
	char name;
	struct Node *next;
	struct Node * prev;

}node;
int len=0;
node * head=NULL;
node * last;
node* createNode(int data,char name){
	node* new=(node*)malloc(sizeof(node));
	new->next=new;
	new->prev=new;
	new->data=data;
	new->name=name;
	new->idx=len;
	return new;
}

void append(int data,char name){
	node * tmp=createNode(data,name);
	if (head==NULL){
		head=tmp;
		last=head;
		return;
	}
	node* t1=head;
	while(t1->next!=head){
		t1=t1->next;
	}
	t1->next=tmp;
	tmp->next=head;
	head->prev=tmp;
	tmp->prev=last;
	last=tmp;
	len++;

}

void print(){
node * tp=head;
do{
	printf("%c %d\n",tp->name,tp->data );
	tp=tp->next;

}while(tp->next!=head->next);

}

void print_rev(){
	node* tp=last;
	do{
	printf("%d\n",tp->data );
	tp=tp->prev;

}while(tp!=head->prev);


}


int delete(int idx){
	node* tmp=head;
	int num;
	if (idx==0){
		head=tmp->next;
		head->prev=last;
		last->next=head;
		num=head->data;
		return num;
	}
	for (int i=0;i<idx-1;i++){
		tmp=tmp->next;

	}
	tmp->next=tmp->next->next;
	tmp->next->prev=tmp;
	num=tmp->data;
	return num;

}

int main(){

	append(4,'A');
	append(5,'B');
	append(6,'C');
	append(7,'D');
	append(8,'E');
	int k=delete(3);
	node * ptr=head;
	ptr=ptr->next->next;
	for(int i=0;i<4;i++){
		print();
		printf("====\n");
		if(i%2==0){
			node* tmp=ptr;
			int m;
			for( m=0;m<k;m++){
				tmp=tmp->prev;

			}
			ptr=tmp->prev;
			k=delete(tmp->idx);

		}
		else{
			node* t1=ptr;
			int j;
			for(j=0;j<k;j++){
				t1=t1->next;
			}
			ptr=t1->next;
			k=delete(t1->idx);
		}

	}
	

}