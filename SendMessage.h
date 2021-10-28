#ifndef SENDMESSAGE_H
#define SENDMESSAGE_H

#include <string>
#include "Action.h"

class SendMessage : public Action
{
private:
    string msgfrom;
    string msgto;
    string msginfo;

public:
    SendMessage(string mf, string mt, string mi);
    void act() const override;
};

#endif // ACTEXTINCTION_H
