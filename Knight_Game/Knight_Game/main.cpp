#include <iostream>
#include "Knight.h"
#include <fstream>

using namespace std;

int main() {
	ifstream myFile;
	Knight game;
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
	game.to_string();
	cout << endl<<endl;
	game.remove_edge(2);
	game.to_string();
	return 0;
}