#ifndef ALARM_H
#define ALARM_H
#include <string>
#include "Action.h"

class Alarm : public Action
{
private:
    string location;
    string alarminfo = "empty";
public:
    Alarm(std::string location);
    Alarm(string location,string alarminfo);
    void act() const override;
};

#endif // ALARM_H
