#include <iostream>
#include "enemies.h"
#include "enemy.h"

using namespace std;

Enemies::Enemies(int n){
  this->head = new Enemy();
  this->total = n;
  this->enemy_points = 0;
}

void Enemies::createList(){
  for(int i = 1; i < total; i++){
    addEnemy();  
  }
}

void Enemies::printEnemies(){
  int j = 0;
  for(Enemy *i = head; i !=NULL && j < 5; i = i->getNext(), j++){
    i->draw();
  }
}

void Enemies::addEnemy(){
    Enemy* aux = new Enemy();
    aux->setNext(head);
    head = aux;
    cout << "Inimigo " << aux->getId() << " adicionado\n";
}

void Enemies::deleteEnemy(int enemy_id){
  Enemy* aux = new Enemy();
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
  enemy_points = 10*aux->getLvl();
  delete aux;
  total--;
}

int Enemies::hit(ALLEGRO_MOUSE_STATE mouse, int dano){
  int drop = 0, j = 0;
  for(Enemy *i = head; i !=NULL && j < 5; i = i->getNext(), j++){
    if(i->isHover(mouse) == true){
      cout << "acertou o inimigo " << i->getId() << endl;
      i->getHit(dano);
      if(!i->getStatus()){
        drop = i->getDrop();
        deleteEnemy(i->getId());
      }
      break;
    }
  }
  return drop;
}

void Enemies::hitPlayer(Player *player){
  int random = rand() % 5;
  Enemy *i = head;
  if(!player->getIsDown()){
    for(int j = 0; j < random; i = i->getNext(), j++);
    player->lossLife(i->shoot());
  }
}