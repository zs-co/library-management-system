#include "User.h"
using namespace std; 

// implementation of the methods... 
User::User(string first_name, string last_name, string username, string password, string email, string role) {
    this->first_name = first_name; 
    this->last_name = last_name; 
    this->username = username; 
    this->password = password; 
    this->email = email; 
    this->role = role; 
    this->is_logged_in = false; 
}

string User::get_first_name() {
    return this->first_name; 
}

string User::get_last_name() {
    return this->last_name; 
}

string User::get_username() {
    return this->username; 
}

string User::get_password() {
    return this->password; 
}

string User::get_email() {
    return this->email; 
}

string User::get_role() {
    return this->role; 
}

void User::set_first_name(string first_name) {
    this->first_name = first_name; 
}

void User::set_last_name(string last_name) {
    this->last_name = last_name; 
}

void User::set_username(string username) {
    this->username = username; 
}

void User::set_password(string password) {
    this->password = password; 
}

void User::set_email(string email) {
    this->email = email; 
}

void User::set_role(string role) {
    this->role = role; 
}

// methods 
void User::print_user() {
    cout << "First Name: " << this->first_name << endl; 
    cout << "Last Name: " << this->last_name << endl; 
    cout << "Username: " << this->username << endl; 
    cout << "Password: " << this->password << endl; 
    cout << "Email: " << this->email << endl; 
    cout << "Role: " << this->role << endl; 
}

// login 
User User::login(string username_or_email, string password) {
    // read user from file and verify login credentials.
    return verify_user_credentials(username_or_email, password);
}

// create user
void User::create_user() {
    // create user and save to file. 
    string first_name, last_name, username, password, email, role;
    cout << "Enter first name: ";
    cin >> first_name;
    cout << "Enter last name: ";
    cin >> last_name;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter role: ";
    cin >> role;
    User user(first_name, last_name, username, password, email, role);
    if (create_user(user)) {
        cout << "User created successfully!" << endl;
    } else {
        cout << "Unable to create user!" << endl;
    }
}

// logout
void User::logout() {
    // logout user. 
    this->is_logged_in = false; 
}

// Destructor
User::~User() {
    // free memory. 
    cout << "User object destroyed!" << endl;
}
