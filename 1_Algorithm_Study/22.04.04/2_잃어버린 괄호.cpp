zz//#1. 덧셈을 먼저 모두 해준 다음에 뺄셈연산을 처리
//피연산자를 저장하는 부분에서 제대로 저장되지 않아 통과 x
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operand;
vector<char> op;

int main() {
	string form; cin >> form;
	string temp = "";
	for (int i = 0; i < form.length(); i++) {
		if (form[i] == '+' || form[i] == '-') {
			int cur = stoi(temp);
			operand.push_back(cur);
			op.push_back(form[i]);
			temp = "";
		}
		else if (i == form.length() - 1) {
			temp += form[i];
			int cur = stoi(temp);
			operand.push_back(cur);
		}
		else {
			temp += form[i];
		}
	}

	vector<int> n_operand;

	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			n_operand.push_back(operand[i]);
			if (i == op.size() - 1) n_operand.push_back(operand[i + 1]);
		}
		else if (op[i] == '+') {
			n_operand.push_back(operand[i] + operand[i + 1]);
			i++;
		}
	}


	int ret = n_operand[0];
	for (int i = 1; i < n_operand.size(); i++) {
		ret -= n_operand[i];
	}

	cout << ret;

	return 0;
}

//#2. 피연산자 저장을 list로 한다면 해결 가능할것
//근데 linkedlist구현도 귀찮고 조금 생각하면 풀 수 있을것같다.

//#3. 뺄셈 이후의 항목인지 검사하며 연산
//피연산자를 처리해줄 필요 없이 뺄셈 이후의 덧셈 연산은 모두 더하여 마지막에 빼줌
//뺄셈 이후에 뺄셈이 다시 나온다면 더해져있는 수를 ret에서 빼준 후 다시 연산을 진행
//마지막에 연산을 종료할 때 남은 neg를 빼주는 연산을 처리해야함
//0ms
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> operand;
vector<char> op;

int main() {
	string form; cin >> form;
	string temp = "";
	for (int i = 0; i < form.length(); i++) {
		if (form[i] == '+' || form[i] == '-') {
			int cur = stoi(temp);
			operand.push_back(cur);
			op.push_back(form[i]);
			temp = "";
		}
		else if (i == form.length() - 1) {
			temp += form[i];
			int cur = stoi(temp);
			operand.push_back(cur);
		}
		else {
			temp += form[i];
		}
	}

	int ret = operand[0];
	int neg = 0;
	bool isNeg = false;

	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+' && !isNeg) {
			ret += operand[i + 1];
		}
		else if (op[i] == '+' && isNeg) {
			neg += operand[i + 1];
		}
		else if (op[i] == '-' && !isNeg) {
			isNeg = true;
			neg += operand[i + 1];
		}
		else if (op[i] == '-' && isNeg) {
			ret -= neg;
			neg = operand[i + 1];
		}
	}
	ret -= neg;

	cout << ret;

	return 0;
}