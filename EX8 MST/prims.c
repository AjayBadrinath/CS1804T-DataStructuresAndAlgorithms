#include <stdio.h>
#include <stdlib.h>
int vtx;
int mincost(int cost[vtx],int mst[vtx]){
	int min=9884743;
	int minidx;
	for(int i=0;i<vtx;i++){
		if(mst[i]==0&&cost[i]<min){
			min=cost[i];
			minidx=i;

		}
	}
	return minidx;
}
void print(int graph[vtx][vtx],int top[vtx]){
	for(int i=1;i<vtx;i++){
		printf("%d %d %d\n",top[i],i,graph[i][top[i]]);
	}


}
void prim(int graph[vtx][vtx]){
	int top[vtx],cost[vtx],mst[vtx];
	for(int i=0;i<vtx;i++){
		cost[i]=9884743;
		mst[i]=0;
	}
	cost[0]=0;
	for(int i=0;i<vtx;i++){
		int min=mincost(cost,mst);
		mst[min]=1;
		for(int j=0;j<vtx;j++){
			if(graph[min][j]&&mst[j]==0&&graph[min][j]<cost[j]){
				top[j]=min;
				cost[j]=graph[min][j];
			}
		}
	}
	print(graph,top);
}
int main(){
	printf("enter no of vertices");
	scanf("%d",&vtx);
	int wt;
	int graph[vtx][vtx];
	for(int i=0;i<vtx;i++){
		for(int j=0;j<vtx;j++){
			scanf("%d",&graph[i][j]);

		}
	}
	prim(graph);
}