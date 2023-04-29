#pragma once

class Pieza
{
  int posx;
  int posy;
  char colorp;
 public:
  Pieza();
  Pieza(int x, int y, char c);
  virtual ~Pieza();
  void setPos();
  void getPos();
  void getColor();
};

