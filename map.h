#ifndef _MAP_H_
#define _MAP_H_

class Map {
  ALLEGRO_BITMAP *wall;
  ALLEGRO_BITMAP *back;
public:
  int width, height;
  // Campeao *campeoes[10];
  // int campeao_ptr;
  // Projetil *projeteis_no_mapa[10000];
  // int projeteis_ptr;

  Map(int width, int height);
  void drawBack();
  void drawWall();
  ~Map();
  // void adicionar_campeao(Campeao *campeao);

  // void adicionar_projetil(Projetil *projetil);

  // void avancar_tempo();
};

#endif