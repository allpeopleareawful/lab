#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node;
typedef char treeData;
typedef Node *link;
int i;
char ch;

struct Node {
    treeData data;
    link left, right;
} *tree;

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

int isAN() { return (ch >= 'a') && (ch <= 'z') || (ch >= '0') && (ch <= '9'); }

int isCH(char c) { return (c >= 'a') && (c <= 'z') || (c >= '0') && (c <= '9'); }

link makeNode(char c, link l, link r) {
    link t = new Node;
    t->data = c;
    t->left = l;
    t->right = r;
    return t;
}

link expr();

link fact() {
    link t;
    scanf("%c", &ch);
    if (ch == '(') {
        t = expr();
        if (ch != ')') printf("ERROR: not )\n");
    } else if (isAN()) t = makeNode(ch, 0, 0);
    else printf("ERROR: not AN\n");
    return t;
}

link term() {
    link tm;
    int done;
    char ch1;
    tm = fact();
    done = 0;
    while ((ch != '\n') && (!done)) {
        scanf("%c", &ch);
        if ((ch == '*') || (ch == '/')) {
            ch1 = ch;
            tm = makeNode(ch1, tm, fact());
        } else done = 1;
    }
    return tm;
}

link expr() {
    link ex;
    int done;
    char ch1;
    ex = term();
    done = 0;
    while ((ch != '\n') && (!done)) {
        if ((ch == '+') || (ch == '-')) {
            ch1 = ch;
            ex = makeNode(ch1, ex, term());
        } else done = 1;
    }
    return ex;
}

void treeToExpr(link tree) {
    if (tree) {
        if ((tree->data == '+') || (tree->data == '-')) printf("(");
        treeToExpr(tree->left);
        printf("%c", tree->data);
        treeToExpr(tree->right);
        if ((tree->data == '+') || (tree->data == '-')) printf(")");
    }
}

void transformTree(link tree) {
    char multiplier, summation;
    if (tree) {
        if (tree->data == '*') {
            if ((isCH(tree->left->data)) && (tree->left->right == NULL) && (tree->left->left == NULL) &&
                (tree->right->data == '+')) {
                tree->data = '+';
                multiplier = tree->left->data;
                tree->left->data = '*';
                tree->left->left = new Node;
                tree->left->right = new Node;
                summation = tree->right->left->data;
                tree->left->left->data = multiplier;
                tree->left->right->data = summation;
                tree->right->data = '*';
                tree->right->left->data = multiplier;
            } else if ((isCH(tree->right->data)) && (tree->right->right == NULL) && (tree->right->left == NULL) &&
                       (tree->left->data == '+')) {
                tree->data = '+';
                multiplier = tree->right->data;
                tree->right->data = '*';
                tree->right->left = new Node;
                tree->right->right = new Node;
                summation = tree->left->left->data;
                tree->right->left->data = multiplier;
                tree->right->right->data = summation;
                tree->left->data = '*';
                tree->left->left->data = multiplier;
            }
        }
        transformTree(tree->left);
        transformTree(tree->right);
    }
}

int main() {
    printf("Input expression:\n");
    tree = expr();
    printTree(tree);
    printf("\n\n-----------------------\n\n");
    treeToExpr(tree);
    i = 1;
    while (i) {
        i = 0;
        transformTree(tree);
    }
    printf("\n\n-----------------------\n\n");
    printTree(tree);
    printf("\n\n-----------------------\n\n");
    treeToExpr(tree);
    printf("\n\n-----------------------\n\n");
    return 0;
}