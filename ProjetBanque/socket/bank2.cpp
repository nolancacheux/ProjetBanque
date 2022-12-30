#include <iostream>
#include <boost/asio.hpp>
#include <chrono>
#include <thread>
#include <vector>

#include <boost/json/serialize.hpp>
#include <boost/json/parser.hpp>
#include <boost/algorithm/string.hpp>

#include "../customer/Customer_for_JSON.hpp"


using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;



string oui; 


string read_(tcp::socket& socket)
{
    boost::asio::streambuf buf;
    boost::asio::read_until(socket, buf, "\n");
    string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}
void send_(tcp::socket& socket, const string& message)
{
    const string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}



string returnCustomer(int nombre) {
    // create ptree to send to user
    ptree pt_write;
    std::ifstream file_in(oui);
    read_json(file_in, pt_write);
    file_in.close();

    Customer Custo;
    Custo = get_a_customer(pt_write, nombre);
    std::string data;
    data = Custo.serialize();

    return data;
}
string returnCompte(int nombre) {
    // create ptree to send to user
    ptree pt_write;
    std::ifstream file_in(oui);
    read_json(file_in, pt_write);
    file_in.close();

    Compte Custo;
    Custo = get_an_account(pt_write, nombre);
    std::string data;
    data = Custo.serialize();

    return data;
}
string returnOperation(int nombre) {
    // create ptree to send to user
    ptree pt_write;
    std::ifstream file_in(oui);
    read_json(file_in, pt_write);
    file_in.close();

    Operation Custo;
    Custo = get_an_operation(pt_write, nombre);
    std::string data;
    data = Custo.serialize();

    return data;
}
string returnAllOperation() {
    // create ptree to send to user
    ptree pt_write;
    std::ifstream file_in(oui);
    read_json(file_in, pt_write);
    file_in.close();

    std::vector<Operation> Opes;
    Opes = get_all_operations(pt_write);
    std::string data;

    for (int i = 0; i < Opes.size(); i++) {
        data += Opes[i].serialize();
        data += "=";
    }

    return data;
}
string returnAllAccount() {
    // create ptree to send to user
    ptree pt_write;
    std::ifstream file_in(oui);
    read_json(file_in, pt_write);
    file_in.close();

    std::string data;
    auto nbrcomptes = get_all_nbcompte(pt_write);

    for (auto i = nbrcomptes.begin(); i != nbrcomptes.end(); ++i) {
        //std::cout << *i << std::endl;
        data += std::to_string(*i);
        data += "-";
    }

    //cout << data;

    return data;
}


string DataDeserialize(string data) {
    if (data == "getallope\n") {
        try
        {
            return returnAllOperation();
        }
        catch (const std::exception&)
        {
            return "0";
        }
    }
    if (data == "getallacc\n") {
        //try
        //{
        return returnAllAccount();
        //}
        //catch (const std::exception&)
        //{
        //    return "0";
        //}
    }
    std::vector<string> result;
    boost::split(result, data, boost::is_any_of("|"));

    //for (int i = 0; i < result.size(); i++)
    //    cout << result[i] << endl;

    if (result[0] == "getbank") {
        return oui;
    }

    if (result[1] == "getcusto") {
        try
        {
            int Number = stoi(result[2]);
            return returnCustomer(Number);
        }
        catch (const std::exception&)
        {
            return "0";
        }
    }

    if (result[1] == "getcompte") {
        try
        {
            int Number = stoi(result[2]);
            return returnCompte(Number);
        }
        catch (const std::exception&)
        {
            return "0";
        }
    }

    if (result[1] == "getope") {
        try
        {
            int Number = stoi(result[2]);
            return returnOperation(Number);
        }
        catch (const std::exception&)
        {
            return "0";
        }
    }
}




int main(int argc, char** argv)
{
    int t = 0;
    int port = 2222;

    cout << "Serveur Bank 2 demarre sur le port : " << port << ", en attente de requete..." << endl;


    string test = argv[0];
    std::vector<string> result;
    boost::split(result, test, boost::is_any_of("\\"));
    for (int i = 0; i < result.size() - 1; i++)
        oui += result[i] + "\\";
    oui += "data2.json";

    cout << oui;

    //string prout = "100222222|getcusto|100222222";
    //string prout = "100222222|getcompte|1001111";
    //string prout = "100222222|getope|1001";
    //string prout = "getallacc\n";
    //cout << DataDeserialize(prout);

    while (1)
    {
        boost::asio::io_service io_service;
        // listen for new connection
        tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), port));

        // socket creation
        tcp::socket socket_(io_service);

        // waiting for connection
        acceptor_.accept(socket_);

        // read operation
        string message = read_(socket_);
        cout << message << endl;

        //analyse message read
        // prepare data to return
        string data;
        data = DataDeserialize(message);


        // write operation
        send_(socket_, data);
        // send_(socket_, "Hello Froom Server!");
        cout << "Donnees envoyees a la banque centrale" << endl;


        t += 1;
    }
    return 0;
}
