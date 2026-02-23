
## 1. The Building Blocks: Bitwise Operators

To understand this code, you need to know three specific tools:

* **AND (`&`)**: Compares bits. `num & 1` checks if the very last bit is a 1 or a 0.
* **OR (`|`)**: Combines bits. Used here to "set" a bit in our new number.
* **Shifts (`<<` and `>>`)**: Moves bits left or right. It’s like moving decimal points, but in binary.

---

## 2. Step-by-Step Breakdown

### The Setup

```c
int reverse_num = 0; // Our "bucket" to store the reversed result.
unsigned int count = sizeof(int) * 8 - 1; // How many shifts are possible.

```

On most modern systems, an `int` is 4 bytes. Since 1 byte = 8 bits, `sizeof(int) * 8` gives us **32 bits**. We subtract 1 because we start counting from position 0.

### The Loop: The "Conveyor Belt"

The loop processes the number from right to left:

```c
while (num != 0) {
    int last_bit = num & 1;           // 1. Grab the rightmost bit of 'num'
    reverse_num = reverse_num | last_bit; // 2. Put that bit into 'reverse_num'
    reverse_num = reverse_num << 1;   // 3. Make room by shifting 'reverse_num' left
    num = num >> 1;                   // 4. Discard the bit we just processed from 'num'
    count--;                          // 5. Keep track of unused bit positions
}

```

### The Final Alignment

```c
reverse_num = reverse_num << count;

```

If your input number was small (like the number `5`, which is `101` in binary), the loop finishes early. However, an `int` has 32 slots. This line slides the reversed bits all the way to the end to ensure the entire 32-bit integer is properly reversed.

---

## 3. C Version Nuances (C89 vs C99 vs C11)

Since you asked about the versions, here is a quick "Mentor Note" on how this code relates to them:

| Feature | C89/C90 | C99 | C11 |
| --- | --- | --- | --- |
| **Variable Placement** | Must declare all variables at the very top of the function. | Can declare variables anywhere (like `int last_bit` inside the loop). | Same as C99, plus better support for multi-threading. |
| **Integers** | `int` size was more ambiguous across systems. | Introduced `<stdint.h>` (e.g., `uint32_t`) for guaranteed bit-widths. | Added `_Generic` expressions (not used here, but cool!). |

**My Advice:** In modern C (C99 and later), we prefer using `unsigned int` for bit manipulation to avoid "Sign Extension" issues where the computer tries to preserve the negative sign of a number during a shift.

---

## 4. Complete Code Example

Here is the code cleaned up with a `main` function so you can run it and see the result:

```c
#include <stdio.h>

int reverse_bits(int num) {
    int reverse_num = 0;
    /* We use unsigned to ensure we don't get unexpected behavior with signs */
    unsigned int count = sizeof(int) * 8 - 1;

    while (num != 0) {
        int last_bit = num & 1;
        reverse_num = reverse_num | last_bit;
        reverse_num = reverse_num << 1;
        num = num >> 1;
        count--;
    }

    reverse_num = reverse_num << count;
    return reverse_num;
}

int main() {
    int input = 5; // Binary: 000...000101
    int result = reverse_bits(input);
    
    printf("Original: %d\n", input);
    printf("Reversed: %d\n", result); 
    
    return 0;
}

```

---

## Helpful Links

* [Bitwise Operators in C (GeeksforGeeks)](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
* [C Standard Versions (Wikipedia)](https://www.google.com/search?q=https://en.wikipedia.org/wiki/C_(programming_language)%23Standardization)
* [Visualizing Binary Numbers](https://baseconvert.com/)

**Would you like me to explain how "Sign Extension" works and why it can sometimes break bit-shifting with negative numbers?**