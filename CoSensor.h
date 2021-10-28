#ifndef COSENSOR_H
#define COSENSOR_H


#include "Sensor.h"
class CoSensor : public Sensor
{

public:
    CoSensor(int id, vector<string> location,string vender);
    string getType()const override{return "CoSensor";};
    void activate() override;
    void deactivate() override;
};

#endif // COSENSOR_H
