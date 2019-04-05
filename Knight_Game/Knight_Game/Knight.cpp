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
int Knight::heuristic(int **state) {
	return 1;
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