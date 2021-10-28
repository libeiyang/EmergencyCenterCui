#ifndef WARN_H
#define WARN_H

#include <string>
#include "Action.h"

class Warn : public Action
{private:
    string location;
    string warnwho;
    string warntype;
    string warninfo = "empty";
public:
    Warn(string warnwho, string location, string warntype);
    Warn(string warnwho, string location,string warntype, string warninfo);
    void act() const override;
};

#endif // WARN_H
