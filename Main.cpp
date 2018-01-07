//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <IniFiles.hpp>
#include <StrUtils.hpp>
#include "Base64.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusinessSkinForm"
#pragma link "bsSkinCtrls"
#pragma link "bsSkinBoxCtrls"
#pragma link "ScBridge"
#pragma link "ScSSHChannel"
#pragma link "ScSSHClient"
#pragma link "bsSkinExCtrls"
#pragma resource "*.dfm"
TFrmMain *FrmMain;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::btnGoClick(TObject *Sender)
{
    /*if (txtHost->Text.Length() > 0 &&
        txtUser->Text.Length() > 0 &&
        txtPass->Text.Length() > 0) { */


        //terminal->Lines = servers;
        //terminal->Lines->Add(Base64Decode("b01pcnVlaXJhMDEj"));

    //}
}

//---------------------------------------------------------------------------
void __fastcall TFrmMain::FormCreate(TObject *Sender)
{
    serversList = new TList();
    TIniFile *configFile = new TIniFile(GetCurrentDir() + "\\servers.ini");
    TStrings *servers = new TStringList();
    configFile->ReadSection("servers",servers);

    for (int i = 0; i < servers->Count; i++) {
        TServer *server = new TServer();
        server->setPort(22);
        AnsiString sectionKey = servers->Strings[i];
        AnsiString sectionValue = configFile->ReadString("servers",sectionKey,"");
        if (!sectionValue.IsEmpty()) {
            if (sectionValue.Pos(":") > 0) {
                TStringList *valueParts = Split(':',sectionValue);
                if (valueParts->Count > 1) {
                    server->setHostName(valueParts->Strings[0]);
                    server->setPass(Base64Decode(valueParts->Strings[1]));
                }
            } else {
                server->setPass(Base64Decode(sectionValue));
            }
        }
        if (sectionKey.Pos(":") > 0) {
            TStringList *keyParts = Split(':',sectionKey);
            server->setPort(keyParts->Strings[1].ToInt());
            sectionKey = keyParts->Strings[0];
        }
        ShowMessage(sectionKey);
    }
}
//---------------------------------------------------------------------------

