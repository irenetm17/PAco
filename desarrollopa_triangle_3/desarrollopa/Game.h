#pragma once
#include "Text.h"
#include "Emmiter.h"
#include "EmmiterConfiguration.h"
#include "Teapot.h"
#include "Cube.h"
#include "Sphere.h"
#include "Display.h"
#include "Torus.h"
#include "Cylinder.h"
#include "Scene.h"
#include "Triangle.h"
#include "Model.h"
#include "ModelLoader.h"
#include "SaveData.h"
#include <chrono>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;
using namespace std::chrono;

class Game
{
private:
	const double TIME_INCREMENT = 0.4;
	const long UPDATE_PERIOD = 10;

	milliseconds initialMilliseconds;
	long lastUpdatedTime;

	vector<Solid*> mainScene;
	int mainSceneIndex;

	int totalPlayerScore;
	string playername;
	Text *saveNameText, *saveScoreText;

	Text* rankingTextList[10];
	SaveData saveData;

	vector<Scene*> scenes;
	Scene* activeScene;

public:

	Game():activeScene(nullptr), initialMilliseconds(duration_cast<milliseconds>(system_clock::now().time_since_epoch())), lastUpdatedTime(0) {}

	void Init();
	void Render();
	void Update(const float& time);
	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessKeyReleased(unsigned char key, int x, int y);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClicked(int button, int state, int x, int y);
	void ProcessSpecialKeyPressed(int key, int x, int y);
	void ProcessSpecialKeyReleased(int key, int x, int y);

};