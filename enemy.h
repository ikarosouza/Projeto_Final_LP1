#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

struct Position{
  int x;
  int y;
};

class Enemy{
  static int total, lvl_base;
  int id;
  int life, dmg, drop, lvl;
  Position pos;
  ALLEGRO_BITMAP *enemy;
  ALLEGRO_BITMAP *enemy_shoot;
  bool is_alive;
  Enemy *next;
  ALLEGRO_FONT *font;
public:
  Enemy();
  int getId();
  Enemy* getNext() { return next; }
  void setNext(Enemy *enemy) { next = enemy; }
  void getHit(int hurt);
  bool isHover(ALLEGRO_MOUSE_STATE mouse);
  int shoot();
  void draw(); 
  bool getStatus(){ return is_alive; }
  Position getPos(){ return pos; }
  int getDrop() { return drop; }
  int getLvl() { return lvl; }
};

#endif