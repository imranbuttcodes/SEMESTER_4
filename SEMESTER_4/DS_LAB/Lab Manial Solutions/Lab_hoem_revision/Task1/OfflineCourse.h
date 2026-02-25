#pragma once
#include "Course.h"

class OfflineCourse: public Course
{
public:
	OfflineCourse(int months, int hoursPerDay);
	int months, hoursPerDay;
	void duration() override;
};

