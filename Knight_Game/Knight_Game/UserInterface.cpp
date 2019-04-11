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
	int x = 0, y = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == std::to_string(move)) {
				board[i][j] = "K";
				x = i;
				y = j;
				break;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == "K" && i != x && j != y) {
				board[i][j] = " ";
			}
		}
	}
}
void UI::to_string() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
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