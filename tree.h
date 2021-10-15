#ifndef TREE_H
#define TREE_H

#define N 8
#include <stdlib.h>
#include <stdio.h>
#include "minimax.h"
#include "node.h"
#include "main.h"


void initializeRoot(Node *p);
int bestChildIndex(Node *p);
void moveComputer(Node *p, int index, int player);
void copyBoard(Node *p, Node *copy);
int calculateChildren(char board[N][N]);
Node *createNode(Node *parent,int index,int level);
void deleteLevel(Node *parent);
void deleteTree(Node *root);
void createLevel(Node *parent,int level);
void createTree(Node *root,int level);
void showNode(Node *p, int level);
void showLevel(Node *father, int level);
void walkTreeRec(Node *root, int level);


#endif // tree_h_INCLUDED

