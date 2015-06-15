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

#define TOTAL_ENEMIES 100
using namespace std;

int main(){
  srand (time(NULL));
  ALLEGRO_DISPLAY *display;
  ALLEGRO_TIMER *timer = NULL;
  ALLEGRO_FONT *font;

  const float FPS = 30.0;
  bool end = false;
  int mouse_x = 0, mouse_y = 0, enemy_drop = 0;
  long int currentTime = 0;
  int minutes = 9, seconds = 60;

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
  map->drawBack();
  list->printEnemies();
  map->drawWall();
  player->draw();
  

  al_flip_display();

  
  ALLEGRO_MOUSE_STATE mouse;
  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  
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

    if(events.keyboard.keycode == ALLEGRO_KEY_S){
      player->getDown();
    }

    if(events.keyboard.keycode == ALLEGRO_KEY_W){
      player->getUp();
    }

    if(events.type == ALLEGRO_EVENT_MOUSE_AXES) {
      al_get_mouse_state(&mouse);
      //cout << "MOUSE x: " << mouse.x << " y:" << mouse.y << endl;
    }

    if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
      if(!player->getIsDown()){
        enemy_drop = list->hit(mouse, player->shoot());
        if(enemy_drop != 0){
          if(enemy_drop == 3){
            seconds += 10;
          }
          player->gainDrop(enemy_drop);
          player->addScore(list->getPoints());
          cout << "PONTOS: " << list->getPoints() << endl;
          enemy_drop = 0;
        }
      }
    }

    if((mouse_x != mouse.x) || (mouse_y != mouse.y)){
      mouse_x = mouse.x;
      mouse_y = mouse.y; 
    }

    if(seconds%3 == 0 && currentTime != al_get_timer_count(timer)/30){
      list->hitPlayer(player);
    }

    if(events.type == ALLEGRO_EVENT_TIMER) {
      if(currentTime != al_get_timer_count(timer)/30){
        currentTime = al_get_timer_count(timer)/30;
        cout << "SEC: " << seconds << endl;
        seconds = 60 - currentTime%60;
        if(seconds == 60){
          minutes = minutes - 1;
        }
      }
      map->drawBack();
      list->printEnemies();
      map->drawWall();

      if(seconds == 60 && minutes == 9){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: %i:00", minutes+1);
      }else if(seconds == 60 && minutes < 9){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: 0%i:00", minutes+1);
      } else if(seconds < 10 && minutes >= 10){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: %i:0%i", minutes, seconds);
      } else if(seconds >= 10 && minutes >= 10){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: %i:%i", minutes, seconds);
      } else if(seconds >= 10 && minutes < 10){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: 0%i:%i", minutes, seconds);
      } else if(seconds < 10 && minutes < 10){
        al_draw_textf(font, al_map_rgb(55,255,255), 450, 5, ALLEGRO_ALIGN_CENTRE, "Time: 0%i:0%i", minutes, seconds);
      }
      player->draw();
      player->drawScope(mouse_x, mouse_y);

      al_flip_display();
    }
  }

  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);

  return 0;
}