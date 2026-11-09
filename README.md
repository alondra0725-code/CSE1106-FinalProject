# CSE 1106 Final Project - Option 3: Equipment Health Monitor

Team Members
- Alondra Hernandez 1002267484

Project Description
A Raspberry Pi-based diagnostic application developed for university IT departments to monitor system resource utilization. The program compares usage against a warning threshold, logs diagnostic events, and uses an external LED connected to GPIO 17 to provide a visible warning indicator.

Repository Structure
- src/ — Contains source code (`main.c`) and compiled binaries (`monitor`)
- docs/ — Contains requirements (`requirements.md`), system design (`design.md`), and change logs (`change_log.md`)
- tests/ — Contains the software test plan (`test_plan.md`)
- data/ — Contains output status logs (`status.txt`)

How to Compile and Run
   gcc -o led src.main.c -lpigpio -lpthread
   sudo ./led
