#include <iostream>
#include <string>
using namespace std;

template <typename T, int n>

class TestScores {
private:
	string participantName;
	T marks[n];
public:
	void input() {
		cout << "Enter Your Name: ";
		getline(cin, participantName);
		
		cout << "Enter " << n << " Marks for " << n << " tasks: ";
		for (int i = 0; i < n; i++) {
			cin >> marks[i];
		}
	}

	void display() {
		cout << "Participant: " << participantName << endl;
		cout << "Marks in each "  << n << "  tasks: ";
		for (int i = 0; i < n; i++) {
			cout << marks[i] << ' ';
		}
		cout << endl;
	}

	T totalMarks() {
		T t_marks = marks[0];

		for (int i = 1; i < n; i++) {
			t_marks += marks[i];
		}
		return t_marks;
	}

	float averageMarks() {
		return totalMarks() / n;
	}
	 
	T highestMark() {
		T h_mark = marks[0];

		for (int i = 0; i < n; i++) {
			if (marks[i] > h_mark) {
				h_mark = marks[i];
			}
		}
		return h_mark;
	}
	void sortMarks() {
		for (int i = 0; i < n - 1; i++) {
			int smallestIndex = i;
			for (int j = i + 1; j < n; j++) {
				if (marks[j] < marks[smallestIndex]) {
					smallestIndex = j;
				}
			}
			swap(marks[i], marks[smallestIndex]);
		}

	}

	int FindMark(T target) {
		int st = 0, end = n - 1;
		while (st <= end) {
			int mid = st + (end - st) / 2;
			if (marks[mid] == target) {
				return mid;
			}
			if (target < marks[mid]) {
				end = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
		return -1;
	}

};

int main() {
	cout << "----------------------- Participant 1 -----------------------\n\n";
	TestScores<int, 5> p1;
	p1.input();
	p1.display();
	cout << "Total Marks: " << p1.totalMarks() << endl;
	cout << "Highest Mark: " << p1.highestMark() << endl;
	cout << "Average Mark: " << p1.averageMarks() << endl;
	cout << "Sorting Marks..." << endl;
	p1.sortMarks();
	cout << "Marks after sortig" << endl;
	p1.display();
	int target;
	cout << "Enter Target Mark to find it's index: ";
	cin >> target;
	cout << "Target Mark (" << target << "): Index found: " << p1.FindMark(4) << endl;
	
	cout << "---------------------------------------------------------------\n\n";

	cout << "----------------------- Participant 2 -----------------------\n\n";
	TestScores<int, 5> p2;
	cin.ignore();
	p2.input();
	p2.display();
	cout << "Total Marks: " << p2.totalMarks() << endl;
	cout << "Highest Mark: " << p2.highestMark() << endl;
	cout << "Average Mark: " << p2.averageMarks() << endl;
	cout << "Sorting Marks..." << endl;
	p2.sortMarks();
	cout << "Marks after sortig" << endl;
	p2.display();
	cout << "Enter Target Mark to find it's index: ";
	cin >> target;
	cout << "Target Mark (" << 4 << "): Index found: " << p2.FindMark(4) << endl;

	cout << "---------------------------------------------------------------\n\n";

	cout << "----------------------- Participant 3 -----------------------\n\n";
	TestScores<int, 5> p3;
	cin.ignore();
	p3.input();
	p3.display();
	cout << "Total Marks: " << p3.totalMarks() << endl;
	cout << "Highest Mark: " << p3.highestMark() << endl;
	cout << "Average Mark: " << p3.averageMarks() << endl;
	cout << "Sorting Marks..." << endl;
	p3.sortMarks();
	cout << "Marks after sortig" << endl;
	p3.display();
	cout << "Enter Target Mark to find it's index: ";
	cin >> target;
	cout << "Target Mark (" << 4 << "): Index found: " << p3.FindMark(4) << endl;

	cout << "---------------------------------------------------------------\n\n";


	cout << "----------------------- Participant 4 -----------------------\n\n";
	TestScores<float, 5> p4;
	cin.ignore();
	p4.input();
	p4.display();
	cout << "Total Marks: " << p4.totalMarks() << endl;
	cout << "Highest Mark: " << p4.highestMark() << endl;
	cout << "Average Mark: " << p4.averageMarks() << endl;
	cout << "Sorting Marks..." << endl;
	p4.sortMarks();
	cout << "Marks after sortig" << endl;
	p4.display();
	float p4_target;
	cout << "Enter Target Mark to find it's index: ";
	cin >> p4_target;
	cout << "Target Mark (" << p4_target << "): Index found: " << p4.FindMark(p4_target) << endl;

	cout << "---------------------------------------------------------------\n\n";

	cout << "----------------------- Participant 5 -----------------------\n\n";
	TestScores<float, 5> p5;
	cin.ignore();
	p5.input();
	p5.display();
	cout << "Total Marks: " << p5.totalMarks() << endl;
	cout << "Highest Mark: " << p5.highestMark() << endl;
	cout << "Average Mark: " << p5.averageMarks() << endl;
	cout << "Sorting Marks..." << endl;
	p5.sortMarks();
	cout << "Marks after sortig" << endl;
	p5.display();
	float P5_target;
	cout << "Enter Target Mark to find it's index: ";
	cin >> P5_target;
	cout << "Target Mark (" << P5_target << "): Index found: " << p5.FindMark(P5_target) << endl;

	cout << "---------------------------------------------------------------\n\n";

}