#ifndef _AMMO_H_
#define _AMMO_H_

#include <iostream>

class Ammo {
  int dmg;
  Ammo *next;
public:
  Ammo();
  int getDmg() { return dmg; };
  Ammo* getNext() { return next; }
  void setNext(Ammo *n) { next = n; };
  int popBullet();
};

#endif

inline Ammo::Ammo(){
  dmg = 10;
  next = NULL;
}