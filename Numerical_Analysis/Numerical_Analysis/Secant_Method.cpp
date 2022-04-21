//One of the Open Methods
//This requires two initial guesses but do not need to bracket the root
//Modified Newton-Raphson when the derivative is not easy to be calculated
//No General Convergence Criterion Exist : ***Convergence is not guaranteed***
//Only applicable for real roots

#include <iostream>
#include "nmath.h"

using namespace std;

float x_prev, x_curr, e_s, cnt;
string func;

void Init();
void Print();

int main() {
	Init();

	float val_x_prev = CalculateMonoVariable(func, x_prev);
	float val_x_curr = CalculateMonoVariable(func, x_curr);

	float x_next = x_curr - val_x_curr * (x_curr - x_prev) / (val_x_curr - val_x_prev);

	float e_a = abs(100 * (x_next - x_curr) / x_next);

	while (e_a > e_s) {
		cnt++;
		x_prev = x_curr;
		x_curr = x_next;

		val_x_prev = CalculateMonoVariable(func, x_prev);
		val_x_curr = CalculateMonoVariable(func, x_curr);

		x_next = x_curr - val_x_curr * (x_curr - x_prev) / (val_x_curr - val_x_prev);

		e_a = abs(100 * (x_next - x_curr) / x_next);
	}

	Print();
}

void Init() {};
void Print() {};