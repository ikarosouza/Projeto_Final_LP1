#include <iostream>
#include "bullet.h"

Bullet::Bullet(int dmg){
  damage = dmg;
  next = NULL;
}

void Bullet::setDmg(int dmg){
  damage = dmg;
}

void Bullet::setNext(Bullet *nxt){
  next = nxt;
}