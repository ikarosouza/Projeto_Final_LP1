#include <iostream>
#include "enemy.h"

using namespace std;

int Enemy::total = 0;
int Enemy::lvl_base = 10;

Enemy::Enemy(){
  total++;
  this->id = total;
  if(total%10 == 0){
    lvl_base--;
  }
  this->lvl = lvl_base;
  this->life = (lvl)*10;
  this->dmg = 5 + 2*lvl;
  this->drop = 0;
  this->pos.x = rand() % 880 + 11;
  this->drop = rand() % 3 + 1;
  this->pos.y = 300;
  enemy = al_load_bitmap("enemy.png");
  enemy_shoot = al_load_bitmap("enemy_shoot.png");
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
  if((mouse.x >= pos.x && mouse.x <= pos.x + 130) && (mouse.y >= pos.y && mouse.y <= pos.y + 180)){
    cout << "Inimigo: " << id << ": " << life << endl;
    return true;
  } else {
    return false;
  }  
}

int Enemy::shoot(){
  al_draw_bitmap(enemy_shoot, pos.x, pos.y, 0);
  al_flip_display();
  al_rest(0.1);

  return dmg;
}

void Enemy::draw(){
    al_draw_bitmap(enemy, pos.x, pos.y, 0);
    al_draw_textf(font, al_map_rgb(255,0,0), pos.x+80, pos.y-30, ALLEGRO_ALIGN_CENTRE, "INIMIGO: %i", id);
}
