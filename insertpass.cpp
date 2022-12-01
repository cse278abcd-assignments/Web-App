/*
 * MySQL++ wrapper for the MySQL C APIs.
 * Coonects to sql
 */

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
    cout << "<h2>Form processed...here is what we got</h2>" << endl;

    std::string username;
    std::string password;

    if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end()) {
        username = Get["username"];
        password = Get["password"];
    } else {
        cout << "<p>Fill out the from and press submit"<<endl;
    }
    cout << "</body></html>" << endl;

   
    mysqlpp::Connection conn(false); 
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();

        query << "INSERT into 01774133Users (username, password) VALUES('"+username+"','"+password+"');";

        query.parse();  
        mysqlpp::SimpleResult result = query.execute();

        if(result) {
            cout <<"<p>Query success...\n";
        } else {
            cerr << "Query error: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}