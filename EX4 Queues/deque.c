#include <stdio.h>
#include <stdlib.h>

int front=0;
int full=0;
int rear=0;
int len;
/*implement deque in circular array*/
int* createCircularArray(int size ){
	int* arr=(int *)malloc(sizeof(int)*size);
	len=size;
	return arr;
}

void push(int *arr,int data){
	if(full==1){
	 	printf("Push not possible\n");
	 	return;
	 }
	if(front==0){
		*(arr+front)=data;
		front=len-1;
		return;

	}
	else if(front>rear+1){
		*(arr+(front--))=data;
		return;
		
	}
	else{
		*(arr+(front))=data;
		full=1;
		return;
	}
	 

}
int  pop(int * arr){
	int popped;
	if(front==rear){
		printf("pop not possible");
		return -1;
	}
	if (front==0)
	{
		popped=*(arr+front);
		*(arr+front)=0;
		return popped;
	}
	if (front==len-1){
		popped=*(arr+front);
		*(arr+front)=0;
		front=0;
		return popped;
		
	}
	popped=*(arr+(front));
	*(arr+front)=0;
	front++;
	full=0;
	return popped;

}
void inject(int* arr,int data){
	if (rear==0){
		*(arr+(++rear))=data;
		return;
	}
	if(rear==len-1){
		full=1;
	}
	else if(rear<front){
		*(arr+rear)=data;
		rear++;
		return;

	}
	if(full==1){
		printf("inject not possible\n");
		return;
	}
	
	
}
int eject(int* arr){
	int eject_el=*(arr+rear);
	if(rear==0){
		printf("eject not possible\n");
		return-1;
	}
	eject_el=*(arr+rear);
	*(arr+rear)=0;
	rear--;
	return eject_el;

}
void print(int * arr){
	for(int i=0;i<len;i++){
		printf("%d\t",*(arr+i) );
	}
	printf("\n");
}
int main(){
	int* arr=createCircularArray(5);
	push(arr,1);
	push(arr,2);
	push(arr,3);
	push(arr,4);
	push(arr,5);
	push(arr,3);
	inject(arr,6);
	//inject(arr,54);
	eject(arr);
	pop(arr);
	pop(arr);
	printf("\n%d %d\n",front,rear);
	print(arr);
}