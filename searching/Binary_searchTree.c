#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree * left;
    struct tree* right;
};


struct tree * create(int value){
    struct tree*temp=NULL;
    temp=malloc(sizeof(struct tree));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;

    return temp;

}

struct tree *insert(struct tree *root,int value){
    if(root==NULL){
        return create(value);
    }
    else{
        if(value<root->data){
            root->left=insert(root->left,value);
        }else{
            root->right=insert(root->right,value);
        }
    }
    return root;

}
void search(struct tree* root,int value){
    if(root==NULL){
        printf("Empty tree");
    }else if(value==root->data){
        printf("Value found %d",root->data);
    }
    else{
        if(value<root->data){
            search(root->left,value);
        }
        else if(value>root->data){
            search(root->right,value);
        }else{
            printf("Value not found");        }
    }
}
void Inorder(struct tree *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d",root->data);
        Inorder(root->right);

    }
}
void Preorder(struct tree *root){
    if(root!=NULL){
        printf("%d",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Postorder(struct tree *root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d",root->data);
    }
}

int  Findmin(struct tree *root){
    struct tree*temp=root;
    if(root==NULL){
        printf("Empty tree");
        return 0;
    }
    else{
        while(temp->left!=NULL){
            temp=temp->left;
        }  
    }
    printf("%d",temp->data);
    return temp->data;
}

int  Findmax(struct tree *root){
    struct tree*temp=root;
    if(root==NULL){
        printf("Empty tree");
        return 0;
    }
    else{
        while(temp->right!=NULL){
            temp=temp->right;
        }  
    }
    printf("%d",temp->data);
    return temp->data;
}
struct tree* Inordersccer(struct tree *root){

}
struct tree *delete(struct tree *root,int value){
    
    if(value>root->data){
        root->right=delete(root->right,value);
    }else if(value<root->data){
        root->left=delete(root->left,value);
    }else{
        if(root->left==NULL){
            struct tree* temp=root->right;
            free(root);
            return temp;

        }
        else if(root->right==NULL){
            struct tree* temp=root->left;
            free(root);
            return temp;
        }
        struct tree *temp=Inordersccer(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    
    
    }return root;
}
int main(){
    struct tree *root=NULL;
    int value;
	int choice;
	while(choice!=9)
	{
		printf("Enter the choice");
		scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value:");
            scanf("%d",&value);
            root=insert(root,value);
        }
		else if(choice==2){
			printf("Enter the value:");
			scanf("%d",&value);
			search(root,value);
		}
        else if(choice==3){
            Inorder(root);
        }
        else if(choice==4){
            Preorder(root);
        }
        else if(choice==5){
            Findmin(root);
        }
        else if(choice==6){
            Findmax(root);
        }
        else if(choice==7){
            printf("Enter the value:");
			scanf("%d",&value);
            root=delete(root,value);

        }
		else{
			printf("Wrong choice");
			exit(0);
		}
		
	}




}







