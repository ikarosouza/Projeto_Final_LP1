#include <iostream>
#include "enemy.h"

using namespace std;

int Enemy::total = 0;

Enemy::Enemy(int lvl){
  total++;
  this->id = total;
  this->life = 100 - 5*(10/lvl);
  this->lvl = lvl;
  this->dmg = 5 + 2*lvl;
  this->drop = 0;
  this->pos.x = rand() % 900 + 1;
  this->pos.y = 300;
  enemy = al_load_bitmap("enemy.png");
  is_alive = true;
  next = NULL;
  font = al_load_font("Roboto-Regular.ttf", 25, 0);
}

int Enemy::getId(){
  return id;
}

void Enemy::getHit(int hurt){
  if(life-hurt > 0){
    this->life-= hurt;
  } else {
    if(is_alive){
      is_alive = false;
    }
  }
}

bool Enemy::isHover(ALLEGRO_MOUSE_STATE mouse){
  
  if(mouse.x >= pos.x && mouse.x <= pos.x + 130){
    if(mouse.y >= pos.y && mouse.x <= pos.x + 180){
      cout << "Inimigo: " << id << ": " << life << endl;
      return true;
    } 
  } else {
    return false;
  }  
}

void Enemy::draw(){
    al_draw_bitmap(enemy, pos.x, pos.y, 0);
    cout << "ENEMY " << id << " X: " << pos.x << " Y: " << pos.y << endl;
    al_draw_textf(font, al_map_rgb(255,0,0), pos.x+80, pos.y-30, ALLEGRO_ALIGN_CENTRE, "INIMIGO: %i", id);
}
