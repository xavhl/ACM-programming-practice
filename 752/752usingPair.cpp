#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
	queue<pair<int, int>> lowPriority, highPriority;//clearance
	int noOfTasks, execTime;

	while (cin >> noOfTasks) {
		//create two records for tasks and respective finishing time
		//pair<int, int>* taskList = new pair<int, int> [noOfTasks];
		//int* taskTime = new int[noOfTasks];
		vector<pair<int, int>> taskList;
		vector<int> taskTime;

		//insert tasks into queues, either with low priority or high
		for (int i = 0; i < noOfTasks; i++) {
			int arrT, workT, priLev;
			cin >> arrT >> workT >> priLev;

			if (i == 0)
				execTime = arrT;

			pair<int, int> task(arrT, workT);//set up pair
			//taskList[i] = task;
			//taskTime[i] = 0;
			taskList.push_back(task);
			taskTime.push_back(0);

			if (priLev == 1)
				lowPriority.push(task);
			else
				highPriority.push(task);
		}

		//execute task, i.e. pop out from queue
		for (int i = 0; i < noOfTasks; i++) {
			int arrT, workT, c;

			if (!highPriority.empty() && lowPriority.empty())
				c = 1;
			else if (highPriority.empty() && !lowPriority.empty())
				c = 2;
			else {
				if (highPriority.front().first <= execTime || highPriority.front().first <= lowPriority.front().first)
					c = 1;
				else//if (lowPriority.front().first < execTime)
					c = 2;
			}

			switch (c)
			{
			case 1:
				workT = highPriority.front().second;
				arrT = highPriority.front().first;

				if (highPriority.front().first > execTime)
					execTime = arrT;

				highPriority.pop();
				break;

			case 2:
				workT = lowPriority.front().second;
				arrT = lowPriority.front().first;

				if (lowPriority.front().first > execTime)
					execTime = arrT;

				lowPriority.pop();
				break;

			default:
				break;
			}

			execTime += workT;

			//search pair and fill in finishing time
			if (arrT < taskList[i].first) {
				for (int j = noOfTasks - 1; j >= 0; j--) {
					if (taskList[j].first == arrT && taskList[j].second == workT)
						taskTime[j] = execTime;
					else
						continue;
				}
			}
			else {
				for (int j = 0; j < noOfTasks; j++) {
					if (taskList[j].first == arrT && taskList[j].second == workT)
						taskTime[j] = execTime;
					else
						continue;
				}
			}
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