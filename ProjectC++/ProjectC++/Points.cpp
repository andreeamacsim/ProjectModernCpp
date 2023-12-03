module PointsModule;
import <vector>;
using game::Points;

uint32_t Points::getPoints() const
{
	return m_points;
}

void Points::setPoints(uint32_t points)
{
	m_points = points;
}

Points::Points()
{
   m_points = 0;
}

void Points::calculateScore(bool wordGuessed, const std::vector<uint32_t>& responseTimes)
{
	if (wordGuessed)
	{
		uint32_t totalResponseTime = 0;
		uint32_t numCorrectResponses = 0;
		for (const auto& time : responseTimes)
		{
			if (time > 0 && time <= 60)
			{
				totalResponseTime += time;
				numCorrectResponses++;
			}
		}
		if (numCorrectResponses > 0)
		{
			double averageResponseTime = static_cast<double>(totalResponseTime / numCorrectResponses);
			m_points += static_cast<uint32_t>(((60 - averageResponseTime) * 100) / 60);
		}
		else
		{
			m_points = -100;
		}
	}
	else
	{
		m_points = -100;
	}
}


void Points::applyGuessingPoints(uint32_t guessingTime)
{
	if (guessingTime < 30)
	{
		m_points += 100;
	}
	else
	{
		m_points += static_cast<uint32_t>(((60 - guessingTime)*100)/30);

	}
}

void Points::applyFailedGuessingPoints()
{
	m_points -= 50;
}
