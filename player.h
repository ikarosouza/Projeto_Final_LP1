#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "gun.h"
#include "life.h"

class Player {
  int lvl, score;
  int pos_x, pos_y;
  bool is_down;
  Gun *gun;
  Life *life;
  ALLEGRO_BITMAP *soldier;
  ALLEGRO_BITMAP *soldier_shoot;
  ALLEGRO_BITMAP *scope;
  ALLEGRO_FONT *font;
public:
  Player(int x, int y);
  // int getLife() { return life; }
  // void setLife(int l);
  // int getLvl() { return lvl; }
  // void setLvl(int l);
  // void getHit();
  void drawScope(int mouse_x, int mouse_y);
  void draw();
  void getDown();
  void getUp();
  int shoot();
  bool getIsDown() {return is_down;}
  void gainDrop(int drop);
  void addScore(int n);
  int getScore() { return score; }
  void lossLife(int hit);
  ~Player();
  
};

#endif