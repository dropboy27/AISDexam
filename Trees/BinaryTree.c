#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}Node;


Node *CreateNode(int value){
    Node* new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Error in allocating memory");
        return NULL;
    }
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Node *InsertNode(Node *root, int val){
    if (root == NULL){
        return CreateNode(val);
    }
    if (val<root->val){
        root->left = InsertNode(root->left, val);
    }
    else if (val >root->val){
        root->right = InsertNode(root->right, val);
    }
    return root;
}

Node *Find(Node *root, int val){
    if (root == NULL){
        return NULL;
    }

    while (root != NULL && root->val != val){
        if (val < root->val){
            root =root->left;
        }
        else if (val>root->val){
            root = root->right;
        }
    }
    return root;
}



Node* Delete(Node *root, int val){
    if (root == NULL){
        return NULL;
    }
    if (val <root->val){
        root->left = Delete(root->left, val);
    }
    else if (val > root->val){
        root->right = Delete(root->right, val);
    }
    else{
        if (root->left == NULL){
            Node* temp = root ->right;
            free(root);
            return  temp;
        }
        else if (root->right == NULL){
            Node* temp = root ->left;
            free(root);
            return  temp;
        }
        else{
            Node *temp = root->right;
            while (temp->left!=NULL){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = Delete(root->right, root->val);
        }
    }
    return root;
}


int main() {

}