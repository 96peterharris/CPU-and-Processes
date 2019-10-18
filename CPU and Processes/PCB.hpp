#pragma once
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include "State.hpp"

class PCB
{
protected:
	std::string pid;

	int processAddress;
	int priority;
	int registryA;
	int registryB;
	int registryC;
	int registryD;

	State state;
	
	static std::map<std::string, PCB*> processesMap;
	
	std::queue<PCB*> readyQueue;
	void addToReadyQueue(PCB * pcb);

	std::vector<std::string> openedFilesList;

	int getProcessAddress();
	void setProcessAddress(int _processAddress);
	int getPriority();
	void setPriority(int _priority);
	int getRegistryA();
	void setRegistryA(int _registryA);
	int getRegistryB();
	void setRegistryB(int _registryB);
	int getRegistryC();
	void setRegistryC(int _registryC);
	int getRegistryD();
	void setRegistryD(int _registryD);

	//memoryPointer 

public:
	PCB() {};
	PCB(std::string _pid, int _processAddress, int _priority, State _state);
	~PCB() {};

	std::queue<PCB*> getReadyProccesses();
	bool createProcess(std::string _pid, int _processAddress, int _priority, State state);
	bool removeProcess(std::string pid);
	bool resumeProcess(std::string pid);
	bool haltProcess(std::string pid);
};

