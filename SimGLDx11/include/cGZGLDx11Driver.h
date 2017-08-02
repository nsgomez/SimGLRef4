#pragma once
#include <cRZUnknown.h>
#include "cIGZGDriver.h"

const uint32_t kIGZGDriverGZIID = 0xa4554849;

class cGZGLDx11Driver : public cIGZGDriver, public cRZUnknown
{
	public:
		//static const uint32_t kGLDx11DriverGZCLSID = 0x5896ab0d;

		// Rather than being nice about it, we're going to hijack the GZCLSID
		// of the original DX7 driver and override it by presenting a higher
		// version number to the GZCOM, because obviously we're better.
		static const uint32_t kGLDx11DriverGZCLSID = 0xbadb6906;

		static bool FactoryFunctionPtr2(uint32_t riid, void** ppvObj) {
			cGZGLDx11Driver* pDriver = new cGZGLDx11Driver();
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
		virtual bool DrawArrays(uint32_t gdPrimType, int32_t, int32_t) { throw; }
		virtual bool DrawElements(uint32_t gdPrimType, int32_t, uint32_t gdType, void const*) { throw; }
		virtual bool InterleavedArrays(int32_t gdVertexFormat, int32_t, void const*) { throw; }

		virtual uint32_t MakeVertexFormat(uint32_t, intptr_t gdElementTypePtr) { throw; }
		virtual uint32_t MakeVertexFormat(uint32_t gdVertexFormat) { throw; }
		virtual uint32_t VertexFormatStride(uint32_t gdVertexFormat) { throw; }
		virtual uint32_t VertexFormatElementOffset(uint32_t gdVertexFormat, uint32_t gdElementType, uint32_t) { throw; }
		virtual uint32_t VertexFormatNumElements(uint32_t gdVertexFormat, uint32_t gdElementType) { throw; }

		virtual uint32_t Clear(void) { throw; }
		virtual uint32_t ClearColor(uint32_t, float, float, float) { throw; }
		virtual uint32_t ClearDepth(double) { throw; }
		virtual uint32_t ClearStencil(int32_t) { throw; }

		virtual uint32_t ColorMask(bool) { throw; }
		virtual uint32_t DepthFunc(uint32_t gdTestFunc) { throw; }
		virtual uint32_t DepthMask(bool) { throw; }

		virtual void StencilFunc(uint32_t gdTestFunc, int32_t, uint32_t) { throw; }
		virtual void StencilMask(uint32_t) { throw; }
		virtual void StencilOp(uint32_t gdStencilOp, uint32_t gdStencilOp2, uint32_t gdStencilOp3) { throw; }

		virtual uint32_t BlendFunc(uint32_t gdBlendFunc, uint32_t gdBlend) { throw; }
		virtual uint32_t AlphaFunc(uint32_t gdTestFunc, float) { throw; }
		virtual uint32_t ShadeModel(uint32_t gdShade) { throw; }

		virtual uint32_t BindTexture(uint32_t gdTextureTarget, uint32_t) { throw; }
		virtual uint32_t TexImage2D(uint32_t gdTextureTarget, int32_t, uint32_t gdInternalTexFormat, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*) { throw; }
		virtual uint32_t PixelStore(uint32_t gdParameter, int32_t) { throw; }

		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, uint32_t gdTextureEnvModeParam) { throw; }
		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, float const*) { throw; }
		virtual uint32_t TexParameter(uint32_t gdTextureTarget, uint32_t gdTextureParamType, uint32_t gdTextureParam) { throw; }

		virtual uint32_t Fog(uint32_t gdFogParamType, uint32_t gdFogParam) { throw; }
		virtual uint32_t Fog(uint32_t gdFogParamType, float const*) { throw; }

		virtual uint32_t ColorMultiplier(float r, float g, float b) { throw; }
		virtual uint32_t AlphaMultiplier(float a) { throw; }
		virtual uint32_t EnableVertexColors(bool, bool) { throw; }

		virtual uint32_t GenTextures(int32_t, uint32_t*) { throw; }
		virtual uint32_t DeleteTextures(int32_t, uint32_t const*) { throw; }
		virtual bool IsTexture(uint32_t) { throw; }
		virtual uint32_t PrioritizeTextures(int32_t, uint32_t const*, float const*) { throw; }
		virtual bool AreTexturesResident(int32_t, uint32_t const*, bool*) { throw; }

		virtual uint32_t MatrixMode(uint32_t gdMatrixTarget) { throw; }
		virtual uint32_t LoadMatrix(float const*) { throw; }
		virtual uint32_t LoadIdentity(void) { throw; }

		virtual uint32_t Flush(void) { throw; }
		virtual uint32_t Enable(uint32_t gdDriverState) { throw; }
		virtual uint32_t Disable(uint32_t gdDriverState) { throw; }
		virtual bool IsEnabled(uint32_t gdDriverState) { throw; }
		virtual bool GetBoolean(uint32_t gdParameter, bool*) { throw; }
		virtual bool GetInteger(uint32_t gdParameter, int32_t*) { throw; }
		virtual bool GetFloat(uint32_t gdParameter, float*) { throw; }
		virtual uint32_t GetError(void) { throw; }

		virtual uint32_t TexStage(uint32_t) { throw; }
		virtual uint32_t TexStageCoord(uint32_t gdTexCoordSource) { throw; }
		virtual uint32_t TexStageMatrix(float const*, uint32_t, uint32_t, uint32_t gdTexMatFlags) { throw; }
		virtual uint32_t TexStageCombine(uint32_t gdTexStageCombineParamType, uint32_t gdTexStageCombineModeParam) { throw; }
		virtual uint32_t TexStageCombine(float gdTexStageCombineSourceParamType, float gdTexStageCombineSourceParam) { throw; }
		virtual uint32_t TexStageCombine(void* gdTexStageCombineOperandParamType, uint32_t gdBlend) { throw; }
		virtual uint32_t TexStageCombine(uint32_t gdTexStageCombineScaleParamType, void* gdTexStageCombineScaleParam) { throw; }

		virtual uint32_t SetTexture(uint32_t, uint32_t) { throw; }
		virtual intptr_t GetTexture(uint32_t) { throw; }
		virtual intptr_t CreateTexture(uint32_t gdInternalTexFormat, uint32_t, uint32_t, uint32_t, uint32_t gdTexHintFlags) { throw; }
		virtual intptr_t LoadTextureLevel(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t gdTexFormat, uint32_t gdType, uint32_t, void const*) { throw; }
		virtual uint32_t SetCombiner(uint32_t const& gdCombiner, uint32_t) { throw; }

		virtual uint32_t CountVideoModes(void) { throw; }
		virtual bool GetVideoModeInfo(uint32_t, uint32_t& gdMode) { throw; }
		virtual bool GetVideoModeInfo(uint32_t& gdMode) { throw; }
		virtual bool SetVideoMode(int32_t, void*, bool, bool) { throw; }
		
		virtual uint32_t PolygonOffset(uint32_t) { throw; }

		virtual uint32_t BitBlt(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) { throw; }
		virtual uint32_t StretchBlt(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) { throw; }
		virtual uint32_t BitBltAlpha(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) { throw; }
		virtual uint32_t StretchBltAlpha(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) { throw; }
		virtual uint32_t BitBltAlphaModulate(int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) { throw; }
		virtual uint32_t StretchBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) { throw; }

		virtual uint32_t SetViewport(void) { throw; }
		virtual uint32_t SetViewport(uint32_t, uint32_t, uint32_t, uint32_t) { throw; }
		virtual uint32_t GetViewport(void) { throw; }
		virtual uint32_t GetDriverInfo(void) { throw; }
		virtual uint32_t GetGZCLSID(void) { throw; }

		virtual bool Init(void) { MessageBoxA(NULL, "Init", NULL, NULL); throw; }
		virtual bool Shutdown(void) { throw; }
		virtual bool IsDeviceReady(void) { throw; }
		virtual bool Punt(uint32_t, void*) { throw; }
};