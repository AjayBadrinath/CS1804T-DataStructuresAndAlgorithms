#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int parent;
int fill=1;

void insert_heap(int * arr,int num){
	parent=fill/2;
	*(arr+fill)=num;
	int child=fill;
	while(child!=1){
		parent=child/2;
		if(*(arr+parent)>*(arr+child)){
			swap((arr+parent),(arr+child));
		}
		child=parent;
	}
	fill++;
}

int delete(int *arr,int size){
	int k=*(arr+1);
	swap((arr+1),(arr+(fill)));
	fill--;
	int si=fill;
	int top=1;
	int child;
	
	for(int i=1;i*2<=si;i=child){
		child=i*2;
		if(child!=si&&*(arr+child)>*(arr+child+1)){
			child++;
		}
		if(*(arr+top)>*(arr+child)){
			swap((arr+top),(arr+child));
			top=child;
		}
		else{
			break;
		}
	}
	return k;
}


void print(int * arr,int size){
	for (int i=1;i<size;i++){
		printf("%d\n",*(arr+i) );
	}
}


int main(){
int arr[12];
int num;
for(int i=0;i<11;i++){
	scanf("%d",&num);
	insert_heap(arr,num);
	
}

print(arr,12);
int s=12;
printf("\n");
fill=fill-1;

for(int i=1;i<12;i++){
printf("%d\t",delete(arr,s));
}
//printf("=%d=",arr[--fill]);


}