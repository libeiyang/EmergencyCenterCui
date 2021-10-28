#include "TurnOn.h"

TurnOn::TurnOn(string loc, string obj)
    :  location{loc}, object{obj}
{
    cout<<"New TurnOn action created"<<endl;
}
void TurnOn::act() const
{
    cout<<"Turn on "<<object<<" in " <<location<<endl;
}
