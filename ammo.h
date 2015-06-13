#ifndef _AMMO_H_
#define _AMMO_H_

#include "bullet.h"

class Ammo {
  Bullet bullets;
  int qtd;
public:
  Ammo();
  int getQtd() { return qtd; };
  Bullet getBullet() { return bullets; }
  void addQtd(int q);
  int popBullet();
};

#endif