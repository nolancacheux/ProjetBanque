#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char** argv){
    string oui;
    string test = argv[0];
    std::vector<string> result;
    boost::split(result, test, boost::is_any_of("\\"));
    oui += "start ";
    for (int i = 0; i < result.size() - 1; i++)
        oui += result[i] + "\\";

    cout << oui;

    string start = oui + "ProjetBanque\\socket\\bank1.exe";
    const char* bank1 = start.c_str();
    system(bank1);

    start = oui + "ProjetBanque\\socket\\bank2.exe";
    const char* bank2 = start.c_str();
    system(bank2);

    start = oui + "ProjetBanque\\socket\\bank3.exe";
    const char* bank3 = start.c_str();
    system(bank3);

    start = oui + "ProjetBanque\\socket\\bank4.exe";
    const char* bank4 = start.c_str();
    system(bank4);


    start = oui + "ProjetBanque\\socket\\central.exe";
    const char* centre = start.c_str();
    system(centre);

    start = oui + "ProjetBanque\\test_wxWidgets\\example_of_use.exe";
    const char* interf = start.c_str();
    system(interf);

    return 0;
}