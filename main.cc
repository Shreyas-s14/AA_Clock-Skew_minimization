#include "def.hh"

int main()
{
  cluster kc("test.txt");
  kc.display();
  std::cout<<"X:"<<kc.centroid.x<<","<<"Y:"<<kc.centroid.y<<std::endl;
}
