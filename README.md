# ❌⭕ Tic-Tac-Toe in C

A terminal-based Tic-Tac-Toe game supporting multiple board sizes, built as a C programming project.

## 🎮 Features
- 3×3, 4×4, and 5×5 board support
- Two-player turn-based gameplay (x and o)
- Row, column, and diagonal win detection
- Tie detection when board is full
- Input validation for invalid or occupied cells
- Move history saved to `moves.txt` with date and time stamps
- Special 3×3 rule: oldest move is removed after each player's 3rd move

## 🛠️ Technologies
- C language
- Dynamic memory allocation (`malloc`, `free`)
- 2D pointer arrays
- File I/O (`fprintf`, `fopen`, `fclose`)
- Time library for timestamps (`time.h`)

## ▶️ How to Run
Compile:
```bash
gcc tictactoe.c -o tictactoe
```
Run:
```bash
./tictactoe        # Linux/Mac
tictactoe.exe      # Windows
```

## 📋 How to Play
- Choose your symbol: `x` or `o`
- Choose board size: 3, 4, or 5
- Enter row and column numbers on your turn
- First to complete a full row, column, or diagonal wins!

## 👥 Authors
- Anara Yusifzada
- Sayali Guliyeva  
- Fidan Muradova
- CENG 23.2
