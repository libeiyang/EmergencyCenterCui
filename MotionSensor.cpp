#include "MotionSensor.h"
#include<time.h>
#include<sstream>

int MotionSensor::getDetectDistance() const
{
    return detectDistance;
}

void MotionSensor::setDetectDistance(int value)
{
    detectDistance = value;
}

MotionSensor::MotionSensor(int id, vector<string> location, string vender) :
    Sensor(id,location,vender)
{
    cout<<"A new MotionSensor created"<<endl;

    this->setType(SensorType::MotionSensor);
}
bool operator>(const struct time &t1,const struct time &t2)
{
    if(t1.tm_hour>t2.tm_hour) return true;
    else if (t1.tm_hour<t2.tm_hour) return false;
    else{
        if(t1.tm_min>t2.tm_min) return true;
        else return false;
    }
}
bool operator>(const struct tm &t1,const struct time &t2)
{
    if(t1.tm_hour>t2.tm_hour) return true;
    else if (t1.tm_hour<t2.tm_hour) return false;
    else{
        if(t1.tm_min>t2.tm_min) return true;
        else return false;
    }
}
bool operator>(const struct time &t1,const struct tm &t2)
{
    if(t1.tm_hour>t2.tm_hour) return true;
    else if (t1.tm_hour<t2.tm_hour) return false;
    else{
        if(t1.tm_min>t2.tm_min) return true;
        else return false;
    }
}
bool CompareTime(struct time &t1,struct time & t2){
    time_t tt=time(NULL);
    struct tm *t =localtime(&tt);
    if (t1.tm_hour == 0 && t1.tm_min == 0 && t2.tm_hour == 0 && t2.tm_min == 0) //without setting activation period
        return true;
    if(t2>t1)    //duration not across 0:00
    {
        if(*t>t1&&t2>*t)
            return true;
        else
            return false;
    }
    else{        //duration across 0:00
        if(*t>t1||t2>*t)
            return true;
        else
            return false;
    }


//    else if(t->tm_hour>t1.tm_hour&&t->tm_hour<t2.tm_hour)
//        return true;
//    else if (t1.tm_hour > t2.tm_hour) //activation duration across 0:00am
//        if (t->tm_hour > t1.tm_hour || t->tm_hour < t2.tm_hour)
//            return true;
//        else return false;
//    else if(t->tm_hour==t1.tm_hour){
//        if(t->tm_min>=t1.tm_min)
//            return true;
//        else return false;
//    }
//    else if(t->tm_hour==t2.tm_hour){
//        if(t->tm_min<=t2.tm_min)
//            return true;
//        else return false;
//    }else return false;
}
void MotionSensor::activate()
{
     if (Sensor::getStatus()) {cout<<"Motion Sensor " << getId()<<" has already been activated before"<<endl;}
    else
    {
        struct time &at = this->actTime;
        struct time &dat = this->deActTime;
        bool enable=CompareTime(at, dat);
    if (this->deActTime.tm_hour==24 && deActTime.tm_min==0 )
    {enable = true;}
        if(enable)
        {
                cout<<"Motion Sensor " << getId()<<" has been activated"<<endl;
                Sensor::setStatus(true);
        }else{
            cout<<"Not able to activate Motion Sensor "<< getId() << " at this time (unless forcely)"<<endl;
        }
    }
}

void MotionSensor::deactivate()
{
    if (Sensor::getStatus() ==true){
        Sensor::setStatus(false);
        cout<<"Motion Sensor " << getId()<<" has been deactivated"<<endl;
    }else{
        cout<<"Motion Sensor " << getId()<<" has already been deactivated"<<endl;
    }
}

void MotionSensor::setActivePeriod(struct time actTime, struct time deActTime)
{
    this->actTime=actTime;
    this->deActTime=deActTime;
    if(this->deActTime.tm_hour==24 && deActTime.tm_min==0)
        this->activate();
}

string MotionSensor::getActivePeriodAsString() const
{
    if (this->deActTime.tm_hour==24 && deActTime.tm_min==0 )
        return "This motion sensor is permanetly active";
    else if(deActTime.tm_hour==0&&deActTime.tm_min==0&&actTime.tm_hour==0&&actTime.tm_min==0)
        return "This motion sensor can be activate at any time";
    else {
        stringstream str;
        str<<"From ";
        if(actTime.tm_hour<10) str<<"0";
        str<<actTime.tm_hour;
        str<<":";
        if(actTime.tm_min<10) str<<"0";
        str<<actTime.tm_min;
        str<<" to ";
        if(deActTime.tm_hour<10) str<<"0";
        str<<deActTime.tm_hour;
        str<<":";
        if(deActTime.tm_min<10) str<<"0";
        str<<deActTime.tm_min;
        return str.str();
    }
}



