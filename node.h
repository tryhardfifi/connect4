#ifndef NODE_H
#define NODE_H

typedef struct node {
    char board[N][N];
    struct node* *children;
    int n_children;
    int value;
} Node;

#endif
