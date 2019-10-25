#pragma once
#include "PCB.hpp"

struct ComparePriority : public PCB{
	struct MyCompare
	{
		bool operator() (const Point& p_lhs, const Point& p_rhs)
		{
			if (p_lhs.getX() > p_rhs.getX()) { return true; }
			if (p_lhs.getX() < p_rhs.getX()) { return false; }
			return (p_lhs.getY() > p_rhs.getY());
		}
	};
};
