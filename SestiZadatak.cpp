#include <iostream>
#include <cmath>
using namespace std;

struct Fraction {
    int numerator{};
    int denominator{};

    
    void reduce() {
        int a{abs(numerator)};
        int b{abs(denominator)};

        while (b != 0) {
            int ostatak{a % b};
            a = b;
            b = ostatak;
        }

        numerator /= a;
        denominator /= a;

        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    
    double value() {
        return static_cast<double>(numerator) / denominator;
    }

    
    void print() {
        cout << numerator << "/" << denominator;
    }
};



Fraction sum(const Fraction& a, const Fraction& b) {

    Fraction rezultat{
        a.numerator * b.denominator +
        b.numerator * a.denominator,

        a.denominator * b.denominator
    };

    rezultat.reduce();

    return rezultat;
}


int main() {

    Fraction a{1, 2};
    Fraction b{1, 4};

    cout << "prvi: ";
    a.print();

    cout << endl;

    cout << "drugi : ";
    b.print();

    cout << endl;

   
    cout << "dec vrijednost prvog: "
         << a.value() << endl;

    cout << "dec vrijednost drugog: "
         << b.value() << endl;

  
    Fraction rezultat{sum(a, b)};

    cout << "zbroj: ";
    rezultat.print();

    cout << endl;

    cout << "dec vrijednost zbroja: "
         << rezultat.value() << endl;

    return 0;
}