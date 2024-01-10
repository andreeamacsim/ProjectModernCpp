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
		void calculateScore(bool wordGuessed, const std::vector<uint32_t>& responseTimes);
		void applyGuessingPoints(uint32_t guessingTime);
		void applyFailedGuessingPoints();
		uint32_t PointsPerRound();//punctele adaugate fiecarui jocator per runda jucata
		uint32_t getPoints();
		void setUserId(uint8_t userId);
		uint8_t getUserId();
	private:
		uint32_t m_points;
		uint8_t m_userId;
	};
}

