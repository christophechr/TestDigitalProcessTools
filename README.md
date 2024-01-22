# Test for DigitalProcessTools

## Description

The project is a test for DigitalProcessTools.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)

## Installation

Requirement : 
- CMake 3.10 or higher
- C++17 compiler

```bash
git clone https://github.com/christophe-chr/TestDigitalProcessTools.git
cmake -S . -B build
cmake --build build
./build.sh
```

## Usage

```bash
./escalator [max_floor] [min_floor] [current_floor] [option_floor_buttons : 0 or 1]
```