#ifndef COOLING_H
#define COOLING_H
#include <string>
#include "Action.h"


class Sprinkle :public Action
{
private:
    string sprinkletype;
    string location;
public:
    Sprinkle(string sprinkletype, string location);
    void act() const override;


};

#endif // COOLING_H
