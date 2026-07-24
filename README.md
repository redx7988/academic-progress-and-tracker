# 📊 Academic Progress Tracker — CLI Edition

A terminal-based attendance tracker built in C++ as an OOP practice project. It currently manages a **single student/subject record** at a time, logs daily attendance, and gives you a formatted dashboard with basic "safe bunk" and "catch-up" math baked in.

> **Status:** This is the current (early) build. It's single-record only for now — multi-course support is on the roadmap below.

---

## NOTE
No ai was used in making this . Ai was only used for me learn about new concept and fix some issues . whole code was written by me only .
**NEW FEATURES WILL BE ADDED IN FUTURE TO FIX LIMITATIONS**

---

## ✨ What It Actually Does Right Now

### 📚 Student Record (Create / Read / Update / Delete)
Manage one active record at a time, containing:
- **Name**
- **Subject**
- **Credit**
- **Classes Held**
- **Classes Attended**

The menu blocks you from creating a second record until the existing one is deleted — so at the moment this tracks **one subject per session**, not a full course list.

### 📝 Daily Logger
A separate mini-menu (Option 5) that lets you maintain a present/absent/cancelled count:

| Option | Action |
|:---:|--------|
| 1 | Add a new attendance list (present / absent / cancelled) |
| 2 | Print current attendance counts |
| 3 | Update the attendance list |
| 4 | Show current attendance percentage |
| 5 | Delete the attendance list |
| 6 | Go back to the main menu |

Note: the logger is a standalone counter right now — it isn't yet linked field-by-field to the specific student/subject record, so it behaves as a second independent tracker rather than a per-course log.

Percentage is calculated as `present / (present + absent) * 100`, with cancelled classes excluded from the total.

### 📈 Status Dashboard (Option 6)
Once both a student record **and** an attendance list exist, the dashboard prints a formatted table (via `iomanip`) showing:
- Subject name & credit
- Current attendance percentage
- A simple `|` progress bar (each `|` ≈ 10%)
- A status tag: `[On track]` if ≥ 75%, `[Warn]` if below

Directly below the table, it also prints one of two "smart" calculations:

- **If ≥ 75%:** how many more classes you can safely skip and stay at/above 75%
- **If < 75%:** how many more classes you need to attend to reach 75%

---

## ⚠️ Known Limitations / Things to Fix Next

- **Single record only** — no list/vector of courses yet, so it can't track multiple subjects side by side.
- **Logger isn't tied to a specific subject** — it's a second, separate counter rather than an attendance log per course.
- **Recovery math is simplified** — the "classes needed to reach 75%" calculation checks how far below target you are *right now*, but doesn't account for each class you attend also increasing the total class count. A fully accurate "consecutive classes needed" formula has to solve for that growing denominator.
- **Safe Bunk math uses integer division**, which can round in your favor by a hair near the threshold — worth double-checking with a ceiling-safe calculation.
- **No persistence** — all data is lost when the program exits (nothing is saved to a file).

---

## 🛠️ Tech Stack

- **Language:** C++
- **Formatting:** `iomanip` for aligned terminal tables
- **Paradigm:** Object-Oriented Programming — two classes (`student`, `logger`), constructors, destructors, encapsulated update methods

---

## 📌 Roadmap

- [x] Single-record CRUD (create / read / update / delete)
- [x] Daily attendance logger (present / absent / cancelled)
- [x] Formatted status dashboard
- [x] Basic safe-bunk & catch-up estimate on the dashboard
- [ ] Link logger to a specific subject (currently separate)
- [ ] Multi-course support (`vector<student*>`)
- [ ] Correct the consecutive-classes-needed recovery formula
- [ ] Persistent storage (save/load from file)
- [ ] Export reports (CSV/PDF)

---

## ⚙️ Getting Started

```bash
# Clone the repository
git clone https://github.com/redx7988/academic-progress-and-tracker.git
cd academic-progress-and-tracker

# Compile
g++ -o academic-progress-and-tracker main.cpp

# Run
./academic-progress-and-tracker
```

---

## 🤝 Contributing

This is a personal learning project focused on mastering OOP fundamentals in C++. Suggestions and pull requests are welcome, especially around the multi-course and persistence roadmap items above.

---

## 📄 License

This project is open source and available for free .
