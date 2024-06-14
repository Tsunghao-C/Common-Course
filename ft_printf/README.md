# 42 Common Core Project - ft_printf

## Objective

1. Replicate the printf function in the library stdio.h.
2. For mandatory part, only replicate the the specifiers of c, i, u, d, x, X, p, and %.
3. For bonus part, need to add the flags of '-', '.', '0', '+', ' ', '#', and the minimun length.

## Key Concept

1. Variadic Functions
2. Understanding of put_number_base
3. Understanding of data type (ex. unsigned number vs signed number)
4. [Optional] Using typedef struct for flags management.

Note:
    I didn't know the method of creating a struct to store and manage flags. It should be a more clever and stuctured wya to handle the flags. So instead, I used arrays to store the flags and created way much more helper functions for the bonus part.

## Flags in printf (from chatGPT)

The `+` and space (` `) flags are only applicable to signed integer conversions (`d` and `i`) and floating-point conversions (`f`, `e`, `g`). They do not have any effect on unsigned conversions (`u`, `o`, `x`, `X`). The `+` flag forces a sign (`+` or `-`) to be shown before the number, and the space flag inserts a space before positive numbers. These are irrelevant for unsigned integers since they are always non-negative.

Here’s a summary of how flags apply to different specifiers in `printf`:

### Applicable Flags by Specifier

| Specifier | Description                          | Applicable Flags       | Non-Applicable Flags  |
|-----------|--------------------------------------|------------------------|-----------------------|
| `d`, `i`  | Signed decimal integer               | `- + 0` (space)        | `#`                   |
| `u`       | Unsigned decimal integer             | `- 0`                  | `+` (space) `#`       |
| `o`       | Unsigned octal                       | `- 0 #`                | `+` (space)           |
| `x`, `X`  | Unsigned hexadecimal                 | `- 0 #`                | `+` (space)           |
| `c`       | Character                            | `-`                    | `+` (space) `0` `#`   |
| `s`       | String                               | `-`                    | `+` (space) `0` `#`   |
| `p`       | Pointer                              | `- 0`                  | `+` (space) `#`       |
| `%`       | Literal `%`                          | `- 0`                  | `+` (space) `#`       |
| `n`       | Number of characters written so far  | (none)                 | (all flags)           |

### Examples to Illustrate

1. **Signed Integer with Flags:**
   ```c
   printf("%+d\n", 42);   // Output: "+42"
   printf("% d\n", 42);   // Output: " 42"
   printf("%05d\n", 42);  // Output: "00042"
   ```
   Explanation: `+` shows the sign, space (` `) adds a space before positive numbers, and `0` pads with zeros.

2. **Unsigned Integer with Ignored Flags:**
   ```c
   printf("%+u\n", 42);   // Output: "42"
   printf("% u\n", 42);   // Output: "42"
   printf("%05u\n", 42);  // Output: "00042"
   ```
   Explanation: `+` and space (` `) are ignored because the number is unsigned, but `0` still pads with zeros.

3. **Unsigned Octal with Flags:**
   ```c
   printf("%#o\n", 42);   // Output: "052"
   printf("%0#6o\n", 42); // Output: "000052"
   ```
   Explanation: `#` adds a leading zero to the octal number, and `0` pads with zeros to meet the width.

4. **Unsigned Hexadecimal with Flags:**
   ```c
   printf("%#x\n", 255);  // Output: "0xff"
   printf("%0#10x\n", 255); // Output: "0x000000ff"
   ```
   Explanation: `#` adds a `0x` prefix, and `0` pads with zeros.

5. **Pointer with Flags:**
   ```c
   int a = 42;
   printf("%15p\n", (void*)&a); // Output: "    0x7ffdfdf074"
   printf("%-15p\n", (void*)&a); // Output: "0x7ffdfdf074    "
   ```
   Explanation: `15` specifies the width, and `-` left-justifies the pointer address.

By understanding which flags are applicable to each specifier, you can format your output accurately and as intended using `printf`.
