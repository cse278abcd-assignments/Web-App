// This is from Dr. Q textarea template.
#include <iostream>
#include <string>
#include <map>
#include "getpost.h"

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

    if (Get.find("txtarea")!=Get.end()) {
        cout <<"<p>User entered: " <<  Get["txtarea"] << endl;
} else {
        cout << "<p>Write a comment and submit form"<<endl;
    }
    cout << "</body></html>" << endl;
    return(0);
}
