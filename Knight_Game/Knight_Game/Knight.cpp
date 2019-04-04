#include "Knight.h"
#include <iostream>

Knight::Knight() {
	board = new int*[16];
	for (int i = 0; i < 16; i++) {
		board[i] = new int[16];
		for (int j = 0; j < 16; j++) {
			board[i][j] = 0;
		}
	}
}
int Knight::heuristic(int **state) {

}
void Knight::to_string() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}
Knight::~Knight() {
	for (int i = 0; i < 16; i++)
		delete[] board[i];
	delete[] board;
}