#include "skillTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

Tree::Tree(){
  root=NULL;
}
void destroyNode(TreeNode *currNode){
    if(currNode!=NULL)
   {
     destroyNode(currNode->leftChild);
     destroyNode(currNode->rightChild);
     LLNode* LLHead = currNode->head;
     LLNode* crawler=LLHead;
     if(LLHead==NULL){

     }
     else{
       while(crawler!=NULL){
         crawler=crawler->next;
         delete LLHead;
         LLHead=crawler;
       }
     }
     delete currNode;
   }
 }
Tree::~Tree(){
  destroyNode(root);
}

void print(TreeNode *currNode){
   if(currNode!=NULL){
    print(currNode->leftChild);
    LLNode* crawler = currNode->head;
    while(crawler!=NULL){
      cout<<" >> ";
      cout<<crawler->title<<endl;
      crawler=crawler->next;
    }
    print(currNode->rightChild);
  }
 }

void Tree::printInventory(){
  if(root==NULL){

  }
  else{
    print(root);
  }
}

TreeNode* addNode(TreeNode *currNode, string class, int health, int damage,int speed,bool range,TreeNode *parent){
  if(currNode==NULL){
    TreeNode* newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->parent=parent;
    newNode->class=class;
    newNode->head=new LLNode(class,damage,health,speed,range);
    return newNode;
  }
  else if(currNode->pos == pos){
    LLMovieNode* crawler = currNode->head;
    LLMovieNode* prev=NULL;
    LLMovieNode* newNode = new LLNode(class,damage,health,speed,range);
    //this adds levels to the final class choice;
    while(crawler!=NULL){
      if(crawler->class>=newNode->class){
        break;
      }
      prev=crawler;
      crawler=crawler->next;
    }
    if(prev==NULL){
      newNode->next=crawler;
      currNode->head=newNode;
    }
    else{
      newNode->next=prev->next;
      prev->next=newNode;
    }
  }
  //how to orgnize the tree needs some work
  else if(currNode->pos < pos){
      currNode->rightChild = addNode(currNode->rightChild,ranking,title,year,rating,currNode);
  }
  else if(currNode->titleChar > title[0]){
      currNode->leftChild = addNode(currNode->leftChild,ranking,title,year,rating,currNode);
  }
  return currNode;
}

void Tree::addClass(string class, int health, int damage,int speed,bool range,int pos) {
  if(root == NULL){
    TreeNode* newNode = new TreeNode;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->class=class;
    newNode->head=new LLNode(class,damage,health,speed,range);
    root = newNode;
  }
  //this is called when the linked list has allready been built
  else{
    root = addNode(root,class,health,damage,speed,range);
  }
}
