#include "AdjListGraph.h"

// printCourses
// Assume the list has at least one course.
void AdjListGraphprintCourses() const
{
	cout << "COURSES:" << endl;
	for (int i = 0; i < numOfVertices; ++i)
		cout << "- " << PREFIX << vertices[i] << endl;
}

// printAllPrereq
// Assume the list has at least one course.
void printAllPrereq() const
{
	for (int i = 0; i < numOfVertices; ++i)
	{
		cout << "- " << PREFIX << vertices[i] << ": ";
		if (list[i]->getCount() == 0)
			cout << "No prerequisites";
		else
			cout << *list[i];
		cout << endl;
	}
}

// renameCourse
// Assume the course exists in the list.
void renameCourse(const string& oldCourse, const string& newCourse) const
{
	int index = 0;
	while (vertices[index] != oldCourse)
		++index;
	vertices[index] = newCourse;

	for (int i = 0; i < numOfVertices; ++i)
		list[i]->replaceData(oldCourse, newCourse);
}