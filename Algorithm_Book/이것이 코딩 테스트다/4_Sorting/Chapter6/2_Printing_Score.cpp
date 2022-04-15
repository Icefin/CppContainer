#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
//점수, 이름을 저장할 변수
vector<pair<int, string>> students;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int score;
		string name;
		cin >> name >> score;
		students.push_back(pair<int, string>(score, name));
	}

	sort(students.begin(), students.end());
	for (int i = 0; i < N; i++)
		cout << students[i].second << ' ';
}

/*
* pair을 쓰는게 class쓰는것 보다 성능상 빠름
* 그러나 class쓰는게 코드 확장성, 가독성이 좋음
*/

//class Student {
//public:
//    string name;
//    int score;
//    Student(string name, int score) {
//        this->name = name;
//        this->score = score;
//    }
//    // 정렬 기준은 '점수가 낮은 순서'
//    bool operator <(Student &other) {
//        return this->score < other.score; 
//    }
//};
//
//int n;
//vector<Student> v;
//
//int main(void) {
//    // N을 입력받기
//    cin >> n;
//
//    // N명의 학생 정보를 입력받아 리스트에 저장
//    for (int i = 0; i < n; i++) {
//        string name;
//        int score;
//        cin >> name >> score;
//        v.push_back(Student(name, score));
//    }
//    
//    sort(v.begin(), v.end());
//
//    // 정렬이 수행된 결과를 출력
//    for(int i = 0; i < n; i++) {
//        cout << v[i].name << ' ';
//    }
//}