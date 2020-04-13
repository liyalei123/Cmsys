#ifndef  CMSYS_COURSE_H
#define  CMSYS_COURSE_H
#include<string> 
using namespace std;

class Course{
	
	friend void read(istream& inputStream, Course& course);
	public:
		Course();
		Course(const string& cName):Course(){ name = cName;};
		Course(const Course& course);
		virtual void PrintInfo() const;
		inline string GetName() const {return name;};
		inline void SetName(const string& newName){name = newName;};
		inline const int GetId() const{return id;};
		friend ostream& operator <<(ostream& out,const Course& course);
	
	protected:
		int id;    //课程ID 
		string name;//课程名称 
		static int currentId;//设置静态变量来生成唯一的ID值 
};

class ProjectCourse: public Course{
	public:
		inline void SetTag(const string& newTag){	tag=newTag;	};
		inline string GetTag() const {return tag;};
		virtual void PrintInfo() const override;
	private:
		string tag;
};

class JudgeCourse: public Course{
	public:
		inline void SetTime(int newTime){	time = newTime;	};
		inline int GetTime(){	return time;	};
		virtual void PrintInfo() const override;
		
	private:
		int time;
};
#endif 
