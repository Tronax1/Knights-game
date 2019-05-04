#include <iostream>
#include "Knight.h"
#include <fstream>
#include "UserInterface.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	ifstream myFile;
	Knight back_end;
	UI board_display;
	bool playing = true;
	int player_move, AI_move, previous_move, starting_move;
	myFile.open("Vertices.txt");
	int vertex_one, vertex_two;
	if (!myFile) {
		cout << "Error opening file" << endl;
		return 0;
	}
	while (myFile>>vertex_one) {
		myFile >> vertex_two;
		back_end.add_edge(vertex_one, vertex_two);
	}
	myFile.close();
	starting_move = rand() % 16;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	board_display.action(starting_move);//Starting position
	previous_move = starting_move;
	while (playing) {
		cout << "Your turn"<<endl;
		cin >> player_move;
		cout << endl;
		if (back_end.is_legal_move(previous_move, player_move)) {
			back_end.remove_edge(previous_move);
			board_display.action(player_move);
			cout << endl;
			back_end.delay();
			AI_move = back_end.decision(player_move);
			previous_move = AI_move;
			if (AI_move == -1) {
				cout << "Computer lost" << endl;
				return 0;
			}
			board_display.action(AI_move);
			if (back_end.player_lost(AI_move)) {
				cout << "You lost" << endl;
				playing = false;
			}
		}
		else {
			cout << "Not a valid move" << endl;
		}
	}
	return 0;
}