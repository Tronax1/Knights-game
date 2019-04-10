#pragma once
#ifndef USERINTERFACE
#define USERINTERFACE
#include <string>

class UI {

private:
	std::string **board;
public:
	UI();
	void action(int move);
	void to_string();
	~UI();
};


#endif
