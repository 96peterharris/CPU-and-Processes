#include "PCB.hpp"


PCB::PCB(std::string _pid, int _processAddress, int _priority, State _state, TypeOfProcess _typeOfProcess) : pid(_pid), processAddress(_processAddress), priority(_priority), state(_state), typeOfProcess(_typeOfProcess) {}
PCB::PCB(std::string _pid, int _processAddress, int _priority, State _state) : pid(_pid), processAddress(_processAddress), priority(_priority), state(_state) {};
void PCB::addToReadyQueueRT(PCB * pcb) {
	this->readyQueueRT.push_back(pcb);
}
void PCB::addToReadyQueueST(PCB * pcb) {
	this->readyQueueST.push_back(pcb);
}
std::string PCB::getPid() {
	return this->pid;
}
void PCB::setPid(std::string _pid) {
	this->pid = _pid;
}
int PCB::getCommandCounter() {
	return this->commandCounter;
}
void PCB::setCommandCounter(int _commandCounter) {
	this->commandCounter = _commandCounter;
}
int PCB::getActualCommandCounter() {
	return this->actualCommandCounter;
}
void PCB::setActualCommandCounter(int _actualCommandCounter) {
	this->actualCommandCounter = _actualCommandCounter;
}
int PCB::getOldCommandCounter() {
	return this->oldCommandCounter;
}
void PCB::setOldCommandCounter(int _oldCommandCounter) {
	this->oldCommandCounter = _oldCommandCounter;
}
int PCB::getProcessAddress() {
	return this->processAddress;
}
void PCB::setProcessAddress(int _processAddress) {
	this->processAddress = _processAddress;
}
int PCB::getPriority() {
	return this->priority;
}
void PCB::setPriority(int _priority) {
	this->priority = _priority;
}
int PCB::getRegistryA() {
	return this->registryA;
}
void PCB::setRegistryA(int _registryA) {
	this->registryA = _registryA;
}
int PCB::getRegistryB() {
	return this->registryB;
}
void PCB::setRegistryB(int _registryB) {
	this->registryB = _registryB;
}
int PCB::getRegistryC() {
	return this->registryC;
}
void PCB::setRegistryC(int _registryC) {
	this->registryC = _registryC;
}
int PCB::getRegistryD() {
	return this->getRegistryD;
}
void PCB::setRegistryD(int _registryD) {
	this->getRegistryD = _registryD;
}
State PCB::getState(){
	return this->state;
} 
void PCB::setState(State _state) {
	this->state = _state;
}
TypeOfProcess PCB::getTypeOfProcess() {
	return this->typeOfProcess;
}
void PCB::setTypeOfprocess(TypeOfProcess _typeOfProcess) {
	this->typeOfProcess = _typeOfProcess;
}
bool PCB::createProcess(std::string _pid, int _processAddress, int _priority, State _state, TypeOfProcess _typeOfProcess) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(_pid);

	if (_pid == it->first) {
		return false;
	}
	else {
		PCB* pcb = new PCB(_pid, _processAddress, _priority, _state, _typeOfProcess);
		this->processesMap.insert(std::pair<std::string, PCB*>(_pid, pcb));
		return true;
	}
}
bool PCB::removeProcess(std::string pid) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(pid);

	if (pid == it->first) {
		//Tu by trzeba dodac ustawienie stanu na terminated chocia¿ ja te to w CP_Scheduling ustawiam tak¿e do rozwa¿enia
		this->processesMap.erase(it);
		return true;
	}
	else {
		return false;
	}
}
bool PCB::resumeProcess(std::string pid) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(pid);

	if (pid == it->first) {
		it->second->state == State::READY;
		return true;
	}
	else {
		return false;
	}
}
bool PCB::haltProcess(std::string pid) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(pid);

	if (pid == it->first) {
		it->second->state == State::WAITING;
		return true;
	}
	else {
		return false;
	}
}
std::deque<PCB*> PCB::getReadyProccessesRT() {
	for (auto const& e : this->processesMap) {
		if (e.second->state == State::READY && e.second->typeOfProcess == TypeOfProcess::REAL_TIME) {
			addToReadyQueueRT(e.second);
		}
	}
}
std::deque<PCB*> PCB::getReadyProccessesST() {
	for (auto const& e : this->processesMap) {
		if (e.second->state == State::READY && e.second->typeOfProcess == TypeOfProcess::STANDARD) {
			addToReadyQueueST(e.second);
		}
	}
}
void PCB::sortMapByPriority() {
	std::map<std::string, PCB*>::iterator it1 = this->processesMap.begin();
	std::map<std::string, PCB*>::iterator it2 = it1++;

	for (int i = 0; i < processesMap.size(); i++)
	{
		for (int j = 0; j < (processesMap.size() - i - 1); j++)
		{
			if (it1->second->getPriority() > it2->second->getPriority()) {
				std::swap(processesMap.at(it1.))
			}
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
			}
		}
	}

}