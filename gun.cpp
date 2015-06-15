#include <iostream>
#include "gun.h"

using namespace std;

Gun::Gun(){
  this->qtd = 20;
  this->tail = this->head = new Ammo();
}

void Gun::create(){
  for(int i=0; i<qtd; i++){
    insertAmmo();
  }
}

int Gun::shoot(int lvl){
  int dmg = lvl*head->getDmg();
  if(qtd > 0){
    removeAmmo();
    qtd--;
    return dmg;
  }
  return 0;
}

void Gun::reload(int q){
  for(int i=0; i<q; i++){
    insertAmmo();
  }
  qtd += q;
}

void Gun::insertAmmo(){
  Ammo *aux = new Ammo();
  tail->setNext(aux);
  tail = aux;
}

void Gun::removeAmmo(){
  Ammo *aux = head;
  this->head = head->getNext();
  delete aux;
}