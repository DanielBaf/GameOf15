#include "PodiumDataSaver.h"

PodiumDataSaver::PodiumDataSaver(int steps, int position, int points, char nickname[20], std::chrono::duration<double> elapsed_seconds)
{
	this->steps = steps;
	this->position = -1;
	this->points = points;
	this->elapsed_seconds = elapsed_seconds;
	this->nickname = nickname;
}

PodiumDataSaver::~PodiumDataSaver()
{
}