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

void FreeTree(Node *root){
    if (root != NULL){
        FreeTree(root->right);
        FreeTree(root->left);
        free(root);
    }
}

void PrintTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 4;

    PrintTree(root->right, space);

    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->val);

    PrintTree(root->left, space);
}


// Обход root->left->right
void PreOrder(Node *root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

// Обход left->root->right
void InOrder(Node *root){
    if (root == NULL){
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

// Обход left->right->root
void PostOrder(Node *root){
    if (root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
}


int main() {
    Node *root = NULL;

    root = InsertNode(root, 4);
    InsertNode(root, 3);
    InsertNode(root, 6);

    printf("Структура дерева:\n");
    PrintTree(root, 0);

    FreeTree(root);
    return 0;
}
