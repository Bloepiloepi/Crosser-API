#include "../include/location.hpp"

crs::Location::Location(int x, int y) : x(x), y(y) {}
crs::Location::Location(const crs::Location &loc) : x(loc.getX()), y(loc.getY()) {}

int crs::Location::getX() const { return Location::x; }
int crs::Location::getY() const { return Location::y; }
