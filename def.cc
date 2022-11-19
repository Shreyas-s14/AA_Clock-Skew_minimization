#include "def.hh"


cluster::cluster(point* setin)
{
  cluster::set = setin;
}

int cluster::display()
{
  if(cluster::set == NULL)
  {
    std::cout<<"Cluster empty"<<std::endl;
    return 0;
  }
  int i;
  for(i = 0;cluster::set[i].id<0;i++)
    std::cout<<cluster::set[i].id<<") X:"<<cluster::set[i].x<<", "<<"Y:"<<cluster::set[i].y<<std::endl;
  return i;
}

point** import(std::string path)
{
  std::ifstream infile(path);
  float a,b;
  int c=0;
  point** arr = (point**)malloc(1000*sizeof(point*));
  while (infile >> a >> b)
  {
    arr[c] = (point*)malloc(sizeof(point));
    arr[c]->x = a;
    arr[c]->y = b;
    arr[c]->id = c;
    c++;
  }
  arr[c] = (point*)malloc(sizeof(point));
  arr[c]->id=-1;
  arr = (point**)realloc(arr,(c+1)*sizeof(point*));
  return arr;
}
