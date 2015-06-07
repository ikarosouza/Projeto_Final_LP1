#include <iostream>
#include <allegro5/allegro.h>
#include "map.h"
#include "player.h"

#define WIDTH 1000
#define HEIGHT 700

using namespace std;

int main(){
  ALLEGRO_DISPLAY *display;

  const float FPS = 60.0;
  bool end = false;
  int mouse_x = 0, mouse_y = 0;

  if (!al_init()) {
    cout << "Erro ao inicializar allegro" << endl;
    return -1;    
  }

  al_set_new_display_flags(ALLEGRO_WINDOWED);

  display = al_create_display(WIDTH, HEIGHT);

  al_set_window_title(display, "Teste");

  al_install_keyboard();
  al_install_mouse();

  Map *map = new Map(WIDTH, HEIGHT);
  map->draw();
  Player *player = new Player(WIDTH - 600, HEIGHT - 279);
  player->draw();
  al_flip_display();

  
  ALLEGRO_MOUSE_STATE mouse;
  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());

  

  while (!end) {
      ALLEGRO_EVENT events;
      al_wait_for_event(event_queue, &events);

      if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
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
        cout << "x: " << mouse.x << " y:" << mouse.y << endl;
      }

      if(al_mouse_button_down(&mouse, 1)){ 
        player->shoot();
      }

      if((mouse_x != mouse.x) || (mouse_y != mouse.y)){
        mouse_x = mouse.x;
        mouse_y = mouse.y; 
      }

      map->draw();
      player->draw();
      player->drawScope(mouse_x, mouse_y);
      al_flip_display(); 
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

  return 0;
}