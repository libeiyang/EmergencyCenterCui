#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <string>
#include "Action.h"
class SendEmail : public Action
{
private:
    string msgfrom;
    string msgto;
    string msginfo;

public:
    SendEmail( string mt, string mi);
    void act() const override;
};

#endif // SENDEMAIL_H
