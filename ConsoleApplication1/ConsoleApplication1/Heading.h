#ifndef HEADING_H
#define HEADING_H

class Heading
{
public:
    virtual double calcHeads(int subordinatesCount) = 0;
    virtual ~Heading() {}
};

#endif