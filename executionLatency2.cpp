#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string filename(argv[1]);
	ifstream file(filename);
	vector<float> values;
	if(file.is_open()) {
		string line;
		while(getline(file, line)) {
			if(line.find("time: \'") != string::npos) {
				int startIndex = line.find("time: \'");
				startIndex += 7;
				int endIndex = line.find("\'\"");
				float num = stof(line.substr(startIndex, endIndex - startIndex));
				values.push_back(num);
			}
		}
		file.close();
	}
	float average = accumulate(values.begin(), values.end(), 0.0)/ values.size();
	size_t n = values.size()/ 2;
	nth_element(values.begin(), values.begin() + n, values.end());
	float p50 = values[n];
	cout << average << "," << p50 << endl;
	return 0;
}
