// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
#include <cmath>

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
double x;
double y;
public:
// TODO 1: Constructor with member initializer list (double x, double y)
Point(double x, double y) : x(x), y(y) {}


// TODO 2: const getter for x
double getX() const { return x; }

// TODO 3: const getter for y
double getY() const { return y; }

// TODO 4: const display()
void display() const {
   std::cout << "(" << x << ", " << y << ")";
}

// TODO 5: declare Rectangle as friend class
friend class Rectangle;


};

class Rectangle {
private:
Point topLeft;
Point bottomRight;
public:
// TODO 6: constructor with member initializer list
Rectangle(double x1, double y1, double x2, double y2)
: topLeft(x1, y1), bottomRight(x2, y2) {}


// TODO 7: const getWidth()
double getWidth() const {
   return std::abs(bottomRight.x - topLeft.x);
}

// TODO 8: const getHeight()
double getHeight() const {
   return std::abs(bottomRight.y - topLeft.y);
}

// TODO 9: const getArea()
double getArea() const {
   return getWidth() * getHeight();
}

// TODO 10: const display()
void display() const {
   std::cout << "Rectangle: ";
   topLeft.display();
   std::cout << " to ";
   bottomRight.display();
   std::cout << " | Width: " << getWidth()
<< ", Height: " << getHeight()
<< ", Area: " << getArea()
<< std::endl;
}

// TODO 11: declare isSameSize as friend function
friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);


};

// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
double w1 = std::abs(r1.bottomRight.x - r1.topLeft.x);
double h1 = std::abs(r1.bottomRight.y - r1.topLeft.y);
double w2 = std::abs(r2.bottomRight.x - r2.topLeft.x);
double h2 = std::abs(r2.bottomRight.y - r2.topLeft.y);
return (std::abs(w1 - w2) < 1e-9) && (std::abs(h1 - h2) < 1e-9);
}

class ConstDemo {
private:
int value;
public:
// TODO 13: constructor with member initializer list
ConstDemo(int v) : value(v) {}


// TODO 14: const getValue()
int getValue() const { return value; }

// TODO 15: NON-const doubleValue() — multiplies value by 2
void doubleValue() { value *= 2; }

// TODO 16: const constGetDouble() — returns value * 2 without modifying
int constGetDouble() const { return value * 2; }


};

// ============================================================
// MAIN
// ============================================================
int main() {
// TODO 17: Demo Point
std::cout << “=== Point Demo ===” << std::endl;
Point p(3.0, 4.0);
p.display();
std::cout << std::endl;


// TODO 18: Demo const Point
const Point cp(1.5, 2.5);
std::cout << "const Point x=" << cp.getX() << ", y=" << cp.getY() << std::endl;

// TODO 19: Demo Rectangle
std::cout << "\n=== Rectangle Demo ===" << std::endl;
Rectangle r1(0, 0, 4, 3);
r1.display();

Rectangle r2(1, 1, 5, 4);
r2.display();

// TODO 20: Demo isSameSize
std::cout << "\n=== isSameSize Demo ===" << std::endl;
std::cout << "r1 and r2 same size? "
<< (isSameSize(r1, r2) ? "Yes" : "No") << std::endl;

Rectangle r3(0, 0, 4, 3);
std::cout << "r1 and r3 same size? "
<< (isSameSize(r1, r3) ? "Yes" : "No") << std::endl;

// TODO 21: Demo ConstDemo
std::cout << "\n=== ConstDemo ===" << std::endl;
ConstDemo cd(5);
std::cout << "Initial value: " << cd.getValue() << std::endl;
std::cout << "constGetDouble: " << cd.constGetDouble() << std::endl;
cd.doubleValue();
std::cout << "After doubleValue(): " << cd.getValue() << std::endl;

const ConstDemo ccd(10);
std::cout << "const ConstDemo value: " << ccd.getValue() << std::endl;
std::cout << "const ConstDemo constGetDouble: " << ccd.constGetDouble() << std::endl;

return 0;


}
