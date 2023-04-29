#pragma once

class Pieza
{
private:
  int posx;
  int posy;
  char colorp;
 public:
  Pieza();
  Pieza(int x, int y, char c);
  virtual ~Pieza();
  void setPos(int x, int y);
  int getPos();
  void getColor();
};

