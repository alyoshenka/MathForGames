#include "lerp.h"

float easeInOutBack(float t, const float b, const float c, float d)
{
	float s = 1.70158f;
	if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525f)) + 1)*t - s)) + b;
	float postFix = t -= 2;
	return c / 2 * ((postFix)*t*(((s *= (1.525f)) + 1)*t + s) + 2) + b;
}
