<div align="center">

<img src="https://capsule-render.vercel.app/api?type=venom&color=0:000000,50:0a0a0a,100:111111&height=200&section=header&text=libft&fontSize=90&fontFamily=JetBrains%20Mono&fontColor=ffffff" />

[![typing](https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=500&size=16&duration=3000&pause=800&color=1D9E75&center=true&vCenter=true&multiline=false&width=580&lines=A+custom+C+library;reimplementing+essential+libc+functions;for+42+School+Curriculum)](https://github.com/sboukhel)

<p align="center">
  <img src="https://res.cloudinary.com/dpwnvpf63/image/upload/v1749674109/UM6P_1337_hqcnme.jpg" alt="1337 Logo" width="160" style="border-radius: 15%;" />
  &nbsp;&nbsp;&nbsp;
  <img src="https://res.cloudinary.com/dpwnvpf63/image/upload/v1749675535/42_network_logo.jpg" alt="42 Network Logo" width="160" style="border-radius: 15%;" />
</p>

---

# school badges
<a href="https://1337.ma"><img src="https://img.shields.io/badge/1337-000000?style=for-the-badge&logo=42&logoColor=1D9E75&labelColor=0d0d0d"/></a>
<a href="https://42network.org"><img src="https://img.shields.io/badge/-Network-000000?style=for-the-badge&logo=42&logoColor=ffffff&labelColor=0d0d0d"/></a>
<img src="https://img.shields.io/badge/language-000000?style=for-the-badge&logo=c&logoColor=5577aa&labelColor=0d0d0d"/>
<img src="https://img.shields.io/badge/status-active-000000?style=for-the-badge&logo=github&logoColor=1D9E75&labelColor=0d0d0d"/>

---

# live repo stats

<img src="https://img.shields.io/github/stars/sboukhel/libft.a?style=for-the-badge&label=%E2%98%85%20stars&labelColor=0d0d0d&color=111111&logoColor=ffffff"/>
<img src="https://img.shields.io/github/forks/sboukhel/libft.a?style=for-the-badge&label=%E2%80%A6%20forks&labelColor=0d0d0d&color=111111"/>
<img src="https://img.shields.io/github/last-commit/sboukhel/libft.a?style=for-the-badge&label=%E2%86%91%20pushed&labelColor=0d0d0d&color=111111&logo=git&logoColor=1D9E75"/>
<img src="https://img.shields.io/github/repo-size/sboukhel/libft.a?style=for-the-badge&label=%E2%96%A6%20size&labelColor=0d0d0d&color=111111"/>

</div>

<br/>

---

## 📝 Description

**libft.a** is a comprehensive C library project from the 42 School curriculum. It recreates essential libc functions from scratch, focusing on deep understanding of memory management, string manipulation, and character handling in C.

This project serves as a foundation for all subsequent 42 projects, providing a solid toolkit of fundamental functions.

---

## 🎯 Key Features

### Memory Management Functions
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Move memory (handles overlaps)
- `ft_memchr` - Search for byte in memory
- `ft_memcmp` - Compare memory areas
- `ft_calloc` - Allocate zeroed memory

### String Manipulation Functions
- `ft_strlen` - Get string length
- `ft_strchr` - Find character in string
- `ft_strrchr` - Find last occurrence of character
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate with size limit
- `ft_strdup` - Duplicate string
- `ft_strjoin` - Join two strings
- `ft_substr` - Extract substring
- `ft_strncmp` - Compare n characters
- `ft_strnstr` - Find substring (bounded)

### Character Classification & Conversion
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum` - Character type checks
- `ft_isascii`, `ft_isprint` - Printable character checks
- `ft_toupper`, `ft_tolower` - Case conversion
- `ft_atoi` - Convert string to integer

---

## 📋 the rules

42 enforces a strict coding standard called **Norminette** — every file in this repo passes it.

```c
/*
**  norminette constraints
**  ─────────────────────────────────────────
**  function body      →  25 lines max
**  declared variables →  5 per function
**  loops              →  while only  (no for)
**  assignments        →  never inside conditions
**  forbidden          →  printf · global vars
**  memory leaks       →  zero tolerance
*/
