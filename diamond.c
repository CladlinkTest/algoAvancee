#include <stdio.h>
#include <stdlib.h>
#include "diamond.h"

int nbConfigurations;

/**********************************
   functions to mangage the board
***********************************/
board_t* createBoard()
{
  board_t* b = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour une board_t et mettre l'adresse dans b
     - "effacer" le plateau
     - mettre NO_NEIGHBOR dans toutes les cases du tableau b->neighbors
     - initialiser neighbors (cf. canevas Java)
  */

  return b;
}

void clearBoard(board_t* b) {
  /* A COMPLETER : cf. canevas Java
   */
}

int voidCellIndex(board_t* b) {
  int id = -1;
  /* A COMPLETER : cf. canevas Java

  */
  return id;
}

void computeScore(board_t* b) {

  /* A COMPLETER : cf. canevas Java
  */

}

void setPawn(board_t* b, int idCell, char value) {
  b->board[idCell] = value;
}


/**********************************
   functions to mangage the nodes
***********************************/

node_t* createNode(int idCell, int turn) {
  node_t* n = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour un node_t et mettre son adresse dans n
     - initialiser les champs idCell, turn, result, nbChildren (cf. canevas Java)
     - allouer l'espace mémoire pour children en fonction de turn (cf. canevas Java et énoncé)
  */
  return n;
}

node_t* addChild(node_t* n, int idCell) {
  node_t* child = NULL;
  /* A COMPLETER : 
     - créer un nouveau noeud child avec comme paramètre idCell et n->turn+1
     - ajouter child aux fils de n et incrémenter son nombre de fils     
  */
  return child;
}

/**********************************
   functions to mangage the tree
***********************************/

tree_t* createTree() {

  tree_t* t = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour un tree_t et mettre son adresse dans t
     - initialiser le champ root
  */

  return t;
}


void setFirstBlueChoice(tree_t* t, board_t* b, int idCell)
{
  /* A COMPLETER : cf. canevas Java
  */
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


