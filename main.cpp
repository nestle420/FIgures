#include <iostream>
#include <iomanip>
using namespace std;
class Figure {

public:
    virtual double area() = 0;

    virtual double perimeter() = 0;
};

class Circle : public Figure {
protected:
    int r;
    double p = 3.14159265;
public:
    Circle() = default;

    double area() override {
        return p * r * r;
    }

    double perimeter() override {
        return 2 * p * r;
    }

    void read() {
        cin >> r;
    }
};

class Rectangle : public Figure {
protected:
    int width;
    int height;

public:
    Rectangle() = default;

    double area() override {
        return width * height;
    }

    double perimeter() override {
        return 2 * height + 2 * width;
    }

    void read() {
        cin >> width >> height;
    }

};
int main() {
    Figure* f;
    string type;
    cin >> type;
    if (type == "Rectangle") {
        Rectangle* r = new Rectangle;
        r->read();
        f = r;
    } else {
        Circle* c = new Circle;
        c->read();
        f = c;
    }
    cout << fixed << setprecision(4);
    cout << f->area() << " " << f->perimeter();
    return 0;
}
