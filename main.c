#include "main.h"


void printBoard(char board[N][N]){
    printf("  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 \n");
    for(int i=N-1; i>=0; i--){
        for(int j=0; j<N; j++)
            if (board[i][j] == 1){
                printf(" 🤷 |");
            }
            else if (board[i][j] == 2){
                printf(" 🤖 |");
            }
            else{
                printf("    |", board[i][j]);
                
            }
        printf(" \n");
    }
        printf(" \n");
        printf(" \n");

}
void initializeBoard(Node *p){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            p->board[i][j] = 0;
        }
    }
    p->n_children = N;
    p->children=malloc(p->n_children * sizeof(Node *));
}


int movePlayer(Node *p, int column){

    if (p->board[N-1][column]==0 && column >= 0 && column < N){
    
        for (int i=0; i < N; i++){
            if (p->board[i][column]==0){
                p->board[i][column]=1;
                break;

            }
        }
        return 0;
    }
    else{
        return -1;
    }


}
int main()
{


    Node p;
    // Node p2;
    // Node p4;
    initializeBoard(&p);
    printBoard(p.board);


    int player = 1;
    int column = 0;

    do {
        player = player%2 + 1;
        if (player == 1){
            do {scanf("%d", &column);}
            while (movePlayer(&p,column-1)==-1);
        }
        if (player == 2){
            initializeRoot(&p);
            // initializeRoot(&p2);
            // initializeRoot(&p4);
            // copyBoard(&p, &p2);
            // copyBoard(&p, &p4);

            createTree(&p,1,7);
            // createTree(&p2,1,2);
            // createTree(&p4,1,4);

            minimax(&p,0);
            // minimax(&p2,0);
            // minimax(&p4,0);


            // walkTreeRec(&p,0);
            // if (p2.value == 100){
            //     moveComputer(&p2,bestChildIndex(&p2),player);
            // }
            // else if (p4.value == 100){
            //     moveComputer(&p4,bestChildIndex(&p4),player);
            // }
            // else{
                moveComputer(&p,bestChildIndex(&p),player);
            // }
            deleteTree(&p);
            // deleteTree(&p2);
            // deleteTree(&p3);
        }
       
        printBoard(p.board);

    } while (!checkGlobalWin(p.board,player));

    return 0;
}
