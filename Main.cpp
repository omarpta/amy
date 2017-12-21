//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <IniFiles.hpp>
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

        TIniFile *configFile = new TIniFile(GetCurrentDir() + "\\servers.ini");
        TStrings *servers = new TStringList();
        configFile->ReadSection("servers",servers);
        terminal->Lines = servers;
        terminal->Lines->Add(Base64Decode(Base64Encode("oMirueira01#")));

    //}
}
//---------------------------------------------------------------------------

