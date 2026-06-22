#include <stdio.h>
#include <stdlib.h>


typedef enum {RED, BLACK}Color;
typedef struct Node{
    Color color;
    int val;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
}Node;


Node *CreateNode(int value){
    Node* new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Error in allocating memory");
        return NULL;
    }
    new->color = RED;
    new->val = value;
    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;
    return new;
}
//CODE FOR FIXING AFTER INSERTION
void Fixup(Node **root_ref, Node *z) {
    // z — это только что вставленный красный узел (у него parent != NULL)
    while (z != *root_ref && z->parent->color == RED) {
        Node *parent = z->parent;
        Node *grandparent = parent->parent;

        if (parent == grandparent->left) { // случай: родитель слева
            Node *uncle = grandparent->right;

            // Случай 3: дядя красный
            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent; // поднимаемся вверх
            } else {
                // Случай 4: зигзаг (z — правый ребёнок parent)
                if (z == parent->right) {
                    // левый поворот вокруг parent
                    Node *tmp = z->left;
                    parent->right = tmp;
                    if (tmp) tmp->parent = parent;
                    z->left = parent;
                    parent->parent = z;
                    // теперь меняем роли: z становится новым parent
                    parent = z;
                    z = parent->left; // z теперь левый ребёнок нового parent
                }
                // Случай 5: прямая линия (z — левый ребёнок parent)
                // правый поворот вокруг grandparent
                Node *tmp = parent->right;
                grandparent->left = tmp;
                if (tmp) tmp->parent = grandparent;
                parent->right = grandparent;
                parent->parent = grandparent->parent;
                if (grandparent->parent) {
                    if (grandparent->parent->left == grandparent)
                        grandparent->parent->left = parent;
                    else
                        grandparent->parent->right = parent;
                } else {
                    *root_ref = parent; // новый корень
                }
                grandparent->parent = parent;
                parent->color = BLACK;
                grandparent->color = RED;
                z = parent; // можно выйти из цикла
            }
        } else { // симметричный случай: родитель справа
            Node *uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                z = grandparent;
            } else {
                if (z == parent->left) {
                    // правый поворот вокруг parent
                    Node *tmp = z->right;
                    parent->left = tmp;
                    if (tmp) tmp->parent = parent;
                    z->right = parent;
                    parent->parent = z;
                    parent = z;
                    z = parent->right;
                }
                // левый поворот вокруг grandparent
                Node *tmp = parent->left;
                grandparent->right = tmp;
                if (tmp) tmp->parent = grandparent;
                parent->left = grandparent;
                parent->parent = grandparent->parent;
                if (grandparent->parent) {
                    if (grandparent->parent->left == grandparent)
                        grandparent->parent->left = parent;
                    else
                        grandparent->parent->right = parent;
                } else {
                    *root_ref = parent;
                }
                grandparent->parent = parent;
                parent->color = BLACK;
                grandparent->color = RED;
                z = parent;
            }
        }
    }
    (*root_ref)->color = BLACK;
}

void InsertNode(Node *root, int val){
    Node *parent =root;
    while(root != NULL){
        parent =root;
        if (val < root -> val){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    Node *new= CreateNode(val);
    new->parent = parent;
    if(val < parent->val){
        parent->left = new;
    } else{
        parent->right = new;
    }
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

int main() {

}
