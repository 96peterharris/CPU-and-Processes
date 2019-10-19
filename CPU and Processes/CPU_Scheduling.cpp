#include "CPU_Scheduling.hpp"



CPU_Scheduling::CPU_Scheduling() {
	this->dummy0 = PCB("Dummy 0", 0000, 0, State::RUNNING);
}
void CPU_Scheduling::increasePriority(PCB* _pcb) {
	if (_pcb->getTypeOfProcess == TypeOfProcess::REAL_TIME && _pcb->getPriority() < 30) {
		int tmp = _pcb->getPriority();
		tmp++;
		_pcb->setPriority(tmp);
	}
	else if (_pcb->getTypeOfProcess() == TypeOfProcess::STANDARD && _pcb->getPriority() < 16) {
		int tmp = _pcb->getPriority();
		tmp++;
		_pcb->setPriority(tmp);
	}
}
void CPU_Scheduling::changeState(PCB* _pcb) {
	_pcb->setState(State::TERMINATED);
}
void CPU_Scheduling::addToTerminatedVec(PCB* _pcb) {
	this->addToTerminatedVec(_pcb);
}
void CPU_Scheduling::getProcesses() {
	this->recivedQueueRT = this->getReadyProccessesRT();
	this->recivedQueueST = this->getReadyProccessesST();
}
void CPU_Scheduling::countingDown() {
	for (int i = 1; i < 6; i++) {
		std::cout << " Commands counter: " << i;
		Sleep(1);
		std::cout << "\x1B[2K\r";
	}
}
void CPU_Scheduling::sortByPriority() {
	
}
void CPU_Scheduling::running() {
	//tu ¿e uruchomiony dummy
	
	while (true) {

		getProcesses();

		if (readyQueueRT.size() == 0 && readyQueueST.size() == 0) {
		
			std::cout << "Now is running: " << this->dummy0.getPid() << " process - State: " << getStateName(dummy0.getState());
			countingDown();
		}
		else {

		}
	}
	
	
}