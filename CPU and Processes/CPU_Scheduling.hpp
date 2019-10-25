#pragma once
#include "PCB.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "ComparePriority.hpp"
#include <algorithm>

class CPU_Scheduling : public PCB
{
private:
	
	std::priority_queue<PCB*, std::vector<PCB*>> recivedQueue; //Queue of processes
	std::vector<PCB*> terminatedProcesses; //Vector of Terminated processes

	void increasePriority();
	void changeState(PCB* pcb);
	void addToTerminatedVec(PCB* pcb);
	std::priority_queue < PCB*, std::vector<PCB*>> getProcesses();
	void countingDown();

public:
	CPU_Scheduling();
	~CPU_Scheduling() {};
	
	void running();

};

