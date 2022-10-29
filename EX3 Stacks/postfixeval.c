/*
Write a C program to evaluate a postfix expression using linked list implementation of stack data structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node * next;
}node;
int tos=-1;
node* head=NULL;
node* top;
node* Create_Node(char data){
	node * tmp=(node* )malloc(sizeof(node));
	tmp->next=NULL;
	tmp->data=data;
	return tmp;
}
void push(char data)
{
	if(head==NULL){
		head=Create_Node(data);
		return;
	}
	node*tmp=head;
	while(tmp->next!=NULL)tmp=tmp->next;
	top=Create_Node(data);
	tmp->next=top;
	
}
int  pop(){
	node* tmp=head;
	int dt=top->data;
	if(top==head){
		top=NULL;
		head=NULL;
		return dt;
	}
	while(tmp->next!=top){
		tmp=tmp->next;
	}
	 
	tmp->next=NULL;
	top=tmp;
	return dt;
}
int is_operator(char s){
	for(int i='0';i<='9';i++){
		if(i==s){
			return 1;
			break;
		}
	}
	return 0;
}
int main(){

char exp[]="234*3-+";
int o1,o2;
for (int i=0;i<strlen(exp);i++){
	if(is_operator(exp[i])==1){
		push(exp[i]-'0');

	}
	else{
		 o1=pop();
		 o2=pop();
		switch(exp[i])
		{
			case '+':
				push(o1+o2);
				break;
			case '-':
				push(o1-o2);
				break;
			case '*':
				push(o1*o2);
				break;
			case '/':
				push(o1/o2);
				break;
		}
		o1=0;
		o2=0;
	}
}
printf("%d",head->data);

	
}

