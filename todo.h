#ifndef TODO_H
#define TODO_H

#include <string>

class Todo
{
public: 
	Todo() = default;
	Todo(const std::string& desc);
	void markCompleted();
	std::string getDescription()const;
	bool isTaskCompleted()const;
	void changeTaskDesc(std::string newDesc);
	~Todo() =default;

private:
	std::string description{};
	bool isCompleted{};
};



#endif // TODO_H
