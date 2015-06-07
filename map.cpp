#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "map.h"


Map::Map(int width, int height) {
  this->width = width;
  this->height = height;
  al_init_image_addon();
  this->wall = al_load_bitmap("wall.png");
  this->back = al_load_bitmap("background.png");
}

void Map::draw(){
  al_draw_bitmap(back, 0,0, 0);
  al_draw_bitmap(wall, 0,height - 400 , 0);
}

Map::~Map(){
  al_destroy_bitmap(back);
  al_destroy_bitmap(wall);
}