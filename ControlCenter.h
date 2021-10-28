#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H
#include "Component.h"
#include "Location.h"
#include "Sensor.h"
#include <string>
#include <vector>
#include "SensorType.h"
#include "SensorType.h"
using namespace std;
class ControlCenter
{
private:
    int nextID;
    vector<shared_ptr<Sensor>> sensors;
    vector<shared_ptr<Location>> locations;
    shared_ptr<Location> topLocation;
public:

    ControlCenter();
    shared_ptr<Location> createComponent(string loc); //create loc
    shared_ptr<Sensor> createComponent(SensorType type, vector<string> loc, string vender ); //create sensor then add it to loc
  //  void addComponentToLoc(vector<string> loc,Component comp ); //暂时搁置
    shared_ptr<Location> findLocation(vector<string> loc);
    shared_ptr<vector<shared_ptr<Sensor>>> findSensorsByLoc(vector<string> loc);
    //find sensors in a exact location  eg. findsensor in gt module10, only return the sensors under module 10
    //and discards sensors in the lower location of module 10
    shared_ptr<vector<shared_ptr<Sensor>>> findAllSensorsUnderLoc(vector<string> loc);
    //find all sensors under the location   eg.findAllSensorsUnderLoc(['GT']) returns all the sensors in gt
    shared_ptr<vector<shared_ptr<Sensor>>> findAllSensorsButType(SensorType type);
    shared_ptr<vector<shared_ptr<Sensor>>> findAllSensorsButType(shared_ptr<Sensor>  sensortype);

    shared_ptr<vector<shared_ptr<Sensor>>> findAllSensorsofType(shared_ptr<Sensor>  sensortype);
    void testSensorByLoc(vector<string> loc);
    //test all sensors under loc
    void overview(string orderBy);
    //implementment uses fast sorting algorithm
    void addSensorToLoc(vector<string> loc,shared_ptr<Sensor> s);
    typedef bool (*fptr)(shared_ptr<Sensor>,shared_ptr<Sensor>);
    fptr comparator(string orderBy);
    static bool idComparator(shared_ptr<Sensor> s1,shared_ptr<Sensor> s2);
    static bool venderComparater(shared_ptr<Sensor> s1,shared_ptr<Sensor> s2);
    static bool locationComparater(shared_ptr<Sensor> s1,shared_ptr<Sensor> s2);
    shared_ptr<vector<shared_ptr<Sensor> >> getSensors() const{return make_shared<vector<shared_ptr<Sensor>>>(sensors);};
    shared_ptr<vector<shared_ptr<Location> >> getLocations() const{return make_shared<vector<shared_ptr<Location>>>(locations);};
};

#endif // CONTROLCENTER_H

