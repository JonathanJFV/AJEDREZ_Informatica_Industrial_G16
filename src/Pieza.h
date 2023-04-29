#pragma once

class Pieza
{
private:
  int posx;
  int posy;
  char colorp;
 public:
  Pieza();
  virtual ~Pieza();
  void setPos(int x, int y);
  float getPos(float pos);
  char getColor();
};

