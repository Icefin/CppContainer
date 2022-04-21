//One of the Bracketing Methods
//We need to select two initial guesses which satisfy f(x1)*f(x2) < 0
//Pros : Easy, Always find root, Number of iteration can be estimated before the computation
//Cons : Slow, Initla guesses must bound roots, No solutions for multiple roots
//Only applicable for real roots

#include <iostream>
#include "nmath.h"

using namespace std;

string func;
float x1, x2, e_s, cnt = 0;

void Init();
void Print();

int main() {
    Init();
    float left = CalculateMonoVariable(func, x1);
    float right = CalculateMonoVariable(func, x2);
    float initial_interval = x2 - x1;

    float e_a = 100;

    float mid = 0;

    while (e_a > e_s){
        cnt++;
        float mid = (x1 + x2) / 2;
        float center = CalculateMonoVariable(func, mid);
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

void Init() {
    cout << "This Code is for Bisection-Method" << '\n';
    cout << "Enter the target function : " << '\n';
    cin >> func;
    cout << "Enter two initial guesses x1, x2 and stopping criterion error e_s" << '\n';
    cout << "Make sure your initial guess satisfies f(x1)*f(x2) <=0" << '\n';
    cin >> x1 >> x2 >> e_s;
}

void Print(float mid) {
    cout << '\n'; cout << '\n';
    cout << "Here is a root and iteration count" << '\n';
    cout << "Estimated Root : " << mid;
    cout << "Iteration count : " << cnt;
}