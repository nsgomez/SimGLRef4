#include <cIGZApp.h>
#include <cIGZFrameWork.h>
#include <cIGZMessage2.h>
#include <cIGZMessageServer2.h>
#include <cIGZMessageTarget2.h>
#include <cISC4App.h>
#include <cISC4RenderProperties.h>
#include <cRZCOMDllDirector.h>
#include <GZServPtrs.h>
#include <Windows.h>
#include "../include/cGZGLDx11Driver.h"

static const uint32_t kGLDx11DriverPluginCOMDirectorID = 0x8bbd9623;

class cGZGLDx11DriverPluginCOMDirector : public cRZCOMDllDirector
{
	public:
		uint32_t GetDirectorID() const {
			return kGLDx11DriverPluginCOMDirectorID;
		}

		bool PreFrameWorkInit() {
			MessageBoxA(NULL, "Hello!", NULL, NULL);
			return true;
		}

		bool OnStart(cIGZCOM* pCOM) {
			cIGZFrameWork* const pFramework = RZGetFrameWork();
			if (pFramework) {
				if (pFramework->GetState() < cIGZFrameWork::kStatePreAppInit) {
					pFramework->AddHook(this);
				}
				else {
					PreAppInit();
				}
			}
			return true;
		}

		bool InitializeCOM(cIGZCOM* pCOM, const cIGZString& sLibraryPath) {
			AddCls(cGZGLDx11Driver::kGLDx11DriverGZCLSID, cGZGLDx11Driver::FactoryFunctionPtr2);
			return cRZCOMDllDirector::InitializeCOM(pCOM, sLibraryPath);
		}
		
		void EnumClassObjects(ClassObjectEnumerationCallback pCallback, void* pContext) {
			for (ChildDirectorArray::iterator it(mChildDirectorArray.begin()); it != mChildDirectorArray.end(); ++it) {
				cRZCOMDllDirector* const pDirector = *it;
				pDirector->EnumClassObjects(pCallback, pContext);
			}

			for (ClassObjectMap::iterator it2(mClassObjectMap.begin()); it2 != mClassObjectMap.end(); ++it2) {
				const uint32_t classID = (*it2).first;
				pCallback(classID, 10, pContext);
			}
		}
};

cRZCOMDllDirector* RZGetCOMDllDirector() {
	static cGZGLDx11DriverPluginCOMDirector sDirector;
	return &sDirector;
}