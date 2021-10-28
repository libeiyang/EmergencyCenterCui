#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H


#include "Sensor.h"


struct time{
    int tm_min; //minute range from 0-59
    int tm_hour; //hour  range from 0-24 24 for permanently active sensors
};
class MotionSensor : public Sensor
{

private:
    struct time actTime={.tm_min=0,.tm_hour=0};
    struct time deActTime={.tm_min=0,.tm_hour=0};
    int detectDistance;
public:
    explicit MotionSensor(int id, vector<string> location,string vender);
    void activate() override;
    void deactivate() override;
    void setActivePeriod(struct time actTime, struct time deActTime);;
    string getType() const override {return "MotionSensor";} ;
    string getActivePeriodAsString() const;

    int getDetectDistance() const;
    void setDetectDistance(int value);
};

#endif // MOTIONSENSOR_H
