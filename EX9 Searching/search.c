/*
implementation of binarysearch and linear search
*/
#include <stdio.h>
#include <stdlib.h>
void linearSearch(int *arr,int size,int data){
	for (int i=0;i<size;i++){
		if((*arr+i)==data){
			printf("Found at %d\n",i );
			return;
		}
	}
	printf("Not Found\n");
}
int binarySearch(int* arr,int size,int data,int low,int high){
	if(low>high){
		return 0;
	}
	else{
		int mid=(low+high)/2;
		if(*(arr+mid)==data){
			return mid;
		}
		else  if(data>mid){
			return binarySearch(arr,size,data,mid+1,high);
		}
		else{
			return binarySearch(arr,size,data,low,mid-1);
		}
	}


}

int main(){
int  arr[]={1,2,3,4,5,6};
printf("binarySearch %d\n",binarySearch(arr,6,-1,0,5));
linearSearch(arr,6,5);
}