#pragma once
#include <conio.h>
#include <chrono>
#include <ctime>   
#include <iostream>

using namespace std;

class PodiumDataSaver
{
public:
	PodiumDataSaver();
	PodiumDataSaver(int, int, int, string, chrono::duration<double>);
	~PodiumDataSaver();
	int get_steps();
	int get_points();
	int get_position();
	string get_user_nick();
	chrono::duration<double> get_elapsed_time();
	void set_position(int);
private:
	int steps;
	std::chrono::duration<double> elapsed_seconds;
	int points;
	int position;
	string user_nick;
};

