#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace msclr::interop;
/*
	For indicating the meaning of variable and its from clearly,
	the [data's variable names] are using "word_word_word" format.
	Otherwise, still use camel style.
*/

/*
	normally all the data stored into this classes structure are considered to be read-only
*/



class Try
{
	/*
		Try = a try in a entry of the task.
		Try can be failed or successed.
	*/
	double time_spent;
	int action_count; // Normally only the valid action input will be counted. 
	bool success_flag;

public:
	Try(bool _success_flag = false, double _time_spent = 0, int _action_count = 0)
	{
		initiate(_success_flag, _time_spent, _action_count);
	}
	void initiate(bool _success_flag, double _time_spent, int _action_count)
	{
		time_spent = _time_spent;
		action_count = _action_count;
		success_flag = _success_flag;
	}
	bool CheckSuccess()
	{
		return success_flag;
	}
	double GetTimeSpent()
	{
		return time_spent;
	}
	int GetTotalActionCounts()
	{
		return action_count;
	}
	double GetApm() // normally used for determining the outliers.
	{
		return action_count / (time_spent * 60);
	}
};
class Entry
{
	/*
		Entry = the entry of a task of the game.
		Every entry can contain many tries.
		1. Only 1 try can be successed, and this try will be the last try of the entry.
		1.1. Any tries after the success try will be considered in the new entry.
	*/

	vector<Try> tries; //insert order
	bool isCompleted = false;
	bool isQuitted = false;
	double passRatio = 0;

public:
	Entry() {}

	int size() { return tries.size(); }


	bool InputTry(bool success_flag, double time, int action_count)
	{
		if (success_flag == true)
		{
			if (isCompleted)
			{
				cout << "error load algorithm" << endl;
				return false;
			}
			else
			{
				isCompleted = true;
				passRatio = (double)1 / (tries.size() + 1);
			}
		}
		tries.push_back(Try(success_flag, time, action_count));
		return true;
	}
	Try& GetLastTry()
	{
		return tries[tries.size() - 1];
	}
	bool IsCompleted() { return isCompleted; }
	bool IsQuitted() { return isQuitted; }
	void SetQuit() { isQuitted = true; }
	bool CheckGiveUp()
	{
		if (tries.size() > 0 && tries[tries.size() - 1].CheckSuccess() == false)
		{
			return true;
		}
		return false;
	}
	bool CheckValidity()
	{
		for (int i = 0; i < tries.size() - 1; i++)
		{
			if (tries[i].CheckSuccess())
				return false;
		}
		return true;
	}
	double GetPassRatio() // the reciprocal of difficulty ratio
	{
		if (CheckGiveUp() == false)
			return 0;
		return (double)1 / tries.size();
	}
	int GetFailureCount() 
	{
		return tries.size();
	}

	vector<Try> GetValidTries(double apmThreshold, double timeSpentMin, double timeSpentMax)
	{
		vector<Try> result;
		for (int i = 0; i < tries.size(); ++i)
		{
			if (tries[i].GetApm() <= apmThreshold && tries[i].GetTimeSpent() >= timeSpentMin && tries[i].GetTimeSpent() <= timeSpentMax)
			{
				result.push_back(tries[i]);
			}
		}
		return result;
	}
};
class Task
{
public:
	int id;
	signed int sequence; // initial sequence
	string name;
	string description;
	Task(int task_id = 0, signed int task_sequence = 0, string task_name = "", string task_description = "")
	{
		id = task_id;
		sequence = task_sequence;
		name = task_name;
		description = task_description;
	}
};

