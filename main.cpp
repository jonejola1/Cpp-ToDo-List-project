
#include <iostream>
#include "ui.h"
#include "todo.h"


int main()
{
	Ui ui_instance1;
	ui_instance1.ui_run();


	std::cout << "Done!" << std::endl;
	return 0;
}