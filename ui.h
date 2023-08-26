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
	int prompt_user(); 
	void list_tasks(vector<Todo>& tasks);

	vector<Todo> tasks;
};


#endif // UI_H
