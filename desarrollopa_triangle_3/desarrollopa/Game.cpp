#include "Game.h"
#include <iostream>


void Game::Init()
{
	cout << "[GAME] Init..." << endl;
	Scene* menu = new Scene(false, Vector3D(0, 0, 10));
	Scene* juego = new Scene(true, Vector3D(0, 0, 50));
	Scene* opciones = new Scene(false, Vector3D(0, 0, 10));
	Scene* ranking = new Scene(false, Vector3D(0, 0, 10));
	Scene* scoreScene = new Scene(false, Vector3D(0, 0, 10));

	this->totalPlayerScore = 0;

	Teapot* teapot1 = new Teapot();
	teapot1->SetPosition(Vector3D(0.0, 0.0, 0.0));
	teapot1->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	teapot1->SetOrientationSpeed(Vector3D(0.0, 15.0, 15.0));
	teapot1->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	menu->AddGameObject(teapot1);
	this->mainScene.push_back(teapot1);

	Text* text1 = new Text("[ PLAY ]");
	text1->SetPosition(Vector3D(-1.0, 3.0, 0.0));
	text1->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text1->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text1->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	menu->AddGameObject(text1);
	this->mainScene.push_back(text1);
	mainSceneIndex = 1;

	Text* text2 = new Text("[ OPTIONS ]");
	text2->SetPosition(Vector3D(-1.0, 1.0, 0.0));
	text2->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text2->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text2->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	menu->AddGameObject(text2);
	this->mainScene.push_back(text2);

	Text* text3 = new Text("[ RANKING ]");
	text3->SetPosition(Vector3D(-1.0, -1.0, 0.0));
	text3->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text3->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text3->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	menu->AddGameObject(text3);
	this->mainScene.push_back(text3);

	Text* text4 = new Text("[ EXIT ]");
	text4->SetPosition(Vector3D(-1.0, -3.0, 0.0));
	text4->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text4->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text4->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	menu->AddGameObject(text4);
	this->mainScene.push_back(text4);

	Text* text5 = new Text("[ OPTIONS ]");
	text5->SetPosition(Vector3D(-1.0, 4.0, 0.0));
	text5->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text5->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text5->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	opciones->AddGameObject(text5);

	Text* text6 = new Text("[ RANKING ]");
	text6->SetPosition(Vector3D(-1.0, 4.0, 0.0));
	text6->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	text6->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text6->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	ranking->AddGameObject(text6);

	saveScoreText = new Text{ "SCORE: " };
	saveScoreText->SetPosition(Vector3D(-1.0, 0.0, 8.0));
	saveScoreText->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	saveScoreText->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	saveScoreText->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scoreScene->AddGameObject(saveScoreText);

	saveNameText = new Text{ "NAME: ______" };
	saveNameText->SetPosition(Vector3D(-1.0, -0.4, 8.0));
	saveNameText->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	saveNameText->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	saveNameText->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	scoreScene->AddGameObject(saveNameText);
	playername = "";

	//scene1->GetCamera()->SetSpeed(Vector3D(0.0, 0.0, 0.0));

	/*
	EmmiterConfiguration config(10, 1000, new Sphere(), true);
	Emmiter* em = new Emmiter(config);
	scene1->AddGameObject(em);

	EmmiterConfiguration configur(50, 1000, new Torus(), true);
	Emmiter* as = new Emmiter(configur);
	scene1->AddGameObject(as);*/


	Text* text100 = new Text("uwu");
	text100->SetPosition(Vector3D(0.0, 0.0, 1.0));
	text100->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	text100->SetOrientationSpeed(Vector3D(0.0, 0.0, 0.0));
	text100->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	juego->AddGameObject(text100);

	/*
	Cube* cube1 = new Cube();
	cube1->SetPosition(Vector3D(3.0, 2.0, 0.0));
	cube1->SetColor(Color(0.8f, 0.7f, 0.6f, 0.4f));
	cube1->SetOrientationSpeed(Vector3D(1.0, 0.0, 3.0));
	cube1->SetSpeed(Vector3D(0.01, 0.02, 0.01));
	menu->AddGameObject(cube1);

	Sphere* sphere1 = new Sphere();
	sphere1->SetPosition(Vector3D(0.0, 4.0, 0.0));
	sphere1->SetColor(Color(0.4f, 0.4f, 0.9f, 0.8f));
	sphere1->SetSpeed(Vector3D(0.01, 0.01, 0.01));
	menu->AddGameObject(sphere1);

	Cylinder* cylinder1 = new Cylinder();
	cylinder1->SetPosition(Vector3D(7.0, 1.0, 0.0));
	cylinder1->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	cylinder1->SetColor(Color(0.6f, 0.1f, 0.7f, 1.0f));
	menu->AddGameObject(cylinder1);*/

	Torus* torus1 = new Torus();
	torus1->SetPosition(Vector3D(1.0, 2.0, 0.0));
	torus1->SetOrientationSpeed(Vector3D(0.0, 1.0, 0.0));
	juego->AddGameObject(torus1);

	//Instanciamos un loader para leer el archivo obj
	ModelLoader* loader = new ModelLoader();
	//fijamos la escala a 2 para que el objeto sea de un tama�o mayor
	loader->SetScale(1.0);
	loader->LoadModel("..\\3dModels\\heart.obj");
	//una vez cargado el modelo, instanciamos un Model usando memoria din�mica
	Model* heart = new Model();
	//Asignamos el modelo del loader a lo apuntado por el puntero llamado bolt
	*heart = loader->GetModel();
	//lo colocamos m�s cerca del centro de la escena
	heart->SetPosition(Vector3D(4, 4, 0));
	//le damos velocidad de orientaci�n...
	heart->SetOrientationSpeed(Vector3D(0, 0.2, 0));
	heart->SetColor(Color(1.0, 0.0, 0.0, 1.0));

	//aqu� a�adimos el modelo a la escena
	juego->AddGameObject(heart);

	//Sobre el resultado:
	// �por qu� no gira sobre s� mismo sino con un desplazamiento?
	// �qu� pasa con el color?

	this->scenes.push_back(menu);       // escena 0
	this->scenes.push_back(juego);      // escena 1
	this->scenes.push_back(opciones);   // escena 2
	this->scenes.push_back(ranking);    // escena 3
	this->scenes.push_back(scoreScene); // escena 4
	this->activeScene = menu;
}

