#include <iostream> 
#include <time.h>
using namespace std;

const int width = 32;
const int height = 14;
const int coords_size = 2;

void print_field(char field[height][width]) {
	int i = 0;
	int j = 0;
	for (i; i < height; i++) {
		for (j; j < width; j++) {
			if (field[i][j] == '-') {
				cout << "\033[3;40;30m  \033[0m";
			}
			else if (field[i][j] == '@') {
				cout << "\033[3;44;30m  \033[0m";
			}
			else if (field[i][j] == '%') {
				cout << "\033[3;47;30m  \033[0m";
			}
			else if (field[i][j] == '#') {
				cout << "\033[3;42;30m  \033[0m";
			}
		}
		j = 0;
		cout << "\n";
	}
	cout << "\n";
}

int find_cell(char field[height][width], int* coords, int ship_long, int direction) {
	int x = (rand() + 2) % 9;
	int y = (rand() + 1) % 9;

	coords[0] = x;
	coords[1] = y;
}

bool is_occupied(char field[height][width], int* coords, int ship_long, int direction) {
	int x = coords[0];
	int y = coords[1];
	if (field[x][y] == '@') {
		if (field[x - 1][y] == '@' && field[x][y - 1] == '@' && field[x - 1][y - 1] == '@' && field[x + 1][y] == '@' && field[x][y + 1] == '@' && field[x + 1][y + 1] == '@' && field[x + 1][y - 1] == '@' && field[x - 1][y + 1] == '@') {
			if (ship_long == 1) {
				return false;
			}
			else if (ship_long == 2) {
				if (direction == 1) {
					if (field[x][y - 2] == '@' && field[x - 1][y - 2] == '@' && field[x + 1][y - 2] == '@') {
						return false;
					}
					else if (field[x][y + 2] == '@' && field[x - 1][y + 2] == '@' && field[x + 1][y + 2] == '@') {
						return false;
					}
				}
				if (direction == 2) {
					if (field[x - 2][y] == '@' && field[x - 2][y - 1] == '@' && field[x - 2][y + 1] == '@') {
						return false;
					}
					else if (field[x + 2][y] == '@' && field[x + 2][y - 1] == '@' && field[x + 2][y + 1] == '@') {
						return false;
					}
				}
			}
		}
	}
	return true;
}

void create_field(char field[height][width]) {
	int single_deck = 4;
	int double_decker = 3;
	int triple_decker = 2;
	int four_decker = 1;
	int all_ships = 10;
}

int main() {
	srand(time(NULL));
	int coords[coords_size] = {0, 0};
	char field[height][width] = { {"-------------------------------"},
								  {"############-------############"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"#@@@@@@@@@@#-------#@@@@@@@@@@#"},
								  {"############-------############"},
								  {"-------------------------------"} };

	create_field(field);
	print_field(field);
	return 0;
}
