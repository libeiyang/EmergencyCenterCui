#include "Warn.h"



Warn::Warn(string warnwho, string location, string warntype)
{
    this->warnwho = warnwho;
    this->location = location;
    this->warntype = warntype;
}

Warn::Warn(string warnwho, string location, string warntype, string warninfo)
{

    this->warnwho = warnwho;
    this->location = location;
    this->warntype = warntype;
    this->warninfo = warninfo;
}

void Warn::act() const
{
    if(warninfo == "empty")
    cout<<"Warning: \nDear " <<warnwho<<",\n There has been "<<warntype<<" in "<< location<<", please be noticed\n"<<endl;
    else{
    cout<<"Warning: \nDear " <<warnwho<<",\n There has been "<<warntype<<warninfo<<" in "<< location<<", please be noticed\n"<<endl;
    }

}
