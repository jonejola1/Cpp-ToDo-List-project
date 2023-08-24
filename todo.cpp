
#include "todo.h"


Todo::Todo(const std::string& desc) : description(desc), isCompleted(false)
{
}

void Todo::markCompleted() {
	isCompleted = true;
}

std::string Todo::getDescription() const{
	return description;
}

bool Todo::isTaskCompleted() const {
	return isCompleted;
}

void Todo::changeTaskDesc(std::string newDesc) {
	description = newDesc;
}