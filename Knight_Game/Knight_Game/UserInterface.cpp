#include "UserInterface.h"
#include <iostream>
#include <iomanip>

UI::UI() {
	board = new std::string*[4];
	int count = 0;
	for (int i = 0; i < 4; i++) {
		board[i] = new std::string[4];
		for (int j = 0; j < 4; j++) {
			board[i][j] = std::to_string(count);
			count++;
		}
	}
}
void UI::action(int move) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == std::to_string(move)) {
				board[i][j] = "K";
				prev_x = i;
				prev_y = j;
				break;
			}
		}
	}
	to_string();
	board[prev_x][prev_y] = " ";
}
void UI::to_string() {
	std::cout << "----------------" << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == "K") {
			}
			std::cout << std::setw(3)<< board[i][j];
			std::cout << "|";
		}
		std::cout <<std::endl<<"----------------"<<std::endl;
	}
}
UI::~UI() {
	for (int i = 0; i < 4; i++)
		delete[] board[i];
	delete[] board;
}