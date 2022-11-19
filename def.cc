#include "def.hh"

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

cluster::cluster(point** setin)
{
  cluster::set = setin;
  cluster::recompute_centroid();
}

cluster::cluster(std::string path)
{
  cluster::set = import(path);
  cluster::recompute_centroid();
}

int cluster::display()
{
  if(cluster::set == NULL)
  {
    std::cout<<"Cluster empty"<<std::endl;
    return 0;
  }
  int i;
  for(i = 0;cluster::set[i]->id>=0;i++)
    std::cout<<cluster::set[i]->id<<") X:"<<cluster::set[i]->x<<", "<<"Y:"<<cluster::set[i]->y<<std::endl;
  return i;
}

void cluster::addpt(point* pt)
{
  cluster::set = (point**)realloc(cluster::set,(cluster::size+1)*sizeof(point*));
  cluster::set[cluster::size]=pt;
  cluster::size++;
  cluster::recompute_centroid();
}

void cluster::recompute_centroid()
{
    float cx = 0, cy = 0;
    int i;
    for(i = 0;cluster::set[i]->id>=0;i++)
    {
      cx+=cluster::set[i]->x;
      cy+=cluster::set[i]->y;
    }
    cluster::centroid.x = cx/i;
    cluster::centroid.y = cy/i;
    cluster::size = i;
}

float distance(point a, point b)
{
  return std::sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

cluster* clusterfit(cluster full)
{
  float distance_matrix[full.size][full.size];
  float dist_to_centroid[full.size];
  for(int i = 0;i<full.size;i++)
  {
    dist_to_centroid[i] = distance(full.set[i],full.centroid);
    for(int j = 0;j<i;j++)
      distance_matrix[i][j]=distance(full.set[i],full.set[j]);
  }

}
