#ifndef _OPTION_H_
#define _OPTION_H_

#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
using namespace std;

class Option {
  string option;
  ALLEGRO_COLOR color;
  int pos_x;
  int pos_y;
  ALLEGRO_FONT *font = NULL;

public:
  Option(string name);
  void draw();
  ~Option(){ al_destroy_font(font); };  
};

#endif