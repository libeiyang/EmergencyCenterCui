#ifndef GASSENSOR_H
#define GASSENSOR_H

#include "Sensor.h"
#include "SensorType.h"
class GasSensor : public Sensor
{
private:
    string gasType;
    long treshold;
    bool aboveorbelow;  //above treshold->1; below treshold->0
public:
    GasSensor(int id, vector<string> location,string vender);
    string getType() const override {return "GasSensor "+getGasType();};
    string getGasType() const;

    void setGasType(const string &value);
    void activate()override;
    void deactivate()override;


    long getTreshold() const;
    void setTreshold(long value);
    bool getAboveorbelow() const;
    void setAboveorbelow(bool value);
};
#endif // GASSENSOR_H
