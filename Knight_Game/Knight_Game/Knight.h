#pragma once
#ifndef KNIGHT
#define KNIGHT

class Knight {

private:
	int **board; //Adjacency matrix
public:
	Knight();
	int heuristic(int pos);
	int decision(int curr);
	bool player_lost(int curr);
	void add_edge(int i, int j);
	void remove_edge(int i);
	void to_string();
	~Knight();
};


#endif

