#include <memory>
#include <iostream>
#include <vector>
#include "Sensor.h"
#include "Action.h"
#include "Actextinction.h"
#include "MotionSensor.h"
#include "SmokeSensor.h"
#include "GasSensor.h"
#include "ControlCenter.h"
#include "Alarm.h"
#include "SendMessage.h"
#include "SendEmail.h"
//#include <vld.h>

int main()
{

    auto controlCenter = ControlCenter();
    cout<<"/****************part1*********************************************/"<<endl;
    shared_ptr<SmokeSensor> smokeSensor;
    smokeSensor =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"GT","5","01"},"Sensor Solution")) ;
    shared_ptr<GasSensor> gasSensor;
    gasSensor=dynamic_pointer_cast<GasSensor>(controlCenter.createComponent(SensorType::GasSensor,{"GT","5","01"},"GasSense")) ;
    gasSensor->setGasType("NOx");

    smokeSensor->addAction(make_unique<Alarm>("GT"));
    smokeSensor->addAction(make_unique<SendMessage>(SendMessage("GroupT 05.01","KULeuven central dispatch","Smoke detected in GT 05.01")));
    gasSensor->addAction(make_unique<Alarm>("0501"));
    gasSensor->addAction(make_unique<SendEmail>("donny.dhondt@kuleuven.be","Detect Gas NOx leakeage in GT 05.01"));
    cout<<" /****************part2*********************************************/"<<endl;
    shared_ptr<SmokeSensor> smokeSensor2;
    smokeSensor2 =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"GT","10","01"},"Sensor Solution")) ;
    shared_ptr<MotionSensor> motionSensor;
    motionSensor=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"GT","10","01"},"GotYou")) ;

    motionSensor->setActivePeriod({.tm_min=0,.tm_hour=22},{.tm_min=0,.tm_hour=7});
    smokeSensor2->addAction(make_unique<Alarm>("GT"));
    smokeSensor2->addAction(make_unique<SendMessage>(SendMessage("GroupT 10.01","KULeuven central dispatch","Smoke detected in GT 10.01")));
    motionSensor->addAction(make_unique<SendMessage>(SendMessage("GroupT 10.01","Gert Vanloock","motion detected in GT 10.01")));
    cout<<" /****************part3*********************************************/"<<endl;
    motionSensor->activate();
//    shared_ptr<MotionSensor> motionSensor2;
//    motionSensor2=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"GT","10","02"},"GotYou")) ;
//    motionSensor2->setActivePeriod({.tm_min=0,.tm_hour=22},{.tm_min=0,.tm_hour=7});
//    motionSensor2->addAction(make_unique<SendMessage>(SendMessage("GroupT 10.02","Gert Vanloock","motion detected in GT 10.02")));
//     cout<<"/****************part4*********************************************/"<<endl;
//    shared_ptr<SmokeSensor> smokeSensor3;
//    smokeSensor3 =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"GT","1","03"},"KitchenSafe")) ;
//    shared_ptr<GasSensor> gasSensor2;
//    gasSensor2=dynamic_pointer_cast<GasSensor>(controlCenter.createComponent(SensorType::GasSensor,{"GT","1","03"},"GasSense")) ;
//    gasSensor2->setGasType("CO");
//    shared_ptr<MotionSensor> motionSensor3;
//    motionSensor3=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"GT","1","03"},"BigBrother Is Watching You")) ;

//    smokeSensor3->addAction(make_unique<ActExtinction>("GT"));
//    smokeSensor3->addAction(make_unique<SendMessage>(SendMessage("GroupT 01.03","Alarm dispatch","Smoke detected in GT 01.03")));
//    motionSensor3->addAction(make_unique<SendMessage>(SendMessage("GroupT 01.03","KULeuven security","motion detected in GT 01.03")));
//    motionSensor3->addAction(make_unique<SendMessage>(SendMessage("GroupT 01.03","Police","motion detected in GT 01.03")));
//    cout<<"/***************First activate and test the smoke sensor in lab Chemistry************************************/"<<endl;
//    (*smokeSensor)++;
//    smokeSensor->test();

//    cout<<"/***************Activate and test all sensors in lab chemistry************************************/"<<endl;
//    (*controlCenter.findLocation({"GT","5","01"}))++;
//    controlCenter.testSensorByLoc({"GT","5","01"});
//    cout<<"/***************Test all sensors in the Group T building************************************/"<<endl;
//    controlCenter.testSensorByLoc({"GT"});
//    cout<<"/***************Activate all sensors using the ++ operator************************************/"<<endl;
//    (*controlCenter.findLocation({"GT"}))++;
//    cout<<"not all the sensors are activated, because of the active time constrains, so we use forceActive to active them all"<<endl;
//    controlCenter.findLocation({"GT"})->forceActivate();

//    cout<<"/***************Test the whole building************************************/"<<endl;
//    controlCenter.testSensorByLoc({"GT"});
//    cout<<"/***************Test module 10************************************/"<<endl;
//    controlCenter.testSensorByLoc({"GT","10"});
//    cout<<"/***************Give an overview of all sensors ordered by vendor********************************/"<<endl;
//    controlCenter.overview("vender");

}

