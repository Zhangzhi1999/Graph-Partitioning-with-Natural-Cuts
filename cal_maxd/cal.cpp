#include<iostream>
#include<fstream>
#include<map>
#include<vector>

using namespace std;


inline long long getDistance(const pair<int,int>& p1, const pair<int, int>& p2) {
	long long dx = p2.first - p1.first;
	long long dy = p2.second - p1.second;
	return sqrt(dx * dx + dy * dy);
}


int main(int argc, char** argv) {

	//time -->c
	//distance-->weight
	if (argc != 3) {
		printf("usage: <arg1> input file name <arg2> output file name\n");
		exit(0);
	}
	FILE* fin;
	FILE* fout;
	fopen_s(&fin, argv[1], "r");
	cout << argv[1] << endl;
	if (fin == NULL) {
		printf("can not open input file\n");
		exit(0);
	}

	fopen_s(&fout, argv[2], "w");
	if (fout == NULL) {
		printf("can not open output file\n");
		exit(0);
	}

	vector<pair<int, int>> loc;
	char c;
	char buff[200];
	int id, lat, lont;
	//while( !originalFile.eof() ){
	while (!feof(fin)) {
		//c = originalFile.peek();
		c = fgetc(fin);
		if (c != 'v') {
			//originalFile.getline(buff,200);
			fgets(buff, 200, fin);
			continue;
		}
		//originalFile >> c >> s >> t >> w;
		fscanf_s(fin, "%d %d %d\n", &id, &lat, &lont);
		loc.emplace_back(lat, lont);
	}
	long long maxDistance = 0.0;
	cout << "pts num:\t" << loc.size() << endl;
	for (size_t i = 0; i < loc.size(); ++i) {
		if (i % 100000 == 0) cout << i << endl;
		for (size_t j = i + 1; j < loc.size(); ++j) {
			double distance = getDistance(loc[i], loc[j]);
			if (distance > maxDistance) {
				maxDistance = distance;
			}
		}
	}
	cout << maxDistance << endl;
	printf("New file has been made\n");

	return 0;
}