#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    int height;
    struct Node *left;
    struct Node *right;
}Node;

int GetHeight(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

Node *CreateNode(int value){
    Node* new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Error in allocating memory");
        return NULL;
    }
    new ->height=1;
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}


int Maximum(int a , int b){
    if (a>=b) return a;
    else return b;
}



Node *RotateLeft(Node *a){
    Node *b = a->right;
    Node *c = b->left;
    b->left = a;
    a ->right = c;
    int a_left_height = GetHeight(a->left);
    int a_right_height = GetHeight(a->right);
    a -> height = Maximum(a_left_height,a_right_height)+1;
    int b_left_height = GetHeight(b->left);
    int b_right_height = GetHeight(b->right);
    b -> height = Maximum(b_left_height,b_right_height)+1;
    return b;
}

Node *RotateRight(Node *a){
    Node *b = a->left;
    Node *c = b->right;
    b->right = a;
    a ->left = c;
    int a_left_height = GetHeight(a->left);
    int a_right_height = GetHeight(a->right);
    a -> height = Maximum(a_left_height,a_right_height)+1;
    int b_left_height = GetHeight(b->left);
    int b_right_height = GetHeight(b->right);
    b -> height = Maximum(b_left_height,b_right_height)+1;
    return b;
}

int BalanceFactor(Node *root){
    int left_height = GetHeight(root->left);
    int right_height = GetHeight(root->right);
    root -> height = Maximum(left_height,right_height)+1;
    return left_height-right_height;
}


Node *Balance(Node *root){
    int root_balance_factor = BalanceFactor(root);
    if (root_balance_factor>1){
        int root_balance_left = BalanceFactor(root->left);
        if (root_balance_left <=-1){
            root->left = RotateLeft(root->left);
        }
        root = RotateRight(root);
        return root;
    }
    if (root_balance_factor<-1){
        int root_balance_right= BalanceFactor(root->right);
        if (root_balance_right >= 1){
            root->right = RotateRight(root->right);
        }
        root = RotateLeft(root);
        return root;
    }
    return root;
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
    int left_height = GetHeight(root->left);
    int right_height = GetHeight(root->right);
    root -> height = Maximum(left_height,right_height)+1;
    return Balance(root);
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



int CountNodes(Node *root){
    if (root == NULL) return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

int main() {
    Node *root = NULL;
    int values[] = {10, 20, 30, 25, 5, 1, 15, 22, 27, 26};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++){
        root = InsertNode(root, values[i]);
        printf("После вставки %d (узлов в дереве: %d):\n", values[i], CountNodes(root));
        PrintTree(root, 0);
        printf("InOrder: ");
        InOrder(root);
        printf("\n---------------------------\n");
    }

    printf("\nВставлено значений: %d, реально узлов в дереве: %d\n", n, CountNodes(root));

    if (CountNodes(root) != n) {
        printf("ОШИБКА: узлы потерялись где-то при вставке/повороте!\n");
    } else {
        printf("OK: ни один узел не потерян.\n");
    }

    FreeTree(root);
    return 0;
}