#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[50];
    struct node* left;
    struct node* right;
};

struct node* newNode(char data[]) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printInorder(struct node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%s ", node->data);
    printInorder(node->right);
}

int hasPath(struct node* root, char (*arr)[50], char x[], int index) {
    if (root == NULL)
        return 0;

    strcpy(arr[index], root->data);

    if (strcmp(root->data, x) == 0)
        return 1;

    if (hasPath(root->left, arr, x, index + 1) ||
        hasPath(root->right, arr, x, index + 1))
        return 1;

    return 0;
}

int main() {
    struct node* root = newNode("Bangalore");

    struct node* suburbs = root->left = newNode("Bangalore-East");
    struct node* townA = suburbs->left = newNode("A");
    struct node* corporationA1 = townA->left = newNode("56001");
    struct node* corporationA2 = townA->right = newNode("56002");

    struct node* corporationB = root->right = newNode("Bangalore-West");
    struct node* townC = corporationB->left = newNode("C");
    struct node* corporationC1 = townC->left = newNode("56005");
    struct node* corporationC2 = townC->right = newNode("56006");

    struct node* townD = corporationB->right = newNode("D");
    struct node* corporationD1 = townD->left = newNode("56007");
    struct node* corporationD2 = townD->right = newNode("56008");

    printInorder(root);
    printf("\n");

    char arr1[20][50]; // answer
    char x1[50]; // input as a string
    printf("Enter the first corporation code: ");
    gets(x1);
    int index1 = 0;
    int functionOutput1 = hasPath(root, &arr1, x1, index1);
    printf("\n");

    char arr2[20][50]; // answer
    char x2[50]; // input as a string
    printf("Enter the second corporation code: ");
    gets(x2);
    int index2 = 0;
    int functionOutput2 = hasPath(root, &arr2, x2, index2);
    printf("\n");

    printf("Common Locations: ");
    int i;
    for (i = 0; i < index1 && i < index2; i++) {
        if (strcmp(arr1[i], arr2[i]) == 0) {
            printf("%s, ", arr1[i]);
        } else {
            break;
        }
    }
    printf("\n");

    return 0;
}
