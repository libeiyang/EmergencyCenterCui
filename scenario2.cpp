#include <memory>
#include <iostream>
#include <vector>
#include "Sensor.h"
#include "Action.h"
#include "MotionSensor.h"
#include "SmokeSensor.h"
#include "CoSensor.h"
#include "GasSensor.h"
#include "ControlCenter.h"
#include "Alarm.h"
#include "SendMessage.h"
#include "SendEmail.h"
#include "TurnOn.h"


int main()
{
    auto controlCenter = ControlCenter();
    cout<<"/****************part1*********************************************/"<<endl;
    shared_ptr<SmokeSensor> smokeSensor;
    smokeSensor =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"Neighborhood","John","shed" }, "Smokey")) ;
    shared_ptr<MotionSensor> motionSensor;
    motionSensor=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"Neighborhood","John","shed" }, "IcanCU")) ;

    smokeSensor->addAction(make_unique<Alarm>("Johns' house"));
    smokeSensor->addAction(make_unique<SendMessage>(SendMessage("John's shed","Fire department of the neighborhood","Smoke detected in John's shed")));
    motionSensor->addAction(make_unique<TurnOn>("John's shed", "light and air conditioner"));
    cout<<" /****************part2*********************************************/"<<endl;
    shared_ptr<SmokeSensor> smokeSensor2;
    smokeSensor2 =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"Neighborhood","Vicky","kitchen"},"Smokey")) ;
    shared_ptr<MotionSensor> motionSensor2;
    motionSensor2=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"Neighborhood","Vicky","kitchen" }, "IcanCU")) ;

    motionSensor2->setActivePeriod(time{.tm_min=0,.tm_hour=22},time{.tm_min=0,.tm_hour=7});
    smokeSensor2->addAction(make_unique<Alarm>("Vicky's house"));
    smokeSensor2->addAction(make_unique<SendMessage>(SendMessage("Vicky's kitchen","Fire department of the neighborhood","Smoke detected in Vicky's kitchen")));
    motionSensor2->addAction(make_unique<SendEmail>("vicky.cooke@gmail.com","Smoke detected in Vicky's kitchen"));
    cout<<" /****************part3*********************************************/"<<endl;

    shared_ptr<CoSensor> coSensor;
    coSensor=dynamic_pointer_cast<CoSensor>(controlCenter.createComponent(SensorType::CoSensor,{"Neighborhood","Dave","living room fireplace"},"BreatheLabs")) ;
    shared_ptr<SmokeSensor> smokeSensor3;
    smokeSensor3 =dynamic_pointer_cast<SmokeSensor>(controlCenter.createComponent(SensorType::SmokeSensor,{"Neighborhood","Dave","living room fireplace"},"BurningInc")) ;

    coSensor->addAction(make_unique<Alarm>("Dave's house"));
    smokeSensor3->addAction(make_unique<TurnOn>("Dave's fireplace in living room", "sprinkler system"));
    smokeSensor3->addAction(make_unique<SendMessage>(SendMessage("Dave's fireplace in living room","Fire department of the neighborhood","Smoke detected in Dave's living room")));
     cout<<"/****************part4*********************************************/"<<endl;
    shared_ptr<GasSensor> gasSensor1;
    gasSensor1 =dynamic_pointer_cast<GasSensor>(controlCenter.createComponent(SensorType::GasSensor,{"Neighborhood","Kaitlin","house"}," TN2S")) ;
    shared_ptr<MotionSensor> motionSensor3;
    motionSensor3=dynamic_pointer_cast<MotionSensor>(controlCenter.createComponent(SensorType::MotionSensor,{"Neighborhood","Kaitlin","lab"},"IcanCU")) ;

    motionSensor3->setActivePeriod({.tm_min=40,.tm_hour=4},{.tm_min=15,.tm_hour=9});
    gasSensor1->addAction(make_unique<Alarm>("all houses in the neighborhood"));
    motionSensor3->addAction(make_unique<SendEmail>("kaitlin@gmail.com","Motion detected in Kaitlin's lab"));

    cout<<"/*************** 1. First activate and test the smoke sensor in John's shed************************************/"<<endl;
    (*smokeSensor)++;
    smokeSensor->test();

    cout<<"/*************** 2. Activate and test all sensors in Vicky's kitchen and John's house************************************/"<<endl;
    (*controlCenter.findLocation({"Neighborhood","Vicky","kitchen"}))++;
    motionSensor2->forceActivate();//because of time constraint
    controlCenter.testSensorByLoc({"Neighborhood","Vicky","kitchen"});
    (*controlCenter.findLocation({"Neighborhood","John"}))++;
    controlCenter.testSensorByLoc({"Neighborhood","John"});
    cout<<"/*************** 3. Test all sensors in the neighborhood************************************/"<<endl;
    controlCenter.testSensorByLoc({"Neighborhood"});
    cout<<"/*************** 4. Activate all sensors using the ++ operator************************************/"<<endl;
    (*controlCenter.findLocation({"Neighborhood"}))++;
    motionSensor3->forceActivate();//because of time constraint
    cout<<"/*************** 5. Test the whole Neighborhood************************************/"<<endl;
    controlCenter.testSensorByLoc({"Neighborhood"});
    cout<<"/*************** 6. Test  the mad scientist’s house************************************/"<<endl;
    controlCenter.testSensorByLoc({"Neighborhood","Kaitlin"});
    cout<<"/*************** 7. Give an overview of all sensors ordered by id********************************/"<<endl;
    controlCenter.overview("id");
}
