#ifndef  ACTEXTINCTION_H
#define ACTEXTINCTION_H

#include <string>
#include "Action.h"
class ActExtinction : public Action
{
private:
    string location;

public:
    ActExtinction(string loc);
    void act() const override;
};

#endif // ACTEXTINCTION_H
