#include "wave_fuction_collapse.h"
using namespace std;

int main() {
	cout << "Hello world:" << endl;
	GenerateNewItem item;
	for (int i = 0; i < NUM_GRID_X; i++) {
		item.Move(i, 3);
		item.PrintItemContainer();

	}

	system("pause");
	return 0;
}