class TaskList
{
private:
	//<ordering, task_id>
	map<signed int, int> orderSequence;
	//<task_id, task>
	unordered_map<int, Task> tasks;
	unordered_map<string, int> keys;
public:
	Task GetTask(int id) { return (tasks.count(id) != 0 ? tasks[id] : Task(-1, -1, "", "")); }
	int GetTaskInSequence(int index) { return orderSequence[index]; }
	int GetSequenceSize() { return orderSequence.size(); }
	map<signed int, int>& GetSequence() { return orderSequence; }
	void InsertTask(int task_id, string task_name, string task_description)
	{
		tasks[task_id].name = task_name;
		tasks[task_id].id = task_id;
		tasks[task_id].description = task_description;
		keys[task_name] = task_id;
	}
	void DeleteTask(int id)
	{
		tasks.erase(id);
	}
	int GetKey(string task_name) 
	{
		return keys[task_name];
	}
	void ClearTasks() { tasks.clear(); }
	int FindMissingSquence()
	{
		for (int i = 1; i < orderSequence.size(); ++i)
		{
			if (orderSequence.count(i) == 0)
				return i;
		}
		return orderSequence.size() + 1;
	}
	void UpdateSequence(int task_id, int desireSequence)
	{
		if (desireSequence <= 0 || orderSequence.count(desireSequence) == 0)
		{
			orderSequence[FindMissingSquence()] = task_id;
		}
		else
		{
			for (int i = orderSequence.size(); i >= desireSequence; --i)
			{
				if (orderSequence.count(i) != 0)
				{
					orderSequence[i + 1] = orderSequence[i];
				}
			}
			orderSequence[desireSequence] = task_id;
		}
	}
	void ClearSequence() { orderSequence.clear(); }
	void PutAll2Sequence()
	{
		ClearSequence();
		for (auto task : tasks)
		{
			UpdateSequence(task.second.id, task.second.sequence);
		}
		cout << "Task Ordering Sequence has Generated." << endl;
	}
	map<int, string> GetMapCopy() 
	{
		map<int, string> result;
		for (auto task : tasks) 
		{
			result[task.first] = task.second.name;
		}
		return result;
	}

};

class Filter
{
	int ApmThreshold = 10;
public:
	void SetApmThreshold(int newApmT) 
	{
		ApmThreshold = newApmT;
	}
};

class PlayerData
{
	unsigned int id;
	string name;
	unordered_map<int, vector<Entry>> task_entries; // <task_id, entries_data>

public:
	void Init(unsigned player_id, string player_name)
	{
		id = player_id;
		name = player_name;
	}

	void StartNewEntry(unsigned int task_id)
	{
		task_entries[task_id].push_back(Entry());
	}
	string GetName() {
		return name;
	}
	bool DoesEnterTask(unsigned int task_id) { return (task_entries.count(task_id) != 0); }
	int GetEntryCount(unsigned int task_id)
	{
		if (task_entries.count(task_id) == 0)
			return 0;
		return task_entries[task_id].size();
	}
	bool DoesGiveUp(unsigned int task_id)
	{
		for (auto entry : task_entries[task_id])
		{
			if (entry.IsCompleted() == true)
				return false;
		}
		return true;
	}
	int GetTryCount(unsigned int task_id, int index)
	{
		if (task_entries.count(task_id) == 0 || index >= GetEntryCount(task_id))
			return 0;
		return task_entries[task_id][index].size();
	}
	int GetTotalTryCount(unsigned int task_id)
	{
		int count = 0;
		for (int i = GetEntryCount(task_id) - 1; i >= 0; --i)
		{
			count += GetTryCount(task_id, i);
		}
		return count;
	}
	Entry& GetEntry(unsigned int task_id, unsigned int index) 
	{
		if (index >= GetEntryCount(task_id))
			index = GetEntryCount(task_id) - 1;
		return task_entries[task_id][index];
	}
	Entry& GetLastEntry(unsigned int task_id)
	{
		return task_entries[task_id][GetEntryCount(task_id) - 1];
	}
	int GetTaskCount(unsigned int task_id)
	{
		if (task_entries.count(task_id) == 0)
			return 0;
		return task_entries.size();
	}
	void InputTry(unsigned int task_id, bool success_flag, double time, int action_count)
	{
		if (GetEntryCount(task_id) == 0 || GetLastEntry(task_id).IsQuitted() || GetLastEntry(task_id).IsCompleted())
		{
			StartNewEntry(task_id);
		}
		GetLastEntry(task_id).InputTry(success_flag, time, action_count);
	}

	vector<double> GetDevelopCurve(int task_id)
	{
		vector<double> result;
		for (auto entry : task_entries[task_id])
		{
			result.push_back(entry.GetPassRatio());
		}
		return result;
	}
	double GetAverageDevelopRatio()
	{
		return 0;
	}
};

class DevelopData
{
private:
	unordered_map<int, PlayerData> players_data; // <player_id, player_data>
	TaskList taskList;
	Filter fil;

