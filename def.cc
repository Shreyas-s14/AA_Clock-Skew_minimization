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
    arr[c]->hl = 1;
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
    cluster::centroid.hl = 0;
    cluster::size = i;
}

float distance(point a, point b)
{
  return std::sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

cluster* clusterfit(cluster full)
{
  if(full.size >= 1)
  {
    cluster* clstr = (cluster*)malloc(sizeof(cluster));
    clstr->set = NULL;
    return clstr;
  }
  float distance_matrix[full.size][full.size];
  float dist_to_centroid[full.size];
  cluster c1(full.set);
  cluster c2(full.set);
  for(int i = 0;i<full.size;i++)
  {
    dist_to_centroid[i] = distance(*full.set[i],full.centroid);
    for(int j = 0;j<i;j++)
      distance_matrix[i][j]=distance(*full.set[i],*full.set[j]);
  }
  cluster* clstr1 = clusterfit(c1);
  cluster* clstr2 = clusterfit(c2);
  int csize1, csize2;
  for(csize1 = 0;clstr1[csize1].set!=NULL;csize1++);
  for(csize2 = 0;clstr2[csize2].set!=NULL;csize2++);
  cluster* newarr = (cluster*)malloc((csize1+csize2-1)*sizeof(cluster));
  for(int i = 0;i<csize1-1;i++)
    newarr[i]=clstr1[i];
  for(int i = (csize1-1);i<(csize1+csize2-1);i++)
    newarr[i]=clstr1[i];
  return newarr;
}

edge** generate_edges(cluster* group)
{
  int csize;
  for(csize = 0;group[csize].set!=NULL;csize++);
  point** carr = (point**)malloc(sizeof(point*));
  int esize = -1;
  edge** edgarr = (edge**)malloc(sizeof(edge*));
  for(int i = 0;i<csize;i++)
  {
    edgarr = (edge**)realloc(edgarr,(esize+2+group[i].size-1)*sizeof(edge));
    for(int j = 0;j<group[i].size;j++)
      {
        edgarr[esize+1+j] = new edge;
        edgarr[esize+1+j]->p1 = 1000+i;
      }
  }
  return edgarr;

}

void export_node(cluster* group, std::string path)
{
  int n;
  for(n = 0;group[n].set!=NULL;n++);
  std::ofstream fout(path);
  for(int i = 0;i<n;i++)
  {
    for(int j = 0;j<group[i].size;j++)
      fout<<group[i].set[j]->id<<","<<group[i].set[j]->x<<","<<group[i].set[j]->y<<","<<group[i].set[j]->hl<<std::endl;
    fout<<"100"<<i<<","<<group[i].centroid.x<<","<<group[i].centroid.y<<","<<group[i].centroid.hl<<std::endl;
  }
}

void export_edge(edge** group, std::string path)
{
  int n;
  for(n = 0;group[n]!=NULL;n++);
  std::ofstream fout(path);
  for(int i = 0;i<n;i++)
    fout<<group[i]->p1<<","<<group[i]->p2<<std::endl;
}
