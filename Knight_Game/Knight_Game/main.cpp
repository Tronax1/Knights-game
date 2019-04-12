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
	UI front_end;
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
	front_end.action(starting_move);//Starting position
	previous_move = starting_move;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	while (playing) {
		front_end.to_string();
		cout << "Your turn"<<endl;
		cin >> player_move;
		cout << endl;
		if (back_end.is_legal_move(previous_move, player_move)) {
			back_end.remove_edge(previous_move);
			front_end.action(player_move);
			front_end.to_string();
			cout << endl;
			back_end.delay();
			AI_move = back_end.decision(player_move);
			previous_move = AI_move;
			if (AI_move == -1) {
				cout << "Computer lost" << endl;
				return 0;
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