	int total_playtime; // in sec

////: LoadData
private:
	short ExamineCommand(const string& line)
	{
		char firstChar = line.at(0);
		if (firstChar == '#')
		{
			string command = line.substr(1, line.size() + 1);
			if (command.compare("END") == 0)
				return 9;
			else if (command.compare("Task") == 0)
				return 0;
			else if (command.compare("Data") == 0)
				return 1;
		}
		else if (firstChar == 'P')
		{
			return 10;
		}
		return -1;
	}

	void LoadTask(string& line)
	{
		// Initiate indexes and get task_id
		int sIndex = line.find('|');
		int task_id = stoi(line.substr(0, sIndex));
		line = line.substr(sIndex + 1, line.size());

		// get task_name
		sIndex = line.find('|');
		string temp = line.substr(0, sIndex);

		// get task_description
		line = line.substr(sIndex + 1, line.size());

		//Insert the task into list
		taskList.InsertTask(task_id, temp, line);
	}
	void UpdatePlayerData(int player_id, string& line)
	{
		int sIndex = 0;
		int task_id = -1;
		bool sFlag = false;
		double tSpent = 0;
		string substring; // using for reduce the calculating time
		while (line.size() > 0)
		{
			if (line.at(0) == '\n')
			{
				break;
			}
			if (line.at(0) == 'T')
			{
				if (line.size() - 1 == 0)
					break;
				sIndex = line.find('=');
				task_id = stoi(line.substr(1, sIndex));
				line = line.substr(sIndex + 1, line.size());
			}
			if (line.at(0) == '!') //This entry has quit
			{
				line = line.substr(1, line.size());
				players_data[player_id].GetLastEntry(task_id).SetQuit();
				continue;
			}

			// Get substring to get a "try"
			sIndex = line.find('>');
			if (sIndex == -1)
				break;

			substring = line.substr(0, sIndex);
			line = line.substr(sIndex + 1, line.size());


			// success flag
			sIndex = substring.find('|');
			sFlag = (stoi(substring.substr(0, sIndex)) != 0);
			substring = substring.substr(sIndex + 1, substring.size());
			// time spent and action count
			sIndex = substring.find('|');
			tSpent = stod(substring.substr(0, sIndex));
			substring = substring.substr(sIndex + 1, substring.size());

			players_data[player_id].InputTry(task_id, sFlag, tSpent, stoi(substring));
		}
		//cout << "------" << players_data[player_id].GetName() << " -> " << taskList.GetTask(task_id).name << " : number of entry = "<<players_data[player_id].GetEntryCount(task_id) << ", number of tries : " << players_data[player_id].GetTotalTryCount(task_id) <<endl;
	}

	int LoadPlayerData(string& line)
	{
		// offset the new player line tag.
		line = line.substr(2, line.size());

		// initiate indexes and get player_id
		int sIndex = line.find('|');
		int player_id = stoi(line.substr(0, sIndex));
		line = line.substr(sIndex + 1, line.size());

		// get player_name
		sIndex = line.find(';');
		players_data[player_id].Init(player_id, line.substr(0, sIndex));
		line = line.substr(sIndex + 1, line.size());

		//cout << "====================== start load [" << players_data[player_id].GetName() << "] =============================" << endl;

		if (line.size() > 0)
			UpdatePlayerData(player_id, line);
		return player_id;
	}

public:
	int GetTotalPlayerCount()
	{
		return players_data.size();
	}
	void LoadData(string address)
	{
		//Initiate the data file
		ifstream data_file;
		data_file.open(address);
		if (data_file.is_open() == false)
		{
			cout << "File input stream has error, cannot open at: [" << address << "]" << endl;
			return;
		}

		// Initiate varibles
		string dataline;
		short command = -1;
		short section = -1; // 0 = load task list, 1 = players' data section
		int current_player_id = 0;
		while (getline(data_file, dataline, '\n'))
		{
			command = ExamineCommand(dataline);
			if (command == 9)
				break;
			else if (command == 0)
				section = 0;
			else if (command == 1)
				section = 1;

			if (section == 0)
			{
				if (command < 0)
				{
					//New line task_data
					LoadTask(dataline);
				}
			}
			else if (section == 1)
			{
				if (command == 10)
				{
					//New linae player_data
					current_player_id = LoadPlayerData(dataline);
				}
				else if (command != 1)
				{
					UpdatePlayerData(current_player_id, dataline);
				}
			}
		}
		cout << "DATA LOADED." << endl;
		data_file.close();
	}
	TaskList& GetTaskList() { return taskList; }
	int GetTotalNumberOfPlayers() { return players_data.size(); }
	////: UpdateFilter
	//Disabled

