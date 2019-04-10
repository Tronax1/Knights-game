#include "Knight.h"
#include <iostream>
#include <iomanip>

Knight::Knight() {
	board = new int*[16];
	for (int i = 0; i < 16; i++) {
		board[i] = new int[16];
		for (int j = 0; j < 16; j++) {
			board[i][j] = 0;
		}
	}
}
int Knight::heuristic(int pos) {
	int ucount = 0;
	for (int i = 0; i < 16; i++) {
		if (board[pos][i] == 1) {
			ucount++;
		}
	}
	if (ucount == 0)
		return -1;
	return ucount;
}

int Knight::decision(int curr){
	int* counts = new int[16];
	int position = -1, lowest_h = 4;
	for (int j = 0; j < 16; j++) {
		counts[j] = -1;
	}
	for (int i = 0; i < 16; i++) {
		if (board[curr][i] == 1) {
			counts[i] = heuristic(i);
		}
	}
	for (int i = 0; i < 16; i++) {
		if (counts[i] > -1 && counts[i] <= lowest_h) {
			position = i;
			lowest_h = counts[i];
		}
	}
	remove_edge(curr);
	return position; //should analyze in main...if -1 returned, computer has lost
}
bool Knight::player_lost(int curr) {
	for (int i = 0; i < 16; i++) {
		if (board[curr][i] == 1)
			return false;
	}
	return true;
}
void Knight::add_edge(int i, int j) {

	board[i][j] = 1;
	board[j][i] = 1;
}
void Knight::remove_edge(int i) {

	for (int k = 0; k < 16; k++) 
		board[i][k] = 0;
	for (int l = 0; l < 16; l++) 
		board[l][i] = 0;
}
void Knight::to_string() {
	std::cout << " ";
	for (int i = 0; i < 16; i++)
		std::cout << std::setw(3)<<i;
	std::cout << std::endl<<std::endl;
	for (int i = 0; i < 16; i++) {
		std::cout << i;
		for (int j = 0; j < 16; j++) {
			std::cout << std::setw(3)<< board[i][j];
		}
		std::cout << std::endl;
	}
}
Knight::~Knight() {
	for (int i = 0; i < 16; i++)
		delete[] board[i];
	delete[] board;
}