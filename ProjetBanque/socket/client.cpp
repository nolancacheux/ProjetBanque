#include <iostream>
#include <boost/asio.hpp>
#include "client.hpp"

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;

string ClientRequest(string request)
{
    boost::asio::io_service io_service;
    // socket creation
    tcp::socket socket(io_service);
    // connection
    try
    {
        socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    }
    catch (...)
    {
        cout << "Pas de connexion vers serv central." << endl;
        return "0";
    }


    // request/message from client

    //string request = "100222222|getcusto|100222222";
    //string request = "100222222|getcompte|1001111";
    //string prout = "100222222|getope|1001";
    //cout << DataDeserialize(prout);

    //string prout = "8888888|getcusto|8888888";
    //cout << DataDeserialize(prout);

    request += "\n";


    boost::system::error_code error;
    boost::asio::write(socket, boost::asio::buffer(request), error);



    if (!error)
    {
        cout << "Envoi d'une requete vers serv central" << endl;
    }
    else
    {
        cout << "send failed: " << error.message() << endl;
        return "0";
    }



    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof)
    {
        cout << "receive failed: " << error.message() << endl;
        return "0";
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        cout << data << endl;
        return data;
    }

    //std::this_thread::sleep_for(std::chrono::milliseconds(500));
}