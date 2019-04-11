#include <iostream>
#include "Knight.h"
#include <fstream>
#include "UserInterface.h"

using namespace std;

int main() {
	ifstream myFile;
	Knight back_end;
	UI front_end;
	bool playing = true;
	int player_move, AI_move, previous_move;
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
	front_end.action(10);//Starting position
	previous_move = 10;
	while (playing) {
		front_end.to_string();
		cout << "Your turn" << endl;
		cin >> player_move;
		cout << endl;
		if (back_end.is_legal_move(previous_move, player_move)) {
			back_end.remove_edge(previous_move);
			front_end.action(player_move);
			AI_move = back_end.decision(player_move);
			previous_move = AI_move;
			if (AI_move == -1) {
				cout << "Computer lost" << endl;
				playing = false;
			}
			front_end.action(AI_move);
			if (back_end.player_lost(AI_move)) {
				front_end.to_string();
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