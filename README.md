# Image Manipulation Project

## Overview

This project is a simple image manipulation program written in C. It allows users to create, initialize, and manipulate RGB images by applying various filters.

## Project Structure

The project is organized into the following directories and files:

- **src/:** Contains the source code files.
  - **main.c:** Main program file that drives the image manipulation.
  - **image.c:** Implementation of image-related functions.
  - **image.h:** Header file for image-related functions.
  - **filters.c:** Implementation of image filter functions.
  - **filters.h:** Header file for image filter functions.
  - **utils.c:** Implementation of utility functions.
  - **utils.h:** Header file for utility functions.

- **Makefile:** Build automation file for compiling the project.

## Compilation

To compile the project, use the provided Makefile. Open a terminal and run the following command:

```bash
make
```

This will build the executable `image_manipulation`.

## Usage

Run the compiled executable:

```bash
./image_manipulation
```

The program will prompt you with a menu allowing you to perform various operations on the image.

## Operations

1. **Image Initialization:**
   - Initialize image with random values.
   - Initialize image from keyboard input.
   - Initialize image from a file.

2. **Image Manipulation:**
   - Extract image component (R, G, B).
   - Apply blur filter.
   - Apply edge detection filter.
   - Apply noise reduction filter.

3. **Saving:**
   - Save the modified image to a file.

4. **Quitting:**
   - Quit the program.

## Cleanup

To clean up the compiled files, run:

```bash
make clean
```