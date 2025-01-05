#include "SaveData.h"

SaveData::SaveData()
	:names{}, scores{}, numPlayers{ 0 }
{}


void SaveData::load(string const& filename)
{
	this->names.clear();
	this->scores.clear();
	this->numPlayers = 0;

	try
	{
		//ifstream file;
		//file.open(filename);
		
		ifstream file(filename); // Intentar abrir el archivo en modo lectura
		if (!file) {
			// Si el archivo no existe, lo creamos
			ofstream createFile(filename); // Crea el archivo en modo escritura
			if (createFile) {cout << "Archivo no encontrado. Se ha creado un nuevo archivo: " << filename << std::endl;	}
			else {cerr << "Error: No se pudo crear el archivo." << std::endl;}  
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////  ERROR: NO SE PUDO CREAR EL ARCHIVO			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			
			
			file.open(filename);
		}
		else {
			std::cout << "Archivo encontrado: " << filename << std::endl;
		}






		while (file.good() && !file.eof())
		{
			string identifier, currname;
			int currscore;

			file >> identifier;
			file >> currname;
			file >> currscore;

			if (identifier[0] == 'p')
			{
				this->names.push_back(currname);
				this->scores.push_back(currscore);
				++numPlayers;
			}

		}

		file.close();
		this->orderScores();
	}
	catch (exception& e)
	{
		cout << "Could not read save data: "<< e.what() << endl;
	}
}

void SaveData::save(string const& filename, string const& name, int score)
{
	try
	{
		ofstream file;
		file.open(filename, ios_base::app);

		file << "p: " << name << " " << score << "\n";

		file.close();
	}
	catch (exception& e)
	{
		cout << "Could not write save data: " << e.what() << endl;
	}
}

void SaveData::orderScores()
{
	if (this->numPlayers <= 0) { return; }

	for (int i = 0; i < this->numPlayers; ++i)
	{
		for (int j = i; j < this->numPlayers; ++j)
		{
			if (scores[i] < scores[j])
			{
				int temp = scores[i];
				scores[i] = scores[j];
				scores[j] = temp;

				string tempName = names[i];
				names[i] = names[j];
				names[j] = tempName;
			}
		}
	}
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "p: " << names[i] << " : " << scores[i] << endl;
	}
}