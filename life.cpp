#include <iostream>
#include "life.h"

using namespace std;

Life::Life(){
  this->qtd = 100;
  this->head = new LifeUnit();
}

void Life::create(){
  for(int i = 0; i < qtd; i++){
    addLife();
  }
}

void Life::addLife(){
  LifeUnit* aux = new LifeUnit();
  aux->setNext(head);
  head = aux;
  cout << head << endl;
}

void Life::popLife(){
  LifeUnit* aux = new LifeUnit();
  aux = head;
  head = head->getNext();
  aux->setNext(NULL);
  delete aux;
  qtd--;
}

void Life::getHit(int n){
  for(int i = 0; i < n; i++){
    popLife();
  }
}

void Life::gainLife(int l){
  for(int i = 0; i < qtd; i++){
    addLife();
  }
  qtd += l;
}