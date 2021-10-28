#ifndef ACTION_H
#define ACTION_H
#include <iostream>

using namespace std;
class Action
{
public:
    virtual void act() const = 0;
};

#endif // ACTION_H
