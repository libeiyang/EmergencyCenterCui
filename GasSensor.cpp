#include "GasSensor.h"

string GasSensor::getGasType() const
{
    return gasType;
}

void GasSensor::setGasType(const string &value)
{
    gasType = value;
}

long GasSensor::getTreshold() const
{
    return treshold;
}

void GasSensor::setTreshold(long value)
{
    treshold = value;
}

bool GasSensor::getAboveorbelow() const
{
    return aboveorbelow;
}

void GasSensor::setAboveorbelow(bool value)
{
    aboveorbelow = value;
}

GasSensor::GasSensor(int id, vector<string> location,string vender):
    Sensor(id, location, vender)
{
    cout<<"A new GasSensor created"<<endl;
    this->setType(SensorType::GasSensor);
}

void GasSensor::activate()
{
    if (Sensor::getStatus() ==false){
        Sensor::setStatus(true);
        cout<<"Gas Sensor " << getId()<<" has been activated"<<endl;
    }else{
        cout<<"Gas Sensor " << getId()<<" has already been activated before"<<endl;
    }
}

void GasSensor::deactivate()
{
    if (Sensor::getStatus() ==true){
        Sensor::setStatus(false);
        cout<<"Gas Sensor " << getId()<<" has been deactivated"<<endl;
    }else{
        cout<<"Gas Sensor " << getId()<<" has already been deactivated"<<endl;
    }
}

