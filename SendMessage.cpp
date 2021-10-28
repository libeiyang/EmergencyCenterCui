#include <iostream>
#include "SendMessage.h"



SendMessage::SendMessage(string mf, string mt, string mi)
    : msgfrom{mf}, msgto{mt}, msginfo{mi}
{
    cout<<"New sendmessage action created"<<endl;
}
void SendMessage::act() const
{
    cout<<"Send message: " <<msginfo<<" \nfrom "<<msgfrom<<" to "<<msgto<<endl;

}


