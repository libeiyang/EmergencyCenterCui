#include "Location.h"
Location::Location(string loc)
{
    this->location=loc;
#ifdef DEBUG
    cout<<"Location "<<loc<< " created"<<endl;
#endif
}

void Location::removeComp(vector<string> loc)
{
    cout<<loc[0]<<" is removed"<<endl;
}

shared_ptr<vector<shared_ptr<Sensor>>> Location::getAllSensors()
{
    vector<shared_ptr<Sensor>> ss;
    ss.insert(ss.end(),sensors.begin(),sensors.end());
    if(locations.size()!=0)
    {
        for(shared_ptr<Location> l:locations)
        {
            auto temp=l->getAllSensors();
            ss.insert(ss.end(),temp->begin(),temp->end());
        }
    }
    return make_shared<vector<shared_ptr<Sensor>>>(ss);
}

void Location::removeAll()
{
    //
    for (shared_ptr<Component> p : this->components)
       {
         p.reset();
       }
    this->components.clear();
    for (shared_ptr<Location> p : this->locations)
       {
         p.reset();
       }
    this->locations.clear();
    for (shared_ptr<Sensor> p : this->sensors)
       {
         p.reset();
       }
    this->sensors.clear();
}

string Location::getLocation()
{
    return this->location;
}

shared_ptr<vector<shared_ptr<Component>>> Location::getComponents()
{
    return make_shared<vector<shared_ptr<Component>>>(this->components);
}

shared_ptr<vector<shared_ptr<Location>>> Location::getLocations()
{
 return make_shared<vector<shared_ptr<Location>>>(this->locations);
}

shared_ptr<vector<shared_ptr<Sensor>>> Location::getSensors()
{
    return make_shared<vector<shared_ptr<Sensor>>>(sensors);
}

void Location::addComponent(shared_ptr<Sensor> sensor)
{
    this->sensors.push_back(sensor);
}
void Location::addComponent(shared_ptr<Location> loc)
{
   this->locations.push_back(loc);
}
void Location::test()
{
    for (shared_ptr<Sensor> s : this->sensors)
       {
         s->test();
       }
    for (shared_ptr<Location> p : this->locations)
       {
         p->test();
    }
}

void Location::activate()
{
    for (shared_ptr<Sensor> s : this->sensors)
       {
         (*s)++;
       }
    for (shared_ptr<Location> p : this->locations)
       {
         (*p)++;
    }
}

void Location::forceActivate()
{
    for (shared_ptr<Sensor> s : this->sensors)
       {
         s->forceActivate();
       }
    for (shared_ptr<Location> p : this->locations)
       {
         p->forceActivate();
    }
}

void Location::deactivate()
{
    for (shared_ptr<Sensor> s : this->sensors)
       {
         (*s)--;
       }
    for (shared_ptr<Location> p : this->locations)
       {
         (*p)--;
    }
}
shared_ptr<Location> Location::findLocation(vector<string> loc)
{
    for(shared_ptr<Location> p : this->locations)
    {
        if(p->getLocation()==loc[0])
        {
            if(loc.size()==1)
                return p;
            else
            {
                loc.erase(loc.begin());
                return p->findLocation(loc);
            }
        }
    }
    return NULL;
}
