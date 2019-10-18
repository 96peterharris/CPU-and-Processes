#include "PCB.hpp"


PCB::PCB(std::string _pid, int _processAddress, int _priority, State _state): pid(_pid), processAddress(_processAddress), priority(_priority), state(_state) {}
void PCB::addToReadyQueue(PCB * pcb) {
	this->readyQueue.push(pcb);
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

}
bool PCB::createProcess(std::string _pid, int _processAddress, int _priority, State _state) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(_pid);

	if (_pid == it->first) {
		return false;
	}
	else {
		PCB* pcb = new PCB(_pid, _processAddress, _priority, _state);
		this->processesMap.insert(std::pair<std::string, PCB*>(_pid, pcb));
		return true;
	}
}
bool PCB::removeProcess(std::string pid) {
	std::map<std::string, PCB*>::iterator it = this->processesMap.find(pid);

	if (pid == it->first) {
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
std::queue<PCB*> PCB::getReadyProccesses() {
	for (auto const& e : this->processesMap) {
		if (e.second->state == READY) {
			addToReadyQueue(e.second);
		}
	}
}