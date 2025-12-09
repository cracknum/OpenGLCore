# introduction

The main goal of this repository is to provide a low-level encapsulation of glad and glfw, to avoid multiple initializations of glad across different modules, and to bind glad and glfw together with the window, so that each window has its own context.

## notice

This repository is developed for Windows and is not suitable for Unix systems because the symbol table mechanism in Unix systems is different from Windows.
