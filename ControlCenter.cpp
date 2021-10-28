#include "ControlCenter.h"
#include "SmokeSensor.h"
#include<algorithm>
#include<iostream>
#include<typeinfo>
#include"MotionSensor.h"
#include"GasSensor.h"
#include"CoSensor.h"
using namespace std;

ControlCenter::ControlCenter()
{
    this->nextID=1;
}
shared_ptr<Location> ControlCenter::createComponent(string loc)
{
    shared_ptr<Location> p_loc;
    p_loc=make_shared<Location>(loc);
    //wait for addComp
    locations.push_back(p_loc);
    return p_loc;
}
shared_ptr<Sensor> ControlCenter::createComponent(SensorType type, vector<string> loc, string vender) //checked
{
    shared_ptr<Sensor> s;
    switch (type) {
        case SensorType::GasSensor:
            s=make_shared<GasSensor>(nextID++,loc,vender);
            break;
        case SensorType::SmokeSensor:
            s= make_shared<SmokeSensor>(nextID++,loc,vender);
            break;
        case SensorType::MotionSensor:
            s=make_shared<MotionSensor>(nextID++,loc,vender);
             break;
		case SensorType::CoSensor:
            s=make_shared<CoSensor>(nextID++,loc,vender);
			break;
    }
    sensors.push_back(s);

    this->addSensorToLoc(loc,s);
    return s;
}
/*
 * 循环解法，应该还可以用recursion的方法把传感器加到某个位置（应在addcomponentoLoc方法中实现）
 *
*/
void ControlCenter::addSensorToLoc(vector<string> loc,shared_ptr<Sensor> s)  //checked
{
    int layers=loc.size();
    if(this->topLocation==NULL){  //create toplocation if not exist
        this->topLocation=createComponent(loc[0]);
    }
    shared_ptr<Location> upperLoc=topLocation;
    shared_ptr<Location> l;
    for(int i =1;i<layers;i++){
        l=NULL;
		vector< shared_ptr<Location>> locationsByUpper= *(upperLoc->getLocations());
        for(shared_ptr<Location> a :locationsByUpper){
            if(a->getLocation()==loc[i]){
                l=a;
                break;
            }
        }
        if(l==NULL){
            shared_ptr<Location> temp=createComponent(loc[i]);
            upperLoc->addComponent(temp);
            upperLoc=temp;
        }else
            upperLoc=l;

    }

    upperLoc->addComponent(s);
}
shared_ptr<vector<shared_ptr<Sensor>>> ControlCenter::findSensorsByLoc(vector<string> loc) //checked
{
    if(this->topLocation->getLocation()==loc[0]){
		if (loc.size() == 1)
			return topLocation->getSensors();
        loc.erase(loc.begin());
        shared_ptr<Location> temp= topLocation->findLocation(loc);
        if(temp!=NULL){
            return temp->getSensors();
        }
    }
#ifdef DEBUG
    else
    cout<<"no topLocation"<<endl;
#endif
    cout<< "no sensor in location ";
    for(string s:loc){
        cout<<s<<" ";
    }
    cout<<endl;
    return NULL;

}
shared_ptr<Location> ControlCenter::findLocation(vector<string> loc){
    if(this->topLocation->getLocation()==loc[0]){
        if(loc.size()==1)
           return topLocation;
        else{
            loc.erase(loc.begin());
            shared_ptr<Location> temp= topLocation->findLocation(loc);
            if(temp!=NULL){
                return temp;
            }
        }

    }
    cout<< "location 404";
    for(string s:loc){
        cout<<s<<" ";
    }
    cout<<endl;
    return NULL;

}
void ControlCenter::testSensorByLoc(vector<string> loc)  //checked
{
       auto location=findLocation(loc);
       if(location!=NULL)
           location->test();
}
shared_ptr<vector<shared_ptr<Sensor>>> ControlCenter::findAllSensorsUnderLoc(vector<string> loc)  //checked
{
    if(this->topLocation->getLocation()==loc[0]){
        if(loc.size()==1)
            return topLocation->getAllSensors();
        loc.erase(loc.begin());
        shared_ptr<Location> temp= topLocation->findLocation(loc);
        if(temp!=NULL){
            return temp->getAllSensors();
        }
    }
#ifdef DEBUG
    else
    cout<<"no topLocation"<<endl;
#endif
    cout<< "no sensor in location ";
    for(string s:loc){
        cout<<s<<" ";
    }
    cout<<endl;
    return NULL;
}

