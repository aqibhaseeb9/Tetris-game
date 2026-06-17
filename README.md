# Tetris (C++ / SFML)

A fully functional clone of the classic Tetris, built from the ground up in C++ using the SFML library for rendering, audio, and input handling. The project was designed with clean object-oriented principles at its core — every tetromino is its own class, the game loop drives a real-time falling/locking/clearing cycle, and difficulty scales dynamically as the player progresses.

## Overview

The game runs on a standard 20×10 grid, internally represented as a 2D array that tracks every locked block on the board. Falling pieces are instances of dedicated shape classes, each responsible for its own movement, rotation, and collision behavior against the grid. Once a piece locks into place, the engine checks for completed rows, updates the score, recalculates the difficulty level, and spawns the next piece — repeating continuously until the board fills up and the game ends.

## Features

**Complete Tetromino Set**
All seven standard pieces — I, O, L, J, S, Z, and T — are implemented as individual classes inheriting from a shared `shape` base class. Each piece manages its own rotation states and grid-locking logic independently.

**Real-Time Movement & Control**
Pieces respond instantly to player input, supporting smooth horizontal movement, rotation, and two falling speeds — a default gravity-driven fall and a fast soft-drop.

**Line Clearing & Scoring**
The engine scans the grid for fully completed rows, clears them, shifts the board down accordingly, and rewards the player with points for every line cleared.

**Dynamic Difficulty Scaling**
Fall speed increases progressively as more lines are cleared, following an exponential speed curve. The game cycles through 8 distinct difficulty levels before looping back, keeping long sessions consistently challenging.

**Anti-Repeat Piece Generation**
A built-in check prevents the same tetromino from spawning twice in a row, ensuring more balanced and unpredictable gameplay compared to fully random generation.

**Audio-Visual Feedback**
Background music plays continuously during gameplay, with dedicated sound effects for leveling up and for game-over. A custom game-over screen displays before the window closes.

**Live HUD**
The current score, level, and total lines cleared are displayed on-screen in real time, updating immediately as the game state changes.

## Tech Stack

| Component | Details |
|---|---|
| Language | C++ |
| Library | SFML — Graphics, Window, System, and Audio modules |
| IDE | Visual Studio |

## Controls

| Key | Action | Notes |
|---|---|---|
| `←` | Move left | Shifts the active piece one column left, blocked by walls or locked blocks |
| `→` | Move right | Shifts the active piece one column right, blocked by walls or locked blocks |
| `↑` | Rotate | Rotates the active piece in place, respecting collision boundaries |
| `↓` (hold) | Soft drop | Temporarily increases fall speed for faster placement; releases back to normal gravity speed |

## Project Structure
├── game.h    # Core game loop, grid management, scoring, and level logic
├── shape.h   # Base class shared by all tetrominoes
├── I.h       # I-piece implementation
├── O.h       # O-piece implementation
├── L.h       # L-piece implementation
├── J.h       # J-piece implementation
├── S.h       # S-piece implementation
├── Z.h       # Z-piece implementation
└── T.h       # T-piece implementation
