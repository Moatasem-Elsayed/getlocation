#include <iostream>
#include "client.hpp"
#include "parser.hpp"
using namespace std;

int sock;
struct sockaddr_in client;
int PORT = 80;

int main(int argc, char const *argv[])
{
    Client client;

    // get public ip
    client.init("api.ipify.org", 80);
    client.connectToServer();
    /* adjust http request*/
    stringstream ss;
    ss << "GET /?format=json"
       << " HTTP/1.1\r\n"
       << "Host: api.ipify.org\r\n"
       << "Accept: application/json\r\n"
       << "\r\n\r\n";
    string request = ss.str();

    client.sendrequest(request);
    std::cout << "Pulbic ip is " << Parser::getip(client.readRespose()) << std::endl;
    client.closeConnection();

    // get longitute and attitue

    client.init("api.ipbase.com", 80);
    client.connectToServer();
    /* adjust http request*/
    ss.str("");
    ss << "GET /v1/json/"
       << " HTTP/1.1\r\n"
       << "Host: api.ipbase.com\r\n"
       << "Accept: application/json\r\n"
       << "\r\n\r\n";
    request = ss.str();

    client.sendrequest(request);
    std::cout << "Coordinates: " << Parser::getCordinates(client.readRespose()) << std::endl;
    std::cout << "please visit :<https://www.google.com/maps/> to see your location" << std::endl;
    client.closeConnection();

    return 0;
}