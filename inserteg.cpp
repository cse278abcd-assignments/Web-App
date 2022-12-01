#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <unistd.h>
#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[]) {
    std::string username;
    cout << "Enter username: ";
    cin >> username;
    char *password = getpass("Enter password: "); 

   
    mysqlpp::Connection conn(false); 
    if(conn.connect("cse278", "localhost", "cse278", "MonSepM1am1")) {

        // Create a query
        mysqlpp::Query query = conn.query();

        query << "INSERT into 01774133Users (username, password) VALUES('"+username+"', '"+password+"');";
     

        query.parse();  
        mysqlpp::SimpleResult result = query.execute();
       
        if(result) {
           cout <<"Query success\n";
        } else {
             cerr << "Query error: " << query.error() << endl;
        }
        return(0);
    } else {
        cerr << "Connection failed: " << conn.error() <<endl;
        return(1);
    }
}
