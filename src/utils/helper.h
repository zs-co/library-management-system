#include <iostream> 
#include <string>
#include <vector>
#include <fstream>
#include "../include/User.h"

using namespace std; 


User verify_user_credentials(string username_or_email, string password); 
bool create_user(User user);



// implementation of the methods...
User verify_user_credentials(string username_or_email, string password) {
    const string file_path = "../files/users.bin";
    ifstream file(file_path, ios::binary);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<string> user_data;
            string delimiter = ",";
            size_t pos = 0;
            string token;
            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                user_data.push_back(token);
                line.erase(0, pos + delimiter.length());
            }
            user_data.push_back(line);
            if (user_data[3] == username_or_email || user_data[4] == username_or_email) {
                if (user_data[5] == password) {
                    cout << "Login successful!" << endl;
                    return;
                }
            }
        }
        cout << "Invalid credentials!" << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }
}

bool create_user(User user) {
    const string file_path = "../files/users.bin";
    ofstream file(file_path, ios::binary | ios::app);
    if (file.is_open()) {
        file << user.get_first_name() << "," << user.get_last_name() << "," << user.get_username() << "," << user.get_password() << "," << user.get_email() << "," << user.get_role() << endl;
        file.close();
        return true;
    } else {
        cout << "Unable to open file!" << endl;
        return false;
    }
}