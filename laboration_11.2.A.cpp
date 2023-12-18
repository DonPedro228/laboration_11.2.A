#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;

enum Specialnist { Computer_Science, Philology, Information_Technology };
string specStr[] = { "Computer_Science", "Philology", "Information_Technology" };

struct Student
{
	char prizv[60];
	int course;
	Specialnist specialnist;
	double physics_grade;
	double math_grade;
	double informatics_grade;
};

void Create(string filename);
void Print(string filename);
int Count5(string filename);
int Count4(string filename);
int Count3(string filename);
void Students_With_Grade_5_In_Physics_And_Math(string filename);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	string filename;
	cout << "Input name of file: "; cin >> filename;

	string fileName;

	int grade3Count;
	int grade4Count;
	int grade5Count;
	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Choose an extion: " << endl << endl;
		cout << " [1] - entering data from the keyboard" << endl;
		cout << " [2] - print data in display" << endl;
		cout << " [3] - cout count 3 from math" << endl;
		cout << " [4] - cout count 4 from math" << endl;
		cout << " [5] - cout count 5 from math" << endl;
		cout << " [6] - Students who got '5' in Physics and Math" << endl;
		cout << " [7] - save to file" << endl;
		cout << " [8] - load from file" << endl;
		cout << " [0] - Exit" << endl << endl;
		cout << "Input value: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(filename);
			break;
		case 2:
			Print(filename);
			break;
		case 3:
			grade3Count = Count3(filename);
			cout << "Count grades 3 from math: " << grade3Count << endl;
			break;
		case 4:
			grade4Count = Count4(filename);
			cout << "Count grades 4 from math: " << grade4Count << endl;
			break;
		case 5:
			grade5Count = Count5(filename);
			cout << "Count grades 5 from math: " << grade5Count << endl;
			break;
		case 6:
			cout << "Students who got '5' in Physics and Math:" << endl;
			Students_With_Grade_5_In_Physics_And_Math(filename);
			break;
		default:
			cout << "You input mistake value!" << endl;
		}
	} while (menuItem != 0);



	return 0;
}

void Create(string filename) {
	ofstream f(filename, ios::binary);
	Student s;
	char ch;
	int spec, i = 0;

	do {
		i++;
		cin.get();
		cout << "#" << i << ":" << endl;
		cout << "LastName: "; cin.getline(s.prizv, 60);
		cout << "Course: "; cin >> s.course;
		cout << "0 - Computer_Science, 1 - Philology, 2 - Information_Technology: "; cin >> spec;
		s.specialnist = (Specialnist)spec;
		cout << "Math_Grade: "; cin >> s.math_grade;
		cout << "Phisics_Grade: "; cin >> s.physics_grade;
		cout << "Informatics_Grade: "; cin >> s.informatics_grade;
		cin.get();

		f.write((char*)&s, sizeof(Student));
		cout << "Continue? (Y/N): "; cin >> ch; cout << endl;
	} while (ch == 'Y' || ch == 'y');
	f.close();
	cout << endl;
}

void Print(string filename)
{
	ifstream f(filename, ios::binary);
	Student s;
	int i = 0;
	cout << "=================================================================================================="
		<< endl;
	cout << "| # | Last Name | Course | Specialnist | Phisics | Math | Informatics |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------------------"
		<< endl;
	while (f.read((char*)&s, sizeof(Student))) {
		i++;
		cout << "| " << i << " | " << setw(10) << left << s.prizv << " | " << setw(4) << left << s.course << " | " << setw(13) << left << specStr[s.specialnist];
		cout << " | " << setw(10) << left << s.math_grade << " | " << setw(6) << left << s.physics_grade << " | " << setw(13) << left << s.informatics_grade << " | ";
		cout << endl;
		cout << "--------------------------------------------------------------------------" << endl;
	}
	cout << "=================================================================================================="
		<< endl;
	f.close();
}

int Count5(string filename) {
	ifstream f(filename, ios_base::binary);
	Student s;
	int totalStudents = 0, grade5Count = 0;
	while (f.read((char*)&s, sizeof(Student))) {
		totalStudents++;
		if (s.math_grade == 5) {
			grade5Count++;
		}
	}
	f.close();

	if (totalStudents == 0)
		return 0.0;

	return grade5Count;
}

int Count4(string filename) {
	ifstream f(filename, ios_base::binary);
	Student s;
	int totalStudents2 = 0, grade4Count = 0;
	while (f.read((char*)&s, sizeof(Student))) {
		totalStudents2++;
		if (s.math_grade == 4) {
			grade4Count++;
		}
	}
	f.close();
	if (totalStudents2 == 0)
		return 0.0;

	return grade4Count;
}

int Count3(string filename) {
	ifstream f(filename, ios_base::binary);
	Student s;
	int totalStudents3 = 0, grade3Count = 0;
	while (f.read((char*)&s, sizeof(Student))) {
		totalStudents3++;
		if (s.math_grade == 3) {
			grade3Count++;
		}
	}
	f.close();
	if (totalStudents3 == 0)
		return 0.0;

	return grade3Count;
}

void Students_With_Grade_5_In_Physics_And_Math(string filename) {
	ifstream f(filename, ios_base::binary);
	Student s;
	cout << "Name of students who got 5 from physics and math: " << endl;
	while (f.read((char*)&s, sizeof(Student))) {
		if (s.physics_grade == 5 && s.math_grade == 5) {
			cout << s.prizv << endl;
		}
	}
	f.close();
}



