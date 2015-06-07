#ifndef _BULLET_H_
#define _BULLET_H_

class Bullet{
  int damage;
  Bullet *next;
public:
  Bullet(){};
  Bullet(int dmg);
  int getDmg() { return damage; };
  void setDmg(int dmg);
  Bullet* getNext() { return next; };
  void setNext(Bullet *nxt);
};
#endif