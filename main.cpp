//g++ main.cpp -o main $(pkg-config --cflags --libs allegro-5.0 allegro_native_dialog allegro_primitives allegro_ttf allegro_font)

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "option.h"

#define LARGURA 800
#define ALTURA 600

int main() {

  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_FONT *font = NULL;

  al_init();
  al_init_font_addon();
  al_init_ttf_addon();

  Option *option = new Option("Novo Jogo");

  al_set_new_display_flags(ALLEGRO_WINDOWED);

  display = al_create_display(LARGURA, ALTURA);
  font = al_load_font("primetime.ttf", 24, 0);
  al_clear_to_color(al_map_rgb(255, 255, 255));

  if (!display) {
    al_show_native_message_box(display, "Olá", "Opções do display", "Mensage,", NULL, 0);
  }

  al_set_window_title(display, "Delicia");
  option->draw();

  al_flip_display();

  bool finalizado = false;
  ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));

    while (!finalizado) {
      ALLEGRO_EVENT events;
      al_wait_for_event(event_queue, &events);

      if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        finalizado = true;
      }
    }
    al_destroy_display(display);
    al_destroy_font(font);

  return 0;
}