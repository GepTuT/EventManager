#pragma once
#include <iostream>
#include "Vehicle.h"
#include "Executor.h"
#include "Service.h"

class TireFitting {
public:

	inline void RegisterService(Service* lastService) { 
		m_lastService = lastService; 
	} 
	inline Executor* GetExecutor() {
		return m_ExecutorIn;
	}
	
protected: 
	Executor* m_ExecutorIn; 
	Service* m_lastService;



};