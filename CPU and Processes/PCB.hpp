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
	int actualCommandCounter; //ACC
	int oldCommandCounter; //OCC
	int registryA;
	int registryB;
	int registryC;
	int registryD;

	State state;
	TypeOfProcess typeOfProcess;
	
	static std::map<std::string, PCB*> processesMap;
	
	std::deque<PCB*> readyQueueRT; //Real Time processes
	std::deque<PCB*> readyQueueST; //Standard processes
	void addToReadyQueueRT(PCB * pcb);
	void addToReadyQueueST(PCB * pcb);

	std::vector<std::string> openedFilesList;

	int getProcessAddress();
	void setProcessAddress(int _processAddress);
	void sortMapByPriority();
	
	//memoryPointer 

public:
	PCB() {};
	PCB(std::string _pid, int _processAddress, int _priority, State _state, TypeOfProcess _typeOfProcess);
	PCB(std::string _pid, int _processAddress, int _priority, State _state);
	~PCB() {};

	std::deque<PCB*> getReadyProccessesRT();
	std::deque<PCB*> getReadyProccessesST();
	bool createProcess(std::string _pid, int _processAddress, int _priority, State state, TypeOfProcess _typeOfProcess);
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
	int getActualCommandCounter();
	void setActualCommandCounter(int _actualCommandCounter);
	int getOldCommandCounter();
	void setOldCommandCounter(int _oldCommandCounter);
	int getPriority();
	void setPriority(int _priority);
	State getState();
	void setState(State _state);
	TypeOfProcess getTypeOfProcess();
	void setTypeOfprocess(TypeOfProcess _typeOfProcess);
	

};

