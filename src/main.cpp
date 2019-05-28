#include <iostream>

#include "randomfile.h"
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main () {
	string filename = "players";
	VariableRecordFile players(filename);

	Record obj1;
	obj1.setData();

	auto start = chrono::high_resolution_clock::now();
	players.writeRecord(obj1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> time = chrono::duration_cast<chrono::duration<double>>(end - start);
	cout << "Writing: " << time.count() << std::endl;

	start = chrono::high_resolution_clock::now();
	players.readRecord(1);
	end = chrono::high_resolution_clock::now();
	time = chrono::duration_cast<chrono::duration<double>>(end - start);
	cout << "Searching: " << time.count();

	return 0;
}
