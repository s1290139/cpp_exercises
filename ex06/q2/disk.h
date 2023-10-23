#ifndef DISK_H
#define DISK_H

#include "shape.h" 
class Point {
public:
    Point(float x, float y) : x(x), y(y) {}
    float get_x() const { return x; }
    float get_y() const { return y; }

private:
    float x;
    float y;
};

class Disk : public Shape { //inheritance
public:
    Disk(Point center, float radius);
    // override
    std::string get_name() const override;
    float compute_area() const override;
    Shape* create() const override;
    Shape* clone() const override;

    ~Disk();

private:
    Point center;
    float radius;
};

#endif // DISK_H
