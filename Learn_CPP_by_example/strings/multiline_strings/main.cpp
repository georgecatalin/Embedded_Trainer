#include <iostream>
#include <string>

using namespace std;

/*
## `<string>` (C++)
- Provides **C++ string types and utilities**, mainly:
  - `std::string`
  - `std::wstring`, `std::u8string`, `std::u16string`, `std::u32string`
  - string-related functions/operators (concatenation, `size()`, `substr()`, etc.)
- You use it when working with **C++ strings** (objects that manage memory for you).

Example:
```cpp
#include <string>

std::string s = "hello";
```

## `<cstring>` (C++ wrapper for C’s `<string.h>`)
- Provides **C-style string and memory functions** (operating on `char*`, `unsigned char*`, raw buffers), such as:
  - `std::strlen`, `std::strcpy`, `std::strcmp`, `std::strchr`, `std::strstr`
  - `std::memcpy`, `std::memset`, `std::memcmp`, `std::memmove`
- These work on **null-terminated character arrays** (`const char*`) or raw memory, not `std::string` (except you can pass `s.c_str()` to them).

Example:
```cpp
#include <cstring>

const char* p = "hello";
auto n = std::strlen(p);
```

## Why you might see “both work”
1. **Indirect includes**: another header you include might itself include `<string>` or `<cstring>`, so your code compiles “by accident.”
2. **Non-strict implementations**: some standard libraries may pull in extra stuff as an implementation detail.
3. **You’re only using overlapping things** (e.g., maybe you only used `memcpy` and included `<string>` somewhere else that happened to include it indirectly, or vice versa).

## Rule of thumb
- Use **`#include <string>`** when you use `std::string` (or other `std::*string` types).
- Use **`#include <cstring>`** when you use C string/memory functions like `std::strlen`, `std::memcpy`, etc.
- Don’t rely on “it compiles without the right include”—it can break with different compilers/versions or build flags.

*/

int main(void)
{
   string first_name("George");
   string last_name = "Calin";
   string complete_name =  first_name + last_name;

   cout<<"The complete name is "<<complete_name<<endl;


   /* multi line strings */
   string address;
   cout<<"Enter your address, ending with \n"<<endl;
   getline(cin,address,'\n');

   cout<<"the address you entered is : "<<address<<endl;



    return 0;
}