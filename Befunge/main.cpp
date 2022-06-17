#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Befunge.h"

using namespace std;

int main()
{
    string source = "code.txt";
    cout << "=========== Interpr�teur BEFUNGE ===========\n   Par : ROMANRAA    version : 1.0"<<endl;
    try{
        if (source.size() < 1) throw runtime_error("Fichier d'entree non precise");
        ifstream read(source.c_str());
        if (read.fail()) throw runtime_error("Impossible de trouver le fichier precise");
        Befunge MyBefunge(read);
        MyBefunge.Exec();
        cout << "----------- Interpr�tation terminee ----------"<<endl;
    }
    catch(exception & e)
	{
        cout <<e.what()<<endl;
    }
    return 0;
}
