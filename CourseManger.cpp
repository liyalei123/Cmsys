#include<stdexcept>
#include<iostream>
#include"CourseManger.h"

using namespace std;

CourseManager::CourseManager(const vector<Course> &course){
	for(auto curs=course.begin();curs!=course.end(); ++curs){
		courseList.push_back(*curs);
	}
}

void CourseManager::AddCourse(const string &courseName){
	Course course(courseName);
	courseList.push_back(course);
}

void CourseManager::AddCourse(const Course& course){
	courseList.push_back(course);
}

void CourseManager::RemoveLast(){
	try
	{
		if(!courseList.empty())
		{
			courseList.pop_back();
			cout << "Deleted successfully!" << endl;
		}
		else
		{
			throw runtime_error("Deleted error, there is no course!");
		}
	}
	catch (runtime_error err)
	{
		cout << err.what() << endl;
	}
}

void CourseManager::RemoveById(int id){
	int index = FindCourse(id);
	if(index > 0)
		courseList.erase(courseList.begin() + index);
	else
		cout << "NOT FOUND" << endl;
}

void CourseManager::RemoveByName(const string& name){
	int index=FindCourse(name);
	if(index > 0)
		courseList.erase(courseList.begin() + index);
	else
		cout << "NOT FOUND" << endl;
}

void CourseManager::PrintAllCourse(){
	cout << "CourseList:" << endl;
	for(auto curs=courseList.begin();curs!=courseList.end();++curs){
		cout << *curs << endl;
	}
}

void CourseManager::PrintCourse(int id){
	int index=FindCourse(id);
	if(index>0)
		cout << courseList[index] << endl;
	else
		cout << "NOT FOUND" << endl;
		
}
 
void CourseManager::PrintCourse(const string &name){
	int index = FindCourse(name);
	if(index>0)
		cout << courseList[index] << endl;
	else
		cout << "NOT FOUND" << endl;
}

void CourseManager::PrintLongNameCourse(){
	int maxLen=0;
	for(auto curs=courseList.begin();curs!=courseList.end();++curs){
		int currentLen=curs->GetName().size();
		if(currentLen > maxLen)
			maxLen=currentLen;
	}
	for(auto curs = courseList.begin();curs!=courseList.end();++curs){
		if(curs->GetName().size()==maxLen)
			cout << *curs << endl;
	}
}

int CourseManager::FindCourse(int id){
	int i=0;
	for(;i<courseList.size();i++){
		if(courseList[i].GetId()==id){
			return i;
		}
	}
	return -1;
}

int CourseManager::FindCourse(const string &name){
	int i=0;
	for(;i<courseList.size();i++){
		if(courseList[i].GetName()==name){
			return i;
		}
	}
	return -1;
}

