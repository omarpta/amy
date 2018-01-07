//---------------------------------------------------------------------------

#ifndef ServerH
#define ServerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
class TServer
{
private:
    AnsiString HostName;
    AnsiString Host;
    int Port;
    AnsiString User;
    AnsiString Pass;
public:
    __fastcall TServer();
    virtual __fastcall ~TServer();
    void __fastcall setHostName(AnsiString HostName);
    AnsiString __fastcall getHostName();
    void __fastcall setHost(AnsiString Host);
    AnsiString __fastcall getHost();
    void __fastcall setPort(int Port);
    int __fastcall getPort();
    void __fastcall setUser(AnsiString User);
    AnsiString __fastcall getUser();
    void __fastcall setPass(AnsiString Pass);
    AnsiString __fastcall getPass();

};
#endif
