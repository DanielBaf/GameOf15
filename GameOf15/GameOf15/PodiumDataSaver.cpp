#include "PodiumDataSaver.h"

PodiumDataSaver::PodiumDataSaver(int steps, int position, int points, char nickname[20], chrono::duration<double> elapsed_seconds)
{
	this->steps = steps;
	this->position = points;
	this->points = points;
	this->elapsed_seconds = elapsed_seconds;
	this->user_nick = nickname;
}

PodiumDataSaver::~PodiumDataSaver()
{
}

int PodiumDataSaver::get_points() {
	return this->points;
}

int PodiumDataSaver::get_steps() {
	return this->steps;
}

int PodiumDataSaver::get_position() {
	return this->position;
}

string PodiumDataSaver::get_user_nick(){
	return this->user_nick;
}

chrono::duration<double> PodiumDataSaver::get_elapsed_time() {
	return this->elapsed_seconds;
}