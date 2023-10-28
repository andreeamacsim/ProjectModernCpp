#pragma once
#include <iostream>
class Points
{
public:
	uint32_t GetPoints();
	uint32_t SetPoints();
	Points();
	uint32_t PointsPerRound();//punctele adaugate fiecarui jocator per runda jucata
private:
	uint32_t m_points;

};

