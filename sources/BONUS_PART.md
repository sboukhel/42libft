<div align="center">

<img src="https://capsule-render.vercel.app/api?type=venom&color=0:000000,50:0a0a0a,100:111111&height=160&section=header&text=libft%20-%20Bonus&fontSize=55&fontFamily=JetBrains%20Mono&fontColor=ffffff" />

### Bonus Part — Singly Linked List

*A subject-by-subject guide to every function, with documentation & the best video explanations*

</div>

---

## 📚 How this guide is organized

The Bonus part steps away from strings and memory buffers to introduce your **first data structure**: a singly linked list (`t_list`). This is a big conceptual jump — instead of walking a flat array, you're now walking a chain of independently `malloc`'d nodes connected by pointers, which means **pointer-to-pointer (`t_list **`)** manipulation becomes unavoidable (e.g. to modify the head of the list from inside a function).

For each function you'll find:
- **What it does**
- **The concept it's really testing**
- **📖 Documentation**
- **🎥 Best video**

> 💡 The core skill of the Bonus part is: *understand that a list is just nodes holding a pointer to the next node, know when you need `t_list *` vs `t_list **`, and never lose a node's address before freeing it.*

---

## 🔗 The structure

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Every bonus function operates on this structure (or the array-of-strings equivalent for testing). The `void *content` is the same generic-pointer idea from `ft_memset` in Part 1 — it lets a single list type hold *any* kind of data.

---

## 🧩 Category 1 — Creating & Growing the List

| Function | Subject | What it does |
|---|---|---|
| `ft_lstnew` | malloc, struct initialization | Allocates and returns a new list node with the given content |
| `ft_lstadd_front` | pointer to pointer | Adds a new node at the **beginning** of the list (needs `t_list **` to update the caller's head) |
| `ft_lstadd_back` | list traversal | Adds a new node at the **end** of the list (must traverse to find the last node first) |

### 📖 Documentation
- [GeeksforGeeks: Linked List in C](https://www.geeksforgeeks.org/c/linked-list-in-c/) — the general reference for insertion, traversal, and the node/pointer model
- [W3Schools: C Pointer to Pointer (Double Pointer)](https://www.w3schools.com/c/c_pointer_to_pointer.php) — read this before `ft_lstadd_front`; it's the first place in libft you truly *need* a `t_list **`

### 🎥 Best videos
- **[Singly Linked List Explained | Linked List Implementation In C — Simplilearn](https://www.youtube.com/watch?v=nrIeocfcdIc)** — a clean theory-first walkthrough of nodes, `next` pointers, and insertion at head/tail.
- **[How to Implement Linked List in C from Scratch (Full Beginner Tutorial)](https://www.youtube.com/watch?v=1tjnJJMFcaY)** — pairs the theory with actual C code you can trace line by line, close to what `ft_lstnew`/`ft_lstadd_front`/`ft_lstadd_back` ask for.
- **[Working with C Structs Containing Pointers](https://www.youtube.com/watch?v=iAxVfDVBie8)** — useful if `struct s_list *next` inside `struct s_list` itself (a self-referential struct) feels confusing.

> ⚠️ The classic `ft_lstadd_front` mistake: forgetting that you receive `t_list **lst` (address of the head pointer), not `t_list *lst`. If you take `t_list *` instead, you can only change your *local copy* of the head — the caller's list won't actually grow.

---

## 🔍 Category 2 — Reading the List

| Function | Subject | What it does |
|---|---|---|
| `ft_lstsize` | traversal, counting | Counts the number of nodes in a list |
| `ft_lstlast` | traversal | Returns the last node of a list |

### 📖 Documentation
- [GeeksforGeeks: Linked List Traversal](https://www.geeksforgeeks.org/c/linked-list-in-c/) (see the "Traversal" section) — the `while (node->next != NULL) node = node->next;` pattern used by both functions

### 🎥 Best videos
- The Simplilearn and "from scratch" videos above already cover traversal in depth — no separate video needed here. If you want a quick refresher, jump to the traversal section of either.

---

## 🗑️ Category 3 — Deleting & Freeing

| Function | Subject | What it does |
|---|---|---|
| `ft_lstdelone` | memory management, function pointers | Frees a single node's content (via a caller-provided `del` function) and the node itself |
| `ft_lstclear` | full-list deallocation, pointer to pointer | Frees an entire list, node by node, and sets the head pointer to `NULL` |

### 📖 Documentation
- [malloc(3) / free(3) — Linux man page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [C function pointers — cppreference](https://en.cppreference.com/w/c/language/pointer) — needed to understand the `void (*del)(void *)` parameter, since `content` could be anything and only the caller knows how to free it

### 🎥 Best videos
- **[Dynamic Memory Allocation in C - malloc, free, and buffer overflows](https://www.youtube.com/watch?v=wadj1UH2gVQ)** — revisit this from Part 2; the same discipline (never lose a pointer before freeing it) is what makes `ft_lstclear` correct instead of a memory leak or a use-after-free.

> ⚠️ The classic `ft_lstclear` bug: freeing a node and *then* reading `node->next` to continue the loop — that's a use-after-free. Always save `next` in a temporary variable **before** calling `ft_lstdelone`.

---

## 🔁 Category 4 — Applying Functions to the List

| Function | Subject | What it does |
|---|---|---|
| `ft_lstiter` | function pointers, side effects | Applies a function to the content of each node (no return value, modifies in place) |
| `ft_lstmap` | function pointers, new list construction, error handling | Applies a function to each node's content to build and return a **new** list, freeing everything already allocated if any step fails |

### 📖 Documentation
- [C function pointers — cppreference](https://en.cppreference.com/w/c/language/pointer)
- [GeeksforGeeks: Function Pointer in C](https://www.geeksforgeeks.org/c/function-pointer-in-c/) — the map/iterate pattern (passing a function as a parameter) mirrors `map()`/`forEach()` in higher-level languages, implemented manually

### 🎥 Best videos
- No dedicated video is needed if you've already watched the function-pointer material referenced in Part 2 (`ft_strmapi`) — `ft_lstiter` and `ft_lstmap` are the exact same idea (apply a function per element) applied to list nodes instead of string characters.

> ⚠️ `ft_lstmap` is the hardest function in the whole libft project for many students: if `malloc` or the mapping function fails partway through, you must free **every node created so far** before returning `NULL` — a partial list must never leak.

---

## 🧩 Suggested learning order

```
1. Singly linked list theory (watch the videos in Category 1 first)
2. ft_lstnew                              (single node creation)
3. ft_lstadd_front → ft_lstadd_back       (grow the list, master t_list **)
4. ft_lstsize → ft_lstlast                (traversal basics)
5. ft_lstdelone → ft_lstclear             (safe deletion, save `next` before freeing)
6. ft_lstiter → ft_lstmap                 (function pointers over the list, error handling)
```

---

<div align="center">

*Part of the [libft](../README.md) project — 42 / 1337 curriculum.*
*See also: [Part 1 — Libc Functions](./PART1.md) · [Part 2 — Additional Functions](./PART2.md)*

</div>
