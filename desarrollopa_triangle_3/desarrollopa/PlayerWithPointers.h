#pragma once
#include <iostream>
#include "RankingStats.h"


using namespace std;


class PlayerWithPointers
{
private:

	int lives;
	int points;
	string name;
	RankingStats* stats;

public:

	PlayerWithPointers(string nameArgument, int livesArgument = 3) :
		name(nameArgument), lives(livesArgument)
	{
		this->points = 0;
		this->stats = new RankingStats();
	};

	void inline SetName(string nameToSet) { this->name = nameToSet; }

	void inline Print() {
		cout << name << ": lives = " << lives << ", points = " << points << endl; stats->Print();
	}


	void inline DecreaseLives() { if (this->lives > 0) this->lives = this->lives - 1; }
	void inline IncreasePoints(int pointsToAdd) { this->points += pointsToAdd; }

	void inline SecretFound() { this->stats->IncreaseSecrets(); }

};

