#pragma once
#include "PCB.hpp"

struct ComparePriority {
	bool operator()(PCB& p1, PCB& p2){
		return p1.getPriority() < p2.getPriority();
	}
};
