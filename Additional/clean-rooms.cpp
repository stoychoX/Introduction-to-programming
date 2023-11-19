#include <iostream>

using namespace std;

constexpr unsigned MAX_LENGTH = 1024 + 1;

void getRooms(unsigned rooms[], unsigned size)
{
	unsigned idx = 0;

	for (size_t i = 0; i < size; i++)
	{
		cin >> rooms[i];
	}
}

void clean(const unsigned rooms[], bool visited[], unsigned idx, unsigned& cleaner, unsigned& maxLongestCycle)
{
	++cleaner;

	unsigned cycleLength = 0;
	while (!visited[idx])
	{
		visited[idx] = true;
		idx = rooms[idx];
		++cycleLength;
	}

	if (cycleLength > maxLongestCycle) 
	{
		maxLongestCycle = cycleLength;
	}
}

void cleanBuilding(unsigned n) 
{
	unsigned rooms[MAX_LENGTH];
	unsigned cleanersNeeded = 0;
	unsigned longestCycle = 0;

	getRooms(rooms, n);

	bool visited[MAX_LENGTH] = { false };

	for (size_t i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			clean(rooms, visited, i, cleanersNeeded, longestCycle);
		}
	}

	cout << "Cleaners needed: " << cleanersNeeded << endl << "Time needed: " << longestCycle << " hours" << endl;
}

int main()
{
	unsigned n = 0;
	cin >> n;

	cleanBuilding(n);
}