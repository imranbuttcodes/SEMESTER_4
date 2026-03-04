#pragma once
#include "Course.h"
class OnlineCourse: public Course
{
public:
	OnlineCourse(int weeks, int hoursPerWeek) ;
	int weeks, hoursPerWeek;
	void duration() override;
};

