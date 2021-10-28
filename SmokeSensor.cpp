#include "SmokeSensor.h"

SmokeSensor::SmokeSensor(int id, vector<string> location,string vender) :
    Sensor(id, location, vender)
{

    cout<<"A new Smoke Sensor created"<<endl;

    this->setType(SensorType::SmokeSensor);

}
void SmokeSensor::activate()
{
    if (Sensor::getStatus() ==false){
        Sensor::setStatus(true);
        cout<<"Smoke Sensor " << getId()<<" has been activated"<<endl;
    }else{
        cout<<"Smoke Sensor " << getId()<<" has already been activated before"<<endl;
    }
}

void SmokeSensor::deactivate()
{
    if (Sensor::getStatus() ==true){
        Sensor::setStatus(false);
        cout<<"Smoke Sensor " << getId()<<" has been deactivated"<<endl;
    }else{
        cout<<"Smoke Sensor " << getId()<<" has already been deactivated"<<endl;
    }
}
