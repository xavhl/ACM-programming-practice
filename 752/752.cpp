#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	queue<tuple<int, int, int>> lowPriority, highPriority;//clearance
	int noOfTasks, execTime;

	while (cin >> noOfTasks) {
		//create two records for tasks and respective finishing time
		vector<tuple<int, int, int>> taskList;
		vector<int> taskTime;

		//insert tasks into queues, either with low priority or high
		for (int i = 0; i < noOfTasks; i++) {
			int arrT, workT, priLev;
			cin >> arrT >> workT >> priLev;

			if (i == 0)
				execTime = arrT;

			tuple<int, int, int> task(i, arrT, workT);
			taskList.push_back(task);
			taskTime.push_back(0);

			if (priLev == 1)
				lowPriority.push(task);
			else
				highPriority.push(task);
		}

		//execute task, i.e. pop out from queue
		for (int i = 0; i < noOfTasks; i++) {
			int arrT, workT, priL, c, ith;

			if (!highPriority.empty() && lowPriority.empty())
				c = 1;
			else if (highPriority.empty() && !lowPriority.empty())
				c = 2;
			else {
				if (get<1>(highPriority.front()) <= execTime || get<1>(highPriority.front()) <= get<1>(lowPriority.front()))
					c = 1;
				else
					c = 2;
			}

			switch (c)
			{
			case 1:
				ith = get<0>(highPriority.front());
				arrT = get<1>(highPriority.front());
				workT = get<2>(highPriority.front());

				if (get<1>(highPriority.front()) > execTime)
					execTime = arrT;

				highPriority.pop();
				break;

			case 2:
				ith = get<0>(lowPriority.front());
				arrT = get<1>(lowPriority.front());
				workT = get<2>(lowPriority.front());

				if (get<1>(lowPriority.front()) > execTime)
					execTime = arrT;

				lowPriority.pop();
				break;

			default:
				break;
			}

			execTime += workT;

			//fill in finishing time
			taskTime[ith] = execTime;
		}

		//print final result
		for (auto i = taskTime.begin(); i != taskTime.end(); i++) {
			cout << *i;
			if (i != taskTime.end() - 1)
				cout << " ";
			else
				cout << endl;
		}

		while (!lowPriority.empty() || !highPriority.empty()) {
			lowPriority.pop();
			highPriority.pop();
		}
		taskList.clear();
		taskTime.clear();
	}

	return 0;
}