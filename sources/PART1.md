<div align="center">

<img src="https://capsule-render.vercel.app/api?type=venom&color=0:000000,50:0a0a0a,100:111111&height=160&section=header&text=libft%20-%20Part%201&fontSize=55&fontFamily=JetBrains%20Mono&fontColor=ffffff" />

### Mandatory Part 1 — Libc Functions

*A subject-by-subject guide to every function, with documentation & the best video explanations*

</div>

---

## 📚 How this guide is organized

Part 1 groups the functions by the C standard-library header they belong to. For each function you'll find:
- **What it does** (short definition)
- **The concept it's really testing** (the "subject" behind the function)
- **📖 Documentation** — the reference manual to read first
- **🎥 Best video** — a good visual explanation if reading isn't enough

> 💡 Tip: don't just memorize the prototypes. 42/1337 wants you to understand **pointers, memory layout, and undefined behavior** — the functions are just the vehicle.

---

## 🧠 Category 1 — Memory Manipulation (`<string.h>`)

These functions work at the **byte level**, using `void *`, so this is where you'll really learn how pointers and typecasting work.

| Function | Subject | What it does |
|---|---|---|
| `ft_memset` | void pointers, typecasting | Fills a memory block with a constant byte value |
| `ft_bzero` | void pointers | Zeroes out a memory block (built on `memset`) |
| `ft_memcpy` | pointer arithmetic | Copies `n` bytes from one memory area to another (non-overlapping) |
| `ft_memmove` | overlapping memory, buffer direction | Copies `n` bytes safely even if the areas overlap |
| `ft_memchr` | linear search in memory | Finds the first occurrence of a byte in a memory block |
| `ft_memcmp` | byte comparison | Compares two memory areas byte by byte |
| `ft_calloc` | dynamic memory allocation | Allocates zeroed memory (`malloc` + `memset`) |

