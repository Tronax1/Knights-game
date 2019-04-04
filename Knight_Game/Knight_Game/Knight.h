#pragma once
#ifndef KNIGHT
#define KNIGHT

class Knight {

private:
	int **board; //Adjacency matrix
public:
	Knight();
	int heuristic(int **state);
	void to_string();
	~Knight();
};


#endif

