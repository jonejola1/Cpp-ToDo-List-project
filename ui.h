#ifndef UI_H
#define UI_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
#include "todo.h"


class Ui
{
public:
	Ui() = default;
	void ui_run();
	~Ui() = default;

private:

	void new_task();
	bool input_handler(int action);
	int promt_user(); 
	void list_tasks(std::vector<Todo>& tasks);

	std::vector<Todo> tasks;
};


#endif // UI_H
