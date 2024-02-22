#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    ofstream ofs(argv[2]);
    string line;
    vector< vector< string>> partitions;

    // ����ǰ����
    getline(file, line);
    getline(file, line);

    // �����ȡ����
    while (getline(file, line)) {
        if (line.find("partition") != std::string::npos) {
            partitions.emplace_back();
            continue;
        }
        if (line[0] == '=') {
            continue;
        }
        if (!line.empty()) {
            istringstream iss(line);
            string pointId;
            iss >> pointId;
            partitions.back().push_back(pointId);
        }
    }
    // ���ת����ĸ�ʽ
    ofs << partitions.size() << endl;
    for (size_t i = 0; i < partitions.size(); ++i) {
        ofs << endl << partitions[i].size() << endl;
        for (const string& point : partitions[i]) {
            ofs << point << endl;
        }
    }

    return 0;
}