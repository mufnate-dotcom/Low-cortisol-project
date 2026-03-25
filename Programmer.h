#ifndef PROGRAMMER_H
#define PROGRAMMER_H
#include "Engineer.h"
using namespace std;

class Programmer : public Engineer
{
private:
    int earlyCodeLines;
    double bonusPerLine;
public:
    Programmer(int id, const string& name, const string& position,
        double hourlyRate, Project* project = nullptr);
    virtual ~Programmer() {}
    void setEarlyCodeLines(int lines) { earlyCodeLines = lines; }
    void setBonusPerLine(double bonus) { bonusPerLine = bonus; }
    double calcProAdditions() override;
};
#endif
