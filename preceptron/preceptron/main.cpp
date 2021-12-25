// the preceptron have two version
// I find that paint in the c++ is fucking complex

// so preceptron 
// we need randon data, 2_D first
// than a algorithms
# include<iostream>
# include<vector>
# include<cstdlib>
# include<random>
using namespace std;

const int data_number = 3;
// const int data_range = 2;
const int Dimension = 2;
const float learning_rate = 1;
typedef float Class;

struct Point
{
	float position[Dimension] = { 0 }; // 2_D
	Class y; // -1 or +1
};

vector<int> assess(Point line, Point *Data)
{
	vector<int> index;
	for (int i = 0; i < data_number; i++)
	{
		int wx = 0;
		for (int j = 0; j < Dimension; j++)
		{
			wx += line.position[j] * Data[i].position[j];
		}
		wx += line.y;
		if (Data[i].y * wx > 0)
			continue;
		else
		{
			index.push_back(i);
		}
	}
	return index;
}


// the origin_version
Point origin_version(Point line, Point *Data)
{
	Point Line;
	Line = line;
	// than the circl
	// find the wrong classification
	while (1) // the end sign is all data be classify correctly
	{
		vector<int> index = assess(Line, Data);
		if (index.empty())
			break;
		// int cap = index.size();
		int rand_index = rand() % index.size();
		Line.y = Line.y + learning_rate * Data[rand_index].y;
		for (int i = 0; i < Dimension; i++)
		{
			Line.position[i] = Line.position[i] + learning_rate * Data[rand_index].position[i] * Data[rand_index].y;
		}
	}
	return Line;
}

// the pait_version
Point pair_version(Point line, Point* Data)
{
	Point Line = line;

	// init the a
	float arf[data_number] = { 0 };

	float Gram[data_number][data_number] = { 0 };
	// init Gram
	for (int i = 0; i < data_number; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			int J = j + i;
			for (int m = 0; m < Dimension; m++)
			{
				Gram[i][J] += Data[i].position[m] * Data[J].position[m];
			}
			if (i != J)
				Gram[J][i] = Gram[i][J];
		}
	}

	while (1)
	{
		vector<int> index = assess(Line, Data);
		if (index.empty())
			break;
		int rand_index = rand() % index.size();

		float var = 0;
		for (int i = 0; i < data_number; i++)
		{
			var += arf[i] * Data[i].y * Gram[i][rand_index];
		}
		
		if (Data[rand_index].y * (var + Line.y) <= 0)
		{
			Line.y += learning_rate * Data[rand_index].y;
			arf[rand_index] += learning_rate;
		}
		
		// I'm making an unnecessary move
		// really shit
		// because I use assess() to assess the wrong classfy point 
		for (int i = 0; i < Dimension; i++)
		{
			Line.position[i] = 0;
		}
		for (int i = 0; i < data_number; i++)
		{
			for (int j = 0; j < Dimension; j++)
			{
				Line.position[j] += arf[i] * Data[i].position[j] * Data[i].y;
			}
		}
	}
	

	return Line;
}

int main()
{
	srand(time(NULL));
	Point Data[data_number];
	// init the data
	for (int i = 0; i < data_number; i++)
	{
		//data[i].y = rand() % 2;
		//if (data[i].y == 0)
		//	data[i].y--;
		//for (int j = 0; j < dimension; j++)
		//{
		//	data[i].position[j] = rand() % data_range + 1;
		//}
		// can't be random produce
		// man hands input
		cin >> Data[i].y;
		for (int j = 0; j < Dimension; j++)
		{
			cin >> Data[i].position[j];
			// Data[i].position[j] = rand() % data_range + 1;
		}
	}

	// init the split line
	Point line;
	line.y = 0;
	for (int j = 0; j < Dimension; j++)
	{
		line.position[j] = 0;
	}

	line = pair_version(line, Data);
	
	for (int i = 0; i < Dimension; i++)
	{
		cout << line.position[i] << "X[" << i << ']' << " + ";
	}
	cout << line.y << endl;
	return 0;
}

// test.
//- 1 1 1
//1 3 3
//1 4 3
//1.5X[0] + 1.5X[1] + -3.5

// ok now is 12/25 I think it's not time to be depression. get up!!
// conclusion: 
// the core of origin_version and pair_version is same 
// so origin_vaersion is easy to understand, and the pari_version will be unnecessary??