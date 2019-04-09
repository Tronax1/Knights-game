#pragma once
#ifndef KNIGHT
#define KNIGHT

class Knight {

private:
	int **board; //Adjacency matrix
public:
	Knight();
	int heuristic(int **state, int pos);
	int decision(int **m, int curr);
	void add_edge(int i, int j);
	void remove_edge(int i);
	void to_string();
	~Knight();
};


#endif

