#include "CoSensor.h"

CoSensor::CoSensor(int id, vector<string> location,string vender):
    Sensor(id, location, vender)
{
    cout<<"A new CO Sensor created"<<endl;

    this->setType(SensorType::CoSensor);
}

void CoSensor::activate()
{
    if (Sensor::getStatus() ==false){
        Sensor::setStatus(true);
        cout<<"CO Sensor " << getId()<<" has been activated"<<endl;
    }else{
        cout<<"CO Sensor " << getId()<<" has already been activated before"<<endl;
    }
}

void CoSensor::deactivate()
{
    if (Sensor::getStatus() ==true){
        Sensor::setStatus(false);
        cout<<"CO Sensor " << getId()<<" has been deactivated"<<endl;
    }else{
        cout<<"CO Sensor " << getId()<<" has already been deactivated"<<endl;
    }
}
