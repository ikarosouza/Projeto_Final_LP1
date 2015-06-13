#include "gun.h"
#include "ammo.h"

int Gun::shoot(){
  return ammo.popBullet();
}