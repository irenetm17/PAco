#pragma once
#include <iostream>

using namespace std;

class RankingStats
{
	int maxLevel;
	int enemiesDefeated;
	int powerUps;

public:
	RankingStats() :maxLevel(0), enemiesDefeated(0), powerUps(0) {}

	void inline Print()
	{
		cout << " max level = " << maxLevel << "; enemies defeated = " << this->enemiesDefeated << ",power ups = " << this->powerUps << endl;
	}

	void inline IncreaseSecrets() { this->powerUps++; }
	void inline IncreaseEnemiesDefeated() { this->enemiesDefeated++; }
	void inline IncreaseMaxLevel() { this->maxLevel++; }
};

