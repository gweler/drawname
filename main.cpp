#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_names(string namesFilename) {
    fstream namesFile;
    string name;
    vector<string> names;
    namesFile.open(namesFilename, ios::in);
    while (getline(namesFile, name)) {
        names.push_back(name);
    }
    namesFile.close();
    return names;
}

int draw_a_number(int numofNames) {
    return rand() % numofNames;
}

int main() {
    vector<string> names = get_names("names.txt");
    srand(time(NULL));
    int drawn = draw_a_number(names.size());
    cout << names.at(drawn);
    return 0;
}
