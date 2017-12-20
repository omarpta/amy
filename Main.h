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
//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
    TbsBusinessSkinForm *bsBusinessSkinForm1;
    TbsSkinGroupBox *configGroup;
    TbsSkinMemo *bsSkinMemo1;
    TbsSkinComboBox *bsSkinComboBox1;
    TbsSkinEdit *bsSkinEdit1;
private:	// User declarations
public:		// User declarations
    __fastcall TFrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
