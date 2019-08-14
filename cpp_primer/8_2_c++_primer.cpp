#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string ifile = "test_io_1.txt";
    ifstream  ifstrm;
    ifstrm.open(ifile, istream::in);
    if(!ifstrm) {
        cout << "open file has failed  !" << endl;
        return -1;
    }

    vector<string> vec_str;
    string line;

    /* read to a vector */
    while (ifstrm)
    {
        getline(ifstrm , line);
        vec_str.push_back(line);
    }
    ifstrm.close();

    for (int i = 0 ; i < vec_str.size() ; i ++)
        cout << vec_str[i] <<endl;

    ofstream ostrm;
    ostrm.open(ifile , ostream::app);
    string scentence;
    cout << "please input scentence :" << endl;
    cin >> scentence ;
    ostrm <<  scentence << '\n' ;
    ostrm.close();

    

    return 0;
}