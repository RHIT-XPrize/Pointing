#include "mwcomtypes.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "Class1_com.hpp"
#include "ObjectCentroidFiltering_idl_i.c"
#include "mwcomutil_i.c"
#include "mwcomtypes_i.c"

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif


static bool _mcr_initialize_fcn(HMCRINSTANCE* inst,
                                const char* path_to_component,
                                mclCtfStream ctfStream)
{
    {
        if (ctfStream) {
            return mclInitializeComponentInstanceEmbedded(  inst,
                                                            NULL, 
                                                            NULL,
                                                            ctfStream);
        } else {
            return false;
        }
    }      
  return false;

}
static bool _mcr_terminate_fcn(HMCRINSTANCE* inst)
{
  return mclTerminateInstance(inst);
}
static CMCLSingleModule g_Module(_mcr_initialize_fcn, _mcr_terminate_fcn, true);
CMCLModule* g_pModule = &g_Module;

static _MCLOBJECT_MAP_ENTRY objectmap[] = 
{
  {
      &CLSID_Class1, Class1::RegisterClass, Class1::UnregisterClass, 
    Class1::GetClassObject, "Class1", "ObjectCentroidFiltering.Class1", 
    "ObjectCentroidFiltering.Class1.1_0"
  },
  {
    NULL, NULL, NULL, NULL, "", "", ""
  }
};

extern "C" {

BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, void *pv )
{
  return g_pModule->InitMain(objectmap, &LIBID_ObjectCentroidFiltering, 1, 0, hInstance, 
                             dwReason, pv);
}

HRESULT __stdcall DllCanUnloadNow()
{
    return (g_pModule->GetLockCount()==0) ? S_OK : S_FALSE;
}

HRESULT __stdcall DllGetClassObject(REFCLSID clsid, REFIID iid, void **ppv )
{
    return g_pModule->GetClassObject( clsid, iid, ppv );
}

HRESULT __stdcall DllRegisterServer()
{
    return g_pModule->UpdateRegistry( TRUE );
}

HRESULT __stdcall DllUnregisterServer()
{
    return g_pModule->UpdateRegistry( FALSE );
}

}
