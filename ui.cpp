
#include "ui.h"
#include "todo.h"




void Ui::new_task()
{
	std::string text;

	system("cls");

	std::cout << "Input text for your todo task : ";

	std::getline(std::cin >> std::ws, text);

	tasks.push_back(text);

}

bool Ui::input_handler(int action)
{
	if(action == 1)
	{
		action = 0;
		new_task();
		return true;
	}
	else if(action == 2){
		action = 0;
		if(tasks.empty()){
			std::cout << "There are no tasks..." << std::endl;
			system("cls");
		} else {
			list_tasks(tasks);
		}
		return true;
	}
	else if(action == 3) 
	{
		action = 0;
		return false; 
	}
	return false;	
		
}

int Ui::promt_user()
	{
		system("cls");
		int action_select;
		std::cout << "Select action you want to do: || ONLY NUMBER || \n1. New To-do task \n2. Show all Tasks or Remove  \n3. Exit program" << std::endl;

		std::cin >> action_select;

		return (input_handler(action_select));
	}

void Ui::list_tasks(std::vector<Todo>& tasks)
{
	system("cls");
	std::string userInput;
	int taskIndex;

	int i{0};
	for(const auto& task : tasks){
		std::cout << (i+1) << ". " << task.getDescription() << (task.isTaskCompleted() ? " [x] Done! " : " [ ] ") << std::endl;
		i++;
	}

	std::cout << "Choose what task you want to change. Press 'c' to cancel \nInput a number: ";
	
	// ChatGPT's Work
	while (!(std::cin >> userInput))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid number or 'c' to cancel: " << std::endl;
	}

	if(userInput == "c") {
		std::cout << "Cancelled." << std::endl;
		return;
	} else {
		taskIndex = std::stoi(userInput);
	}
	//
	
	
	int action{};
	std::string newDesc;

	if(userInput == userInput){
		std::cout << "What do you want to do with " << (tasks[taskIndex - 1].getDescription()) << "?\n1. Mark as done \n2. Change description\n3. Delete \n4.Cancel" << std::endl;
		std::cin >> action;
		if(action == 1){
			action = 0;
			tasks[taskIndex - 1].markCompleted();
			list_tasks(tasks);
		}
		else if(action == 2){
			action = 0;
			std::cout << "New description : ";
			std::getline(std::cin >> std::ws, newDesc);

			tasks[taskIndex - 1].changeTaskDesc(newDesc);
			list_tasks(tasks);
		}
		else if(action == 3){
			action = 0;
			tasks.erase(tasks.begin() + taskIndex - 1);
			if(!tasks.empty()){
				list_tasks(tasks);
				std::cout << "Task deleted successfully!" << std::endl;
			} 	
		}
		else if(action == 4){
			action = 0;
			list_tasks(tasks);
		}
	}else {
		return;
	}
	return;
}

void Ui::ui_run()
{
	bool running{true};
	
	do
	{
		running = promt_user();
	}
	while(running);
}
