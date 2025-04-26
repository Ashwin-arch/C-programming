#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void SelectionSort(int arr[],int n){
 int i, j , minIndex=0;
 for(i=0;i<n-1;++i){
 minIndex=i;
 for(j=i+1;j<n;++j)
 if(arr[j]<arr[minIndex]){
 minIndex=j;
 }
}
 if(minIndex!=i) {
 int temp=arr[i];
     arr[i]=arr[minIndex];
     arr[minIndex]=temp;
}
}
int main(){
int i,j,n;
printf("Enter the no of elements:\n");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(i=0;i<n;i++){
arr[i]=rand()%10000;
}
clock_t start=clock();
SelectionSort(arr,n);
clock_t end=clock();
double time_taken=(((double) end-start)/(CLOCKS_PER_SEC));
printf("The time Taken for the clock to print elements are %f seconds",time_taken);
}
