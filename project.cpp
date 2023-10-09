#include <iostream> 
#include <time.h>
using namespace std;

const int width = 32; //width of matrix
const int height = 14; //height of matrix
const int coords_size = 2; // coordinate array size


enum Directions{up = 1, down, left, right};



//function for displaying a matrix on the screen
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

//function for getting a random cell on the field
int* find_cell(char field[height][width], int* coords, int ship_long) {
	int x = (rand() % 10) + 1;
	int y = (rand() % 10) + 2;

	coords[0] = x;
	coords[1] = y;

	return coords;
}

int* find_enemy_cell(char field[height][width], int* enemy_coords, int ship_long) {
	int x = (rand() % 10) + 20;
	int y = (rand() % 10) + 2;

	enemy_coords[0] = x;
	enemy_coords[1] = y;

	return enemy_coords;
}

int direction_generation() {
	return (rand() % 2) + 1;
}


//function checking cell occupancy
bool is_occupied(char field[height][width], int* coords, int ship_long, int direction, int& second_direction) {
	int x = coords[0];
	int y = coords[1];



	if (field[x][y] == '@') {
		if (field[x - 1][y] != '%' && field[x][y - 1] != '%' && field[x - 1][y - 1] != '%' && field[x + 1][y] != '%' && field[x][y + 1] != '%' && field[x + 1][y + 1] != '%' && field[x + 1][y - 1] != '%' && field[x - 1][y + 1] != '%') {
			if (ship_long == 1) {
				return false;
			}
			else if (ship_long == 2) {
				if (direction == 1) {
					if (field[x][y - 2] == '@' && field[x - 1][y - 2] == '@' && field[x + 1][y - 2] == '@') {
						second_direction = up;
						return false;
					}
					else if (field[x][y + 2] == '@' && field[x - 1][y + 2] == '@' && field[x + 1][y + 2] == '@') {
						second_direction = down;
						return false;
					}
				}
				else if (direction == 2) {
					if (field[x - 2][y] == '@' && field[x - 2][y - 1] == '@' && field[x - 2][y + 1] == '@') {
						second_direction = Directions::left;
						return false;
					}
					else if (field[x + 2][y] == '@' && field[x + 2][y - 1] == '@' && field[x + 2][y + 1] == '@') {
						second_direction = Directions::right;
						return false;
					}
				}
			}
			else if (ship_long == 3) {
				if (direction == 1) {
					if (field[x][y - 2] == '@' && field[x - 1][y - 2] == '@' && field[x + 1][y - 2] == '@') {
						if (field[x][y - 3] == '@' && field[x - 1][y - 3] == '@' && field[x + 1][y - 3] == '@') {
							second_direction = up;
							return false;
						}
					}
					else if (field[x][y + 2] == '@' && field[x - 1][y + 2] == '@' && field[x + 1][y + 2] == '@') {
						if (field[x][y + 3] == '@' && field[x - 1][y + 3] == '@' && field[x + 1][y + 3] == '@') {
							second_direction = down;
							return false;
						}
					}
				}
				else if (direction == 2) {
					if (field[x - 2][y] == '@' && field[x - 2][y - 1] == '@' && field[x - 2][y + 1] == '@') {
						if (field[x - 3][y] == '@' && field[x - 3][y - 1] == '@' && field[x - 3][y + 1] == '@') {
							second_direction = Directions::left;
							return false;
						}
					}
					else if (field[x + 2][y] == '@' && field[x + 2][y - 1] == '@' && field[x + 2][y + 1] == '@') {
						if (field[x + 3][y] == '@' && field[x + 3][y - 1] == '@' && field[x + 3][y + 1] == '@') {
							second_direction = Directions::right;
							return false;
						}
					}
				}
			}

			else if (ship_long == 4) {
				if (direction == 1) {
					if (field[x][y - 2] == '@' && field[x - 1][y - 2] == '@' && field[x + 1][y - 2] == '@') {
						if (field[x][y - 3] == '@' && field[x - 1][y - 3] == '@' && field[x + 1][y - 3] == '@') {
							if (field[x][y - 4] == '@' && field[x - 1][y - 4] == '@' && field[x + 1][y - 4] == '@') {
								second_direction = up;
								return false;
							}
						}
					}
					else if (field[x][y + 2] == '@' && field[x - 1][y + 2] == '@' && field[x + 1][y + 2] == '@') {
						if (field[x][y + 3] == '@' && field[x - 1][y + 3] == '@' && field[x + 1][y + 3] == '@') {
							if (field[x][y + 4] == '@' && field[x - 1][y + 4] == '@' && field[x + 1][y + 4] == '@') {
								second_direction = down;
								return false;
							}
						}
					}
				}
				else if (direction == 2) {
					if (field[x - 2][y] == '@' && field[x - 2][y - 1] == '@' && field[x - 2][y + 1] == '@') {
						if (field[x - 3][y] == '@' && field[x - 3][y - 1] == '@' && field[x - 3][y + 1] == '@') {
							if (field[x - 4][y] == '@' && field[x - 4][y - 1] == '@' && field[x - 4][y + 1] == '@') {
								second_direction = Directions::left;
								return false;
							}
						}
					}
					else if (field[x + 2][y] == '@' && field[x + 2][y - 1] == '@' && field[x + 2][y + 1] == '@') {
						if (field[x + 3][y] == '@' && field[x + 3][y - 1] == '@' && field[x + 3][y + 1] == '@') {
							if (field[x + 4][y] == '@' && field[x + 4][y - 1] == '@' && field[x + 4][y + 1] == '@') {
								second_direction = Directions::right;
								return false;
							}
						}
					}
				}
			}

		}
	}
	return true;
}

