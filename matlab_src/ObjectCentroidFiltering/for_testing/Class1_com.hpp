#ifndef _ObjectCentroidFiltering_Class1_com_HPP
#define _ObjectCentroidFiltering_Class1_com_HPP 1

#include <windows.h>
#include "ObjectCentroidFiltering_idl.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "mclcomclass.h"

class Class1 : public CMCLClassImpl<IClass1, &IID_IClass1, Class1, &CLSID_Class1>
{
public:
  Class1();
  ~Class1();
  HRESULT __stdcall get_help(/*[in]*/ BSTR funcname, /*[out, retval*/ BSTR* text);

  HRESULT __stdcall find_object_centroids(/*[in]*/long nargout, /*[in,out]*/VARIANT* 
                                          outputImg, /*[in,out]*/VARIANT* 
                                          outputCentroids, /*[in]*/VARIANT img); 
private:
  static std::map<std::string, const wchar_t*> help_map;
  static std::map<std::string, const wchar_t*> createHelpMap();
};
#endif
