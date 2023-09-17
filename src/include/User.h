#include <iostream> 
#include <string>
#include "../utils/helper.h"

using namespace std; 

// This is a class declaration.
class User {
    private:
        string first_name;  
        string last_name;  
        string username;  // can be used for login.   
        string password; 
        string email; // can be used for login. 
        string role;
        bool is_logged_in; // check if user is logged in. 

    public: 
        // Constructor
        User(string first_name, string last_name, string username, string password, string email, string role); 

        // Getters
        string get_first_name(); 
        string get_last_name(); 
        string get_username(); 
        string get_password(); 
        string get_email(); 
        string get_role(); 

        // Setters
        void set_first_name(string first_name); 
        void set_last_name(string last_name); 
        void set_username(string username); 
        void set_password(string password); 
        void set_email(string email); 
        void set_role(string role); 

        // Destructor
        ~User();

        // Methods
        void print_user();
        static User login(string username, string password);
        static void create_user();
        void logout();
}; 

