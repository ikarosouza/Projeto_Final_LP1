#include <iostream>
#include "player.h"
#include "gun.h"

using namespace std;

Player::Player(int x, int y): gun(){
  this->life = 100;
  this->lvl = 1;
  this->pos_x = x;
  this->pos_y = y;
  this->is_down = false;
  gun = new Gun();
  al_init_font_addon();
  al_init_ttf_addon();
  soldier = al_load_bitmap("soldier.png");
  scope = al_load_bitmap("scope.png");
  qtdAmmo = al_load_font("Roboto-Regular.ttf", 25, 0);
}

void Player::drawScope(int mouse_x, int mouse_y){
  int bullets = gun->getAmmo().getQtd();
  al_draw_bitmap(scope, mouse_x-63, mouse_y-64, 0);
  al_draw_textf(qtdAmmo, al_map_rgb(0,255,255), 5, 5, ALLEGRO_ALIGN_LEFT, "Ammo: %i", bullets);
}

void Player::draw(){
  al_draw_bitmap(soldier, pos_x, pos_y, 0);
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

void Player::shoot(){
  gun->shootOne();
}

Player::~Player(){
  al_destroy_bitmap(scope);
  al_destroy_bitmap(soldier);
}