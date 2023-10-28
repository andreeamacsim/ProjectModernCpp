#include "Points.h"

uint32_t Points::GetPoints()
{
    return m_points;
}

uint32_t Points::SetPoints()
{
    //m_points=GetPoints()+ PointsPerRound();
}

Points::Points()
{
   m_points = 0;
}
