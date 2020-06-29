#include "wave_fuction_collapse.h"
using namespace std;

ItemContainer::ItemContainer() {
	for (int i = 0; i < NUM_GRID_X; i++) {
		for (int j = 0; j < NUM_GRID_Y; j++) {
			grid_array[i][j] = 0;
		}
	}
}

ItemContainer::~ItemContainer() {

}

void ItemContainer::Initialize(int value) {
	for (int i = 0; i < NUM_GRID_X; i++) {
		for (int j = 0; j < NUM_GRID_Y; j++) {
			grid_array[i][j] = value;
		}
	}
}

void ItemContainer::get_grid_array_x_y_size() {
	cout << "Grid_X size: " << NUM_GRID_X << endl;
	cout << "Grid_Y size: " << NUM_GRID_Y << endl;
}

int ItemContainer::get_grid_array_value(int x_index, int y_index) {
	return grid_array[x_index][y_index];
}

void ItemContainer::set_grid_array_value(int x_index, int y_index, int value) {
	grid_array[x_index][y_index] = value;
}

GenerateNewItem::GenerateNewItem() {
	srand(time(NULL));
	for (int i = 0; i < NUM_ITEM; i++) {
		possible_item_[i].Initialize(1);
	}
}

GenerateNewItem::~GenerateNewItem() {

}

void GenerateNewItem::Move(int x_index, int y_index) {
	Collapse_(x_index, y_index);
}

int GenerateNewItem::Collapse_(int x_index, int y_index) {
	while (true) {
		int select = fabs(rand() * 92657589 % NUM_ITEM);
		if (possible_item_[select].get_grid_array_value(x_index, y_index) == 1) {
			item_container_.set_grid_array_value(x_index, y_index, (select + 1) * 10);
			for (int i = 0; i < NUM_ITEM; i++) {
				if (i != select) {
					possible_item_[i].set_grid_array_value(x_index, y_index, 0);
				}
			}
			return select;
		}
	}
}

bool GenerateNewItem::isValid_(int x_index, int y_index) {
	if (x_index >= 0) {
		if (x_index < NUM_GRID_X) {
			if (y_index >= 0) {
				if (y_index < NUM_GRID_Y) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void GenerateNewItem::VertifyCondition_ID_10(int x_index, int y_index){

}

void GenerateNewItem::VertifyCondition_ID_20(int x_index, int y_index) {

}

void GenerateNewItem::VertifyCondition_ID_30(int x_index, int y_index) {

}

void GenerateNewItem::PrintItemContainer() {
	cout << endl;
	for (int j = 0; j < NUM_GRID_Y; j++) {
		for (int i = 0; i < NUM_GRID_X; i++) {
			printf(" %2d ", item_container_.get_grid_array_value(i, j));
		}
		cout << endl;
	}
}

void GenerateNewItem::PrintPossibleItem_(int num_item) {
	cout << endl;
	cout << "PrintPossibleItem_[ " << num_item << " ]" <<endl;
	for (int j = 0; j < NUM_GRID_Y; j++) {
		for (int i = 0; i < NUM_GRID_X; i++) {
			printf(" %2d ", possible_item_[num_item].get_grid_array_value(i, j));
		}
		cout << endl;
	}
}