void create_field(char field[height][width], int* coords) {
	int single_deck = 4;
	int double_decker = 3;
	int triple_decker = 2;
	int four_decker = 1;
	int all_ships = 10;
	
	int direction = direction_generation();
	int second_direction = 0;

	int x = 0;
	int y = 0;

	for (single_deck; single_deck > 0; single_deck--) {
		coords = find_cell(field, coords, 1);

		while (is_occupied(field, coords, 1, direction, second_direction)) {
			coords = find_cell(field, coords, 1);
		}

		x = coords[0];
		y = coords[1];

		field[x][y] = '%';

		all_ships--;
	}

	for (double_decker; double_decker > 0; double_decker--) {
		coords = find_cell(field, coords, 2);

		while (is_occupied(field, coords, 2, direction, second_direction)) {
			coords = find_cell(field, coords, 2);
			direction = direction_generation();
		}

		x = coords[0];
		y = coords[1];

		field[x][y] = '%';

		if (second_direction == 1) field[x][y - 1] = '%';
		else if (second_direction == 2) field[x][y + 1] = '%';
		else if (second_direction == 3) field[x - 1][y] = '%';
		else field[x + 1][y] = '%';

		all_ships--;
	}

	for (triple_decker; triple_decker > 0; triple_decker--) {
		coords = find_cell(field, coords, 3);

		while (is_occupied(field, coords, 3, direction, second_direction)) {
			coords = find_cell(field, coords, 3);
			direction = direction_generation();
		}

		x = coords[0];
		y = coords[1];

		field[x][y] = '%';

		if (second_direction == 1) {
			field[x][y - 1] = '%';
			field[x][y - 2] = '%';
		}
		else if (second_direction == 2) {
			field[x][y + 1] = '%';
			field[x][y + 2] = '%';
		}
		else if (second_direction == 3) {
			field[x - 1][y] = '%';
			field[x - 2][y] = '%';
		}
		else {
			field[x + 1][y] = '%';
			field[x + 2][y] = '%';
		}

		all_ships--;
	}


	coords = find_cell(field, coords, 4);

	while (is_occupied(field, coords, 4, direction, second_direction)) {
		coords = find_cell(field, coords, 4);
		direction = direction_generation();
	}

	x = coords[0];
	y = coords[1];

	field[x][y] = '%';

	if (second_direction == 1) {
		field[x][y - 1] = '%';
		field[x][y - 2] = '%';
		field[x][y - 3] = '%';
	}
	else if (second_direction == 2) {
		field[x][y + 1] = '%';
		field[x][y + 2] = '%';
		field[x][y + 3] = '%';
	}
	else if (second_direction == 3) {
		field[x - 1][y] = '%';
		field[x - 2][y] = '%';
		field[x - 3][y] = '%';
	}
	else {
		field[x + 1][y] = '%';
		field[x + 2][y] = '%';
		field[x + 3][y] = '%';
	}

	all_ships--;

}

