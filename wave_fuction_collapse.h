#include <stdio.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <random>

#define NUM_GRID_X 5
#define NUM_GRID_Y 5
#define NUM_ITEM 3

class ItemContainer {
public:
	ItemContainer();
	~ItemContainer();
	void Initialize(int value);
	void get_grid_array_x_y_size();
	int get_grid_array_value(int x_index, int y_index);
	void set_grid_array_value(int x_index, int y_index , int value);
private:
	int grid_array[NUM_GRID_X][NUM_GRID_Y];
};

class GenerateNewItem {
public:
	GenerateNewItem();
	~GenerateNewItem();
	void Move(int x_index, int y_index);
	void PrintItemContainer();
//private:
	ItemContainer item_container_;
	ItemContainer possible_item_[NUM_ITEM];
	//void InitializePossibleItemNum1; 
	//used to initialize item possible, if its possibility doesn`t distribute evenly.
	int Collapse_(int x_index, int y_index);
	bool isValid_(int x_index, int y_index);
	void VertifyCondition_ID_10(int x_index, int y_index);
	void VertifyCondition_ID_20(int x_index, int y_index);
	void VertifyCondition_ID_30(int x_index, int y_index);
	void PrintPossibleItem_(int num_item); //debug
};


