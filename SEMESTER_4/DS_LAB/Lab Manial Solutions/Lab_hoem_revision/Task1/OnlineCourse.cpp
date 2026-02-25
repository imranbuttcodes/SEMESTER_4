#include<iostream>
#include "OnlineCourse.h"
using namespace std;
void OnlineCourse::duration() {
	cout << "Duration for OnlineCourse: " << weeks * hoursPerWeek << endl;
}


OnlineCourse::OnlineCourse(int weeks, int hoursPerWeek) : weeks(weeks), hoursPerWeek(hoursPerWeek) {}

