#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string filename(argv[1]);
	ifstream file(filename);
	vector<long> values;
	if (file.is_open()) {
		string line;
		while(getline(file, line)) {
			long num = stol(line);
			values.push_back(num);
		}
	}
	file.close();
	float average = accumulate(values.begin(), values.end(), 0.0)/ values.size();
	size_t n = values.size()/ 2;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p50 = values[n];
	n = values.size()/ 4;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p25 = values[n];
	n = (values.size() * 3)/ 4;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p75 = values[n];
	n = (values.size() * 90)/ 100;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p90 = values[n];
	n = (values.size() * 99)/ 100;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p99 = values[n];
	cout << average << "," << p25 << "," << p50 << "," << p75 << "," << p90 << "," << p99 << endl;
	return 0;
}
