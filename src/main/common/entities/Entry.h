#ifndef DATABASE_ENTRY_H
#define DATABASE_ENTRY_H

#include <string>

class Entry {
    private:
        std::string name;
        std::string address;
        std::string phone;
    public:
        Entry(std::string& name, std::string& address, std::string& phone);
        Entry(std::string& entry_str);
        std::string& get_name();
        std::string& get_address();
        std::string& get_phone();
        std::string to_string() const;
};


#endif //DATABASE_ENTRY_H