### 📖 Documentation
- [memset / memcpy / memmove — cppreference](https://en.cppreference.com/w/c/string/byte)
- [Linux man pages: memset(3), memcpy(3), memmove(3), memcmp(3), memchr(3)](https://man7.org/linux/man-pages/man3/memcpy.3.html)

### 🎥 Best videos
- **[ft_memcpy and ft_memmove — 42Born2Code](https://www.youtube.com/watch?v=-cJBiEHIlnw)** — explains exactly the difference the 42 evaluation asks about (why `memmove` must handle overlap and `memcpy` doesn't have to).
- **[Void Pointer in C Demystified](https://www.youtube.com/watch?v=FdR894REHoo)** — start here if `void *b` and the `unsigned char *` typecasting trick confuse you; it's the foundation for `memset`/`memcpy`.
- **[The What, How, and Why of Void Pointers in C and C++ — Jacob Sorber](https://www.youtube.com/watch?v=Vd-4eGnBAK8)** — a systems-level channel, great for understanding *why* `void *` exists and how it's used in real libc code.
- **[Memcpy vs. Memmove in C](https://www.youtube.com/watch?v=s01N_K2VHQs)** — a focused comparison if you want a second explanation of overlap handling.

---

## 🔤 Category 2 — String Manipulation (`<string.h>`)

These build on the memory functions above, but now the data is **NUL-terminated (`'\0'`)**, so bounds and terminators matter.

| Function | Subject | What it does |
|---|---|---|
| `ft_strlen` | NUL-terminated strings | Returns the length of a string (excluding `'\0'`) |
| `ft_strchr` | linear search in a string | Finds the first occurrence of a character |
| `ft_strrchr` | reverse search | Finds the *last* occurrence of a character |
| `ft_strlcpy` | safe copying, buffer size | Copies a string with a size limit, always NUL-terminating |
| `ft_strlcat` | safe concatenation | Appends a string with a size limit, always NUL-terminating |
| `ft_strncmp` | bounded comparison | Compares up to `n` characters of two strings |
| `ft_strnstr` | substring search | Finds a substring within a bounded length |

### 📖 Documentation
- [strlen / strcpy / strcat / strcmp — cppreference](https://en.cppreference.com/w/c/string/byte)
- [strlcpy(3) / strlcat(3) man page (BSD, adopted by 42 norm)](https://man.openbsd.org/strlcpy.3)
- [Why strlcpy/strlcat exist instead of strcpy/strcat — original design paper](https://www.usenix.org/legacy/publications/library/proceedings/usenix99/full_papers/millert/millert.pdf)

### 🎥 Best videos
- **[C Tutorial: String Library Functions (strlen, strcat, strcpy, strcmp)](https://www.youtube.com/watch?v=CJ_pzdZ39N4)** — a clear walkthrough of how these functions treat the null terminator, which is exactly what `ft_strlcpy`/`ft_strlcat` need to replicate safely.
- Pair this with the **void pointer video above** — once you understand pointer walking on `void *`, walking a `char *` until `'\0'` is the same idea with a stopping condition.

> ⚠️ Understanding **why** `strlcpy`/`strlcat` were invented (buffer overflows from `strcpy`/`strcat`) will make the 42 evaluation questions about "safe string handling" much easier to answer.

---

## 🔁 Category 3 — Conversion (`<stdlib.h>`)

| Function | Subject | What it does |
|---|---|---|
| `ft_atoi` | string parsing, ASCII math | Converts a numeric string to an `int`, handling whitespace and signs |

### 📖 Documentation
- [atoi — cppreference](https://en.cppreference.com/w/c/string/byte/atoi)
- [GeeksforGeeks: atoi() Function in C](https://www.geeksforgeeks.org/c/c-atoi-function/) — good for the "convert digit char to int" math (`res * 10 + (c - '0')`)

### 🎥 Best videos
- Search-wise this one is best learned by **reading the algorithm walkthrough** above and tracing it by hand (skip whitespace → check sign → accumulate digits). If you prefer video, any general "**how strings become numbers in C**" explainer from a C fundamentals channel works — the core trick is always the same `(c - '0')` ASCII offset used in the character-classification section below.

---

## 🔡 Category 4 — Character Classification & Conversion (`<ctype.h>`)

| Function | Subject | What it does |
|---|---|---|
| `ft_isalpha` | ASCII ranges | Checks if a character is a letter |
| `ft_isdigit` | ASCII ranges | Checks if a character is a digit |
| `ft_isalnum` | combining predicates | Checks if a character is alphanumeric |
| `ft_isascii` | ASCII table | Checks if a value is a valid ASCII character (0–127) |
| `ft_isprint` | printable range | Checks if a character is printable (space through `~`) |
| `ft_toupper` | case conversion | Converts lowercase to uppercase |
| `ft_tolower` | case conversion | Converts uppercase to lowercase |

### 📖 Documentation
- [ctype.h — cppreference](https://en.cppreference.com/w/c/string/byte)
- [ctype(3) man page — full ASCII predicate table](https://unix.com/man-page/v7/3/ctype/)
- [ASCII Table reference](https://www.asciitable.com/) — keep this open while implementing this whole category; every function here is just a range check against ASCII codes (`'a'`–`'z'` = 97–122, `'0'`–`'9'` = 48–57, etc.)

### 🎥 Best videos
- No single great video exists for this category specifically since it's mostly memorizing ASCII ranges — but understanding the ASCII table (linked above) replaces the need for one. Once you know the letters, digits, and printable range as numbers, every function is a one-line comparison.

---

## 🧩 Suggested learning order

```
1. void pointers (watch the videos in Category 1 first)
2. ft_memset → ft_bzero → ft_memcpy → ft_memmove → ft_memchr → ft_memcmp → ft_calloc
3. ft_strlen → ft_strchr → ft_strrchr → ft_strncmp → ft_strnstr
4. ft_strlcpy → ft_strlcat (read the BSD design paper — it explains *why* they're safer)
5. ft_isascii → ft_isprint → ft_isdigit → ft_isalpha → ft_isalnum → ft_toupper/ft_tolower
6. ft_atoi (combines string parsing + the char classification you just built)
```

---

<div align="center">

*Part of the [libft](../README.md) project — 42 / 1337 curriculum.*
*See also: [Part 2 — Additional Functions](./PART2.md) · [Bonus — Linked List](./BONUS_PART.md)*

</div>
