#ifndef TURNON
#define TURNON
#include <string>
#include "Action.h"

class TurnOn : public Action
{
public:
    TurnOn(string location, string object);
    void act() const override ;

private:
    string location;
    string object;
};

#endif // TURNON
