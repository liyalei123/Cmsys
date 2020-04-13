#ifndef CMSYS_CMDMANAGER_H
#define CMSYS_CMDMANAGER_H

#include"CourseManger.h"
#include"Cmd.h"

#include<map>
#include<istream>
using namespace std;
class CmdManager{
	public:
		CmdManager()=default;
		void Init();
		void PrintAllHelp() const;
		void PrintCmdHelp(const CourseCmd cmd) const;
		bool HandleCmd(const CourseCmd cmd);
		CourseManager& GetCourseManager() {	return manager;	};
	private:
		CourseManager manager;
		map<CourseCmd,string> cmdMap;
};

#endif
