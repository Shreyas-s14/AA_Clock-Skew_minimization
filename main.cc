#include "def.hh"

int main()
{
  cluster kc("test.txt");
  kc.display();
  std::cout<<"X:"<<kc.centroid.x<<","<<"Y:"<<kc.centroid.y<<std::endl;
  cluster* res = clusterfit(kc);
  export_node(res,"node.csv");
  export_edge(generate_edges(res),"edge.csv");
}
