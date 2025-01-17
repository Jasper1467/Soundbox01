#pragma once
#include <xaudio2.h>

class Voice
{
	IXAudio2SourceVoice* m_voice = nullptr;
	FLOAT m_volume;
public:
	Voice();
	~Voice();

	Voice(const Voice&) = delete; // copy constructor
	Voice& operator=(const Voice&) = delete; // copy assignment
	void SetVolume(FLOAT newValue);
	FLOAT GetVolume() const;
	static void LoadWave();
	void FlushSourceBuffers();
	void SubmitSourceBuffer(void* data);
};

