#pragma once
#include <cIGZUnknown.h>

class cIGZBufferRegionExtension : public cIGZUnknown
{
	public:
		virtual bool BufferRegionEnabled(void) = 0;
		
		virtual uint32_t NewBufferRegion(int32_t gdBufferRegionType) = 0;
		virtual bool DeleteBufferRegion(int32_t bufferRegion) = 0;
		virtual int ReadBufferRegion(uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t) = 0;
		virtual int DrawBufferRegion(uint32_t, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t) = 0;
		
		virtual bool IsBufferRegion(uint32_t bufferRegion) = 0;
		virtual bool CanDoPartialRegionWrites(void) = 0;
		virtual bool CanDoOffsetReads(void) = 0;

		virtual ~cIGZBufferRegionExtension(void) = 0;

		virtual bool Init(void) = 0;
		virtual bool Shutdown(void) = 0;
		virtual bool FinalRelease(void) = 0;

		virtual bool MatrixMode(int32_t gdMatrixTarget) = 0;
		virtual bool LoadMatrix(float const* matrix) = 0;
		virtual bool LoadIdentity(void) = 0;

		virtual bool DrawArrays(int32_t gdPrimType, int32_t, int32_t) = 0;
		virtual bool DrawElements(int32_t gdPrimType, int32_t, int32_t gdType, void const*) = 0;
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

};