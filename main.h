#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include "minimax.h"
#include "node.h"
#include "tree.h"


void printBoard(char board[N][N]);
int movePlayer(Node *p, int column);
void initializeBoard(Node *p);

#endif
