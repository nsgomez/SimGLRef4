#pragma once
#include <cRZUnknown.h>
#include <GL/glcorearb.h>
#include <GL/wglext.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "cIGZGDriver.h"

const uint32_t kIGZGDriverGZIID = 0xa4554849;

class cGZGLRef4Driver : public cIGZGDriver, public cRZUnknown
{
	private:
		enum class DriverError
		{
			OK = 0,
			OUT_OF_RANGE = 2,
			CREATE_CONTEXT_FAIL = 6,

			FORCE_DWORD = 0x7FFFFFFF
		};

	private:
		GLFWwindow *window;
		DriverError lastError;
		std::vector<sGDMode> videoModes;
		uint32_t videoModeCount;
		bool areVideoModesLoaded;
		int32_t currentVideoMode;

	private:
		int32_t InitializeVideoModeVector(void);
		void SetLastError(DriverError err);

	public:
		cGZGLRef4Driver();
		virtual ~cGZGLRef4Driver();

		// Rather than being nice about it, we're going to hijack the GZCLSID
		// of the original DX7 driver and override it by presenting a higher
		// version number to the GZCOM, because obviously we're better.
		static const uint32_t kGLRef4DriverGZCLSID = 0xc4554841;

		static bool FactoryFunctionPtr2(uint32_t riid, void** ppvObj) {
			cGZGLRef4Driver* pDriver = new cGZGLRef4Driver();
			bool bSucceeded = pDriver->QueryInterface(riid, ppvObj);
			
			if (!bSucceeded || *ppvObj == NULL) {
				bSucceeded = false;

				delete pDriver;
				pDriver = NULL;
			}
			
			return bSucceeded;
		}

	public:
		virtual bool QueryInterface(uint32_t riid, void** ppvObj) {
			if (riid == kIGZGDriverGZIID) {
				*ppvObj = static_cast<cIGZGDriver*>(this);
				return true;
			}

			return cRZUnknown::QueryInterface(riid, ppvObj);
		}

		virtual uint32_t AddRef(void) {
			return cRZUnknown::AddRef();
		}

		virtual uint32_t Release(void) {
			return cRZUnknown::Release();
		}

	public:
		virtual bool DrawArrays(uint32_t gdPrimType, int32_t, int32_t);
		virtual bool DrawElements(uint32_t gdPrimType, uint32_t count, uint32_t gdType, void const* indices);
		virtual bool InterleavedArrays(int32_t gdVertexFormat, int32_t, void const*);

		virtual uint32_t MakeVertexFormat(uint32_t, intptr_t gdElementTypePtr);
		virtual uint32_t MakeVertexFormat(uint32_t gdVertexFormat);
		virtual uint32_t VertexFormatStride(uint32_t gdVertexFormat);
		virtual uint32_t VertexFormatElementOffset(uint32_t gdVertexFormat, uint32_t gdElementType, uint32_t);
		virtual uint32_t VertexFormatNumElements(uint32_t gdVertexFormat, uint32_t gdElementType);

		virtual uint32_t Clear(void);
		virtual uint32_t ClearColor(uint32_t, float, float, float);
		virtual uint32_t ClearDepth(double);
		virtual uint32_t ClearStencil(int32_t);

		virtual uint32_t ColorMask(bool);
		virtual uint32_t DepthFunc(uint32_t gdTestFunc);
		virtual uint32_t DepthMask(bool);

		virtual void StencilFunc(uint32_t gdTestFunc, int32_t, uint32_t);
		virtual void StencilMask(uint32_t);
		virtual void StencilOp(uint32_t gdStencilOp, uint32_t gdStencilOp2, uint32_t gdStencilOp3);

		virtual uint32_t BlendFunc(uint32_t gdBlendFunc, uint32_t gdBlend);
		virtual uint32_t AlphaFunc(uint32_t gdTestFunc, float);
		virtual uint32_t ShadeModel(uint32_t gdShade);

