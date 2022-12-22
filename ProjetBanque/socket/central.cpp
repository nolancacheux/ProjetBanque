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


int get_bank_number(int CustoNumber) {
    ptree pt;
    std::ifstream file_in("UserBankList.json");
    read_json(file_in, pt);
    file_in.close();

    int BankNumber = 0;
    for (ptree::value_type& v : pt.get_child("Customers")) {
        if (v.second.get<int>("Nombre") == CustoNumber) {
            BankNumber = v.second.get<int>("Banque");
        }
    }
    return BankNumber;
}



string request(string msg, const int port) {

    cout << "Message :  " << msg << "  vers le port:  " << port << endl;

    boost::asio::io_service io_service;
    // socket creation
    tcp::socket socket(io_service);
    // connection
    try
    {
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), port));
    }
    catch (...)
    {
        cout << "Can't connect to the banque decentralise." << endl;
        return "0";
    }


    // request/message from client
    msg = msg + "\n";
    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(msg), error);
    if (!error)
    {
        cout << "Message envoye a une banque decentralise" << endl;
    }
    else
    {
        cout << "send failed: " << error.message() << endl;
    }



    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof)
    {
        cout << "receive failed: " << error.message() << endl;
    }
    else
    {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        //cout << data << endl;
        return data;
    }

    return "0";
}


string get_all_operation() {
    ptree pt;
    std::ifstream file_in("UserBankList.json");
    read_json(file_in, pt);
    file_in.close();

   
    string data = "";
    string req = "getallope";


    int BankNumber = 1111;
    data += request(req, BankNumber);

    BankNumber = 2222;
    data += request(req, BankNumber);

    return data;
}

string DataDeserialize(string data) {

    if (data == "getallope") {
        string data;
        data = get_all_operation();
        return data;
    }


    std::vector<string> result;
    boost::split(result, data, boost::is_any_of("|"));

    //for (int i = 0; i < result.size(); i++)
    //    cout << result[i] << endl;



    // récupération de la banque de l'utilisateur via son numéro de compte
    //int BankNumber = get_bank_number(stoi(result[0]));
    int port;

    int BankNumber = stoi(result[1]);

    if (BankNumber == 1) {
        port = 1111;
    }
    if (BankNumber == 2) {
        port = 2222;
    }
    if (BankNumber == 3) {
        port = 3333;
    }
    if (BankNumber == 4) {
        port = 4444;
    }
    //cout << port;

    // envoi de la requête vers la banque décentralisé correspondante (contenant le compte)
    try
    {
        return request(data, port);
    }
    catch (const std::exception&)
    {
        return "0";
    }

}





int main()
{
    int t = 0;
    cout << "Serveur central demarre, en attente de requete..." << endl;

    //string prout = "100222222|getcusto|100222222";
    //string prout = "100222222|getcompte|1001111";
    //string prout = "100222222|getope|1001";
    //string prout = "getallope";
    //cout << DataDeserialize(prout);

    ///prout = "8888888|getcusto|8888888";
    //string prout = "8888888|getcompte|1001111";
    //string prout = "8888888|getope|1001";
    //cout << DataDeserialize(prout);

    while (1)
    {
        boost::asio::io_service io_service;
        // listen for new connection
        tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234));
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
        cout << "Donnees envoyees au client" << endl;


        t += 1;
    }
    return 0;
}
