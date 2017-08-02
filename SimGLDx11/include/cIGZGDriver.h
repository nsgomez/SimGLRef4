#pragma once
#include <cIGZUnknown.h>

class cIGZGDriver : public cIGZUnknown
{
	public:
		virtual bool DrawArrays(uint32_t gdPrimType, int32_t, int32_t) = 0;
		virtual bool DrawElements(uint32_t gdPrimType, int32_t, uint32_t gdType, void const*) = 0;
		virtual bool InterleavedArrays(int32_t gdVertexFormat, int32_t, void const*) = 0;

		virtual uint32_t MakeVertexFormat(uint32_t, intptr_t gdElementTypePtr) = 0;
		virtual uint32_t MakeVertexFormat(uint32_t gdVertexFormat) = 0;
		virtual uint32_t VertexFormatStride(uint32_t gdVertexFormat) = 0;
		virtual uint32_t VertexFormatElementOffset(uint32_t gdVertexFormat, uint32_t gdElementType, uint32_t) = 0;
		virtual uint32_t VertexFormatNumElements(uint32_t gdVertexFormat, uint32_t gdElementType) = 0;

		virtual uint32_t Clear(void) = 0;
		virtual uint32_t ClearColor(uint32_t, float, float, float) = 0;
		virtual uint32_t ClearDepth(double) = 0;
		virtual uint32_t ClearStencil(int32_t) = 0;

		virtual uint32_t ColorMask(bool) = 0;
		virtual uint32_t DepthFunc(uint32_t gdTestFunc) = 0;
		virtual uint32_t DepthMask(bool) = 0;

		virtual void StencilFunc(uint32_t gdTestFunc, int32_t, uint32_t) = 0;
		virtual void StencilMask(uint32_t) = 0;
		virtual void StencilOp(uint32_t gdStencilOp, uint32_t gdStencilOp2, uint32_t gdStencilOp3) = 0;

		virtual uint32_t BlendFunc(uint32_t gdBlendFunc, uint32_t gdBlend) = 0;
		virtual uint32_t AlphaFunc(uint32_t gdTestFunc, float) = 0;
		virtual uint32_t ShadeModel(uint32_t gdShade) = 0;

		virtual uint32_t BindTexture(uint32_t gdTextureTarget, uint32_t) = 0;
		virtual uint32_t TexImage2D(uint32_t gdTextureTarget, int32_t, uint32_t gdInternalTexFormat, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*) = 0;
		virtual uint32_t PixelStore(uint32_t gdParameter, int32_t) = 0;

		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, uint32_t gdTextureEnvModeParam) = 0;
		virtual uint32_t TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, float const*) = 0;
		virtual uint32_t TexParameter(uint32_t gdTextureTarget, uint32_t gdTextureParamType, uint32_t gdTextureParam) = 0;

		virtual uint32_t Fog(uint32_t gdFogParamType, uint32_t gdFogParam) = 0;
		virtual uint32_t Fog(uint32_t gdFogParamType, float const*) = 0;

		virtual uint32_t ColorMultiplier(float r, float g, float b) = 0;
		virtual uint32_t AlphaMultiplier(float a) = 0;
		virtual uint32_t EnableVertexColors(bool, bool) = 0;

		virtual uint32_t GenTextures(int32_t, uint32_t*) = 0;
		virtual uint32_t DeleteTextures(int32_t, uint32_t const*) = 0;
		virtual bool IsTexture(uint32_t) = 0;
		virtual uint32_t PrioritizeTextures(int32_t, uint32_t const*, float const*) = 0;
		virtual bool AreTexturesResident(int32_t, uint32_t const*, bool*) = 0;

		virtual uint32_t MatrixMode(uint32_t gdMatrixTarget) = 0;
		virtual uint32_t LoadMatrix(float const*) = 0;
		virtual uint32_t LoadIdentity(void) = 0;

		virtual uint32_t Flush(void) = 0;
		virtual uint32_t Enable(uint32_t gdDriverState) = 0;
		virtual uint32_t Disable(uint32_t gdDriverState) = 0;
		virtual bool IsEnabled(uint32_t gdDriverState) = 0;
		virtual bool GetBoolean(uint32_t gdParameter, bool*) = 0;
		virtual bool GetInteger(uint32_t gdParameter, int32_t*) = 0;
		virtual bool GetFloat(uint32_t gdParameter, float*) = 0;
		virtual uint32_t GetError(void) = 0;

		virtual uint32_t TexStage(uint32_t) = 0;
		virtual uint32_t TexStageCoord(uint32_t gdTexCoordSource) = 0;
		virtual uint32_t TexStageMatrix(float const*, uint32_t, uint32_t, uint32_t gdTexMatFlags) = 0;
		virtual uint32_t TexStageCombine(uint32_t gdTexStageCombineParamType, uint32_t gdTexStageCombineModeParam) = 0;
		virtual uint32_t TexStageCombine(float gdTexStageCombineSourceParamType, float gdTexStageCombineSourceParam) = 0;
		virtual uint32_t TexStageCombine(void* gdTexStageCombineOperandParamType, uint32_t gdBlend) = 0;
		virtual uint32_t TexStageCombine(uint32_t gdTexStageCombineScaleParamType, void* gdTexStageCombineScaleParam) = 0;

		virtual uint32_t SetTexture(uint32_t, uint32_t) = 0;
		virtual intptr_t GetTexture(uint32_t) = 0;
		virtual intptr_t CreateTexture(uint32_t gdInternalTexFormat, uint32_t, uint32_t, uint32_t, uint32_t gdTexHintFlags) = 0;
		virtual intptr_t LoadTextureLevel(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t gdTexFormat, uint32_t gdType, uint32_t, void const*) = 0;
		virtual uint32_t SetCombiner(uint32_t const& gdCombiner, uint32_t) = 0;

		virtual uint32_t CountVideoModes(void) = 0;
		virtual bool GetVideoModeInfo(uint32_t, uint32_t& gdMode) = 0;
		virtual bool GetVideoModeInfo(uint32_t& gdMode) = 0;
		virtual bool SetVideoMode(int32_t, void*, bool, bool) = 0;
		
		virtual uint32_t PolygonOffset(uint32_t) = 0;

		virtual uint32_t BitBlt(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) = 0;
		virtual uint32_t StretchBlt(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) = 0;
		virtual uint32_t BitBltAlpha(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) = 0;
		virtual uint32_t StretchBltAlpha(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) = 0;
		virtual uint32_t BitBltAlphaModulate(int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) = 0;
		virtual uint32_t StretchBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) = 0;

		virtual uint32_t SetViewport(void) = 0;
		virtual uint32_t SetViewport(uint32_t, uint32_t, uint32_t, uint32_t) = 0;
		virtual uint32_t GetViewport(void) = 0;
		virtual uint32_t GetDriverInfo(void) = 0;
		virtual uint32_t GetGZCLSID(void) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;
		virtual bool IsDeviceReady(void) = 0;
		virtual bool Punt(uint32_t, void*) = 0;
};