#ifndef _GAME_CSTATETEMPLATE_HPP
#define _GAME_CSTATETEMPLATE_HPP
template<class T>
class CStateTemplate : public CState {
protected:
	typedef void (T::*PFNSTATE)(void);
	T*m_pInstance;
	PFNSTATE m_pfnBeginState;
	PFNSTATE m_pfnState;
	PFNSTATE m_pfnEndState;
public:
	CStateTemplate() : m_pInstance(0),m_pfnBeginState(0),m_pfnState(0),m_pfnEndState(0){}
	void Set(T*pInstance,PFNSTATE pfnBeginState,PFNSTATE pfnState,PFNSTATE pfnEndState)
	{
		m_pInstance = pInstance;
		m_pfnBeginState=pfnBeginState;
		m_pfnState=pfnState;
		m_pfnEndState=pfnEndState;
	}

	virtual void ExecuteBeginState()
	{
		(m_pInstance->*m_pfnBeginState)();
	}
	virtual void ExecuteState()
	{
		(m_pInstance->*m_pfnState)();
	}
	virtual void ExecuteEndState()
	{
		(m_pInstance->*m_pfnEndState)();

	}
};
#endif // _GAME_CSTATETEMPLATE_HPP
