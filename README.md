# woolong

Final project for San Jac COSC 1437: simplified db

## Setting Up Visual Studio Code (VS Code) for C++ Development

First Follow <https://code.visualstudio.com/docs/languages/cpp> instructions to get VS Code and C++ Support installed

- Install Visual Studio Code
- Add C++ Extension Pack to VS Code
- Install MSYS2 to get g++ (for Windows)
- Add Initial Code to Project
- Ctrl+Shift+B to Run Build Task, select g++ as compilier

Then Follow <https://dev.to/talhabalaj/setup-visual-studio-code-for-multi-file-c-projects-1jpi>

- Install Make
- Set up directory structure (bin/src/include)
- Create and populate Makefile
-- Use this one as template, or reference link above
-- In VS Code, must use tabs and NOT spaces (VS Code has a command to convert indentation properly)
- Now you can:
-- Type 'make' in terminal to build the binary executable
-- Type './bin/main' to run the main.exe
-- Type 'make clean' to clear build artifacts before rebuilding

Recommended to install Git Bash, and use Git bash as the default terminal for VS Code, even in Windows. Will always be using standard Linux terminal syntax and slash-style
