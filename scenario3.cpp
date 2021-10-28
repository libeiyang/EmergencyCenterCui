#include <QCoreApplication>
#include <memory>
#include <iostream>
#include <vector>
#include "ControlCenter.h"
#include "Sensor.h"
#include "SmokeSensor.h"
#include "Actextinction.h"
#include "MotionSensor.h"
#include "GasSensor.h"
#include "SensorType.h"
int main(int argc, char *argv[])
//{
{

    ControlCenter c {};
    shared_ptr<MotionSensor> ms1 = dynamic_pointer_cast<MotionSensor>(c.createComponent(SensorType::MotionSensor,{"Twix Galaxy"},"v1"));

//    c.addSensorToLoc(l,s);
    c.overview("id");
    c.findSensorsByLoc({"Twix Galaxy"});

    shared_ptr<GasSensor> gs1 = dynamic_pointer_cast<GasSensor>(c.createComponent(SensorType::GasSensor,{"Twix Galaxy","X AE A-12"},"v1"));
    shared_ptr<SmokeSensor> ss1 = dynamic_pointer_cast<SmokeSensor>(c.createComponent(SensorType::SmokeSensor,{"Twix Galaxy","X AE A-12","Redstone"},"v1"));
    shared_ptr<SmokeSensor> ss2 = dynamic_pointer_cast<SmokeSensor>(c.createComponent(SensorType::SmokeSensor,{"Twix Galaxy","X AE A-12","Orangestone"},"v1"));


    // Just a test
    return 0;
}

