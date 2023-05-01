#include "Voice.h"

#include <cmath>

Voice::Voice(): m_volume(0)
{
}

Voice::~Voice()
{
	if (m_voice)
	{
		m_voice->DestroyVoice();
	}
}

void Voice::SetVolume(FLOAT newVolume)
{
	/*
	 * The expression fabs(m_volume - newVolume) > Epsilon is a more numerically stable way
	 * to check if two floating-point values m_volume and newVolume are equal within
	 * a small tolerance value Epsilon. This is because floating-point arithmetic is
	 * not exact and can introduce small rounding errors.
	 */
	constexpr double Epsilon = 0.0001;
	if (fabs(m_volume - newVolume) > Epsilon)
	{
		m_volume = newVolume;
	}
}

FLOAT Voice::GetVolume() const
{
	return m_volume;
}

void Voice::LoadWave()
{
}
