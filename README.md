This project is intended to bridge a BlueTooth gamepad (8bitdo FC30) 
with an Arduino that has a HC-05 module. The idea is to control a
robot from the gamepad.

Status
------
Currently there's only some test code here. Nothing really functional.

Environment
-----------
Using conda to manage the environment.

Export the config:

    conda env export > environment.yml
    
Import the file:
    
    conda env create -f environment.yml
    
Start using the environment:

    source activate robot-control
    
Ideas
-----
* Add sensors to the robot.
* Add some intelligence to the controls.