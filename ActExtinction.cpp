#include "Actextinction.h"
#include <iostream>

ActExtinction::ActExtinction(std::string location)
{
    std::cout<<"create a new action in " <<location<<std::endl;
}

void ActExtinction::act() const
{
    std::cout<<"Start extinction system now at " <<location<<std::endl;
}
