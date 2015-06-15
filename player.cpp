#include <iostream>
#include "player.h"

using namespace std;

Player::Player(int x, int y): gun(){
  this->lvl = 1;
  this->score = 0;
  this->pos_x = x;
  this->pos_y = y;
  this->is_down = false;
  gun = new Gun();
  gun->create();
  life = new Life();
  life->create();
  al_init_font_addon();
  al_init_ttf_addon();
  soldier = al_load_bitmap("soldier.png");
  soldier_shoot = al_load_bitmap("soldier_shoot.png");
  scope = al_load_bitmap("scope.png");
  font = al_load_font("Roboto-Regular.ttf", 25, 0);
}

void Player::drawScope(int mouse_x, int mouse_y){
  int ammo = gun->getAmmo();
  al_draw_bitmap(scope, mouse_x-63, mouse_y-64, 0);
  al_draw_textf(font, al_map_rgb(0,255,255), 5, 5, ALLEGRO_ALIGN_LEFT, "Ammo: %i", ammo);
}

void Player::draw(){
  al_draw_bitmap(soldier, pos_x, pos_y, 0);
  al_draw_textf(font, al_map_rgb(255,0,0), 850, 5, ALLEGRO_ALIGN_LEFT, "SCORE: %i", score);
  al_draw_textf(font, al_map_rgb(255,0,0), 5, 40, ALLEGRO_ALIGN_LEFT, "LIFE: %i", life->getQtd());
}

void Player::getDown(){
  if(!is_down){
    this->pos_y+=100;
    is_down = true;
  }
  //draw();
}

void Player::getUp(){
  if(is_down){
    this->pos_y-=100;
    is_down = false; 
  }
  //draw();
}

int Player::shoot(){
  al_draw_bitmap(soldier_shoot, pos_x, pos_y, 0);
  al_flip_display();
  al_rest(0.1);
  return gun->shoot(lvl);
}

void Player::gainDrop(int drop){
  if(drop == 1){
    life->gainLife(10);
  } else if(drop == 2){
    gun->reload(5);
  }
}

void Player::addScore(int n){
  score += n; 
}

void Player::lossLife(int hit){
  this->life->getHit(hit);
}

Player::~Player(){
  al_destroy_bitmap(scope);
  al_destroy_bitmap(soldier);
}