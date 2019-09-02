#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    string text1 = "testcopy1.txt";
    string text2 = "testcopy2.txt";

    ifstream ifstrm;
    ofstream ofstrm;

    ifstrm.open(text1, istream::in );
    if(!ifstrm){
        cout << " open text1 failed! " << endl;
        return -1;
    }

    vector<string> vec_buf;
    string line;

    /* read from text1 */
    while (ifstrm)
    {
        getline(ifstrm , line);
        vec_buf.push_back(line);
    }
    ifstrm.close();

    /* open text2 and write in */
    ofstrm.open(text2 , ostream::out);
    if(!ofstrm){
        cout << "open text2 failed!" << endl;
        return -1;
    }

    for(int i = 0 ; i < vec_buf.size() ; i ++){
        ofstrm << vec_buf[i] <<endl; 
    }
    ofstrm.close();
    
    return 0;

}