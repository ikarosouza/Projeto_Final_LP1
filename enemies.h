#ifndef _ENEMIES_H_
#define _ENEMIES_H_

#include "enemy.h"

class Enemies {
  int total;
  Enemy *head;
public:
  Enemies(int n);
  int getTotal() {return total;}
  void createList();
  void addEnemy();
  void printEnemies();
  void deleteEnemy(int enemy_id);
  void hit(ALLEGRO_MOUSE_STATE mouse, int dano);
  ~Enemies();
  
};

#endif