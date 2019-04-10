#include <iostream>
#include "Knight.h"
#include <fstream>
#include "UserInterface.h"

using namespace std;

int main() {
	ifstream myFile;
	Knight game;
	UI display;
	bool playing = true;
	int player_move, AI_move;
	myFile.open("Vertices.txt");
	int vertex_one, vertex_two;
	if (!myFile) {
		cout << "Error opening file" << endl;
		return 0;
	}
	while (myFile>>vertex_one) {
		myFile >> vertex_two;
		game.add_edge(vertex_one, vertex_two);
	}
	myFile.close();
	display.action(10);
	game.remove_edge(10);
	while (playing) {
		display.to_string();
		cout << "Your turn" << endl;
		cin >> player_move;
		display.action(player_move);
		AI_move = game.decision(player_move);
		if (AI_move == -1) {
			cout << "Computer lost" << endl;
			playing = false;
		}
		display.action(AI_move);
	}
	return 0;
}