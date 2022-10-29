/*
Array implementation of Lists 

Operations:
	1.Insertion
	2.Deletion
	3.Search
	4.Display

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  len=0;
void insert(int idx,int val,int* arr){
	*(arr+idx)=val;
	len++;
}

void delete(int idx,int* arr){
	int i;
	for(i=idx;i<len-1;i++){
		*(arr+i)=*(arr+i+1);
	}
	len=len-1;
}

void print(int *arr,int len){
	for(int i=0;i<len;i++)printf("%d\t",*(arr+i));
	printf("\n");
}
void search(int *arr,int elem){
	for (int i=0;i<len;i++){
		if(*(arr+i)==elem){
			printf("Found at index  %d\n",i);
			return;
		}

	}
	printf("Not Found\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int * arr=(int * )malloc(n*sizeof(int));
	insert(0,5,arr);
	insert(1,6,arr);
	insert(2,56,arr);
	delete(1,arr);
	search(arr,4);
	print(arr,len);
}