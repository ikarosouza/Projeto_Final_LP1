#include "gun.h"
#include "ammo.h"

void Gun::shootOne(){
  ammo.popBullet();
}