#ifndef _LIFE_H_
#define _LIFE_H_

#include "lifeUnit.h"

class Life{
  int qtd;
  LifeUnit *head;
public:
  Life();
  void create();
  void addLife();
  void popLife();
  void getHit(int n);
  int getQtd() { return qtd; }
  void gainLife(int l);
};

#endif