shared_ptr<vector<shared_ptr<Sensor> > > ControlCenter::findAllSensorsButType(SensorType type)
{

    vector<shared_ptr<Sensor> >  sensorswithouttype;
    for(unsigned int index =0;index <sensors.size();index++)
    {if (sensors[index]->getType()!=type){
            sensorswithouttype.push_back(sensors[index]);
        }}
    return make_shared<vector<shared_ptr<Sensor>>>(sensorswithouttype);
}

shared_ptr<vector<shared_ptr<Sensor> > > ControlCenter::findAllSensorsButType(shared_ptr<Sensor> sensortype)
{
    vector<shared_ptr<Sensor> >  sensorswithouttype;
    for(unsigned int index =0;index <sensors.size();index++)

    {
//        bool a =typeid(* sensors[index])==typeid(*sensortype);
//        cout<<index<<" "<<typeid( sensors[index]).name()<<typeid(*sensortype).name()<<a<<endl;
        if (typeid(* sensors[index])!=typeid(*sensortype)){
            sensorswithouttype.push_back(sensors[index]);
        }}
    return make_shared<vector<shared_ptr<Sensor>>>(sensorswithouttype);
}

shared_ptr<vector<shared_ptr<Sensor> > > ControlCenter::findAllSensorsofType(shared_ptr<Sensor> sensortype)
{
    vector<shared_ptr<Sensor> >  sensorswithouttype;
    for(unsigned int index =0;index <sensors.size();index++)
    {
        if (typeid(* sensors[index])==typeid(*sensortype)){
            sensorswithouttype.push_back(sensors[index]);
        }}
    return make_shared<vector<shared_ptr<Sensor>>>(sensorswithouttype);
}


void ControlCenter::overview(string orderBy)   //checked
{
    if(topLocation!=NULL){
        shared_ptr<vector<shared_ptr<Sensor>>> sensors=topLocation->getAllSensors();
        sort(sensors->begin(),sensors->end(),comparator(orderBy)); //sort sensors according to a required order
        for(shared_ptr<Sensor> s:*sensors){
            s->getDescription();  //need to finalize the description
        }
    }
}
typedef bool (*fptr)(shared_ptr<Sensor>,shared_ptr<Sensor>);
fptr ControlCenter::comparator(string orderBy){
    if(orderBy=="id")
    {
        return ControlCenter::idComparator;
    }
    else if(orderBy=="vender")
    {
        return ControlCenter::venderComparater;
    }
    else
    {
        return ControlCenter::locationComparater;
    }
}

bool ControlCenter::idComparator(shared_ptr<Sensor> s1, shared_ptr<Sensor> s2)
{
    return s1->getId()<s2->getId();
}
bool ControlCenter::venderComparater(shared_ptr<Sensor> s1, shared_ptr<Sensor> s2)
{
    return s1->getVender()<s2->getVender();
}
bool ControlCenter::locationComparater(shared_ptr<Sensor> s1, shared_ptr<Sensor> s2)
{
    shared_ptr<vector<string>> loc1=s1->getLocation();
    shared_ptr<vector<string>> loc2=s2->getLocation();
    int layers= min(loc1->size(),loc2->size());
    for(int i=0;i<layers;i++)
    {
        if((*loc1)[i]!=(*loc2)[i])
        {
            return (*loc1)[i]<(*loc2)[i];
        }
    }
    return loc1->size()<loc2->size();
}
