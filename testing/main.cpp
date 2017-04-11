#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>

//#include <QCoreApplication>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

/*
std::istream& ignoreline(std::ifstream& in, std::ifstream::pos_type& pos){
    pos = in.tellg();
    return in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getLastLine(std::ifstream& in){
    std::ifstream::pos_type pos = in.tellg();

    std::ifstream::pos_type lastPos;
    while(in >> std::ws && ignoreline(in, lastPos))
        pos = lastPos;
    in.clear();
    in.seekg(pos);

    std::string line;
    std::getline(in, line);
    return line;
}

int main()
{
    //QCoreApplication a(argc, argv);

    std::ifstream file("C:Users\\Kurtis\\Documents\\testing\\example.txt");

    if(file){
        std::string line = getLastLine(file);
        std::cout << line << '\n';
    }
    else
        std::cout << "Unable to open file .\n";
}
*/

using namespace std;
int main(){
    //QCoreApplication a(argc, argv);



    QFile file("C:Users\\Kurtis\\Documents\\build-testing-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\debug\\example.txt");

    if (!file.exists()){
        cout << "lel" << endl;
    }
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout << "File opened" << endl;
    }
    else{
        cout << "File not opened" << endl;
        perror("C:Users\\Kurtis\\Documents\\build-testing-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\debug\\example.txt");
    }


    file.close();

/*
    string line;
    ifstream myfile("C:Users\\Kurtis\\Documents\\build-testing-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\debug\\example.txt");
    if(myfile.is_open()){
        while(getline(myfile, line)){
            cout<<line<<'\n';
        }
        myfile.close();
    }
    else
        perror("C:Users\\Kurtis\\Documents\\build-testing-Desktop_Qt_5_8_0_MSVC2015_64bit-Debug\\debug\\example.txt");
    return 0;
*/
}
