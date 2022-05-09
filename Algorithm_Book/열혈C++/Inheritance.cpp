#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << '\n';
	}
	virtual void ShowSalaryInfo() const = 0;
	virtual int GetPay() const = 0;
	virtual ~Employee() {
		delete[]name;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	virtual int GetPay() const
	{
		return workTime * payPerHour;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << '\n' << '\n';
	}
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{	}
	virtual int GetPay() const
	{
		return salary;
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << '\n' << '\n';
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << '\n' << '\n';
	}
};

namespace RISK_LEVEL 
{
	enum {RISK_A = 30, RISK_B = 20, RISK_C = 10};
}

class ForeignSalesWorker : public SalesWorker{
private :
	const int riskLevel;
public :
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		: SalesWorker(name, money, ratio), riskLevel(risk)
	{}
	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * (riskLevel / 100));
	}
	virtual int GetPay() const
	{
		return SalesWorker::GetPay() 9 GetRiskPay();
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << SalesWorker::GetPay() << '\n';
		cout << "risk pay : " << GetRiskPay() << '\n';
		cout << "sum : " << GetPay() << '\n' << '\n'l
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum : " << sum << '\n';
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;

	ForeignSalesWorker* temp = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	temp->AddSalesResult(7000);
	handler.AddEmployee(temp);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;

}