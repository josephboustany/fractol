
# Fract-ol

Fract-ol is a fractal rendering project, created as part of the 42 School curriculum. This project visualizes complex mathematical sets, including the Mandelbrot and Julia sets, and offers interactive features for exploring these fascinating shapes.

## Features

- **Fractal Sets**: Supports Mandelbrot and Julia fractal sets.
- **Zoom & Pan**: Explore fractals in detail by zooming in/out and panning around.
- **Customizable Parameters**: Adjust parameters to modify the appearance of the fractal.
- **Keyboard and Mouse Interactions**: Use keyboard keys and mouse controls for intuitive navigation and customization.

## Files Overview

- **`main.c`**: Initializes the program and handles user input.
- **`fractol.h`**: Header file containing structure definitions, constants, and function prototypes.
- **`fractal_rendering.c`**: Handles the mathematical calculations and rendering logic for fractals.
- **`initialize_rendering.c`**: Manages the setup for rendering, including window and graphics initialization.
- **`event_handlers.c`**: Contains event management functions for handling user interactions.
- **`graphics_utils.c`**: Provides helper functions for drawing and color calculations.
- **`input_handler.c`**: Processes user inputs from the keyboard and mouse.
- **`view_movements.c`**: Implements functionality for panning and moving the view around the fractal.
- **`zoom_utils.c`**: Manages zoom calculations and scaling for better control over fractal navigation.
- **`Makefile`**: Compiles the project, generating the executable.

## Installation

To build the project, ensure that you have [MiniLibX](https://github.com/42Paris/minilibx-linux) and necessary dependencies (such as OpenGL) installed. Then, simply run the following command:

```bash
make
```

This will generate an executable named `fractol`.

## Usage

Run the program with:

```bash
./fractol [fractal_type]
```

### Fractal Types

- **Mandelbrot**: `./fractol mandelbrot`
- **Julia**: `./fractol julia`

### Controls

- **Zoom In/Out**: `+` and `-` keys on the numpad
- **Pan**: Arrow keys or mouse dragging
- **Reset**: `R`
- **Exit**: `ESC`

## Requirements

- MiniLibX library
- OpenGL
- Compatible with macOS and Linux

## Project Goals

The goal of this project is to provide an interactive experience with fractals, utilizing complex mathematical calculations and real-time rendering techniques. This project also helps build a solid foundation in graphics programming.

## Acknowledgments

This project was completed as part of the 42 School curriculum. Special thanks to the contributors and instructors who provided guidance along the way.
