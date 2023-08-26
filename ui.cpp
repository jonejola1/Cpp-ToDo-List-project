
#include "ui.h"
#include "todo.h"

using namespace std;




void Ui::new_task()
{
	string text;

	system("cls");

	cout << "Input text for your todo task : ";

	getline(cin >> ws, text);

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
			cout << "There are no tasks..." << endl;
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

int Ui::prompt_user()
	{
		system("cls");
		int action_select;
		cout << "Select action you want to do: || ONLY WHOLE NUMBERS || \n1. New To-do task \n2. Show all Tasks or Remove  \n3. Exit program" << endl;

		cin >> action_select;

		return (input_handler(action_select));
	}

void Ui::list_tasks(vector<Todo>& tasks)
{
	system("cls");
	string userInput;
	int taskIndex;

	int i{0};
	for(const auto& task : tasks){
		cout << (i+1) << ". " << task.getDescription() << (task.isTaskCompleted() ? " [x] Done! " : " [ ] ") << endl;
		i++;
	}

	cout << "Choose what task you want to change. Press 'c' to cancel \nInput a number: ";
	
	// ChatGPT's Work
	while (!(cin >> userInput))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Please enter a valid number or 'c' to cancel: " << endl;
	}

	if(userInput == "c" || userInput == "C") {
		cout << "Cancelled." << endl;
		return;
	} else {
		taskIndex = stoi(userInput);
	}
	//
	
	
	int action{};
	string newDesc;

	if(userInput == userInput){
		cout << "What do you want to do with " << (tasks[taskIndex - 1].getDescription()) << "?\n1. Mark as done \n2. Change description\n3. Delete \n4.Cancel" << endl;
		cin >> action;
		if(action == 1){
			action = 0;
			tasks[taskIndex - 1].markCompleted();
			list_tasks(tasks);
		}
		else if(action == 2){
			action = 0;
			cout << "New description : ";
			getline(cin >> ws, newDesc);

			tasks[taskIndex - 1].changeTaskDesc(newDesc);
			list_tasks(tasks);
		}
		else if(action == 3){
			action = 0;
			tasks.erase(tasks.begin() + taskIndex - 1);
			if(!tasks.empty()){
				list_tasks(tasks);
				cout << "Task deleted successfully!" << endl;
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
		running = prompt_user();
	}
	while(running);
}
