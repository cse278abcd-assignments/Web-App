#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <iostream>
#include <string>
#include <map>
#include "getpost.h"

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::map;

int main() {
    map<string,string> Get;
    initializePost(Get);
    cout << "Content-type: text/html" << endl << endl;
    cout << "<html><body>" << endl;
    cout << "<h2>Form processed...</h2>" << endl;

 if (Get.find("I Ain't Worried")!=Get.end()) {
        cout << "<p>You selected " << Get["I Ain't Worried"] << endl;
}  if (Get.find("Poker Face")!=Get.end()) {
        cout << "<p>You selected " << Get["Poker Face"] << endl;
}  if (Get.find("Eye of the Tiger")!=Get.end()) {
        cout << "<p>You selected " << Get["Eye of the Tiger"] << endl;
}  if (Get.find("Dream On")!=Get.end()) {
        cout << "<p>You selected " << Get["Dream On"] << endl;
}  if (Get.find("Something in the Orange")!=Get.end()) {
        cout << "<p>You selected " << Get["Something in the Orange"] << endl;
 }
    if (Get.find("All I Want For Christmas is You")!=Get.end()) {
        cout << "<p>You selected " << Get["All I Want For Christmas is You"] << endl;
 }
    if (Get.find("Ocean Drive")!=Get.end()) {
        cout << "<p>You selected " << Get["Ocean Drive"] << endl;
 }  if (Get.find("Stand By Me")!=Get.end()) {
        cout << "<p>You selected " << Get["Stand By Me"] << endl;
    } else {
        cout << "<p>Make a selection and submit form"<<endl;
    }
        cout << "</body></html>" << endl;
    return(0);
}