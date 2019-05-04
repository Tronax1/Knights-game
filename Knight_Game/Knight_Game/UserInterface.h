#pragma once
#ifndef USERINTERFACE
#define USERINTERFACE
#include <string>

class UI {

private:
	std::string **board;
	int prev_x = 0;
	int prev_y = 0;
public:
	UI();
	void action(int move);
	void to_string();
	~UI();
};


#endif
