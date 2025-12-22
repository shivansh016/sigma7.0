#include<iostream>
#include<string>
using namespace std;

class Complex{
    int real;
    int img;
    public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    void print(){
        cout << real << "+" << img << "i" <<endl;
    }



Complex operator -(Complex &c2){
    int resReal = this->real - c2.real;
    int resImg = this->img - c2.img;
    Complex c3(resReal, resImg);
    return c3;
}
};

int main(){
    Complex c1(3,2);
    Complex c2(2,7);
    c1.print();
    c2.print();
    Complex c3 = c1 - c2;
    c3.print();
    return 0;
}