
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}node;

node** adjlist;


node* Create_Node(int data){
	node*tmp=(node*)malloc(sizeof(node));
	tmp->next=NULL;
	tmp->data=data;
	return tmp;
}

node* append(node*head,int data){

	if (head==NULL){
		head=Create_Node(data);
		return head;
	}
	node* tmp=head;
	while(tmp->next!=NULL)tmp=tmp->next;
	tmp->next=Create_Node(data);
	return tmp;

}

void printList(node* head){
	if (head==NULL){
		printf("No Elements to print\n");
		return;
	}
	node* tmp=head;
	while(tmp!=NULL){
		printf("%d\t",tmp->data);
		tmp=tmp->next;
	}
}

node** add_edge(int e1,int e2){
	
	if(adjlist[e1]==NULL){
		adjlist[e1]=append(adjlist[e1],e2);
		append(adjlist[e2],e1);
		return adjlist;
	}
	if (adjlist[e2]==NULL)
	{
		adjlist[e2]=append(adjlist[e2],e1);
		append(adjlist[e1],e2);
		return adjlist;
	}
	adjlist[e1]=append(adjlist[e1],e2);
	adjlist[e2]=append(adjlist[e2],e1);
	return adjlist;
}

int tos=-1;

int* set_stk(int bytes){
	int* stk=(int*)malloc(sizeof(stk)*bytes);
	return stk;
}

void push(int* stk,int data){
	*(stk+(++tos))=data;

}

int pop(int* stk){
	if(tos==-1){
		printf("Stack empty");
		return -1;
	}
	return *(stk+(tos--));

}

int peek(int* stk){
	return *(stk+tos);
}

void print(int* stk){
	for (int i= tos;i>=0;i--){
		printf("%d\n", *(stk+i));
	}
}

int isVisited(int *arr,int node,int size){
	for(int i=0;i<size;i++){
		if(*(arr+i)==node){
			return 1;
			
		}
	}
	return 0;
}

int main(){
	int n_vtx;
	
	printf("Enter the number of vertices ");
	scanf("%d",&n_vtx);
	int visited[n_vtx];
	int * stk=set_stk(n_vtx);
	adjlist=(node **)malloc(sizeof(node*)*100);
	for(int i=0;i<n_vtx;i++){
		adjlist[i]=NULL;
	}
	add_edge(1,2);
	add_edge(1,3);
	add_edge(2,4);
	add_edge(3,4);
	for(int i=1;i<=n_vtx;i++){
		printList(adjlist[i]);
		printf("\n");
	}
	int n=0;
	int v=0;
	int s=1;
	
	visited[v++]=s;
	node* tmp=adjlist[s];
	while(tmp!=NULL){
		if(isVisited(visited,tmp->data,v)==0){
			push(stk,tmp->data);
		}
		tmp=tmp->next;
	}
	while(v!=n_vtx){
		s=pop(stk);

		if(isVisited(visited,s,v)==0){
			visited[v++]=s;
		}
		node* tmp=adjlist[s];
		while(tmp!=NULL){
		if(isVisited(visited,tmp->data,v)==0){
			push(stk,tmp->data);
		}
		tmp=tmp->next;
	}

	}
	printf("DFS TRAVERSAL\n");
	for(int i=0;i<n_vtx;i++){
		printf("==%d==\n",visited[i]);
	}


}