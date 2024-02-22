#include<iostream>
#include<fstream>
#include<map>

using namespace std;

int main(int argc, char** argv) {

	//time -->c
	//distance-->weight
	if (argc != 4) {
		printf("usage: <arg1> input file name <arg2> output file name\n");
		exit(0);
	}
	FILE* finc;
	FILE* finw;
	FILE* fout;
	fopen_s(&finc, argv[1], "r");
	if (finc == NULL) {
		printf("can not open input w file\n");
		exit(0);
	}
	fopen_s(&finw, argv[2], "r");
	if (finw == NULL) {
		printf("can not open input c file\n");
		exit(0);
	}
	fopen_s(&fout, argv[3], "w");
	if (fout == NULL) {
		printf("can not open output file\n");
		exit(0);
	}

	map< pair<int, int>, pair<int, int> > edge_map;
	char c;
	char buff[200];
	int s, t, w, v;
	//while( !originalFile.eof() ){
	while (!feof(finc)) {
		//c = originalFile.peek();
		c = fgetc(finc);
		if (c != 'a') {
			//originalFile.getline(buff,200);
			fgets(buff, 200, finc);
			continue;
		}
		//originalFile >> c >> s >> t >> w;
		fscanf_s(finc, "%d %d %d\n", &s, &t, &w);
		pair<int, int> p(s, t);
		if (s < t) {
			edge_map[p].first = w;
		}
	}
	while (!feof(finw)) {
		//c = originalFile.peek();
		c = fgetc(finw);
		if (c != 'a') {
			//originalFile.getline(buff,200);
			fgets(buff, 200, finw);
			continue;
		}
		//originalFile >> c >> s >> t >> w;
		fscanf_s(finw, "%d %d %d\n", &s, &t, &w);
		pair<int, int> p(s, t);
		if (s < t) {
			edge_map[p].second = w;
		}
	}
	map< pair<int, int>, pair<int, int> >::const_iterator iter = edge_map.begin();

	fprintf_s(fout, "%d\n", edge_map.size());
	//fprintf_s(fout, "Original Edges: %d. Duplicated edges: %d\n", a, d);
	while (iter != edge_map.end()) {
		//newFile << 'a' << iter->first.first << ' ' << iter->first.second
		//	<< ' ' << iter->second << endl;
		fprintf_s(fout, "%d %d %d %d\n", iter->first.first, iter->first.second, iter->second.first, iter->second.second);
		iter++;
	}
	printf("New file has been made\n");

	return 0;
}