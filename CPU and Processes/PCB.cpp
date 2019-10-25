#include "PCB.hpp"


PCB::PCB(std::string _pid, int _processAddress, int _priority, State _state) : pid(_pid), processAddress(_processAddress), priority(_priority), state(_state) {

	this->addToReadyQueue(new PCB("DUMMY0", 11, 0, NEW));
}
void PCB::addToReadyQueue(PCB * pcb) {
	this->readyQueue.push_back(pcb);
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
bool PCB::createProcess(std::string _pid, int _processAddress, int _priority, State _state) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(_pid);

	if (_pid == it->first) {
		return false;
	}
	else {
		PCB* pcb = new PCB(_pid, _processAddress, _priority);
		this->processesMap.insert(std::pair<std::string, PCB*>(_pid, pcb));
		return true;
	}
}
bool PCB::removeProcess(std::string pid) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(pid);

	if (pid == it->first) {
		it->second->setState(TERMINATED);
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
std::deque<PCB*> PCB::getReadyProccesses() {
	sortMapByPriority();
	for (auto const& e : this->processesMap) {
		if (e.second->state == State::READY) {
			addToReadyQueue(e.second);
		}
	}
}
void PCB::sortMapByPriority() {
	int i = 1;
	std::pair<std::string, PCB*>next = this->processesMap.at[1];

	for (auto& e : processesMap) {

		if (e.second->getPriority() < next.second->getPriority()) {
			this->processesMap.emplace(next, e);
		}
		next = this->processesMap.at[i++];
	}
}