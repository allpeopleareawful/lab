#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node;
typedef char treeData;
typedef Node *link;

struct Node {
    treeData data;
    link left, right;
} *tree;

int i, counter = 0;

void printTree(link tree) {
    static int nodeDeep = 0;
    ++nodeDeep;
    if (tree) {
        printTree(tree->right);
        for (i = 0; i < nodeDeep; ++i)printf("    ");
        printf("\\_\'%c\'\n", tree->data);
        printTree(tree->left);
    }
    --nodeDeep;
}

void insertNode(link &t, treeData v) {
    if (!t) {
        t = new Node;
        t->data = v;
        t->right = 0;
        t->left = 0;
    } else {
        if (int(v) <= int(t->data)) insertNode(t->left, v);
        else if (int(v) > int(t->data)) insertNode(t->right, v);
    }
}

link parent;

void deleteNode(link &tree) {
    if (tree->right) deleteNode(tree->right);
    else {
        parent->data = tree->data;
        parent = tree;
        tree = tree->left;
    }
}

void deleteTree(link &tree, treeData v) {
    if (tree)
        if (v < tree->data) deleteTree(tree->left, v);
        else if (!(tree->right)) tree = tree->left;
        else if (!(tree->left)) tree = tree->right;
        else {
            parent = tree;
            deleteNode(parent->left);
        }
}

void generateTree(link &t, int n) {
    for (i = 0; i < n; ++i) {
        treeData v = 33 + (rand() % 93);
        insertNode(tree, v);
    }
}

void count(link t) {
    if (t) {
        count(t->right);
        counter++;
        count(t->left);
    }
}

int treeHeight(link t) {
    if (!t) return 0;
    int leftH = treeHeight(t->left);
    int rightH = treeHeight(t->right);
    if (leftH > rightH) return leftH + 1;
    else return rightH + 1;
}

void dfs(link t, int treeHeight, int *Array) {
    ++Array[treeHeight];
    if (t->left) dfs(t->left, treeHeight + 1, Array);
    if (t->right) dfs(t->right, treeHeight + 1, Array);
}

int treeWidth(link t) {
    int max = 0;
    int height = treeHeight(t);
    int *Array = new int[height];
    dfs(t, 0, Array);

    for (int i = 0; i < height; ++i) {
        if (Array[i] > max) max = Array[i];
    }

    return max;
}


void mainAction(link t) {

}

int main() {
    time_t t;
    srand(time(&t));
    int k = 1, n;
    tree = 0;
    treeData v;
    while (k) {
        printf("\n    MENU\n "
               "0 - exit\n"
               "1 - add random tree"
               "\n 2 - print tree"
               "\n 3 - insert item"
               "\n 4 - delete item"
               "\n 5 - number of nodes"
               "\n 6 - clear tree"
               "\n 7 - levels"
               "\n 8 - main action"
               "\n =>");
        scanf("%d", &k);
        if (!k) break;
        if (k == 1) {
            printf("\nInput number of items -> ");
            scanf("%d", &n);
            generateTree(tree, n);
        }
        if (k == 2)
            if (tree) printTree(tree);
            else printf("\nTree is empty\n");
        if (k == 3) {
            printf("For insert input v -> ");
            scanf(" %c", &v);
            insertNode(tree, v);
        }
        if (k == 4) {
            printf("For delete input v ->");
            scanf(" %c", &v);
            deleteTree(tree, v);
        }
        if (k == 5) {
            counter = 0;
            count(tree);
            printf("\nNumber of nodes -> %d\n", counter);
        }
        if (k == 6) tree = 0;
        if (k == 7) {
            printf("Levels of tree -> %d\n", treeHeight(tree));
        }
        if (k == 8) {

            printf("Breadth of tree %d\n", treeWidth(tree));
        }
    }
    return 0;
}