

#include "marvin_404_not_found.hpp"
using namespace std;

/** @brief Read file and store in vector
 * @param file_path Path to file
 * @param grid Vector to store file
 * @param N Number of rows
*/

void read_file(char *file_path, vector<string> &grid, int &N) {
	ifstream file(file_path);
	if (!file.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		grid.push_back(line);
		N++;
	}
	file.close();
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
		return (1);
	}
	int N = 0;
	vector<string> grid;
	read_file(argv[1], grid, N);
	if (N == 0) {
		std::cout << "Error: File is empty" << std::endl;
		return (1);
	}
	int M = grid[0].size();
	solve(grid, N, M);
	return (0);
}
