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
	
	std::deque<PCB*> recivedQueueRT; //Queue of Real Time processes
	std::deque<PCB*> recivedQueueST; //Queue of Standart processes
	std::vector<PCB*> terminatedProcesses; //Vector of Terminated processes
	PCB dummy0;

	void increasePriority(PCB* _pcb);
	void changeState(PCB* _pcb);
	void addToTerminatedVec(PCB* _pcb);
	void getProcesses();
	void countingDown();
	void dummy0();

public:
	CPU_Scheduling();
	~CPU_Scheduling() {};
	
	void running();

};

