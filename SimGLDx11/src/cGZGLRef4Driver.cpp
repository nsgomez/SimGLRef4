#pragma once
#include "../include/cGZGLRef4Driver.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define NOTIMPL() { MessageBoxA(NULL, __FUNCSIG__, NULL, NULL); }

cGZGLRef4Driver::cGZGLRef4Driver() {
	this->window = nullptr;
	this->lastError = DriverError::OK;
	this->areVideoModesLoaded = false;
	this->currentVideoMode = -1;
	this->videoModeCount = 0;
}

cGZGLRef4Driver::~cGZGLRef4Driver() {
	NOTIMPL();
}

bool cGZGLRef4Driver::DrawArrays(uint32_t gdPrimType, int32_t, int32_t) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::DrawElements(uint32_t gdPrimType, uint32_t count, uint32_t gdType, void const* indices) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::InterleavedArrays(int32_t gdVertexFormat, int32_t, void const*) {
	NOTIMPL();
	return false;
}

uint32_t cGZGLRef4Driver::MakeVertexFormat(uint32_t, intptr_t gdElementTypePtr) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::MakeVertexFormat(uint32_t gdVertexFormat) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::VertexFormatStride(uint32_t gdVertexFormat) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::VertexFormatElementOffset(uint32_t gdVertexFormat, uint32_t gdElementType, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::VertexFormatNumElements(uint32_t gdVertexFormat, uint32_t gdElementType) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::Clear(void) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ClearColor(uint32_t, float, float, float) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ClearDepth(double) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ClearStencil(int32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ColorMask(bool) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::DepthFunc(uint32_t gdTestFunc) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::DepthMask(bool) {
	NOTIMPL();
	return UINT_MAX;
}

void cGZGLRef4Driver::StencilFunc(uint32_t gdTestFunc, int32_t, uint32_t) {
	NOTIMPL();
}

void cGZGLRef4Driver::StencilMask(uint32_t) {
	NOTIMPL();
}

void cGZGLRef4Driver::StencilOp(uint32_t gdStencilOp, uint32_t gdStencilOp2, uint32_t gdStencilOp3) {
	NOTIMPL();
}

uint32_t cGZGLRef4Driver::BlendFunc(uint32_t gdBlendFunc, uint32_t gdBlend) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::AlphaFunc(uint32_t gdTestFunc, float) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ShadeModel(uint32_t gdShade) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::BindTexture(uint32_t gdTextureTarget, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexImage2D(uint32_t gdTextureTarget, int32_t, uint32_t gdInternalTexFormat, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::PixelStore(uint32_t gdParameter, int32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, uint32_t gdTextureEnvModeParam) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexEnv(uint32_t gdTextureEnvTarget, uint32_t gdTextureEnvParamType, float const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexParameter(uint32_t gdTextureTarget, uint32_t gdTextureParamType, uint32_t gdTextureParam) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::Fog(uint32_t gdFogParamType, uint32_t gdFogParam) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::Fog(uint32_t gdFogParamType, float const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::ColorMultiplier(float r, float g, float b) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::AlphaMultiplier(float a) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::EnableVertexColors(bool, bool) {
	NOTIMPL();
	return UINT_MAX;
}

void cGZGLRef4Driver::GenTextures(int32_t, uint32_t*) {
	NOTIMPL();
}

uint32_t cGZGLRef4Driver::DeleteTextures(int32_t, uint32_t const*) {
	NOTIMPL();
	return UINT_MAX;
}

bool cGZGLRef4Driver::IsTexture(uint32_t) {
	NOTIMPL();
	return false;
}

uint32_t cGZGLRef4Driver::PrioritizeTextures(int32_t, uint32_t const*, float const*) {
	NOTIMPL();
	return UINT_MAX;
}

bool cGZGLRef4Driver::AreTexturesResident(int32_t, uint32_t const*, bool*) {
	NOTIMPL();
	return false;
}

uint32_t cGZGLRef4Driver::MatrixMode(uint32_t gdMatrixTarget) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::LoadMatrix(float const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::LoadIdentity(void) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::Flush(void) {
	NOTIMPL();
	return UINT_MAX;
}

void cGZGLRef4Driver::Enable(uint32_t gdDriverState) {
	NOTIMPL();
}

void cGZGLRef4Driver::Disable(uint32_t gdDriverState) {
	NOTIMPL();
}

bool cGZGLRef4Driver::IsEnabled(uint32_t gdDriverState) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::GetBoolean(uint32_t gdParameter, bool*) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::GetInteger(uint32_t gdParameter, int32_t*) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::GetFloat(uint32_t gdParameter, float*) {
	NOTIMPL();
	return false;
}

uint32_t cGZGLRef4Driver::GetError(void) {
	return static_cast<uint32_t>(this->lastError);
}

uint32_t cGZGLRef4Driver::TexStage(uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexStageCoord(uint32_t gdTexCoordSource) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::TexStageMatrix(float const*, uint32_t, uint32_t, uint32_t gdTexMatFlags) {
	NOTIMPL();
	return UINT_MAX;
}

void cGZGLRef4Driver::TexStageCombine(uint32_t gdTexStageCombineParamType, uint32_t gdTexStageCombineModeParam) {
	NOTIMPL();
}

uint32_t cGZGLRef4Driver::TexStageCombine(float gdTexStageCombineSourceParamType, float gdTexStageCombineSourceParam) {
	NOTIMPL();
	return UINT_MAX;
}

void cGZGLRef4Driver::TexStageCombine(void* gdTexStageCombineOperandParamType, uint32_t gdBlend) {
	NOTIMPL();
}

void cGZGLRef4Driver::TexStageCombine(uint32_t gdTexStageCombineScaleParamType, void* gdTexStageCombineScaleParam) {
	NOTIMPL();
}

uint32_t cGZGLRef4Driver::SetTexture(uint32_t, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

intptr_t cGZGLRef4Driver::GetTexture(uint32_t) {
	NOTIMPL();
	return 0;
}

intptr_t cGZGLRef4Driver::CreateTexture(uint32_t gdInternalTexFormat, uint32_t, uint32_t, uint32_t, uint32_t gdTexHintFlags) {
	NOTIMPL();
	return 0;
}

intptr_t cGZGLRef4Driver::LoadTextureLevel(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t gdTexFormat, uint32_t gdType, uint32_t, void const*) {
	NOTIMPL();
	return 0;
}

uint32_t cGZGLRef4Driver::SetCombiner(uint32_t const& gdCombiner, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::CountVideoModes(void) {
	if (!this->areVideoModesLoaded) {
		this->InitializeVideoModeVector();
	}

	return this->videoModeCount;
}

bool cGZGLRef4Driver::GetVideoModeInfo(uint32_t dwIndex, sGDMode& gdMode) {
	if (dwIndex == -1 || dwIndex >= this->videoModes.size()) {
		MessageBoxA(NULL, "NO", NULL, NULL);
		this->SetLastError(DriverError::OUT_OF_RANGE);
		return false;
	}

	gdMode = this->videoModes[dwIndex];
	return true;
}

bool cGZGLRef4Driver::GetVideoModeInfo(sGDMode& gdMode) {
	return this->GetVideoModeInfo(this->currentVideoMode, gdMode);
}

bool cGZGLRef4Driver::SetVideoMode(int32_t, void*, bool, bool) {
	NOTIMPL();
	return false;
}

uint32_t cGZGLRef4Driver::PolygonOffset(uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::BitBlt(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::StretchBlt(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::BitBltAlpha(int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::StretchBltAlpha(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::BitBltAlphaModulate(int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::StretchBltAlphaModulate(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t, uint32_t gdTexFormat, uint32_t gdType, void const*, bool, void const*, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::SetViewport(void) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::SetViewport(uint32_t, uint32_t, uint32_t, uint32_t) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::GetViewport(void) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::GetDriverInfo(void) {
	NOTIMPL();
	return UINT_MAX;
}

uint32_t cGZGLRef4Driver::GetGZCLSID(void) {
	return kGLRef4DriverGZCLSID;
}

bool cGZGLRef4Driver::Init(void) {
	if (!glfwInit()) {
		this->SetLastError(DriverError::CREATE_CONTEXT_FAIL);
		return false;
	}

	return true;
}

bool cGZGLRef4Driver::Shutdown(void) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::IsDeviceReady(void) {
	NOTIMPL();
	return false;
}

bool cGZGLRef4Driver::Punt(uint32_t, void*) {
	NOTIMPL();
	return false;
}

void unknownStaticFunc1(uint32_t x0) {
	printf("");
}

int32_t cGZGLRef4Driver::InitializeVideoModeVector(void) {
	int count;
	const GLFWvidmode* modes = glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);

	sGDMode tempMode;
	memset(&tempMode, 0, sizeof(sGDMode));

	for (int i = 0; i < count; i++) {
		tempMode.videoModeId = this->videoModeCount++;
		tempMode.width = modes[i].width;
		tempMode.height = modes[i].height;
		tempMode.depth = modes[i].redBits + modes[i].greenBits + modes[i].blueBits;

		tempMode.__unknown1 = 1;
		tempMode.__unknown2 = 1;
		tempMode.__unknown3 = 0xCAFEF00D;
		tempMode.__unknown3 = (uint32_t)(&unknownStaticFunc1);

		this->videoModes.push_back(tempMode);

		tempMode.videoModeId = this->videoModeCount++;
		tempMode.__unknown1 = 0;

		this->videoModes.push_back(tempMode);
	}

	this->areVideoModesLoaded = true;
	return count;
}

void cGZGLRef4Driver::SetLastError(DriverError err) {
	this->lastError = err;
}