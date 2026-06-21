#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char type; //'N' - Number or 'O' - operator
    char op;
    int val;
    struct Node *left;
    struct Node *right;
}Node;


Node *CreateNode(char ch){
    Node* new = (Node *) malloc(sizeof(Node));
    if (new == NULL){
        printf("Error in allocating memory");
        return NULL;
    }
    if (ch =='+'||ch =='-'||ch =='*'||ch =='/'){
        new->type = 'O';
        new->op = ch;
        new->val = 0;
    }
    else{
        new->type = 'N';
        new->val = ch-'0';
        new->op ='\0';
    }
    new->left = NULL;
    new->right = NULL;
    return new;
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

    space += 5;

    PrintTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }

    if (root->type == 'O') {
        printf("%c\n", root->op);
    } else {
        printf("%d\n", root->val);
    }

    PrintTree(root->left, space);
}


int Evaluate(Node *root){
    if (root == NULL){
        return 0;
    }
    if (root->type == 'N'){
        return root->val;
    }
    int left_res = Evaluate(root->left);
    int right_res = Evaluate(root->right);

    switch (root->op) {
        case '+':
            return left_res+right_res;
            break;
        case '-':
            return left_res-right_res;
            break;
        case '*':
            return left_res*right_res;
            break;
        case '/':
            return left_res/right_res;
            break;
    }
}

Node *Parse(int n, char string[n], int start, int end){
    if (start == end) {
        return CreateNode(string[start]);
    }
    for (int i = end; i>=start;i--){
        if (string[i] == '+' || string[i] == '-'){
            Node *new = CreateNode(string[i]);
            new->left = Parse(n, string, start, i-1);
            new->right = Parse(n, string,i+1, end);
            return new;
        }


    }
    for (int i = end; i>=start;i--) {
        if (string[i] == '*' || string[i] == '/') {
            Node *new = CreateNode(string[i]);
            new->left = Parse(n, string, start, i - 1);
            new->right = Parse(n, string, i + 1, end);
            return new;
        }
    }
    Node *new = CreateNode(string[start]);

}
int main() {
    int n = 6;
    char str[6] = "5+4*3";
    Node *exptree = Parse(6,str,0,6);
    PrintTree(exptree, 4);
    int result = Evaluate(exptree);
    printf("%d", result);
    return 0;
}
