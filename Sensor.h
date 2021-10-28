#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <vector>
#include <memory>
#include "Component.h"
#include "Location.h"
#include "Action.h"
#include "SensorType.h"
#include <numeric>

using namespace std;
class Location;
class Sensor : Component
{
private:
    int id;
    string vender;
    //Location * location;
    vector<string> location;
    bool status = false;
    vector<shared_ptr<Action>> actions;
    SensorType type;
public:
    friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);
    explicit Sensor(int id, vector<string> location,string vender);
    void getDescription();
    void performAction();
    void test();
    void addAction(shared_ptr<Action> newAction);
    shared_ptr<vector<string>> getLocation();
    string getVender() const {return this->vender;};
    virtual string getType() const ;
    int getId() const {return this->id;};
    virtual void activate();
    virtual void deactivate();
    void forceActivate();
    bool getStatus (){return status;}
    void setStatus (bool s) {status = s;}

    void operator++ (int) {activate();}//post increment
    void operator-- (int) {deactivate();} //post increment


    string getLocationasString();
    void setType(const SensorType &value) {this->type = value;};
    SensorType getType(){return type;};

};

#endif // SENSOR_H
