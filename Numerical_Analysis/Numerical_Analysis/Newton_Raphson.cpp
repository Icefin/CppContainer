#include <iostream>
#include "nmath.h"

using namespace std;

float x, y, e_a;

void Init() {
    cout << "This Code is for Newton-Raphson Method" << '\n';
    cout << "Enter two initial guesses x, y and criterion error e_a" << '\n';
    cin >> x >> y >> e_a;
}

void Print(int cnt) {
    cout << '\n'; cout << '\n';
    cout << "Here are answers and iteration count" << '\n';
    cout << "x : " << x << " y : " << y << '\n';
    cout << "Iteration count : " << cnt;
}

//So far, this code is only for functions
//u(x, y) = x^2 + xy - 10
//v(x, y) = y + 3xy^2 - 57
int main() {
    Init();

    float e = 1;
    int iter_cnt = 0;

    mat3 A = { 2, 0, 0,
        0, 2, 0,
        0, 0, 2 };

    mat3 B = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    mat3 C = A * B;

    while (e > e_a) {
        iter_cnt++;
        float u = x * x + x * y - 10;
        float v = y + 3 * x * y * y - 57;

        float dudx = 2 * x + y;
        float dudy = x;
        float dvdx = 3 * y * y;
        float dvdy = 1 + 6 * x * y;

        float x_n = x - ((u * dvdy - v * dudy) / (dudx * dvdy - dudy * dvdx));
        float y_n = y - ((u * dvdx - v * dudx) / (dvdx * dudy - dvdy * dudx));

        float e_x = abs(100 * (x_n - x) / x_n);
        float e_y = abs(100 * (y_n - y) / y_n);

        x = x_n;
        y = y_n;
        e = max(e_x, e_y);
    }

    Print(iter_cnt);
}