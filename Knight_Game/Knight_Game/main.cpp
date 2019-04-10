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
	int player_move, AI_move;
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
	back_end.remove_edge(10);//Deleting starting position
	while (playing) {
		front_end.to_string();
		cout << "Your turn" << endl;
		cin >> player_move;
		front_end.action(player_move);
		AI_move = back_end.decision(player_move);
		cout << AI_move << endl;
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
		back_end.remove_edge(AI_move);
	}
	return 0;
}