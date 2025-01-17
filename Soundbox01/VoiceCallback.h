#pragma once
#include "WindowMessages.h"
#include <xaudio2.h>

class VoiceCallback : public IXAudio2VoiceCallback
{
	HWND m_hwnd;
public:
	VoiceCallback(HWND Parent) : m_hwnd(Parent)
	{

	}

	~VoiceCallback()
	{

	}

	void OnStreamEnd() noexcept override
	{
		OutputDebugStringW(L"Stream ended\n");
		SendMessage(m_hwnd, WM_CM_STREAM_ENDED, 0, 0);
	}
	void OnVoiceProcessingPassStart(UINT32 BytesRequired) noexcept override
	{
		// INFO: never ending stream of output OutputDebugStringW(L"OnVoiceProcessingPassStart\n");
	}
	void OnVoiceProcessingPassEnd() noexcept override
	{
		// INFO: never ending stream of output  OutputDebugStringW(L"OnVoiceProcessingPassEnd\n");
	}
	void OnBufferEnd(void* pContext) noexcept override
	{
		OutputDebugStringW(L"OnBufferEnd\n");
	}
	void OnBufferStart(void* pContext)noexcept override
	{
		OutputDebugStringW(L"OnBufferStart\n");
	}
	void OnLoopEnd(void* pContext)noexcept override {}
	void OnVoiceError(void* pContext, HRESULT Error) noexcept override {}
};

