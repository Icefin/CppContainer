#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	string name;
	int korean;
	int english;
	int math;

	//cpp의 객체 생성자 정의
	Student(string name, int kor, int eng, int math)
	{
		this->name = name;
		this->korean = kor;
		this->english = eng;
		this->math = math;
	}

	//연산자 오버로딩을 통해 sort함수 사용
	//this < other로 비교
	//if (same korean score, same english score, same math score) : 이름을 오름차순 정렬 => this->name < other.name일 때 true
	//if (same korean score, same english score) : 수학 점수를 내림차순 정렬 => this->math > other.math일 때 true
	//if (same korean score) : 영어 점수를 오름차순 정렬 => this->english < other.english일 때 true
	//국어 점수를 내림차순 정렬 => this->korean > other.korean일 때 true
	bool operator <(Student& other) {
		if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
			return this->name < other.name;
		}
		if (this->korean == other.korean && this->english == other.english) {
			return this->math > other.math;
		}
		if (this->korean == other.korean) {
			return this->english < other.english;
		}
		return this->korean > other.korean;
	}
};

int N;

vector<Student> students;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		int korean, english, math;
		cin >> name >> korean >> english >> math;

		Student student(name, korean, english, math);
		students.push_back(student);
	}

	sort(students.begin(), students.end());

	for (int i = 0; i < N; i++)
		cout << students[i].name << '\n';
}

/*
연산자 오버로딩 대신에

bool compare(Student& other)
{
if (this->korean == other.korean && this->english == other.english && this->math == other.math) {
		return this->name < other.name;
	}
	if (this->korean == other.korean && this->english == other.english) {
		return this->math> other.math;
	}
	if (this->korean == other.korean) {
		return this->english < other.english;
	}
	return this->korean > other.korean;
}

이 후 main에서 sort(students.begin(), students.end(), compare);으로 해도 동일한 결과 얻을 것.
*/