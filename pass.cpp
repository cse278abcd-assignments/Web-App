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

    std::string username;
    std::string password;
if (Get.find("username")!=Get.end() && Get.find("password")!=Get.end()) {
        cout << "<p>You entered, username: "<<Get["username"]<<" and password: "<<Get["password"] << endl;
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
        query << "SELECT * FROM 01774133Users";

        query.parse();

    
        mysqlpp::StoreQueryResult result = query.store();

        if(result) {
                cout <<"<p>Query success...\n";
                for (int i = 0; i < result.num_rows(); ++i) {
                        std:: string u = result[i]["username"].c_str();
                        std::string p = result[i]["password"].c_str();
                        if (username == u && password == p) {
                                cout << "Correct username and password\n";
                                cout <<"<p><a href = \"landing.html\">Home</a\n>";
                                cout <<"<p><a href = \"access.html\">Functions</a\n>";
                }
            }
        } else {
            cerr << "Query failed: " << query.error() << endl;
            cout << "Try again" << endl;
        }


        cout << "</body></html>" << endl;
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}
