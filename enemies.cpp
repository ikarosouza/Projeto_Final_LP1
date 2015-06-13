#include <iostream>
#include "enemies.h"
#include "enemy.h"

using namespace std;

Enemies::Enemies(int n){
  this->head = new Enemy(1);
  this->total = n;
}

void Enemies::createList(){
  for(int i = 0; i < total; i++){
    addEnemy();  
  }
}

void Enemies::printEnemies(){
  int j = 0;
  for(Enemy *i = head; i !=NULL && j < 5; i = i->getNext(), j++){
    cout << "J = " << j << endl;
    i->draw();
  }
}

void Enemies::addEnemy(){
    Enemy* aux = new Enemy(1);
    aux->setNext(head);
    head = aux;
    cout << "Inimigo " << aux->getId() << " adicionado\n";
}

void Enemies::deleteEnemy(int enemy_id){
  Enemy* aux = new Enemy(1);
  if (head->getId() == enemy_id){
      aux = head;
      head = head->getNext();
      aux->setNext(NULL);
    } else {
      for(Enemy *i = head; i !=NULL; i = i->getNext()){
        if(i->getNext() && i->getNext()->getId() == enemy_id){
          aux = i->getNext();
          i->setNext(aux->getNext());
          //aux->setNext(NULL);
        } 
      }
    }
  delete(aux);
  total--;
}

void Enemies::hit(ALLEGRO_MOUSE_STATE mouse, int dano){
  for(Enemy *i = head; i !=NULL; i = i->getNext()){
    if(i->isHover(mouse) == true){
      //cout << "acertou o inimigo " << i->getId() << endl;
      i->getHit(dano);
      if(!i->getStatus()){
        deleteEnemy(i->getId());
      }
      break;
    }
  }
}