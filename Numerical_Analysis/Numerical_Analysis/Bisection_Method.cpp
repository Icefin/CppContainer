#include <iostream>

using namespace std;

float x1, x2, e_s, cnt = 0;

void Init() {
    cout << "This Code is for Bisection-Method" << '\n';
    cout << "Enter two initial guesses x, y and stopping criterion error e_s" << '\n';
    cout << "Caution : You MUST check whether your initial guess satisfies f(x)*f(y) <=0" << '\n';
    cin >> x1 >> x2 >> e_s;
}

void Print(float mid) {
    cout << '\n'; cout << '\n';
    cout << "Here is a root and iteration count" << '\n';
    cout << "Estimated Root : " << mid;
    cout << "Iteration count : " << cnt;
}

//This code is only for f = x^3 + x^2 - 4x - 4, target root : 1
int main() {
    Init();
    float left = pow(x1, 3) + pow(x1, 2) - 4 * x1 - 4;
    float right = pow(x2, 3) + pow(x2, 2) - 4 * x2 - 4;
    float initial_interval = x2 - x1;

    float e_a = 100;

    float mid = 0;

    while (e_a > e_s){
        cnt++;
        float mid = (x1 + x2) / 2;
        float center = pow(mid, 3) + pow(mid, 2) - 4 * mid - 4;
        if (center == 0) break;
        else if (left * center < 0) {
            x2 = mid;
        }
        else {
            x1 = mid;
        }

        e_a = 100 * initial_interval / pow(2, cnt);
    }

    Print(mid);
}