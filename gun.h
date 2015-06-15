#ifndef _GUN_H_
#define _GUN_H_

#include "ammo.h"

class Gun {
  int qtd;
  Ammo *head;
  Ammo *tail;
public:
  Gun();
  int getAmmo() { return qtd; }
  void create();
  int shoot(int lvl);
  void reload(int q);
  void insertAmmo();
  void removeAmmo();
};

#endif