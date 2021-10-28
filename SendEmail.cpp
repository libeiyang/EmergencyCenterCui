#include "SendEmail.h"

SendEmail::SendEmail( string mt, string mi)
    :  msgto{mt}, msginfo{mi}
{
    cout<<"New sendemail action created"<<endl;
}
void SendEmail::act() const
{
    cout<<"Send email: " <<msginfo<< " to "<<msgto<<endl;

}
