//Methods for Polynomials
//Projecting a parabola to the x axis through three function values
//if) only real roots are estimated : choose two of x0, x1, x2 close to x3
//if) real && complex roots are estimated : choose sequentially -> x1, x2, x3

#include <iostream>
#include "nmath.h"

using namespace std;

string func;
float x0, x1, x2;
float del_0, del_1, h_0, h_1, e_s;
float a, b, c;

void Init() {};
void Print() {};

int main() {
	float e_a = 1;

	float val_x0;
	float val_x1;
	float val_x2;

	float x_next, x_prev = x2;

	while (e_a > e_s) {
		val_x0 = CalculateMonoVariable(func, x0);
		val_x1 = CalculateMonoVariable(func, x1);
		val_x2 = CalculateMonoVariable(func, x2);

		h_0 = x1 - x0; h_1 = x2 - x1;
		del_0 = (val_x1 - val_x0) / h_0; del_1 = (val_x2 - val_x1) / h_1;
		a = (del_1 - del_0) / (h_1 + h_0); b = a * h_1 + del_1; c = val_x2;
		
		x_next = x_prev - 2 * c / (b + sqrt(b * b - 4 * a * c));		//Require Selecting Larger Denominator step

		e_a = abs((x_next - x_prev) / x_next);
		x_prev = x_next;							//Require Selecting next x0, x1, x2 step
	}
}