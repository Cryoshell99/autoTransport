#include "Transport.h"
float weightToPowerRatio(Transport* tr);
bool Compare(Transport* first, Transport* second)
{
	return weightToPowerRatio(first) < weightToPowerRatio(second);
};