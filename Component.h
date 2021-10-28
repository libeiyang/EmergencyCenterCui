#ifndef COMPONENT_H
#define COMPONENT_H
#include<string>


class Component
{
private:
//    int ID;
public:
    virtual void test() = 0;
    virtual void activate()=0;
    virtual void deactivate()=0;

};


#endif // COMPONENT_H

