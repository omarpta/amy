//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "BusinessSkinForm.hpp"
#include "bsSkinCtrls.hpp"
#include "bsSkinBoxCtrls.hpp"
#include <Mask.hpp>
#include "ScBridge.hpp"
#include "ScSSHChannel.hpp"
#include "ScSSHClient.hpp"
#include "bsSkinExCtrls.hpp"
#include "Server.h"
//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
    TbsBusinessSkinForm *bsBusinessSkinForm1;
    TbsSkinGroupBox *configGroup;
    TbsSkinMemo *terminal;
    TbsSkinComboBox *cmbHosts;
    TbsSkinEdit *terminalInput;
    TbsSkinStdLabel *bsSkinStdLabel1;
    TbsSkinEdit *txtHost;
    TbsSkinStdLabel *bsSkinStdLabel2;
    TbsSkinEdit *txtUser;
    TbsSkinStdLabel *bsSkinStdLabel3;
    TbsSkinStdLabel *bsSkinStdLabel4;
    TbsSkinEdit *txtForward;
    TScSSHClient *ScSSHClient1;
    TScSSHShell *ScSSHShell1;
    TScFileStorage *ScFileStorage1;
    TbsSkinXFormButton *btnGo;
    TbsSkinPasswordEdit *txtPass;
    void __fastcall btnGoClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall cmbHostsChange(TObject *Sender);
private:	// User declarations
    TList *serversList;
public:		// User declarations
    __fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
