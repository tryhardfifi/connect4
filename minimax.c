#include "minimax.h"

int maximum(Node *p){
    int j = -10000;
    for(int i = 0; i < p->n_children; i++){
       if (j < p->children[i]->value){
           j = p->children[i]->value;
       }
    }
    return j;
}
int minimum(Node *p){
    int j = 10000;
    for(int i = 0; i < p->n_children; i++){
       if (j > p->children[i]->value){
           j = p->children[i]->value;
       }
    }
    return j;
}
void minimax(Node *parent, int level){
   for(int i=0;i<parent->n_children;i++){
   	minimax(parent->children[i],level+1);
   }
   if (parent->n_children > 0){
       if (level%2){
           parent->value = minimum(parent);
       }
       else {
           parent->value = maximum(parent);
       }
   }
}
int checkGlobalWin(char board[N][N], int p){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-3; j++){
            if (board[i][j] == p && board[i][j+1] == p && board[i][j+2] == p && board[i][j+3] == p){
            return 1;
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-3; j++){
            if (board[j][i] == p && board[j+1][i] == p && board[j+2][i] == p && board[j+3][i] == p){
                return 1;
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N-3; j++){
            if (board[i][j] == p && board[i+1][j+1] == p && board[i+2][j+2] == p && board[i+3][j+3] == p){
                return 1;
            }
        }
    }
    for (int i = 3; i < N; i++){
        for (int j = 0; j < N-3; j++){
            if (board[i][j] == p && board[i-1][j+1] == p && board[i-2][j+2] == p && board[i-3][j+3] == p){

                return 1;
            }
        }
    }
    return 0;
}
int score(Node* p){
    if (checkGlobalWin(p->board,1)){
        return -100;
    }
    if (checkGlobalWin(p->board,2)){
        return 100;
    }
    else{
        return rand()%100 - 50;
    }
}
