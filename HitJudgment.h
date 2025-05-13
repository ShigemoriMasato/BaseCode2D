#pragma once
#include"Vector.h"
#include<cmath>

bool BoxToBox(Vector2 aPos, Vector2 aSize, Vector2 bPos, Vector2 bSize)
{
	if (aPos.x + aSize.x > bPos.x && aPos.x < bPos.x + bSize.x && aPos.y + aSize.y > bPos.y && aPos.y < bPos.y + bSize.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircleToCircle(Vector2 aPos, float aRadius, Vector2 bPos, float bRadius)
{
	float distance = sqrtf((aPos.x - bPos.x) * (aPos.x - bPos.x) + (aPos.y - bPos.y) * (aPos.y - bPos.y));
	if (distance < aRadius + bRadius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BoxToCircle(Vector2 aPos, Vector2 aSize, Vector2 bPos, float bRadius)
{
	Vector2 circleDistance;
	circleDistance.x = abs(bPos.x - aPos.x - aSize.x / 2);
	circleDistance.y = abs(bPos.y - aPos.y - aSize.y / 2);

	if (circleDistance.x > (aSize.x / 2 + bRadius))
	{
		return false;
	}
	if (circleDistance.y > (aSize.y / 2 + bRadius))
	{
		return false;
	}

	if (circleDistance.x <= (aSize.x / 2))
	{
		return true;
	}
	if (circleDistance.y <= (aSize.y / 2))
	{
		return true;
	}

	float cornerDistance_sq = (circleDistance.x - aSize.x / 2) * (circleDistance.x - aSize.x / 2) + (circleDistance.y - aSize.y / 2) * (circleDistance.y - aSize.y / 2);

	return (cornerDistance_sq <= (bRadius * bRadius));
}
