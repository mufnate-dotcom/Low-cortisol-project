#ifndef PERSONAL_H
#define PERSONAL_H
#include "Employee.h"
using namespace std;
class Personal : public Employee, public WorkBaseTime
{
protected:
	double hourlyRate;
public:
	Personal(int id, const string& name, const string& position, double hourlyRate);
	double calcBase(double hours, double rate) const override;
	double calcBonus(double hours) const override { return 0; }
	void calc() override;
	void printInfo() const override;
	string serialize() const override;
};
class Cleaner : public Personal
{
public:
	Cleaner(int id, const string& name, double hourlyRate);
	double calcBonus(double hours) const override;
};
#endif
