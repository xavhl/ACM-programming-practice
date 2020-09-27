// 741.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// first approach: find all row patterns first, for each patterns, filp columns.
// way to generate / find row patterns:
/*
1. somehow make a combination of 0 and 1 ? Something like grey code
2. switch rows based on this.
*/
vector<string> generate_col_pattern(int col_num);

int switch_col_switch_row(int * input[], vector<string>, int, int);



int switch_col_switch_row(int * input[], vector<string> unique_patterns, int row, int col)
{
	int maximum_value = 0;

	// for each unique patterns, switch the columns
	int ** copy_input;
	copy_input = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		copy_input[i] = new int[col];
	}

	copy_input = input;

	int size = static_cast<int>(unique_patterns.size());
	for (int count_p = 0; count_p < size; ++count_p)
	{
		input = copy_input;
		for (int i = 0; i < col; ++i)
		{
			int col_head = (int)(unique_patterns[count_p][i]) - 48;
			if (input[0][i] != col_head)
			{
				for (int j = 0; j < row; ++j)
				{
					switch (input[j][i])
					{
					case 1:
						input[j][i] = 0;
						break;
					case 0:
						input[j][i] = 1;
						break;
					}
				}
			}
		}
		// switch row if tails inside is more than heads
		for (int i = 1; i < row; ++i)
		{
			int count_tail = 0;
			for (int j = 0; j < col; ++j)
			{
				if (input[i][j] == 0)
					count_tail++;
			}
			if (col == 1)
			{
				for (int j = 0; j < col; ++j)
				{
					switch (input[i][j])
					{
					case 1:
						input[i][j] = 1;
						break;
					case 0:
						input[i][j] = 1;
						break;
					}
				}
			}
			else if (col % 2 == 1 && count_tail >= col / 2 + 1)
			{
				for (int j = 0; j < col; ++j)
				{
					switch (input[i][j])
					{
					case 1:
						input[i][j] = 0;
						break;
					case 0:
						input[i][j] = 1;
						break;
					}
				}
			}
			else if (col % 2 == 0 && count_tail >= col / 2)
			{
				for (int j = 0; j < col; ++j)
				{
					switch (input[i][j])
					{
					case 1:
						input[i][j] = 0;
						break;
					case 0:
						input[i][j] = 1;
						break;
					}
				}
			}
		}


		// count heads and update maximum value.
		int count_head = 0;

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (input[i][j] == 1)
				{
					count_head++;
				}
			}
		}


		if (count_head > maximum_value)
			maximum_value = count_head;
	}


	return maximum_value;
}


vector<string> generate_col_pattern(int col_num)
{
	vector<string> unique_patterns;

	unique_patterns.push_back("0");
	unique_patterns.push_back("1");

	int count, i;

	for (count = 2; count < (1 << col_num); count = count << 1)
	{
		// duplicate the vector~
		for (i = 0; i < count; ++i)
		{
			unique_patterns.push_back(unique_patterns[i]);
		}

		for (i = 0; i < count; ++i)
		{
			unique_patterns[i] = "0" + unique_patterns[i];
		}

		for (i = count; i < 2 * count; ++i)
		{
			unique_patterns[i] = "1" + unique_patterns[i];
		}

	}
	int num = 1 << col_num;

	for (vector<string>::iterator it = unique_patterns.begin();
		it != unique_patterns.end(); ++it)
	{
		int count_zero = 0;
		for (int i = 0; i < col_num; ++i)
		{
			if (it[0][i] == '0')
			{
				count_zero++;
			}
		}
		if ((count_zero >= col_num / 2 && col_num % 2 == 0) || (count_zero > col_num / 2 && col_num % 2 == 1))
		{
			it = unique_patterns.erase(it);
		}
		else
		{
			//cout << it[0] << endl;
		}
	}

	return unique_patterns;
}



int main()
{

	int ** input;
	int row = 0, col = 0;


	while (cin >> row >> col)
	{
		if (row == 0 || col == 0)
		{
			break;
		}
		else if (row < 1 || row > 100 || col < 1 || col > 10)
		{
			break;
		}
		else
		{
			// declare a new 2D array
			input = new int*[row];
			for (int i = 0; i < row; ++i)
			{
				input[i] = new int[col];
			}

			// initialize
			for (int i = 0; i < row; ++i)
			{
				for (int j = 0; j < col; ++j)
				{
					input[i][j] = 0;
				}
			}

			int count_row = 0;

			while (count_row < row)
			{
				string input_binary_string;

				cin >> input_binary_string;
				int count_col = 0;

				while (count_col < col)
				{
					input[count_row][count_col] = (int)(input_binary_string[count_col]) - 48;
					count_col++;
				}
				count_row++;
			}

			vector<string> unique_col_pattern;
			unique_col_pattern = generate_col_pattern(col);

			// switch columns based on patterns
			int max = switch_col_switch_row(input, unique_col_pattern, row, col);
			cout << max << endl;
		}
	}
}
