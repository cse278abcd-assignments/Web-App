/*
 * MySQL++ wrapper for the MySQL C APIs.
 * Connect to SQL
 */

#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "getpost.h"
using namespace std;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[]) {

map<string,string> Get;
    initializePost(Get);
    cout << "Content-type: text/html" << endl << endl;
    cout << "<html><body>" << endl;
    cout << "<h2>Form processed...here is what we got</h2>" << endl;

    std::string song;
    std::string value;

    if (Get.find("song")!=Get.end() && Get.find("value")!=Get.end()) {
        cout << "<p>You entered, song: "<<Get["song"]<<" and value: "<<Get["value"] << endl;
        song = Get["song"];
        value = Get["value"];
    } else {
        cout << "<p>Fill out the from and press submit"<<endl;
    }
    cout << "</body></html>" << endl;

    mysqlpp::Connection conn(false); 
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();
        query << "SELECT * FROM 01774133Sell";
        query.parse();

        mysqlpp::StoreQueryResult result = query.store();

        if(result) {

                cout << "Content-type: text-html\n\n";
                cout << "<html><head><title>CGI to MYSQL</title><body>\n";
                cout << "<table border = 1 width = 600><tr><th>Songs</th><th>Price</th>\n";
            for (int i = 0; i < result.num_rows(); ++i) {
                int sum = 0;
                cout << "<tr><td>" << result[i]["song"] << "</td>" << 
                "<td>" << result[i]["value"] << "</td>" << endl;
            }
                cout << "</table></body></html>\n";
        } else {
            cerr << "Query failed: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}
