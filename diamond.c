#include <stdio.h>
#include <stdlib.h>
#include "diamond.h"

int nbConfigurations;


/**********************************
   functions to mangage the board
***********************************/

/**
 *
    A COMPLETER :
    - allouer l'espace mémoire pour une board_t et mettre l'adresse dans b
    - "effacer" le plateau
    - mettre NO_NEIGHBOR dans toutes les cases du tableau b->neighbors
    - initialiser neighbors (cf. canevas Java)

 * @return
 */
board_t* createBoard()
{
    int i,j;
    board_t* b = NULL;
    b = malloc(sizeof(board_t));
        clearBoard(b);
    b->neighbors;
    for (i=0;i<BOARD_LENGTH;i++)
        for (j=0;j<NEIGHBORS_LENGTH;j++)
            b->neighbors[i][j] = NO_NEIGHBOR;

    // define b->neighbors for cell 0
    b->neighbors[0][0] = 1;
    b->neighbors[0][1] = 3;
    b->neighbors[0][2] = 4;
    // define b->neighbors for cell 1
    b->neighbors[1][0] = 0;
    b->neighbors[1][1] = 2;
    b->neighbors[1][2] = 4;
    b->neighbors[1][3] = 5;
    // define b->neighbors for cell 2
    b->neighbors[2][0] = 1;
    b->neighbors[2][1] = 5;
    b->neighbors[2][2] = 6;
    // define b->neighbors for cell 3
    b->neighbors[3][0] = 0;
    b->neighbors[3][1] = 4;
    b->neighbors[3][2] = 7;
    // define b->neighbors for cell 4
    b->neighbors[4][0] = 0;
    b->neighbors[4][1] = 1;
    b->neighbors[4][2] = 3;
    b->neighbors[4][3] = 5;
    b->neighbors[4][4] = 7;
    b->neighbors[4][5] = 8;
    // define b->neighbors for cell 5
    b->neighbors[5][0] = 1;
    b->neighbors[5][1] = 2;
    b->neighbors[5][2] = 4;
    b->neighbors[5][3] = 6;
    b->neighbors[5][4] = 8;
    b->neighbors[5][5] = 9;
    // define b->neighbors for cell 6
    b->neighbors[6][0] = 2;
    b->neighbors[6][1] = 5;
    b->neighbors[6][2] = 9;
    // define b->neighbors for cell 7
    b->neighbors[7][0] = 3;
    b->neighbors[7][1] = 4;
    b->neighbors[7][2] = 8;
    b->neighbors[7][3] = 10;
    // define b->neighbors for cell 8
    b->neighbors[8][0] = 4;
    b->neighbors[8][1] = 5;
    b->neighbors[8][2] = 7;
    b->neighbors[8][3] = 9;
    b->neighbors[8][4] = 10;
    b->neighbors[8][5] = 11;
    // define b->neighbors for cell 9
    b->neighbors[9][0] = 5;
    b->neighbors[9][1] = 6;
    b->neighbors[9][2] = 8;
    b->neighbors[9][3] = 11;
    // define b->neighbors for cell 10
    b->neighbors[10][0] = 7;
    b->neighbors[10][1] = 8;
    b->neighbors[10][2] = 11;
    b->neighbors[10][3] = 12;
    // define b->neighbors for cell 11
    b->neighbors[11][0] = 8;
    b->neighbors[11][1] = 9;
    b->neighbors[11][2] = 10;
    b->neighbors[11][3] = 12;
    // define b->neighbors for cell 12
    b->neighbors[12][0] = 10;
    b->neighbors[12][1] = 11;

  return b;
}

void clearBoard(board_t* b)
{
    for(int i=0;i<BOARD_LENGTH;i++)
        b->board[i] = VOID_CELL;
    b->blueScore = 0;
    b->redScore = 0;
}

int voidCellIndex(board_t* b)
{
  int id = -1;
    for(int i=0;i<BOARD_LENGTH;i++)
        if (b->board[i] == VOID_CELL)
            return i;
    return id; // abnormal case.
}

void computeScore(board_t* b)
{
    b->blueScore = 0;
    b->redScore = 0;
    int idVoid = voidCellIndex(b);
    for(int i=0;i<NEIGHBORS_LENGTH;i++)
        if (b->neighbors[idVoid][i] != NO_NEIGHBOR)
            if (b->board[b->neighbors[idVoid][i]] <= NEIGHBORS_LENGTH)
            {
                b->blueScore += b->board[b->neighbors[idVoid][i]];
            }
            else
            {
                b->redScore += (b->board[b->neighbors[idVoid][i]]-NEIGHBORS_LENGTH);
            }
}

void setPawn(board_t* b, int idCell, char value)
{
  b->board[idCell] = value;
}


/**********************************
   functions to mangage the nodes
***********************************/

/**
 *  A COMPLETER :
 *   - allouer l'espace mémoire pour un node_t et mettre son adresse dans n
 *   - initialiser les champs idCell, turn, result, nbChildren (cf. canevas Java)
 *   - allouer l'espace mémoire pour children en fonction de turn (cf. canevas Java et énoncé)
 * @param idCell
 * @param turn
 * @return
 */
node_t* createNode(int idCell, int turn)
{
    node_t* n = NULL;
    n = (node_t*)malloc(sizeof(node_t));
    n->idCell = (char)idCell;
    n->turn = (char)turn;
    if(turn == 1)
        n->children = (node_t**)malloc(sizeof(node_t));
    else if(turn<12)
        n->children = (node_t**)malloc(sizeof(node_t)*(13-turn));
    else
        n->nbChildren = NULL;
    n->nbChildren = 0;
    n->result = NO_RESULT;

    return n;
}

/**
 * A COMPLETER :
 *   - créer un nouveau noeud child avec comme paramètre idCell et n->turn+1
 *   - ajouter child aux fils de n et incrémenter son nombre de fils
 * @param n
 * @param idCell
 * @return
 */
node_t* addChild(node_t* n, int idCell)
{
    node_t* child = NULL;
    child = createNode(idCell, n->turn+1);
    n->children[n->nbChildren] = child;
    n->nbChildren = (char)(n->nbChildren+1);

    return child;
}

/**********************************
   functions to mangage the tree
***********************************/

/**
 * A COMPLETER :
 *     - allouer l'espace mémoire pour un tree_t et mettre son adresse dans t
 *     - initialiser le champ root
 * @return
 */
tree_t* createTree()
{
    tree_t* t = NULL;
    t = (tree_t*)malloc(sizeof(tree_t));
    t->root = NULL;
    nbConfigurations =0;

    return t;
}

/**
 * A COMPLETER : cf. canevas Java
 * @param t
 * @param b
 * @param idCell
 */
void setFirstBlueChoice(tree_t* t, board_t* b, int idCell)
{
    t->root = createNode(idCell,1);
    setPawn(b,idCell,1);
}

void setFirstRedChoice(tree_t* t, board_t* b, int idCell)
{
    /* A COMPLETER : cf. canevas Java
     */
}

void buildTree(tree_t* t, board_t* b)
{
    /* A COMPLETER : cf. canevas Java
    */
}

void computePossibilities(node_t* n, board_t* b)
{

    /* A COMPLETER : cf. canevas Java
    */

}

int computeBlueVictories(node_t* n)
{
    int nb = 0;
    /* A COMPLETER :
    */
    return nb;
}

int computeRedVictories(node_t* n)
{
    int nb = 0;
    /* A COMPLETER :
    */
    return nb;

}

int computeDraws(node_t* n)
{
    int nb = 0;
    /* A COMPLETER :
    */
    return nb;

}


