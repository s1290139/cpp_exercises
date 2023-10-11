#include "queue.h"
#include <iostream>

int main(void) {
  int x=0;
  int y=0;
  int z=0;
  int d=0;
  Queue queue(100); // maximum size of 100
  for(int i=0; i<500; i++){
    Point p = {x, y, z};
    if(queue.size()>=100){
      queue.dequeue();
      d++;
    }
    queue.enqueue(p);
    x++;
    y++;
    z++;
  }

  std::cout << "Size of queue: " << queue.size() << std::endl; //number of elements

  Point front = queue.peek();
  std::cout << "Front element: (" << front.x << ", " << front.y << ", " << front.z << ")" << std::endl;

  queue.dequeue();

  std::cout << "dequeue: " << d << std::endl; //number of dequeue

  return 0;
}