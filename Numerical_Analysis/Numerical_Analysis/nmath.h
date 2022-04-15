#pragma once

///////////////////////
/*자료형 선언 파트*/
///////////////////////
struct vec3 {
	float x;
	float y;
	float z;
};

struct vec4 {
	float x;
	float y;
	float z;
	float w;
};

struct mat3 {
	float matrix[3][3];
};

struct mat4 {
	float matrix[4][4];
};


///////////////////////
/*연산자 오버로딩 파트*/
///////////////////////
mat3 operator * (mat3 A, mat3 B) {
	mat3 ret;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			float sum = 0;
			for (int i = 0; i < 3; i++) {
				sum += A.matrix[r][i] * B.matrix[i][c];
			}
			ret.matrix[r][c] = sum;
		}
	}
	return ret;
}

mat4 operator * (mat4 A, mat4 B) {
	mat4 ret;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			float sum = 0;
			for (int i = 0; i < 4; i++) {
				sum += A.matrix[r][i] * B.matrix[i][c];
			}
			ret.matrix[r][c] = sum;
		}
	}
	return ret;
}