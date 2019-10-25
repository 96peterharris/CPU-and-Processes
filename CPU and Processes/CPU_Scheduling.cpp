#include "CPU_Scheduling.hpp"



CPU_Scheduling::CPU_Scheduling() {}
void CPU_Scheduling::increasePriority(PCB* _pcb) {
	if (_pcb->getPriority() < 15) {
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
std::priority_queue < PCB*, std::vector<PCB*>> CPU_Scheduling::getProcesses() {
	this->recivedQueue = getReadyProccesses();
}
void CPU_Scheduling::countingDown() {
	for (int i = 1; i < 6; i++) {
		std::cout << " Commands counter: " << i;
		Sleep(1);
		std::cout << "\x1B[2K\r";
	}
}

void CPU_Scheduling::running() {
	//tu ¿e uruchomiony dummy
	
	while (true) {

		for (int i = 0; i < 5; i++) {
			
			
		}

		while (!readyQueue.empty()) {
			for (int i = 0; i < 5; i++) {
				increasePriority(commandCounter);
				this->readyQueue.at[0];
			}
			commandCounter++;
		}

		getProcesses();
		

	
	
	}
	
	
}