#pragma once
#include <conio.h>
#include <chrono>
#include <ctime>   

using namespace std;

class PodiumDataSaver
{
public:
	PodiumDataSaver(int, int, int, char[20], std::chrono::duration<double>);
	~PodiumDataSaver();
private:
	int steps;
	std::chrono::duration<double> elapsed_seconds;
	int points;
	int position;
	char nickname[20];
};

