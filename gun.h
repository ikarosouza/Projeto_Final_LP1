#ifndef _GUN_H_
#define _GUN_H_

#include "ammo.h"

class Gun {
  Ammo ammo;
public:
  Gun(): ammo(){};
  Ammo getAmmo() { return ammo; }
  void shootOne();
};

#endif

