#include <iostream>

double power(double base, int exponent) {
    // Base case: Any number raised to the power of 0 is 1.
    if (exponent == 0) {
        return 1.0;
    }

    // Recursion: Multiply the base by the result of the smaller problem (exponent - 1).
    return base * power(base, exponent - 1);
}

int main() {
    double base = 2.0;
    int exponent = 3;

    double result = power(base, exponent);

    std::cout << base << " raised to the power of " << exponent << " is " << result << std::endl;

    return 0;
}
