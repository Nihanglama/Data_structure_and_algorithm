#include<stdio.h>
#include<stdbool.h>
#define size 10

int arr[size];
int front=-1;
int rear=-1;

int isempty(){
    if(front==-1&&rear==-1){
        return true;
    }
    else{
        return false;
    }

}
int isFull(){
    if((rear+1%size)==front){
        return true;
    }else{
        return false;
    }

}

void enque(int value){
    if(isFull()==true){
        printf("Stack overflow");
    }else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        arr[rear]=value;
    }else{
        rear=(rear+1)%size;
        arr[rear]=value;
    }

}
void deque(){
    if(isempty()==true){
        printf("Stack underflow");
    }else if(front==rear){
        front--;
        rear--;
    }else{
        front=(front+1)%size;
    }


}

void display()
{
    printf("%d %d",rear,front);
    int count=front;
    while(count!=rear){
        printf("%d ",arr[count]);
        count=(count+1)%size;
    }
    printf("%d ",arr[count]);

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