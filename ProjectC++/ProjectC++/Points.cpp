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

void Points::calculateScore(bool wordGuessed, const uint32_t& responseTimes)
{
	if (wordGuessed)
	{
		uint32_t totalResponseTime = 0;
		uint32_t numCorrectResponses = 0;
		
			if (responseTimes > 0 && responseTimes <= 60)
			{
				totalResponseTime += responseTimes;
				numCorrectResponses++;
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


void Points::setUserId(uint32_t userId)
{
	m_userId = userId;
}

uint32_t Points::getUserId() const
{
	return m_userId;
}

uint32_t game::Points::getId() const
{
	return m_id;
}

void game::Points::setId(uint32_t id)
{
	this->m_id = id;
}
