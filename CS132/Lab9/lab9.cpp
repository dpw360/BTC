// Lab 09 - Templates
// Combine the following four "divide" functions into a templated function
// with any necessary specializations to handle different operations.

#include<iostream>

template <typename T> T divide(T x, T y) {
    return x / y;
}

int main() {
    std::cout << "Let's divide some things!\n";
    std::cout << "12 / 6 = " << divide(12, 6) << "\n";
    std::cout << "3.5 / 1.2 = " << divide(3.5, 1.2) << "\n";
    std::cout << "0.0007 / 0.0000001 = " << divide(0.0007, 0.0000001) << "\n";
    std::cout << "z / $ = " << divide('z', '$') << "\n\n";
    
    return 0;
}