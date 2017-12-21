//---------------------------------------------------------------------------


#pragma hdrstop

#include "Base64.h"
#include <vcl.h>
#include <math.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
// Base 64 encoder / decoder

//—————————————————————————

AnsiString Base64Encode(AnsiString slToEnc)
{
//The Base64 Table
const char Base64Table[64]=
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char * buftoenc = slToEnc.c_str();
int bufsize = slToEnc.Length() + 1;
char * encbuf = new char[slToEnc.Length() * 5];
encbuf[0] = '\0'; int ilStrLen = -1;
int i=0; int b64byte[5];
unsigned char *buftemp;
AnsiString slRetVal = EmptyStr;

buftemp=(unsigned char *)malloc(bufsize+2);
strcpy(buftemp,buftoenc);
if (std::fmod(bufsize,3)==1)
{
buftemp[bufsize]='\0';
buftemp[bufsize+1]='\0';
}
if (std::fmod(bufsize,3)==2)buftemp[bufsize]='\0';
while (i<bufsize) {
b64byte[0]=buftemp[i]>>2;
b64byte[1]=((buftemp[i]&3)<<4)|(buftemp[i+1]>>4);
b64byte[2]=((buftemp[i+1]&0x0F)<<2)|(buftemp[i+2]>>6);
b64byte[3]=buftemp[i+2]&0x3F;
encbuf[i+(i/3)]=Base64Table[b64byte[0]];
encbuf[i+(i/3)+1]=Base64Table[b64byte[1]];
encbuf[i+(i/3)+2]=Base64Table[b64byte[2]];
encbuf[i+(i/3)+3]=Base64Table[b64byte[3]];
i+=3;
}
free(buftemp);

if (std::fmod(bufsize,3)==0) ilStrLen = bufsize*8/6;
else if (std::fmod(bufsize,3)==1) ilStrLen = ((bufsize+2)*8/6)-2;
else if (std::fmod(bufsize,3)==2) ilStrLen = ((bufsize+1)*8/6)-1;
else ilStrLen = -1;
if(ilStrLen > 0) slRetVal = AnsiString(encbuf).SubString(1, ilStrLen);
if(encbuf != NULL) { delete encbuf; encbuf = NULL; }

return slRetVal;
}

//———————————————————————–

AnsiString Base64Decode(AnsiString slToDec)
{
//Base64 Table
const char Base64Table[64]=
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char * buftodec = slToDec.c_str();
int bufsize = slToDec.Length() + 1;
char * decbuf = new char[slToDec.Length() * 5];
decbuf[0] = '\0'; int ilStrLen = -1;
AnsiString slRetVal = EmptyStr;

int i=0; unsigned char binbyte[4];
int cpos[5]; unsigned char *buftemp;

buftemp=(unsigned char *)malloc(bufsize);
strcpy(buftemp,buftodec);
if (std::fmod(bufsize,4)==1)
{
buftemp[bufsize]='\0';
buftemp[bufsize+1]='\0';
buftemp[bufsize+2]='\0';
}
if (std::fmod(bufsize,4)==2)
{
buftemp[bufsize]='\0';
buftemp[bufsize+1]='\0';
}
if (std::fmod(bufsize,4)==3)buftemp[bufsize]='\0';
while (i<bufsize) {
cpos[0]=strchr(Base64Table,buftemp[i])-Base64Table;
cpos[1]=strchr(Base64Table,buftemp[i+1])-Base64Table;
cpos[2]=strchr(Base64Table,buftemp[i+2])-Base64Table;
cpos[3]=strchr(Base64Table,buftemp[i+3])-Base64Table;
binbyte[0]=((cpos[0]<<2)|(cpos[1]>>4));
binbyte[1]=((cpos[1]<<4)|(cpos[2]>>2));
binbyte[2]=(((cpos[2]&0x03)<<6)|(cpos[3]&0x3f));
decbuf[i-(i/4)]=binbyte[0];
decbuf[i-(i/4)+1]=binbyte[1];
decbuf[i-(i/4)+2]=binbyte[2];
i+=4;
}
free(buftemp);
if (std::fmod(bufsize,4)==0) ilStrLen = bufsize*6/8;
else if (std::fmod(bufsize,4)==1) ilStrLen = ((bufsize+3)*6/8)-3;
else if (std::fmod(bufsize,4)==2) ilStrLen = ((bufsize+2)*6/8)-2;
else if (std::fmod(bufsize,4)==3) ilStrLen = ((bufsize+1)*6/8)-1;
else ilStrLen = -1;
if(ilStrLen > 0) slRetVal = AnsiString(decbuf).SubString(1, ilStrLen);
if(decbuf != NULL) { delete decbuf; decbuf = NULL; }
return slRetVal;
}
