#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

using namespace std;

class SaveData
{
private:

	vector<string> names;
	vector<int> scores;
	int numPlayers;

	void orderScores();


public:
	SaveData();

	void load(string const& filename);
	void save(string const& filename, string const& name, int score);
	
	inline string getPlayerName(int index) const { return this->names[index]; }
	inline int getPlayerScore(int index) const { return this->scores[index]; }
	inline int getNumPlayers() const { return this->numPlayers; }


};