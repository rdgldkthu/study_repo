#pragma once

#include <vector>
#include "Teacher.h"
#include "Student.h"

class Lecture
{
private:
	std::string m_name;
	Teacher* teacher;
	std::vector<Student*> students;

public:
	Lecture(const std::string& name_in)
		: m_name(name_in)
	{}

	~Lecture() {}

	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << "*** " << m_name << " Studied ***" << std::endl << std::endl;

		for (auto& stu : students)
			stu->setIntel(stu->getIntel() + 1);
	}

	friend std::ostream& operator << (std::ostream& out, const Lecture& lecture)
	{
		out << "------------------------------" << std::endl;
		out << "LECTURE: " << lecture.m_name << std::endl;
		out << "TEACHER: " << *lecture.teacher << std::endl;

		for (auto& stu : lecture.students)
			out << *stu << std::endl;

		out << "------------------------------";
		return out;
	}
};