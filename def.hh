#ifndef DEF_H
#define DEF_H
#include<iostream>
#include<string>
#include <fstream>

typedef struct point
{
  int id;
  float x;
  float y;
}pt;

typedef struct edge
{
  int p1;
  int p2;
}edge;

point** import(std::string);

class cluster
{
  point* set = NULL;
  public:
    cluster(point*);
    int display();
    point centroid;
};

#endif
