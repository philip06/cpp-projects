#include <algorithm>
#include <iostream>
#include <vector>

#include "solver.hpp"

Solver::Solver() 
: contents{ // Sudoku contents
{0,0,7,0,0,1,3,0,0},
{3,0,0,0,5,0,6,0,0},
{5,0,8,0,3,0,0,0,4},
{0,8,0,0,6,0,9,0,0},
{7,0,0,0,0,0,0,0,6},
{0,0,4,0,1,0,0,7,0},
{2,0,0,0,8,0,4,0,3},
{0,0,6,0,7,0,0,0,8},
{0,0,5,9,0,0,7,0,0}
}
{}

void Solver::checkRow(int rowNum) {
    vector<int> exclusions;
    
    for (int i = 0; i < 9; i++) { // Find numbers already in row
        if (this->contents[rowNum][i] != 0) {
            //std::cout << this->contents[rowNum][i] << std::endl;
            exclusions.push_back(this->contents[rowNum][i]);
        }
    }
    
    for (int i = 1; i < 10; i++) { // Add remaining numbers to possibilites
        if (std::find(exclusions.begin(), exclusions.end(), i) == exclusions.end()) {
            rowPossibilities.push_back(i);
        }
    } 
}

void Solver::checkColumn(int colNum) {
    vector<int> exclusions;

    for (int i = 0; i < 9; i++) { // Find numbers already in column
        if (this->contents[i][colNum] != 0) {
            //std::cout << this->contents[rowNum][i] << std::endl;
            exclusions.push_back(this->contents[i][colNum]);
        }
    }

    for (int i = 1; i < 10; i++) { // Add remaining numbers to possibilities
        if (std::find(exclusions.begin(), exclusions.end(), i) == exclusions.end()) {
            columnPossibilities.push_back(i);
        }
    }
}

void Solver::checkBox(int colNum, int rowNum) {
    vector<int> exclusions;
    int rowBlock[3];
    int colBlock[3];

    if (rowNum < 4) {
        rowBlock[0] = 0;
        rowBlock[1] = 1;
        rowBlock[2] = 2;
    } else if (rowNum >= 4 && rowNum < 7) {
        rowBlock[0] = 3;
        rowBlock[1] = 4;
        rowBlock[2] = 5;
    } else {
        rowBlock[0] = 6;
        rowBlock[1] = 7;
        rowBlock[2] = 8;
    }

    if (colNum < 4) {
        colBlock[0] = 0;
        colBlock[1] = 1;
        colBlock[2] = 2;
    } else if (colNum >= 4 && colNum < 7) {
        colBlock[0] = 3;
        colBlock[1] = 4;
        colBlock[2] = 5;
    } else {
        colBlock[0] = 6;
        colBlock[1] = 7;
        colBlock[2] = 8;
    }

    for (int i = 0; i < 3; i++) { // Find numbers already in box
        for (int g = 0; g < 3; g++) {
            if (this->contents[rowBlock[g]][colBlock[i]] != 0) {
                exclusions.push_back(this->contents[rowBlock[g]][colBlock[i]]);
            }
        }
    }

    for (int i = 1; i < 10; i++) { // Add remaining numbers to possibilities
        if (std::find(exclusions.begin(), exclusions.end(), i) == exclusions.end()) {
            boxPossibilities.push_back(i);
        }
    }
}