		virtual uint32_t BindTexture(uint32_t gdTextureTarget, uint32_t);
		virtual uint32_t TexImage2D(uint32_t gdTextureTarget, int32_t, uint32_t gdInternalTexFormat, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*);
		virtual uint32_t PixelStore(uint32_t gdParameter, int32_t);

		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, uint32_t gdTextureEnvModeParam);
		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, float const*);
		virtual uint32_t TexParameter(uint32_t gdTextureTarget, uint32_t gdTextureParamType, uint32_t gdTextureParam);

		virtual uint32_t Fog(uint32_t gdFogParamType, uint32_t gdFogParam);
		virtual uint32_t Fog(uint32_t gdFogParamType, float const*);

		virtual uint32_t ColorMultiplier(float r, float g, float b);
		virtual uint32_t AlphaMultiplier(float a);
		virtual uint32_t EnableVertexColors(bool, bool);

		virtual void GenTextures(int32_t, uint32_t*);
		virtual uint32_t DeleteTextures(int32_t, uint32_t const*);
		virtual bool IsTexture(uint32_t);
		virtual uint32_t PrioritizeTextures(int32_t, uint32_t const*, float const*);
		virtual bool AreTexturesResident(int32_t, uint32_t const*, bool*);

		virtual uint32_t MatrixMode(uint32_t gdMatrixTarget);
		virtual uint32_t LoadMatrix(float const*);
		virtual uint32_t LoadIdentity(void);

		virtual uint32_t Flush(void);
		virtual void Enable(uint32_t gdDriverState);
		virtual void Disable(uint32_t gdDriverState);
		virtual bool IsEnabled(uint32_t gdDriverState);
		virtual bool GetBoolean(uint32_t gdParameter, bool*);
		virtual bool GetInteger(uint32_t gdParameter, int32_t*);
		virtual bool GetFloat(uint32_t gdParameter, float*);
		virtual uint32_t GetError(void);

		virtual uint32_t TexStage(uint32_t);
		virtual uint32_t TexStageCoord(uint32_t gdTexCoordSource);
		virtual uint32_t TexStageMatrix(float const*, uint32_t, uint32_t, uint32_t gdTexMatFlags);
		virtual void TexStageCombine(uint32_t gdTexStageCombineParamType, uint32_t gdTexStageCombineModeParam);
		virtual uint32_t TexStageCombine(float gdTexStageCombineSourceParamType, float gdTexStageCombineSourceParam);
		virtual void TexStageCombine(void* gdTexStageCombineOperandParamType, uint32_t gdBlend);
		virtual void TexStageCombine(uint32_t gdTexStageCombineScaleParamType, void* gdTexStageCombineScaleParam);

		virtual uint32_t SetTexture(uint32_t, uint32_t);
		virtual intptr_t GetTexture(uint32_t);
		virtual intptr_t CreateTexture(uint32_t gdInternalTexFormat, uint32_t, uint32_t, uint32_t, uint32_t gdTexHintFlags);
		virtual intptr_t LoadTextureLevel(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t gdTexFormat, uint32_t gdType, uint32_t, void const*);
		virtual uint32_t SetCombiner(uint32_t const& gdCombiner, uint32_t);

		virtual uint32_t CountVideoModes(void);
		virtual bool GetVideoModeInfo(uint32_t dwIndex, sGDMode& gdMode);
		virtual bool GetVideoModeInfo(sGDMode& gdMode);
		virtual bool SetVideoMode(int32_t, void*, bool, bool);
		
		virtual uint32_t PolygonOffset(uint32_t);

		virtual uint32_t BitBlt(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*);
		virtual uint32_t StretchBlt(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*);
		virtual uint32_t BitBltAlpha(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t);
		virtual uint32_t StretchBltAlpha(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t);
		virtual uint32_t BitBltAlphaModulate(int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t);
		virtual uint32_t StretchBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t);

		virtual uint32_t SetViewport(void);
		virtual uint32_t SetViewport(uint32_t, uint32_t, uint32_t, uint32_t);
		virtual uint32_t GetViewport(void);
		virtual uint32_t GetDriverInfo(void);
		virtual uint32_t GetGZCLSID(void);

		virtual bool Init(void);
		virtual bool Shutdown(void);
		virtual bool IsDeviceReady(void);
		virtual bool Punt(uint32_t, void*);
};