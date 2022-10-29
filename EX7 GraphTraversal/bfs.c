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

int isVisited(int *arr,int node,int size){
	for(int i=0;i<size;i++){
		if(*(arr+i)==node){
			return 1;
			
		}
	}
	return 0;
}

int  main(){

	int n;
	int visited[n];
	printf("Enter No of nodes: ");
	scanf("%d",&n);
	int arr[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}

	int a,b;
	int edge;
	printf("Enter no of Edges: ");
	scanf("%d",&edge);
	printf("Enter the edges as a b if edge exist");
	for(int i=0;i<edge;i++){
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}

	int v=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}


for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(arr[i][j]==1){
			if(isVisited(visited,i,v)==0){
				visited[v++]=i;
				enqueue(i);

			}
			else if(isVisited(visited,j,v)==0){
				visited[v++]=j;
				enqueue(j);
			}
			else{
				continue;
			}
		}
	}
}


printf("BFS traversal order: ");
print();
printf("==\n");
}