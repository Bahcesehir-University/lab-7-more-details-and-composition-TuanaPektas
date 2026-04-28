// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================

#include <iostream>
#include <string>
#include <cmath>  // std::abs için gerekli

// ============================================================
// CLASS DEFINITIONS
// ============================================================

class Point {
private:
   double x;
   double y;

public:
   // TODO 1: Constructor with member initializer list
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
   // Rectangle'ın private üyelere (x, y) erişebilmesi için friend tanımlıyoruz
   friend class Rectangle;
};


class Rectangle {
private:
   Point topLeft;
   Point bottomRight;

public:
   // TODO 6: constructor with member initializer list
   // Composition: Point nesnelerini initializer list ile başlatıyoruz
   Rectangle(double x1, double y1, double x2, double y2)
       : topLeft(x1, y1), bottomRight(x2, y2) {}

   // TODO 7: const getWidth()
   // std::abs kullanarak negatif sonuçları önlüyoruz
   double getWidth() const {
       return std::abs(bottomRight.getX() - topLeft.getX());
   }

   // TODO 8: const getHeight()
   double getHeight() const {
       return std::abs(bottomRight.getY() - topLeft.getY());
   }

   // TODO 9: const getArea()
   double getArea() const {
       return getWidth() * getHeight();
   }

   // TODO 10: const display()
   void display() const {
       std::cout << "Rectangle[TopLeft=";
       topLeft.display();
       std::cout << ", BottomRight=";
       bottomRight.display();
       std::cout << ", Area=" << getArea() << "]";
   }

   // TODO 11: declare isSameSize as friend function
   // Global fonksiyonun private metotlara erişimi için friend
   friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
};


// TODO 12: implement isSameSize
// İki dikdörtgenin genişlik ve yüksekliklerini karşılaştırır
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
   return (r1.getWidth() == r2.getWidth()) &&
          (r1.getHeight() == r2.getHeight());
}


class ConstDemo {
private:
   int value;

public:
   // TODO 13: constructor with member initializer list
   ConstDemo(int v) : value(v) {}

   // TODO 14: const getValue()
   int getValue() const { return value; }

   // TODO 15: NON-const doubleValue() — modifies the object
   // Nesneyi değiştirdiği için const DEĞİLDİR
   void doubleValue() {
       value *= 2;
   }

   // TODO 16: const constGetDouble() — read-only calculation
   // Nesneyi değiştirmez, sadece hesaplar -> const OLMALIDIR
   int constGetDouble() const {
       return value * 2;
   }
};


// ============================================================
// MAIN
// ============================================================
int main() {
   // TODO 17: Create and display a Point
   Point p(3.5, 4.2);
   std::cout << "Point: ";
   p.display();
   std::cout << "\n\n";

   // TODO 18: Create and display a Rectangle
   Rectangle rect(0.0, 0.0, 4.0, 3.0);
   std::cout << "Rectangle Info:\n";
   rect.display();
   std::cout << "\n\n";

   // TODO 19: Display rectangle properties
   std::cout << "Properties -> Width: " << rect.getWidth()
<< ", Height: " << rect.getHeight()
<< ", Area: " << rect.getArea() << "\n\n";

   // TODO 20: Test isSameSize function
   Rectangle rect2(1.0, 1.0, 4.0, 4.0); // 3x3 boyutunda
   std::cout << "Size Comparison:\n";
   std::cout << "rect vs rect2: "
<< (isSameSize(rect, rect2) ? "SAME SIZE" : "DIFFERENT SIZE")
<< "\n\n";

   // TODO 21: Test ConstDemo class (const vs non-const behavior)
   std::cout << "ConstDemo Test:\n";
   ConstDemo demo(7);
   std::cout << "Initial value: " << demo.getValue() << "\n";

   // constGetDouble: nesneyi değiştirmez, sadece 2 katını hesaplar
   std::cout << "constGetDouble() result: " << demo.constGetDouble() << "\n";
   std::cout << "Value after constGetDouble: " << demo.getValue() << " (unchanged)\n";

   // doubleValue: nesneyi kalıcı olarak değiştirir
   demo.doubleValue();
   std::cout << "Value after doubleValue(): " << demo.getValue() << " (doubled!)\n";

   return 0;
}