	////: Get and Pre-treat data 
		//<task_id, {remain number, remain ratio, quit number, quitRatio = NumberOfQuits/numberOfEnters}>
	void GetData4PlayerRemain(map<int, vector<double>>& rData)
	{
		int remainNumber = 0;
		int quitNumber = 0;
		int previousEnters = players_data.size();

		rData[0].resize(4);
		rData[0][0] = previousEnters;
		rData[0][1] = 1;
		rData[0][2] = 0;
		rData[0][3] = 0;

		for (auto task : taskList.GetSequence())
		{
			remainNumber = 0;
			quitNumber = 0;
			for (auto player : players_data)
			{
				if (player.second.DoesEnterTask(task.second))
				{
					remainNumber++;
					if (player.second.DoesGiveUp(task.second))
					{
						quitNumber++;
					}
				}
			}

			rData[task.second].resize(4);
			rData[task.second][0] = remainNumber;
			rData[task.second][1] = (double)remainNumber / players_data.size();
			rData[task.second][2] = quitNumber;
			rData[task.second][3] = (remainNumber != 0 ? (double)quitNumber / remainNumber : 0);

			previousEnters = remainNumber;
		}
		for (auto data : rData) { cout << data.first << ": Remains=" << data.second[0] << ", RemainRatio=" << data.second[1] << ", Quits=" << data.second[2] << ", QuitRatio=" << data.second[3] << endl; }
	}

	//<entry_index, <successRatio, number of players in the ratio>>
	unordered_map<int, pair<unordered_map<double, int>, unordered_map<int, int>>> GetDifficultyCurve(int task_id)
	{
		unordered_map<int, pair<unordered_map<double, int>, unordered_map<int, int>>> dCurve;

		double passRatio = 0;
		for (auto player : players_data) 
		{
			for (int i = 0; i < player.second.GetEntryCount(task_id); ++i) 
			{
				passRatio = player.second.GetEntry(task_id, i).GetPassRatio();
				if (passRatio != 0)
					dCurve[i].first[passRatio]++;
				dCurve[i].second[player.second.GetEntry(task_id, 1).GetFailureCount()]++;
			}
		}
		return dCurve;
	}
};

class Visualizer 
{
	DevelopData playerData;
	map<int, vector<double>> RemainingData;
	string dataAddress = "Empty";
	Filter filter;
	unsigned int selectedTask = 0;
	unsigned int lastExamedTask_id = 0;
public: 
	static Visualizer &Get() { static Visualizer v; return v;}
	Visualizer() 
	{
		
	}
	void SetDataAddress(string address) 
	{
		dataAddress = address;
	}
	string GetDataAddress() { return dataAddress; }
	bool LoadPlayerData(string address)
	{
		if (address.compare("Empty") == 0)
			return false;
		playerData.LoadData(address);
		return true;
	}
	int GetTotalPlayerCount() { return playerData.GetTotalPlayerCount(); }
	map<int, string> GetTasklistCopy() 
	{
		return playerData.GetTaskList().GetMapCopy();
	}
	string GetTaskNameSystemString(int task_id)
	{
		return playerData.GetTaskList().GetTask(task_id).name;
	}
	Filter& GetFilter() 
	{
		return filter;
	}
	int SetSelectedTask(string task_name) 
	{
		selectedTask = playerData.GetTaskList().GetKey(task_name);
		return selectedTask;
	}
	int GetSelectedTask() 
	{
		return selectedTask;
	}
	bool CheckSelectedTask() 
	{
		return (selectedTask > 0 && selectedTask != lastExamedTask_id);
	}
	
	map<int, vector<double>> GetRemainingData() 
	{
		map<int, vector<double>> RemainingData;
		playerData.GetTaskList().PutAll2Sequence();
		playerData.GetData4PlayerRemain(RemainingData);
		return RemainingData;
	}
	unordered_map<int, pair<unordered_map<double, int>, unordered_map<int, int>>> GetDifficultyCurve() 
	{
		lastExamedTask_id = selectedTask;
		return playerData.GetDifficultyCurve(selectedTask);
	}
};