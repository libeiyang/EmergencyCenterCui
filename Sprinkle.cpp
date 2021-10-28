#include "Sprinkle.h"

Sprinkle::Sprinkle(string sprinkletype, string location)
{
    this->sprinkletype = sprinkletype;
    this->location = location;
}

void Sprinkle::act() const
{
    cout<<"Activate "<<sprinkletype<<" sprinklers at "<<location<<endl;
}