void Game::Render()
{
	this->activeScene->Render();
}

void Game::Update(const float& time)
{
	//cout << "[GAME] Update..." << endl;
	//this->activeScene->Update();
	milliseconds currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	if ((currentTime.count() - this->initialMilliseconds.count()) - this->lastUpdatedTime > UPDATE_PERIOD)
	{
		this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdatedTime = currentTime.count() - this->initialMilliseconds.count();

	}

	this->mainScene[0]->SetPosition(this->mainScene[mainSceneIndex]->GetPosition() + Vector3D(-1.0, 0.0, 0.0)); 
	
}

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//cout << "tecla pulsada: " << key << endl;
	cout << "Tecla presionada: {'" << key << "' = '" << (int)(key) << "'}\n";

	int index = (key - '0') - 1; ////////SI PULSAS 1 Y 2 CAMBIA ENTRE LAS ESCENAS
	
	if (index < this->scenes.size())
	{
		this->activeScene = this->scenes[index];
	}
	this->activeScene->ProcessKeyPressed(key, px, py);

	int active;
	for (int i = 0; i < this->scenes.size();i++) 
	{
		if (this->activeScene == this->scenes[i]) { active = i; }
	}
	switch (active)
	{
	case 0: //escena activa : menu
		if (((key == 'w') || (key == 'W')) && (mainSceneIndex > 1))	{mainSceneIndex--;}
		if (((key == 's') || (key == 'S')) && (mainSceneIndex < 4))	{mainSceneIndex++;}

		if ((key == '\n' || key == 13)) //esta tecla es el intro
		{
			if(mainSceneIndex==4){exit(0);} //           EXIT
			else if(mainSceneIndex == 3)  //             RANKING
			{

				saveData.load("../../Data/save.sav");

				//resetear el top 10 del ranking
				for (int i = 0; i < 10; ++i)
				{
					std::string txt = std::to_string(1 + i) + ") --- : ---";
					rankingTextList[i]->SetText(txt);
				}
				//mostrar el top 10 del ranking
				for (int i = 0; i <  saveData.getNumPlayers(); ++i)
				{
					std::string txt = std::to_string(1 + i) + ") " + saveData.getPlayerName(i) + " : " + std::to_string(saveData.getPlayerScore(i));
					rankingTextList[i]->SetText(txt);
				}
			}
			else{ this->activeScene = this->scenes[mainSceneIndex]; }
		}
		break;
	case 1://escena activa : juego
		if ((key == '\n' || key == 13))
		{
			this->activeScene = this->scenes[0];
		}
		break;
	case 2://escena activa : opciones
		if ((key == '\n' || key == 13))
		{
			this->activeScene = this->scenes[0];
		}

		break;
	case 3://escena activa : ranking
		if ((key == '\n' || key == 13))
		{
			this->activeScene = this->scenes[0];
		}
		break;
	case 4:
		this->saveScoreText->SetText("SCORE: " + to_string(this->totalPlayerScore));      //esto habra que ponerlo cuando se llame a la activacion de esta escena
		if (!playername.empty() && (key == '\n' || key == '\r'))
		{
			saveData.save("../../Data/save.sav",playername,totalPlayerScore); ////////////////////////////////////////////////
			totalPlayerScore = 0;
			playername = "";
			this->activeScene = this->scenes[0];
		}
		else if (key == 8 && playername.length() > 0)
		{
			playername.pop_back();
			this->saveNameText->SetText("NAME: " + playername);
		}
		else if (playername.length() < 6 && (isalpha(key) || isdigit(key)))
		{
			playername.push_back(key);
			//playername += key;
			this->saveNameText->SetText("NAME: " + playername);
		}
		cout << "LONGITUD: " << playername.length() << "\n";
		cout << "PLAYER NAME: "<< playername <<"\n";
		break;
	default:
		cout << "Este caso no debería ser posible, si has llegado aquí, algo se ha roto muy fuertemente.\n";
		break;
	}

}

void Game::ProcessSpecialKeyPressed(int key, int x, int y)
{
	std::cout << "Tecla especial presionada: {'" << key << "', " << x << ", " << y << "}\n";
	if ((key == '\n' || key == '\r'))
	{
		this->activeScene = this->scenes[3];
	}

	/*for (auto controller : Controller::gameControllers)
	{
		controller->ProcessSpecialKeyPressed(key, x, y);
	}
	if (menuScene.getIsActive())
	{
		if (key == 101)
		{
			menuOption--;
		}

		if (key == 103)
		{
			menuOption++;
		}

		menuOption = Math::clamp<int>(menuOption, 0, 3);
	}*/


}

void Game::ProcessKeyReleased(unsigned char key, int x, int y)
{
	std::cout << "Tecla soltada: {'" << key << "'}\n";
}

void Game::ProcessSpecialKeyReleased(int key, int x, int y)
{
	std::cout << "Tecla especial soltada: {'" << key << "', " << x << ", " << y << "}\n";
}

void Game::ProcessMouseClicked(int button, int state, int x, int y)
{
	cout << "[GAME] Click:" << button << endl;
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "[GAME] Movement:" << x << ", " << y << endl;
	this->activeScene->ProcessMouseMovement(x, y);
}
