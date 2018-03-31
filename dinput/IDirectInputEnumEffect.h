#pragma once

struct ENUMEFFECT
{
	LPVOID pvRef;
	LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback;
};

class m_IDirectInputEnumEffect
{
public:
	m_IDirectInputEnumEffect() {}
	~m_IDirectInputEnumEffect() {}

	static BOOL CALLBACK EnumEffectCallback(LPDIRECTINPUTEFFECT, LPVOID);
};
