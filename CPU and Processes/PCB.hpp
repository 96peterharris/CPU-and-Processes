#pragma once
#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <iterator>
#include "State.hpp"
#include "TypeOfProcesshpp.hpp"
#include <functional>

class PCB
{
protected:
	std::string pid;

	int processAddress;
	int priority;
	int commandCounter;
	int registryA;
	int registryB;
	int registryC;
	int registryD;

	

	State state;
	TypeOfProcess typeOfProcess;
	
	static std::map<std::string, PCB*> processesMap;
	
	std::deque<PCB*> readyQueue; //Real Time processes
	void addToReadyQueue(PCB * pcb);

	std::vector<std::string> openedFilesList;

	int getProcessAddress();
	void setProcessAddress(int _processAddress);
	void sortMapByPriority();
	
	//memoryPointer 

public:
	PCB() {};
	PCB(std::string _pid, int _processAddress, int _priority, State _state);
	PCB(std::string _pid, int _processAddress, int _priority, State _state);
	~PCB() {};

	std::deque<PCB*> getReadyProccesses();
	bool createProcess(std::string _pid, int _processAddress, int _priority, State state);
	bool removeProcess(std::string pid);
	bool resumeProcess(std::string pid);
	bool haltProcess(std::string pid);

	std::string getPid();
	void setPid(std::string _pid);
	int getRegistryA();
	void setRegistryA(int _registryA);
	int getRegistryB();
	void setRegistryB(int _registryB);
	int getRegistryC();
	void setRegistryC(int _registryC);
	int getRegistryD();
	void setRegistryD(int _registryD);
	int getCommandCounter();
	void setCommandCounter(int _commandCounter);
	int getPriority();
	void setPriority(int _priority);
	State getState();
	void setState(State _state);
	

};

