#pragma once
#include <string>

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
			/*
			float sum = 0;
			for (int i = 0; i < 3; i++) {
				sum += A.matrix[r][i] * B.matrix[i][c];
			}
			*/
			ret.matrix[r][c] = A.matrix[r][0] * B.matrix[0][c] + A.matrix[r][1] * B.matrix[1][c] + A.matrix[r][2] * B.matrix[2][c];
		}
	}
	return ret;
}

vec3 operator * (mat3 A, vec3 B) {
	vec3 ret;
	ret.x = A.matrix[0][0] * B.x + A.matrix[0][1] * B.y + A.matrix[0][2] * B.z;
	ret.y = A.matrix[1][0] * B.x + A.matrix[1][1] * B.y + A.matrix[1][2] * B.z;
	ret.z = A.matrix[2][0] * B.x + A.matrix[2][1] * B.y + A.matrix[2][2] * B.z;
	return ret;
}

mat4 operator * (mat4 A, mat4 B) {
	mat4 ret;
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			/*
			float sum = 0;
			for (int i = 0; i < 4; i++) {
				sum += A.matrix[r][i] * B.matrix[i][c];
			}
			*/
			ret.matrix[r][c] = A.matrix[r][0] * B.matrix[0][c] +
				A.matrix[r][1] * B.matrix[1][c] +
				A.matrix[r][2] * B.matrix[2][c] +
				A.matrix[r][3] * B.matrix[3][c];
		}
	}
	return ret;
}

vec4 operator * (mat4 A, vec4 B) {
	vec4 ret;
	ret.x = A.matrix[0][0] * B.x + A.matrix[0][1] * B.y + A.matrix[0][2] * B.z + A.matrix[0][3] * B.w;
	ret.y = A.matrix[1][0] * B.x + A.matrix[1][1] * B.y + A.matrix[1][2] * B.z + A.matrix[1][3] * B.w;
	ret.z = A.matrix[2][0] * B.x + A.matrix[2][1] * B.y + A.matrix[2][2] * B.z + A.matrix[2][3] * B.w;
	ret.w = A.matrix[3][0] * B.x + A.matrix[3][1] * B.y + A.matrix[3][2] * B.z + A.matrix[3][3] * B.w;
	return ret;
}

///////////////////////
/*필요 함수 정의 파트*/
///////////////////////

float CalculateMonoVariable(std::string eq, float v) {
	float ret = 0.0f;



	return ret;
}

float CalculateMultiVariable(std::string eq, float v1, float v2) {
	float ret = 0.0f;

	return ret;
}

std::string DerivateFuncWRTchar(std::string eq, char op) {
	std::string ret;

	return ret;
}