#ifndef DEF_H
#define DEF_H
#include<iostream>
#include<string>
#include <fstream>
#include<cmath>
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

class cluster
{
  public:
    cluster(point**);
    cluster(std::string);
    int display();
    void addpt(point*);
    point centroid;
    point** set = NULL;
    int size;
  private:
    void recompute_centroid();
};


point** import(std::string);
void clusterdf(point**);

#endif
