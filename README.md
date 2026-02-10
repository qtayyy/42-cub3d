# cub3d

A simplistic 3D game engine inspired by the classic Wolfenstein 3D, built using the 42 MiniLibX library.

## Description

Cub3d is a project that explores the fascinating world of raycasting. It renders a 3D perspective from a 2D map by casting rays from the player's viewpoint and calculating intersections with walls. This project deepens understanding of trigonometry, matrix transformations, and graphics rendering.

## Features

-   **Raycasting Engine**: Real-time 3D rendering of a maze-like environment.
-   **Texture Mapping**: Support for different textures on North, South, East, and West walls.
-   **Floor & Ceiling Colors**: Customizable RGB colors for the floor and ceiling.
-   **Player Movement**: Smooth movement (WASD) and rotation (Arrow keys).
-   **Collision Detection**: Prevents the player from walking through walls.
-   **Map Parsing**: Reads `.cub` configuration files to set up the game world, checking for valid map structure and enclosed spaces.

## Controls

| Key | Action |
| :--- | :--- |
| `W` | Move Forward |
| `S` | Move Backward |
| `A` | Move Left (Strafe) |
| `D` | Move Right (Strafe) |
| `←` | Rotate Left |
| `→` | Rotate Right |
| `Esc` | Quit Game |

## Getting Started

### Prerequisites

-   `gcc` or `clang`
-   `make`
-   `minilibx` (included or system installed)
-   `X11` libraries (for Linux)

### Installation & Usage

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/qtayyy/42-cub3d.git
    cd 42-cub3d
    ```

2.  **Compile the program:**
    ```bash
    make
    ```

3.  **Run the game:**
    Provide a valid `.cub` map file as an argument.
    ```bash
    ./cub3D maps/walls.cub
    ```
    *(Note: Ensure map files exist in the `maps/` directory)*
