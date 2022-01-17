#include<stdio.h>
#include<stdbool.h>
#define size 10
int arr[size];
int front=-1;
int rear=-1;

int isempty(){
    if(front<0 || front>rear){
        return true;
    }else{
        return false;
    }

}
int isFull(){
    if(rear==size-1){
        return true;
    }else{
        return false;
    }

}

void enque(int value){
    if(isFull()==true){
        printf("Queue overflow");
    }else if(front==-1&&rear==-1){
        front++;
        rear++;
        arr[rear]=value;
    }else{
        rear++;
        arr[rear]=value;
    }

}
void deque(){
    if(isempty()==true){
        printf("Empty Queue");
    }
    else{
        front++;
    }

}

void display(){
    int i;
    if(isempty()==true){
        printf("Empty Queue");
    }
    for(i=front;i<=rear;i++){
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
            enque(value);

        }
        else if(choose==2){
            deque();

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