void create_enemy_field(char enemy_field[height][width], int* enemy_coords) {
	int single_deck = 4;
	int double_decker = 3;
	int triple_decker = 2;
	int four_decker = 1;
	int all_ships = 10;

	int direction = direction_generation();
	int second_direction = 0;

	int x = 0;
	int y = 0;

	for (single_deck; single_deck > 0; single_deck--) {
		enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 1);

		while (is_occupied(enemy_field, enemy_coords, 1, direction, second_direction)) {
			enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 1);
		}

		x = enemy_coords[0];
		y = enemy_coords[1];

		enemy_field[x][y] = '%';

		all_ships--;
		print_field(enemy_field);
	}

	for (double_decker; double_decker > 0; double_decker--) {
		enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 2);

		while (is_occupied(enemy_field, enemy_coords, 2, direction, second_direction)) {
			enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 2);
			direction = direction_generation();
		}

		x = enemy_coords[0];
		y = enemy_coords[1];

		enemy_field[x][y] = '%';

		if (second_direction == 1) enemy_field[x][y - 1] = '%';
		else if (second_direction == 2) enemy_field[x][y + 1] = '%';
		else if (second_direction == 3) enemy_field[x - 1][y] = '%';
		else enemy_field[x + 1][y] = '%';

		all_ships--;
		print_field(enemy_field);
	}

	for (triple_decker; triple_decker > 0; triple_decker--) {
		enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 3);

		while (is_occupied(enemy_field, enemy_coords, 3, direction, second_direction)) {
			enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 3);
			direction = direction_generation();
		}

		x = enemy_coords[0];
		y = enemy_coords[1];

		enemy_field[x][y] = '%';

		if (second_direction == 1) {
			enemy_field[x][y - 1] = '%';
			enemy_field[x][y - 2] = '%';
		}
		else if (second_direction == 2) {
			enemy_field[x][y + 1] = '%';
			enemy_field[x][y + 2] = '%';
		}
		else if (second_direction == 3) {
			enemy_field[x - 1][y] = '%';
			enemy_field[x - 2][y] = '%';
		}
		else {
			enemy_field[x + 1][y] = '%';
			enemy_field[x + 2][y] = '%';
		}

		all_ships--;
		print_field(enemy_field);
	}


	enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 4);

	while (is_occupied(enemy_field, enemy_coords, 4, direction, second_direction)) {
		enemy_coords = find_enemy_cell(enemy_field, enemy_coords, 4);
		direction = direction_generation();
	}

	x = enemy_coords[0];
	y = enemy_coords[1];

	enemy_field[x][y] = '%';

	if (second_direction == 1) {
		enemy_field[x][y - 1] = '%';
		enemy_field[x][y - 2] = '%';
		enemy_field[x][y - 3] = '%';
	}
	else if (second_direction == 2) {
		enemy_field[x][y + 1] = '%';
		enemy_field[x][y + 2] = '%';
		enemy_field[x][y + 3] = '%';
	}
	else if (second_direction == 3) {
		enemy_field[x - 1][y] = '%';
		enemy_field[x - 2][y] = '%';
		enemy_field[x - 3][y] = '%';
	}
	else {
		enemy_field[x + 1][y] = '%';
		enemy_field[x + 2][y] = '%';
		enemy_field[x + 3][y] = '%';
	}

	print_field(enemy_field);

	all_ships--;
}

int main() {
	srand(time(NULL));

	//coordinate array
	int coords[coords_size] = {0, 0};

	//enemy coordinate array
	int enemy_coords[coords_size] = {0, 0};

	//Matrix (the left field is ours, the right field is the enemy)
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

	char enemy_field[height][width] = { {"-------------------------------"},
									    {"-------------------############"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------#@@@@@@@@@@#"},
									    {"-------------------############"},
									    {"-------------------------------"} };

	create_field(field, coords);
	print_field(field);
	print_field(enemy_field);
	create_enemy_field(enemy_field, enemy_coords);
	return 0;
}
