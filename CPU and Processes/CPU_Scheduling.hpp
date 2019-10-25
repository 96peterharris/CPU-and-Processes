#pragma once
#include "PCB.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>

class CPU_Scheduling : public PCB
{
private:
	
	std::deque<PCB*> recivedQueue; //Queue of processes
	std::vector<PCB*> terminatedProcesses; //Vector of Terminated processes

	void increasePriority(PCB* _pcb);
	void changeState(PCB* _pcb);
	void addToTerminatedVec(PCB* _pcb);
	void getProcesses();
	void countingDown();

public:
	CPU_Scheduling();
	~CPU_Scheduling() {};
	
	void running();

};

