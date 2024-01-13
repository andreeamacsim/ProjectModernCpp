module;

import <vector>;

export module PointsModule;
namespace game {
	export class Points
	{
	public:
		uint32_t getPoints() const;
		void setPoints(uint32_t points);
		Points();
		void calculateScore(bool wordGuessed, const uint32_t& responseTimes);
		void applyGuessingPoints(uint32_t guessingTime);
		void applyFailedGuessingPoints();
		uint32_t PointsPerRound();//punctele adaugate fiecarui jocator per runda jucata
		void setUserId(uint32_t userId);
		uint32_t getUserId() const;
		uint32_t getId()const;
		void setId(uint32_t id);
	private:
		uint32_t m_id;
		uint32_t m_points=0;
		uint32_t m_userId;
	};
}

