#include <iostream>
#include <cstdlib> 
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "enemies.h"

#define WIDTH 1000
#define HEIGHT 700

#define TOTAL_ENEMIES 20
using namespace std;

int main(){
  srand (time(NULL));
  ALLEGRO_DISPLAY *display;
  ALLEGRO_TIMER *timer = NULL;
  ALLEGRO_FONT *font;

  const float FPS = 60.0;
  bool end = false;
  int mouse_x = 0, mouse_y = 0;
  long int currentTime = 0;

 


  if (!al_init()) {
    cout << "Erro ao inicializar allegro" << endl;
    return -1;    
  }
  al_init_font_addon();
  al_init_ttf_addon();

  timer = al_create_timer(1.0 / FPS);

  font = al_load_font("Roboto-Regular.ttf", 25, 0);

  al_set_new_display_flags(ALLEGRO_WINDOWED);

  display = al_create_display(WIDTH, HEIGHT);

  al_set_window_title(display, "Teste");

  al_install_keyboard();
  al_install_mouse();

  Map *map = new Map(WIDTH, HEIGHT);

  
  Player *player = new Player(WIDTH - 600, HEIGHT - 279);
  Enemies* list = new Enemies(TOTAL_ENEMIES);
  list->createList();
  
  //Enemy *enemy = new Enemy(1);
  //Enemy *enemy2 = new Enemy(1);
  map->drawBack();
  //enemy->draw();
  //enemy2->draw();
  list->printEnemies();
  map->drawWall();
  player->draw();
  //cout << "ID: " << enemy->getId() << endl;
  //cout << "ID2: " << enemy2->getId() << endl;

  

  al_flip_display();

  
  ALLEGRO_MOUSE_STATE mouse;
  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  //al_register_event_source(event_queue, al_get_timer_event_source(timer));
  
al_start_timer(timer);
  while (!end) {
    
    ALLEGRO_EVENT events;
    al_wait_for_event(event_queue, &events);

    // if(events.type == ALLEGRO_EVENT_TIMER) {
    //   currentTime = ;
    // }

    if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
      al_stop_timer(timer);
      break;
    }

    if(events.keyboard.keycode == ALLEGRO_KEY_DOWN){
      player->getDown();
    }

    if(events.keyboard.keycode == ALLEGRO_KEY_UP){
      player->getUp();
    }

    if(events.type == ALLEGRO_EVENT_MOUSE_AXES) {
      al_get_mouse_state(&mouse);
      cout << "MOUSE x: " << mouse.x << " y:" << mouse.y << endl;
    }

    if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ 
      list->hit(mouse, player->shoot());
    }

    if((mouse_x != mouse.x) || (mouse_y != mouse.y)){
      mouse_x = mouse.x;
      mouse_y = mouse.y; 
    }


    map->drawBack();
    // if(enemy->getStatus()){
    //   enemy->draw();
    // }
    list->printEnemies();
    map->drawWall();
    al_draw_textf(font, al_map_rgb(20,255,255), 350, 5, ALLEGRO_ALIGN_CENTRE, "Time: %li", 1000 - al_get_timer_count(timer));
    player->draw();
    player->drawScope(mouse_x, mouse_y);

    al_flip_display(); 
  }

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);

  return 0;
}