#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

//#include "../linkedlist/int/link.hpp"

using std::vector;

class Solver {
    public:
        Solver();
	void checkRow(int rowNum);
	void checkColumn(int colNum);
	void checkBox(int colNum, int rowNum);
    //private:
        int contents[9][9]; 
	vector<int> rowPossibilities;
	vector<int> columnPossibilities;
	vector<int> boxPossibilities;
	int value;
};

#endif
