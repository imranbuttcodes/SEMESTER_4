#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
public:
	string student_id_, name_;
	int age_, credit_hours_;
	float cgpa_;
	Student(string student_id, string name,int age, float cgpa, int credit_hours):
		student_id_(student_id), name_(name), age_(age), cgpa_(cgpa), credit_hours_(credit_hours) {}
	void displayInfo() {
		cout << student_id_ << '\t' << name_ << '\t' << age_ << cgpa_ << '\t' << credit_hours_ << endl;
	}


};


class StudentManager {
public:
	vector<Student> students_;
	int id = 1;
	void addStudent() {
		string student_id, name;
		int age, credit_hours;
		float cgpa;
		cout << "Enter Name: ";
		getline(cin, name);
		cout << "Enter Age: ";
		cin >> age;
		cout << "Enter Credit Hours: ";
		cin >> credit_hours;
		cout << "Enter CGPA: ";
		cin >> cgpa;
		cout << "StudentId generated: " << id << endl;
		students_.push_back(Student(to_string(id), name, age, cgpa, credit_hours));
		id++;
		updateFile();
	}
	void updateFile() {
		ofstream write("student_database.txt");
		write << "ID,Name,Age,CGPA,Credit_Hours," << endl;
		if (!students_.empty()) {
			for (auto student : students_) {
				write << student.student_id_ << "," << student.name_ << "," << student.age_ << "," << student.cgpa_ << "," << student.credit_hours_ << endl;
			}
		}
		write.close();
	}
	void readFile() {
		ifstream read("student_database.txt");
		if (!read) {
			cout << "OOPs! File not found!" << endl;
			return;
		}
		string line;
		getline(read, line);

		while (getline(read, line)) {
			string student_id, name,age, credit_hours,cgpa;
			std::stringstream ss(line);
			getline(ss, student_id,',');
		/*	id = stoi(student_id);*/
			getline(ss, name, ',');
			getline(ss, age, ',');
			getline(ss, cgpa, ',');
			getline(ss, credit_hours, ',');
			students_.push_back(Student(student_id, name, stoi(age), stof(cgpa), stoi(credit_hours)));
		}
		
		//id = stoi(students_[students_.size() - 1].student_id_);
		//id++;
	}
	bool isStudentExist(string id) {
		if (students_.empty())	return false;
		for (auto& student : students_) {
			if (student.student_id_ == id)	return true;
		}
		return false;
	}

	void displayAllStudents() {
		if (students_.empty()) {
			cout << "Zero Students Record Found!" << endl;
			return;
		}
		cout << "StudentID\tName\tAge\tCGPA\tCredit Hours" << endl;
		for (auto& student : students_) {
			student.displayInfo();
		}
		cout << "--------------------------------------------------------------------------------\n";
	}

	Student* getStudent(string id) {
		if (students_.empty())	return nullptr;
		for (auto& student : students_) {
			if (student.student_id_ == id)	return &student;
		}
		return nullptr;
	}

	void UpdateInfo() {
		string id;
		cout << "Enter StudentID: ";
		if (!isStudentExist(id)) {
			cout << "ERROR: Student with this id not found!" << endl;
			return;
		}
		Student* student = getStudent(id);
		string choice;
		while (true) {
			cout << "--------------- Welcome ----------------------\n";
			cout << "[1] Update Name\n";
			cout << "[2] Update Age\n";
			cout << "[3] Update CGPA\n";
			cout << "[4] Update Credit Hours\n";
			cout << "[0] Exit and Save Changes\n";
			cout << "Enter Your Choice: ";
			getline(cin, choice);
			if (choice == "0") {
				cout << "Exiting....";
				return;
			}
			if (choice == "1") {
				cout << "Enter New Name: ";
				getline(cin, student->name_);
				cout << "Updated Name Successfully!" << endl;
			}
			else if (choice == "2") {
				cout << "Enter New Age: ";
				string new_age_;
				getline(cin, new_age_);
				student->age_ = stoi(new_age_);
				cout << "Updated Age Successfully!" << endl;
			}
			else if (choice == "3") {
				cout << "Enter New CGPA: ";
				string new_cgpa;
				getline(cin, new_cgpa);
				student->cgpa_ = stof(new_cgpa);
				cout << "Updated CGPA Successfully!" << endl;
			}
			else if (choice == "4") {
				cout << "Enter New Credit Hours: ";
				string new_hr;
				getline(cin, new_hr);
				student->credit_hours_ = stoi(new_hr);
				cout << "Updated Credit Hours Successfully!" << endl;
			}
			else if (choice == "0") {
				cout << "Saving Changes....";
				updateFile();
				cout << "Changes Saved" << endl;
				break;
			} else{
					cout << "Invalide Choice!" << endl;
			}
		}
	}
	void GradeBasedSearch() {
		string choice;
		while (true) {
			cout << "------------- Searching Students -------------\n";
			cout << "[1] Search Students based on CGPA" << endl;
			cout << "[0] Exit\n";
			if (choice == "1") {
				float min_cgpa, max_cgpa;
				cout << "Enter Minimum CGPA: ";
				cin >> min_cgpa;
				cout << "Enter Maximum CGPA: ";
				cin >> max_cgpa;
				cout << "Searching students for these thresholds.....";
				bool foundAny = false;
				cout << "StudentID\tName\Age\tCGPA\tCredit Hours" << endl;
				for (auto& student: students_) {
					if (student.cgpa_ >= min_cgpa && student.cgpa_ <= max_cgpa) {
						student.displayInfo();
						foundAny = true;
					}
				}
				if (!foundAny) {
					cout << "No Students found within this range!" << endl;
					cout << "--------------------------------------------------------------------------------\n";
				}
				else {
					cout << "--------------------------------------------------------------------------------\n";
				}

			}
			else if (choice == "0") {
				cout << "Exiting......";
				break;
			}
			else {
				cout << "Invalid Choice!" << endl;
			}
		}
	}
};


void start() {
	string choice;
	StudentManager sm;
	sm.readFile();
	while (1) {
		cout << "---------------------------- Students Dashhboard ----------------------------\n";
		cout << "[1] Add Student\n";
		cout << "[2] Update Student Record\n";
		cout << "[3] Display All Students\n";
		cout << "[4] Search Students\n";
		cout << "[0] Exit\n";
		cout << "Enter Your Choice: ";
		getline(cin, choice);
		if (choice == "1") {
			sm.addStudent();
		}
		else if (choice == "2") {
			sm.UpdateInfo();
		}
		else if (choice == "3") {
			sm.displayAllStudents();
		}
		else if (choice == "4") {
			sm.GradeBasedSearch();
		}
		else if (choice == "0") {
			cout << "Exiting.....\n";
			break;
		}
		else {
		
			cout << "Invalide Choice!" << endl;
		}
	}
}

int main() {
	start();
}
