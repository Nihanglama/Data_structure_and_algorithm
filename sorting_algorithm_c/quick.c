#include<stdio.h>
#define size 10

int partition(int arr[size],int l,int h){
    int i=l-1;
    int j=l;
    int temp;
    int pi=arr[h];
    printf("%d\n",pi);
    for(int j=l;j<h;j++){
        if(arr[j]<pi){
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    arr[h]=arr[i+1];
    arr[i+1]=pi;
    return i+1;
}
void quick(int arr[size],int l,int h){
    if(l<h){
        int p=partition(arr,l,h);
        quick(arr,l,p-1);
        quick(arr,p+1,h);
    }
}
void print(int arr[size]){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);

    }
}
int main(){

        int arr[size]={5,4,3,2,1,6,7,9,12,10};
        quick(arr,0,size-1);
        print(arr);


}
