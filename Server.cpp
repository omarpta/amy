//---------------------------------------------------------------------------


#pragma hdrstop

#include "Server.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
void __fastcall TServer::setHostName(AnsiString HostName)
{
    this->HostName = HostName;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TServer::getHostName()
{
    return this->HostName;
}
//---------------------------------------------------------------------------
void __fastcall TServer::setHost(AnsiString Host)
{
    this->Host = Host;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TServer::getHost()
{
    return this->Host;
}
//---------------------------------------------------------------------------
void __fastcall TServer::setPort(int Port)
{
    this->Port = Port;
}
//---------------------------------------------------------------------------
int __fastcall TServer::getPort()
{
    return this->Port;
}
//---------------------------------------------------------------------------
void __fastcall TServer::setUser(AnsiString User)
{
    this->User = User;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TServer::getUser()
{
    return this->User;
}
//---------------------------------------------------------------------------
void __fastcall TServer::setPass(AnsiString Pass)
{
    this->Pass = Pass;
}
//---------------------------------------------------------------------------
AnsiString __fastcall TServer::getPass()
{
    return this->Pass;
}
//---------------------------------------------------------------------------
__fastcall TServer::TServer()
{
}
//---------------------------------------------------------------------------
__fastcall TServer::~TServer()
{
}
