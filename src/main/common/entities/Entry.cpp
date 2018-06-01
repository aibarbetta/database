#include "Entry.h"

#include <sstream>
#include <src/main/common/definitions/EntryData.h>

const static char SEPARATOR = ',';

Entry::Entry(std::string& name, std::string& address, std::string& phone)
        : name(name), address(address), phone(phone) {}

Entry::Entry(std::string& entry_str) {
    std::stringstream ss(entry_str);
    std::string arg;

    std::getline(ss, arg, SEPARATOR);
    name = arg;
    std::getline(ss, arg, SEPARATOR);
    address = arg;
    std::getline(ss, arg, SEPARATOR);
    phone = arg;
}

std::string Entry::to_string() const {
    std::stringstream ss;
    ss << name << SEPARATOR << address << SEPARATOR << phone << std::endl;
    return ss.str();
}

EntryData Entry::serialize(long type) const {
    EntryData data;
    data.mtype = type;

    name.copy(data.name, );

    return data;
}