#include <iostream>
#include "ammo.h"

using namespace std;

Ammo::Ammo(){
  this->qtd = 15;
  for(int i = 0; i < qtd; i++){
    Bullet aux;
    aux.setDmg(10);
    aux.setNext(&bullets);
    bullets = aux;
  }
}

void Ammo::addQtd(int q){
  for(int i = qtd; i < qtd+q; i++){
    Bullet aux(10);
    aux.setNext(bullets.getNext());
    bullets = aux;
  }
  qtd += q;
}

void Ammo::popBullet(){
  if(qtd > 0){
    Bullet aux(10);
    aux = bullets;
    bullets = *(aux.getNext());
    qtd--;
  } else {
    cout << "Sem balas\n";
  }
}