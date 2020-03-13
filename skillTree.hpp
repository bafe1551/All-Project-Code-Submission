/****************************************************************/
/*                  MovieTree Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

using namespace std;
#ifndef SKILLTREE_HPP
#define SKILLTREE_HPP
#include <string>

/* Linked List node structure that will be stored at each node in the BST*/
struct LLNode
{
  string class;
  int damage;
  int speed;
  int health;
  bool range;
  struct Node* next;   // Pointer to the next node

  LLNode(){} // default constructor

  // Parametrized constructor
  LLNode(string c,int d, int h, int s,bool r) {
    class=c;
    damage=d;
    health=h;
    speed=s;
    range=r;
  }
};

/* Node struct that will be stored in the MovieTree BST */

struct TreeNode
{
  int pos;
  LLNode* head = NULL;    // Pointer to the head node of a LL
  TreeNode *leftChild = NULL;  // Pointer to its leftChild in BST
  TreeNode *rightChild = NULL; // Pointer to its rightChild in BST
};

/* Class for storing and manipulating the TreeNode's of BST*/

class Tree
{
    public:
      // Check writeup for detailed function descriptions
      Tree();
      ~Tree();
      void printInventory();
      void addClass(string class, int health, int damage,int speed,bool range,int pos);
    private:
      TreeNode *root;
};

#endif
