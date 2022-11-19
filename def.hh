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
cluster** import(point**);

class cluster
{
  public:
    cluster(point*);
    int display();
    int addpt(point);
    point centroid;
    point* set = NULL;
};

#endif
