<div align="center">

<img src="https://capsule-render.vercel.app/api?type=venom&color=0:000000,50:0a0a0a,100:111111&height=160&section=header&text=libft%20-%20Part%202&fontSize=55&fontFamily=JetBrains%20Mono&fontColor=ffffff" />

### Additional Part 2 — Extra Functions

*A subject-by-subject guide to every function, with documentation & the best video explanations*

</div>

---

## 📚 How this guide is organized

Part 2 is where **libft stops mimicking libc and starts building your own toolkit**. These functions aren't found in the standard library (except `ft_itoa`-like patterns) — the subject explicitly asks you to design them. This is also where **dynamic memory allocation (`malloc`)** becomes central: almost every function here returns a newly allocated string or array, so **you** are responsible for correct sizing and freeing.

For each function you'll find:
- **What it does**
- **The concept it's really testing**
- **📖 Documentation**
- **🎥 Best video**

> 💡 The core skill of Part 2 is: *count first, allocate exactly once, fill second, always check `malloc` for `NULL`.*

---

## 🧵 Category 1 — String Building Functions (`<stdlib.h>` style, malloc-based)

| Function | Subject | What it does |
|---|---|---|
| `ft_strjoin` | malloc + concatenation | Allocates and returns the concatenation of two strings |
| `ft_substr` | malloc + bounded copy | Allocates and returns a substring from a string, given a start index and length |
| `ft_strtrim` | malloc + trimming | Allocates and returns a copy of a string with characters from a `set` removed from both ends |
| `ft_split` | malloc + double pointers | Allocates and returns a `NULL`-terminated array of strings, splitting the input on a delimiter |
| `ft_itoa` | malloc + integer-to-string conversion | Allocates and returns a string representation of an integer (including negative numbers and `INT_MIN`) |
| `ft_strmapi` | malloc + function pointers | Applies a function to each character of a string (with its index) to build a new string |
| `ft_striteri` (bonus-adjacent) | function pointers, in-place iteration | Applies a function to each character of a string in place, passing its index |

### 📖 Documentation
- [malloc(3) — Linux man page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Why you must always check malloc's return value](https://en.cppreference.com/w/c/memory/malloc)
- [ft_split subject explained in depth (community write-up)](https://github.com/Rapcampo/Ft_split_explained/blob/main/ft_split.md) — walks through the two-pass approach (count words, then allocate and fill)
- [C function pointers — cppreference](https://en.cppreference.com/w/c/language/pointer) (see the function pointer section) — needed for `ft_strmapi`/`ft_striteri`

### 🎥 Best videos
- **[C Dynamic Memory Allocation: malloc, calloc, realloc, & free Explained for Beginners](https://www.youtube.com/watch?v=mbPU0IL9eAo)** — watch this first if `malloc`/`free` and heap vs. stack aren't fully clear yet; every function in this category depends on it.
- **[Dynamic Memory Allocation in C - malloc, free, and buffer overflows](https://www.youtube.com/watch?v=wadj1UH2gVQ)** — good second pass focused on the failure modes (off-by-one allocation, forgetting the `'\0'` byte) that are the #1 source of bugs in `ft_strjoin`/`ft_substr`/`ft_split`.

> ⚠️ For `ft_split` and `ft_substr` specifically: the classic bug is forgetting to `malloc(len + 1)` for the null terminator, or miscounting words when there are consecutive delimiters. Trace through an example like `"   42  1337   "` by hand before coding.

---

## 🖨️ Category 2 — Output Functions (`<unistd.h>`, file descriptors)

| Function | Subject | What it does |
|---|---|---|
| `ft_putchar_fd` | file descriptors | Writes a single character to a given file descriptor |
| `ft_putstr_fd` | file descriptors | Writes a string to a given file descriptor |
| `ft_putendl_fd` | file descriptors | Writes a string followed by a newline to a given file descriptor |
| `ft_putnbr_fd` | file descriptors, recursion | Writes an integer to a given file descriptor (handling negative numbers and `INT_MIN`) |

### 📖 Documentation
- [write(2) — Linux man page](https://man7.org/linux/man-pages/man3/write.3p.html)
- [File descriptors explained — 42 Cursus community guide](https://42-cursus.gitbook.io/guide/useful-tools/file-descriptors-fd) — written specifically for 42 students, covers `0`/`1`/`2` (stdin/stdout/stderr) and how `write()` differs from `printf()`
- [stdin(3) man page — where fd 0/1/2 come from](https://man7.org/linux/man-pages/man3/stdin.3.html)

### 🎥 Best videos
- **[File Descriptor concept dumbed down with simple example](https://www.youtube.com/watch?v=qHE4RdSZdiE)** — the clearest beginner explanation of what a file descriptor actually is and why `0`, `1`, and `2` are reserved for stdin/stdout/stderr — exactly the mental model these four functions need.

> 💡 Since `printf` is a forbidden function at 42, this category is really asking: *"can you build your own tiny print system on top of the raw `write()` syscall?"* `ft_putnbr_fd` is the trickiest because `-INT_MIN` overflows an `int` — you must handle it as a special case (usually by casting to `long` or peeling off the first digit separately).

---

## 🧩 Suggested learning order

```
1. malloc/free fundamentals (watch the videos in Category 1 first)
2. ft_substr → ft_strjoin → ft_strtrim   (all: count length, malloc, fill, NUL-terminate)
3. ft_split                              (hardest: word-counting edge cases)
4. ft_itoa                               (handle sign, handle INT_MIN separately)
5. ft_strmapi → ft_striteri              (function pointers over a string)
6. ft_putchar_fd → ft_putstr_fd → ft_putendl_fd → ft_putnbr_fd  (build on write())
```

---

<div align="center">

*Part of the [libft](../README.md) project — 42 / 1337 curriculum.*
*See also: [Part 1 — Libc Functions](./PART1.md) · [Bonus — Linked List](./BONUS_PART.md)*

</div>
