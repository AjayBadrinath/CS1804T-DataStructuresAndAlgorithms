#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int*b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void bubblesort(int* arr,int len){
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
			if(*(arr+j)<*(arr+j+1)){
				swap(arr+j,arr+j+1);
			}
		}
	}
}
void print(int* arr,int len){
	for(int i=0;i<len;i++){
		printf("%d\n",*(arr+i) );
	}
}
void insertionsort(int *arr,int len){
	int val,j;
	for(int i=1;i<len;i++){
		j=i-1;
		val=arr[i];
		while(j>=0 && arr[j]>val){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=val;
	}
}
void selectionsort(int*arr,int len){
	int min;
	for(int i=0;i<len-1;i++){
		min=i;
		for(int j=i;j<len;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(min!=i){
			swap(arr+min,arr+i);
		}
	}
}

int partition(int *arr,int l,int h){
	int pivot=*(arr+h);
	int i=l-1;
	for(int j=l;j<=h-1;j++){
		if(*(arr+j)<pivot){
			i++;
			swap(arr+i,arr+j);
		}
	}
	swap(arr+i+1,arr+h);
	return i+1;
}
void qksort(int*arr,int l,int h){
	if(l<h){
		int p=partition(arr,l,h);
	
	qksort(arr,l,p-1);
	qksort(arr,p+1,h);
}
}
int main(){
  //Tests
int arr[]={3,53,2,6,8};
qksort(arr,0,5);
print(arr,5);
}
