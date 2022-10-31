#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int*b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
/*
BUBBLE SORT
*/

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

/*
insertionSort
*/

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

/*
mergeSort
*/

void merge(int arr[],int l,int m,int e){
	int l1=m-l+1;
	int l2=e-m;
	int arr1[l1],arr2[l2];
	for(int i=0;i<l1;i++){
		arr1[i]=arr[l+i];
	}
	for(int j=0;j<l2;j++){
		arr2[j]=arr[j+1+m];

	}
	int i=0,j=0,k=l;
	while(i<l1 &&j<l2){
		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
		}
		else{
			arr[k]=arr2[j];
			j++;
		}
		k++;

	}
	while(i<l1){
		arr[k]=arr1[i];
		i++;
		k++;
	}
	while(j<l2){
		arr[k]=arr2[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int l,int h){
	if(l<h){
		int m=l+(h-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,h);
		merge(arr,l,m,h);
	}
}

/*
Selectionsort
*/

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

/*
QuickSort
*/

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
/*Tests*/
}
int main(){
int arr[]={3,53,2,6,8,89};
mergeSort(arr,0,6);
print(arr,6);
}
