module;

import <vector>;

export module PointsModule;

export class Points
{
public:
	uint32_t GetPoints() const;
	uint32_t SetPoints() const;
	Points();
	uint32_t PointsPerRound();//punctele adaugate fiecarui jocator per runda jucata
private:
	uint32_t m_points;
};

