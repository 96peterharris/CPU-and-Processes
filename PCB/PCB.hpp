#pragma once
#include <iostream>
#include <string>
#include <map>
#include "STATE.hpp"

class PCB {
protected:
	std::string pid;
	int addressProcess;
	int priority;
	enum class State
	{
		NEW = 1,
		RUNNIG = 2,
		WAITING = 3,
		READY = 4,
		TERMINATED = 5
	};
	std::map<std::string, PCB*> readyQueue;
	std::map<std::string, PCB*> addToReadyQueue(PCB * pcb){}
	
	
};