
#include "todo.h"
using namespace std;

Todo::Todo(const string& desc) : description(desc), isCompleted(false)
{
}

void Todo::markCompleted() {
	isCompleted = true;
}

string Todo::getDescription() const{
	return description;
}

bool Todo::isTaskCompleted() const {
	return isCompleted;
}

void Todo::changeTaskDesc(string newDesc) {
	description = newDesc;
}