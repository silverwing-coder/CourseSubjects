#include <iostream>
#include <fstream>

using namespace std;

 int main(){

    ifstream ifile;
    ifile.open("exam.txt");
    string str;
    while(!ifile.eof()){
        ifile >> str;
        cout << str << " ";
        str = "";
    }

    return 0;
}