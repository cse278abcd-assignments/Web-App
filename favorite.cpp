#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include "getpost.h"

using namespace std;

int main(int argc, char* argv[]) {

    map<string,string> Get;
    initializePost(Get);
    cout << "Content-type: text/html" << endl << endl;
    cout << "<html><body>" << endl;
    cout << "<h2>Form processed...</h2>" << endl;

    std::string song;
    std::string rate;

    if (Get.find("song")!=Get.end() && Get.find("rate")!=Get.end()) {
        cout << "<p>You entered, song: "<<Get["song"]<<" and rate: "<<Get["rate"] << endl;
        song = Get["song"];
        rate = Get["rate"];
    } else {
        cout << "<p>Fill out the from and press submit"<<endl;
    }
    cout << "</body></html>" << endl;

    // Connect to database with: database, server, userID, password
    mysqlpp::Connection conn(false); // Exceptions suppressed to keep code simple
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();

        query << "INSERT into 01774133Favorite (song, rate) VALUES('"+song+"', '"+rate+"');";

        query.parse();  
        mysqlpp::SimpleResult result = query.execute();
     

        if(result) {
            cout <<"<p>Success...\n";
        } else {
            cerr << "Error: " << query.error() << endl;
              }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}