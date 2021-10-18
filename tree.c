#include "tree.h"

void copyBoard(Node *p, Node *copy){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            copy->board[i][j] = p->board[i][j];
        }
    }
}
int calculateChildren(char board[N][N]){
    int children = 0;
    for (int j=0; j < N; j++){
        if (board[N-1][j]==0){
            children++;
        }
    }

    return children;
}

int bestChildIndex(Node *p){
  for (int i=0; i < p->n_children; i++){
      if (p->children[i]->value == p->value){
          return i;
      }
  }
}

void moveComputer(Node *p, int index, int player){
    int column = 0;
    for (int j=0; j < N; j++){
        if (p->board[N-1][j]==0){
            column++;
        }
        if (column == index+1){
            column = j;
            break;
        }
    }
    for (int i=0; i<N; i++){
        if (p->board[i][column]==0){
            p->board[i][column]=player;
            break;
        }
    }

}
Node *createNode(Node *parent,int index,int level, int maxlevel) {
    Node *p = malloc(sizeof(Node));
    copyBoard(parent,p);
    moveComputer(p,index,level%2 + 1);
    if (level<maxlevel) {
        p->value=score(p);
        if (p->value == 100 && p->value == -100){
            p->n_children=0;
            p->children=malloc(p->n_children * sizeof(Node *));
        }
        else{
            p->n_children=calculateChildren(p->board);
            p->children=malloc(p->n_children * sizeof(Node *));
        }
    }
    else {
        p->n_children=0;
        p->children=NULL;
        p->value=score(p);
    }
    return p;
}


void deleteLevel(Node *parent) {
    free(parent->children);
}

void deleteTree(Node *root) {
    for(int i=0;i<root->n_children;i++){
        deleteTree(root->children[i]);
    }
    deleteLevel(root);
}

void createLevel(Node *parent,int level, int maxlevel) {
    for(int i=0;i<parent->n_children;i++){
        parent->children[i]=createNode(parent,i,level,maxlevel);
    }
}
void initializeRoot(Node *root){
    root->n_children = calculateChildren(root->board);
    root->children=malloc(root->n_children * sizeof(Node *));
}

void createTree(Node *root, int level, int maxlevel) {
    createLevel(root,level, maxlevel);
    for(int i=0;i<root->n_children;i++){
        createTree(root->children[i],level+1, maxlevel);
    }
}



void showNode(Node *p, int level)
{
       for (int i = 0; i < level; i++)
       {
                  printf("\t");
       }
          printf("-  %d\n", p->value);
}
void showLevel(Node *father, int level)
{
       for (int i = 0; i < father->n_children; i++)
       {
                  showNode(father->children[i], level);
       }
}
void walkTreeRec(Node *root, int level)
{
       showNode(root, level);

          for (int i = 0; i < root->n_children; i++)
          {
                     walkTreeRec(root->children[i], level + 1);
          }
}
