#include "vecteurs.h"

vecteurs operator*(const vecteurs& vec, float f)
{
	return vecteurs(vec.x * f, vec.y * f);
}