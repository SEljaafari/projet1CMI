#pragma once

struct vecteurs
{
	float x, y;
	vecteurs(float x, float y) :x(x), y(y) {}

	vecteurs& operator+=(const vecteurs& rhs)
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}
};
vecteurs operator*(const vecteurs& vec, float f);
