#include <stdio.h>
#include <stdlib.h>
typedef struct kruskal{
	int v1;
	int v2;
	int cost;
}krus;
void swap(krus * a,krus *b){
	
	krus tmp=*a;
	*a=*b;
	*b=tmp;
	
	
}

int parent;
int fill=1;

void insert_heap(krus arr[],int v1,int v2,int num){
	parent=fill/2;
	arr[fill].cost=num;
	arr[fill].v1=v1;
	arr[fill].v2=v2;
	int child=fill;

	while(child!=1){
		parent=child/2;
		if(arr[parent].cost>arr[child].cost){
			swap(&arr[parent],&arr[child]);
		}
		child=parent;
	}
	fill++;
}

krus delete(krus arr[]){
	krus k=arr[1];
	swap(&arr[1],&arr[fill]);
	fill--;
	int si=fill;
	int top=1;
	int child;
	
	for(int i=1;i*2<=si;i=child){
		child=i*2;
		if(child!=si&&arr[child].cost>arr[child+1].cost){
			child++;
		}
		if(arr[top].cost>arr[child].cost){
			swap(&arr[top],&arr[child]);
			top=child;
		}
		else{
			break;
		}
	}
	return k;
}


int main(){
	int vtx;
	scanf("%d",&vtx);
	int unions[vtx];
	int edge,v1,v2,cost;
	scanf("%d",&edge);
	for(int i=0;i<vtx;i++)unions[i]=0;
	krus* graf=(krus*)malloc(sizeof(krus)*edge);
	for(int i=0;i<edge;i++){
		printf("Enter vtx in order v1 v2 cost :");
		scanf("%d %d %d",&v1,&v2,&cost);
		insert_heap(graf,v1,v2,cost);

	}

	for(int i=1;i<fill;i++){
		printf("%d %d %d\n",graf[i].v1,graf[i].v2,graf[i].cost);
	}
	/*
	swap(&graf[2],&graf[3]);
	printf("\n");
	for(int i=1;i<fill;i++){
		printf("%d %d %d\n",graf[i].v1,graf[i].v2,graf[i].cost);
	}
	*/
	int v1_new,v2_new,cost_new;
	for(int i=1;i<=edge;i++){
		krus del=delete(graf);
		v1_new=del.v1;
		v2_new=del.v2;
		cost_new=del.cost;
		if(unions[v1_new]==1 && unions[v2_new]==1){
			continue;
		}
		if(unions[v1_new]==0){
			unions[v1_new]=1;
		}
		if(unions[v2_new]==0){
			unions[v2_new]=1;
		}
		printf("\n%d %d %d\n",v1_new,v2_new,cost_new);

	}

}