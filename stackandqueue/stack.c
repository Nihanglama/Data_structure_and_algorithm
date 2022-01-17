#include<stdio.h>
#include<stdbool.h>
#define size 10
int arr[size];
int ptr=-1;


int isempty(){
    if(ptr<0){
        return true;
    }else{
        return false;
    }

}
int isFull(){
    if(ptr==size-1){
        return true;
    }
    else{
        return false;
    }

}

void Push(int value){
    if(isFull(ptr)==true){
        printf("Stack overflow");
    }else{
        ptr++;
        arr[ptr]=value;
    }
    printf("%d \n",ptr);
}

void Pop(){
    if(isempty(ptr)==true){
        printf("stack underflow");
    }else{
        ptr--;
    }

}

void display(){
    int i;
    if(isempty(ptr)==true){
        printf("Empty stack");
    }
    for(i=0;i<=ptr;i++){
        printf("%d ",arr[i]);
    }
}


int main(){
    int choose;
    int value;

  while(1){
        printf("Enter the choice:");
        scanf("%d",&choose);
        if(choose==1){
            printf("Enter the value to push");
            scanf("%d",&value);
            Push(value);

        }
        else if(choose==2){
            Pop();

        }
        else if(choose==3){
            if(isempty()==true){
                printf("Stack is empty");

            }else{
                printf("Stack is not empty");
            }

        }
        else if(choose==4){
            if(isFull()==true){
                printf("Stack is empty");

            }else{
                printf("Stack is not empty");
            }

        }
        else if(choose==5){
            display();
        }
        else{
            printf("Enter the valid chooice");
        }
    }


}