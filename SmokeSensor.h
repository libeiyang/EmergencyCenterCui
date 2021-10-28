#ifndef SMOKESENSOR_H
#define SMOKESENSOR_H
#include "Sensor.h"
class SmokeSensor : public Sensor
{

public:
    SmokeSensor(int id, vector<string> location,string vender);
    string getType() const override {return "SmokeSensor";} ;
    void activate()override;
    void deactivate()override;
};




#endif // SMOKESENSOR_H
