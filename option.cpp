#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "option.h"

using namespace std;

Option::Option(string name){
  this->option = name;
  this->color = al_map_rgb(255, 250, 0);
  this->pos_x = 100;
  this->pos_y = 50;
  this->font = al_load_font("primetime.ttf", 24, 0);
}

void Option::draw(){
  al_draw_text(font, color, pos_x, pos_y, ALLEGRO_ALIGN_CENTRE, "Novo Jogo");
}