#include <iostream>
using namespace std;

class Task {
protected:
	string task;
public:
	Task(string t) : task(t) {}

	virtual void show() const {
		cout << task << endl;
	}
};

class GreatedTask : public Task {
public:
	GreatedTask(string t) : Task(t) {}

	virtual void show() const {
		cout << "!!! " << task << endl;
	}
};

class DeadLineTask : public Task {
	int month, day;
public:
	DeadLineTask(string t, int m, int d) : Task(t), month(m), day(d) {}

	virtual void show() const {
		cout << "Date: " << month << "/" << day << " " << task << endl;
	}
};

class DailyTask : public Task {
	int hour, minute;
public:
	DailyTask(string t, int h, int m) : Task(t), hour(h), minute(m) {}

	DailyTask(string t, int h) : Task(t), hour(h), minute(0) {}

	virtual void show() const {
		if (minute == 0)
			cout << "Time: " << hour << ":00 " << task << endl;
		else
			cout << "Time: " << hour << ":" << minute << " " << task << endl;
	}
};

int main() {
	Task* all[5];
	all[0] = new Task("Simple task");
	all[1] = new GreatedTask("Important task");
	all[2] = new DeadLineTask("Urgent task", 8, 12);
	all[3] = new DailyTask("Daily task 1", 10, 30);
	all[4] = new DailyTask("Daily task 2", 12);

	cout << "\033[1mTO DO LIST:\033[0m\n";
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ") ";
		all[i]->show();
	}
}