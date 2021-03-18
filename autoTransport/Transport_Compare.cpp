#include "Transport.h"
float WPRatio(Transport* tr);
bool Compare(Transport* first, Transport* second)
{
	return WPRatio(first) < WPRatio(second);
};