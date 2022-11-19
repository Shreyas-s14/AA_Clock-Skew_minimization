#include "def.hh"

int main()
{
  point** arr = import("test.txt");
  for(int i = 0;arr[i]->id>=0;i++)
    std::cout<<arr[i]->id<<") X:"<<arr[i]->x<<", "<<"Y:"<<arr[i]->y<<std::endl;
}
