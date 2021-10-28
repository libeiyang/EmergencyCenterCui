#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include <vector>
#include "Component.h"
#include "Sensor.h"
using namespace std;


class Sensor;
class Location : Component
{
private:
    vector<shared_ptr<Component>> components;
    vector<shared_ptr<Location>> locations;
    vector<shared_ptr<Sensor>> sensors;
    string location;
public:
    Location(string loc);
    //void addComp(Component c, string loc);  //
    void removeComp(vector<string> loc);
    shared_ptr<vector<shared_ptr<Sensor>>> getAllSensors(); //recursively get sensors
    void removeAll();
    string getLocation();
    shared_ptr<vector<shared_ptr<Component>>> getComponents();
    shared_ptr<vector<shared_ptr<Location>>> getLocations();
    shared_ptr<vector<shared_ptr<Sensor>>> getSensors(); //get sensors in this very spot
    void addComponent(shared_ptr<Sensor>);
    void addComponent(shared_ptr<Location>);
    void test();
    void activate();
    void forceActivate();
    void deactivate();
    //to be finished
    void operator++ (int) {activate();}//post increment
    void operator-- (int) {deactivate();} //post increment
    shared_ptr<Location> findLocation(vector<string> loc);
};

#endif // LOCATION_H
