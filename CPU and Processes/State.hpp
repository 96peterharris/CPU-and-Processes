#pragma once
#include <exception>

enum State
{
	NEW,
	RUNNING,
	WAITING,
	READY,
	TERMINATED

};
int getNumberOfState(State e)
{
	switch(e){

		case 
			NEW: return 1;

		case 
			RUNNING: return 2;

		case 
			WAITING: return 3;

		case
			READY: return 4;

		case
			TERMINATED: return 5;

		default: throw std::length_error("Out of enum range!");
	}
}