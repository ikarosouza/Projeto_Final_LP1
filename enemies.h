#ifndef _ENEMIES_H_
#define _ENEMIES_H_

#include "enemy.h"
#include "player.h"

class Enemies {
  int total;
  Enemy *head;
  int enemy_points;
public:
  Enemies(int n);
  int getTotal() {return total;}
  void createList();
  void addEnemy();
  void printEnemies();
  void deleteEnemy(int enemy_id);
  int hit(ALLEGRO_MOUSE_STATE mouse, int dano);
  int getPoints() { return enemy_points; }
  void hitPlayer(Player *player);
  ~Enemies(); 
};

#endif