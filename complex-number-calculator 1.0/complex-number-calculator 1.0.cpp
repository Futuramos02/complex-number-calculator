#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;
public:
    Complex() {
        real = 0.0;
        imag = 0.0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }

    double magnitude() {
        return sqrt(real * real + imag * imag);
    }

    void print() {
        std::cout << "(" << real << " + " << imag << "i)" << std::endl;
    }
};

int main() {
    double real1, imag1, real2, imag2;
    std::cout << "Enter the real part of the first complex number: ";
    std::cin >> real1;
    std::cout << "Enter the imaginary part of the first complex number: ";
    std::cin >> imag1;
    std::cout << "Enter the real part of the second complex number: ";
    std::cin >> real2;
    std::cout << "Enter the imaginary part of the second complex number: ";
    std::cin >> imag2;

    Complex a(real1, imag1), b(real2, imag2);
    Complex c = a + b;
    std::cout << "The sum of the two complex numbers is: ";
    c.print();
    c = a - b;
    std::cout << "The difference of the two complex numbers is: ";
    c.print();
    c = a * b;
    std::cout << "The product of the two complex numbers is: ";
    c.print();
    c = a / b;
    std::cout << "The quotient of the two complex numbers is: ";
    c.print();
    std::cout << "The magnitude of the quotient is: " << c.magnitude() << std::endl;
    return 0;
}
