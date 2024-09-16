# Daisy Primer

## Author

Scruffy Cat Studios - 2024

## Description

This is my primer for using VSCode with libDaisy. The following assumptions are made.

1. You have checkout the DaisyExamples repo and followed the MyProj example. See: https://github.com/electro-smith/DaisyExamples/tree/master
2. Directory structure should be something like: ${HOME}/DaisyExamples/MyProjects/ThisProject
3. If you need to change the location you can do so but you need to make sure you also update the Makefile and possibly .vscode/c_cpp_properties.json.
4. I have modified .vscode/tasks.json to include a serial_monitor and build_and_program_dfu_serial_monitor tasks. These work on MacOS only!!! Sorry windowse guys, I'm a linux/mac guy.... Please note that to get this to work you'll need to modify the task with the port used by YOUR setup, this was how it shows on my system and well I making this for me mainly.

## How I use this.

Simple really, I clone this repo, re-initialize it after chaning project settings...


1. Download or Clone into your project foler (assuming DaisyExamples/MyProjects)
2. Update Makefile and change the name of the project.
3. Do a git init on this new repo, and configure with new remote origin.