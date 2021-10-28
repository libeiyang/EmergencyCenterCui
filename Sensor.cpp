#include "Sensor.h"
#include <iostream>
#include <algorithm>
#include"MotionSensor.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Sensor& sensor)
{
    string locs = "";
    int layers=sensor.location.size();
    for(int i = 0; i<layers; i++)
    {
        string loc = sensor.location[i];
        if(i<layers - 1 ) locs = locs + loc + ", " ;
        else locs = locs + loc;
    }
    string workingPeriod="";
    if(sensor.getType()=="MotionSensor")
    {
        MotionSensor* temp=(MotionSensor*)&sensor;
        workingPeriod=temp->getActivePeriodAsString();
    }
    return os<<"***************************\n"<<"Sensor description: " <<"\nSensor ID: " <<sensor.id<<"\nVender: "<<sensor.vender
                  <<"\nType: "<<sensor.getType()<<"\nLocation: "<<locs<<"\nStatus: "<<(sensor.status? "active" : "inactive")
                 <<endl<<workingPeriod;
}

void Sensor::activate()
{
    if (!status){
        status = true;
        cout<<"Sensor " << getId()<<" has been activated"<<endl;
    }else{
        cout<<"Sensor " << getId()<<" has already been activated"<<endl;
    }
}

void Sensor::deactivate()
{
    if (status){
        status = false;
        cout<<"Sensor " << getId()<<" has been deactivated";
    }else{
        cout<<"Sensor " << getId()<<" has already been deactivated";
    }
}


void Sensor::forceActivate()
{
    if(!status)
    {
        status=true;
        cout<<"Sensor " << getId()<<" has been forcibly activated"<<endl;
    }
}



string Sensor::getLocationasString()
{
    return accumulate(this->location.begin(), this->location.end(), string{});
}
Sensor :: Sensor (int id, vector<string> location,string vender)
{
    vector<Action> actions;
    this->id = id;
    this->location=location;
    this->vender = vender;
    cout<<"creating a new sensor" <<endl;
}
void Sensor::test()
{
    if(status)
    {
        cout<<"*************"<<endl;
        cout<<"The test of Sensor "<<id<<" starts now."<<endl;
        performAction();
        cout<<"*************"<<endl;
    }
    else {cout<<"Sensor "<<id<<" is currently deactivated, no test case"<<"\n*************"<<endl;}
}
void Sensor::addAction(shared_ptr<Action> newAction)
{
    actions.push_back(move(newAction));
    cout<<"Add new action successfully"<<endl;
}
//string Sensor::getVender() const
//{
//    return vender;
//}
void Sensor::getDescription()
{
    cout<<*this<<endl<<"***************************"<<endl;
}
shared_ptr<vector<string>> Sensor::getLocation()
{
    return make_shared<vector<string>>(location);
}


void Sensor::performAction()
{
    if(status)
    {
        for(unsigned int index =0;index <actions.size();index++)
            actions[index]->act();
    }
}
string Sensor::getType() const{return "";}
