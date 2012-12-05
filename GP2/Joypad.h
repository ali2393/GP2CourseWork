#pragma once

#include <Windows.h>
#include <XInput.h>

class CJoypad
{
public:
	CJoypad();
	CJoypad(int index);
	~CJoypad();

	void update();

	float getLeftThumbStickX()
	{
		return m_fLeftThumbstickXNormalized;
	};

	float getLeftThumbStickY()
	{
		return m_fLeftThumbstickYNormalized;
	};

	float getRightThumbStickX()
	{
		return m_fRightThumbstickXNormalized;
	};

	float getRightThumbStickY()
	{
		return m_fRightThumbstickYNormalized;
	};

	static CJoypad& getInstance(int index)
	{
		static CJoypad instance;
		return instance;
	};

	bool isConnected()
	{
		return m_bIsConnected;
	}
private:
	bool m_bIsConnected;
	XINPUT_STATE m_JoypadState;
	int m_iIndex;



	CJoypad(CJoypad const&){};
	void operator=(CJoypad const&){};

	CJoypad *m_pJoypads;

	float m_fLeftThumbstickX;
	float m_fLeftThumbstickY;
	float m_fLeftThumbstickXNormalized;
	float m_fLeftThumbstickYNormalized;
	float m_fLeftMagnitude;
	float m_fLeftNormalizedMagnitude;

	float m_fRightThumbstickX;
	float m_fRightThumbstickY;
	float m_fRightThumbstickXNormalized;
	float m_fRightThumbstickYNormalized;
	float m_fRightMagnitude;
	float m_fRightNormalizedMagnitude;

	float m_fRightTrigger;
	float m_fLeftTrigger;
};