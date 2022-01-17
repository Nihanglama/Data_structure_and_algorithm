#include<stdio.h>
#define size 10

void merge(int arr[size],int l,int mid,int u){
    int size1=mid-l+1;
    int i;
    int size2=u-mid;
    int L[size1];
    int R[size2];
    for(i=0;i<size1;i++){
        L[i]=arr[l+i];
    }
    for(i=0;i<size2;i++){
        R[i]=arr[mid+1+i];
    }
    i=0;
    int j=0;
    int k=l;
    while(i<size1 && j<size2){
        if(R[j]<L[i]){
            arr[k]=R[j];
            j++;
            k++;
        }else{
            arr[k]=L[i];
            i++;
            k++;
        }
    }
    while(j<size2){
        arr[k]=R[j];
        j++;
        k++;

        }
    while (i<size1)
        {
            arr[k]=L[i];
            i++;
            k++;
        }  
}

void mergesort(int arr[size],int l,int u){
   
    if(l<u){
        int mid=(l+u)/2;
        mergesort(arr,mid+1,u);
        mergesort(arr,l,mid);
        merge(arr,l,mid,u);
    }


}
void print(int arr[size]){
    int i;
    for(i=0;i<size;i++){
        printf("%d",arr[i]);
    }
}
int main(){

    int arr[size]={2,4,1,3,6,8,5,9,7};
    mergesort(arr,0,size-1);
    print(arr);


}