#include "disk.h"

Disk::Disk(Point center, float radius) : center(center), radius(radius) {}

std::string Disk::get_name() const {
    return "Disk";
}

float Disk::compute_area() const {
    return 3.14159265359f * radius * radius;
}

Shape* Disk::create() const {
    return new Disk(center, radius);
}

Shape* Disk::clone() const {
    return new Disk(center, radius);
}

Disk::~Disk() { 
}
