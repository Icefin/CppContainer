//One of the Bracketing Methods
//We need to select two initial guesses which satisfy f(x1)*f(x2) < 0
//This Method is quite similar with Bisection_Method
//This could be faster than Bisection_Method in general case... But Never Guaranteed!!

#include <iostream>
#include "nmath.h"

using namespace std;

string func;
float x1, x2, e_s, cnt = 0;

void Init() {};
void Print() {};

int main() {
	Init();

	float left = CalculateMonoVariable(func, x1);
	float right = CalculateMonoVariable(func, x2);

	float e_a = 100;

	float prev = 0.0f;

	while (e_a > e_s) {
		cnt++;
		float mid = (x1 * right - x2 * left) / (right - left);
		float center = CalculateMonoVariable(func, mid);

		if (center * left < 0) {
			x2 = mid;
		}
		else if (center * right < 0) {
			x1 = mid;
		}
		else {
			break;
		}

		e_a = abs(100 * (mid - prev) / mid);
		prev = mid;
	}

	Print();
}