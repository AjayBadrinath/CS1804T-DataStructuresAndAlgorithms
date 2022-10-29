#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
	int pt;
	char name;
	int prev;
	struct Node* next;

}node;
node* head=NULL;
node * last;
node* createNode(char name){
	node* new=(node*)malloc(sizeof(node));
	new->name=name;
	new->pt=0;
	new->prev=-1;
	new->next=new;
	return new;

}
int gen_rand(){
	
	srand(time(0));
	return rand()%6;

}

void append(char name){
	node* tmp=createNode(name);
	if(head==NULL){
		head=tmp;
		last=head;
		return;

	}
	node* t= head;
	while(t->next!=head){
		t=t->next;

	}
	
	t->next=tmp;
	tmp->next=head;
	last=tmp;
}
void delete(node* nodes){
	if (nodes==head){
		head=nodes->next;
		last->next=head;
		return;
	}	
	node* tmps=head;
	while(tmps->next!=nodes){
		tmps=tmps->next;
	}
	tmps->next=tmps->next->next;


}
void print(){
	node* t1=head;
	do{
		printf("%c %d\n",t1->name,t1->pt );
		t1=t1->next;
	}while(t1->next!=head->next);
}
int main()
{
	/*
	printf("%d\n",gen_rand() );
	append('A');
	append('B');
	append('C');
	print();	
	printf("==\n");
	node* tmp= head;
	delete(tmp->next);
	print();
	return 0;
	*/
	append('A');
	append('B');
	append('C');

	node * ptr=head;
	while (1){
		int roll=gen_rand();
		
		int ptss=ptr->pt;
		if (ptss==50){
			break;
		}
		else{
		if (roll==1){
			int roll1=gen_rand();
			if (roll1==1)
			{
				node* new=ptr->next;
				delete(ptr);
				ptr=new;
			}
		}
		else{
			int pts=ptr->pt;
			pts+=roll;
			ptr->pt=pts;
			
			ptr=ptr->next;
		}}
		printf("==\n");
		print();
		
		/*
		same stuff works either ways  [:)]
		int pts=ptr->pt;
		if(pts==50){
			break;
		}
		if (roll==1){
			pts+=1;
			ptr->pt=pts;
			int rolls=gen_rand();
			if(roll==1){
				node* t=ptr->next;
				delete(ptr);
				ptr=t;
			}
			else{
				pts+=rolls;
				ptr=ptr->next;
			}
			print();
		}
		else{
			pts+=roll;
			ptr->pt=pts;
			ptr=ptr->next;
			print();
		}

		//print();
		*/
	}

}