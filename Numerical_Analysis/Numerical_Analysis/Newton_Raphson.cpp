//One of the Open Methods

#include <iostream>
#include "nmath.h"

using namespace std;

string func_u;
string func_v;
float x, y, e_s;

void Init() {
    cout << "This Code is for Newton-Raphson Method" << '\n';
    cout << "Enter two initial guesses x, y and stopping criterion error e_s" << '\n';
    cin >> x >> y >> e_s;
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

    while (e > e_s) {
        iter_cnt++;
        float u = CalculateMultiVariable(func_u, x, y);
        float v = CalculateMultiVariable(func_v, x, y);

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