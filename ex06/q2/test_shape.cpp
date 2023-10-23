#include <iostream>
#include "disk.h"

int main() {
    Point center(0.0, 0.0);
    float radius=5.0;
    Disk disk(center, radius);

    std::cout << "radius is " << radius << std::endl;
    // Shape interface test
    std::cout << "Shape Name: " << disk.get_name() << std::endl;
    std::cout << "Area: " << disk.compute_area() << std::endl;

    // create method of shape interface
    Shape* createDisk = disk.create();
    std::cout << "New Disk Area(create): " << createDisk->compute_area() << std::endl;

    // clone method of shape interface
    Shape* clonedDisk = disk.clone();
    std::cout << "Cloned Disk Area: " << clonedDisk->compute_area() << std::endl;

    // freeing memory
    delete createDisk;
    delete clonedDisk;

    return 0;
}
