#pragma once
#include <conio.h>
#include <chrono>
#include <ctime>   
#include <iostream>

using namespace std;

class PodiumDataSaver
{
public:
	PodiumDataSaver(int, int, int, char[20], chrono::duration<double>);
	~PodiumDataSaver();
	int get_steps();
	int get_points();
	int get_position();
	string get_user_nick();
	chrono::duration<double> get_elapsed_time();
private:
	int steps;
	std::chrono::duration<double> elapsed_seconds;
	int points;
	int position;
	string user_nick;
};

