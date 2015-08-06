#include <iostream>
#include <vector>

#include "solver.hpp"

int main() {
    Solver solv;
    std::vector<int> possib;

    solv.checkColumn(0); // Obtain possible solutions base on current column
    solv.checkRow(0); //Obtain possible solutions base on current row
    solv.checkBox(0,0); //Obtain possible solutions base on current box
    possib.reserve( solv.rowPossibilities.size() + solv.columnPossibilities.size() + solv.boxPossibilities.size());
    possib.insert( possib.end(), solv.rowPossibilities.begin(), solv.rowPossibilities.end() );
    possib.insert( possib.end(), solv.columnPossibilities.begin(), solv.columnPossibilities.end() );
    possib.insert( possib.end(), solv.boxPossibilities.begin(), solv.boxPossibilities.end() ); // Merge the vectors
    for (std::vector<int>::const_iterator i = possib.begin(); i != possib.end(); ++i) // Output vector contents
        std::cout << *i << std::endl;
    return 0;
}
