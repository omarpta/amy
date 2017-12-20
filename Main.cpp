//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BusinessSkinForm"
#pragma link "bsSkinCtrls"
#pragma link "bsSkinBoxCtrls"
#pragma resource "*.dfm"
TFrmMain *FrmMain;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
