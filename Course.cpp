#include<iostream>
#include "Course.h"

using namespace std;
int Course::currentId = 1;
Course::Course(){
	id = currentId++;
	name = "";
} 

Course::Course(const Course& course){
	id=course.GetId();
	name=course.GetName();
}

void Course::PrintInfo() const {
	cout << "Course: " << id << ":" << name << endl;

}
void read(istream& is, Course &item){
	is>>item.name;
}
ostream &operator<<(ostream &os, const Course& course){
	os << "Course: " << course.id << ":" << course.name;
	return os;
}

void ProjectCourse::PrintInfo() const{
	cout << "ProjectCourse: " << id << ":" << name << ":" << tag << endl;
}

void JudgeCourse::PrintInfo() const{
	cout << "JudgeCourse: " << id << ":" << name << ":" << time << endl;
}
