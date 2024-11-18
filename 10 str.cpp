#include <iostream>
#include <cstring>
#include "Str.h"

Str::Str() : str(nullptr), length(0) {}

Str::Str(const char* input) {
    length = strlen(input);
    str = new char[length + 1];
    strcpy_s(str, length + 1, input);
}
Str::Str(const Str& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str); 
}
Str::~Str() {
    delete[] str;
}
Str& Str::operator=(const Str& other) {
    if (this == &other) return *this; 
    delete[] str; 

    length = other.length;
    str = new char[length + 1];
    strcpy_s(str, length + 1, other.str); 
    return *this;
}
bool Str::operator==(const Str& other) const {
    return strcmp(str, other.str) == 0;
}
bool Str::operator!=(const Str& other) const {
    return !(*this == other);
}
bool Str::operator<(const Str& other) const {
    return strcmp(str, other.str) < 0;
}
bool Str::operator>(const Str& other) const {
    return strcmp(str, other.str) > 0;
}
bool Str::operator<=(const Str& other) const {
    return *this < other || *this == other;
}
bool Str::operator>=(const Str& other) const {
    return *this > other || *this == other;
}
