#include "OfflineCourse.h"
#include <iostream>
using namespace std;

void OfflineCourse::duration() {
	cout << "Duration for OfflineCourse: " << months * 30 * hoursPerDay << endl;
}


OfflineCourse::OfflineCourse(int months, int hoursPerDay) : months(months), hoursPerDay(hoursPerDay) {}



