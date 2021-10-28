#include "Alarm.h"
#include <iostream>

Alarm::Alarm(string loc)
{
    this->location = loc;
    cout<<"New alarm action created"<<endl;
}

Alarm::Alarm(string location, string alarminfo)
{
    this->location=location;
    this->alarminfo=alarminfo;
}

void Alarm::act() const
{
    if(alarminfo == "empty")
    cout<<"Start an alarm now at " <<location<<endl;
    else{
    cout<<"Start an alarm now at " <<location<<endl<<alarminfo<<endl;
    }
}
