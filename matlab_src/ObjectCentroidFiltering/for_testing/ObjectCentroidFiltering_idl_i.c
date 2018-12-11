

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for C:\Users\crowelmk\Documents\Class Materials\Senior Project\Pointing\matlab_src\ObjectCentroidFiltering\for_testing\ObjectCentroidFiltering_idl.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=IA64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IClass1,0x6E84E08A,0xCF10,0x442E,0xA9,0x0E,0x2B,0x78,0x76,0x64,0xB2,0x4B);


MIDL_DEFINE_GUID(IID, LIBID_ObjectCentroidFiltering,0x62A5B219,0xED8A,0x4518,0xA1,0x2F,0x25,0xE9,0x97,0x50,0xEF,0x95);


MIDL_DEFINE_GUID(CLSID, CLSID_Class1,0x214B5135,0xC26F,0x48D7,0x9F,0xB7,0x59,0x8C,0x8C,0xC1,0x28,0x9B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



