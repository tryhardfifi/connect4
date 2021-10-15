#ifndef MINIMAX_H
#define MINIMAX_H
#define N 8
#include <stdlib.h>
#include <stdio.h>
#include "minimax.h"
#include "node.h"
#include "main.h"

int maximum(Node *p);
int minimum(Node *p);
void minimax(Node *parent, int level);
int checkGlobalWin(char board[N][N], int p);
int score(Node* p);

#endif

