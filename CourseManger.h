#ifndef CMSYS_COURSEMANGER_H
#define CMSYS_COURSEMANGER_H

#include<vector>
#include"Course.h"

using namespace std;

class CourseManager{
	public:
		CourseManager() = default;
		CourseManager(const vector<Course>& courseVect);
		inline int GetCourseNum(){	return courseList.size();	};
		void AddCourse(const Course &course);
		void AddCourse(const string &courseName);
		void RemoveLast();
		void RemoveByName(const string &name);
		void RemoveById(int id);
		void PrintAllCourse();
		void PrintCourse(const string &name);
		void PrintCourse(int id);
		void PrintLongNameCourse();
		
	private:
		vector<Course> courseList;
		int FindCourse(const string& name);
		int FindCourse(int id);
};

#endif
