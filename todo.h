#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <string>
#include <vector>

class Todo
{
public: 
	Todo() = default;
	Todo(const string& desc);
	void markCompleted();
	string getDescription()const;
	bool isTaskCompleted()const;
	void changeTaskDesc(string newDesc);
	~Todo() =default;

private:
	string description{};
	bool isCompleted{};
};



#endif // TODO_H
