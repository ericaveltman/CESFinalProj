# CESFinalProj
This project is a 35mm film project that moves film left and right.

<b>What You Need<b> <br>
Software<br>
Arduino IDE<br>
Hardware<br>
ESP32<br>
28BYJ-48 Step Motor<br>
ULN2003 Stepper Motor Driver<br>
4x4 Matrix Keypad<br>
wires<br>
Connections:<br>
Stepper Motor/Driver: The power and ground are connected to 5V power and ground on the breadboard. In 1 is connected to GPIO 4, In 2 to GPIO 0, In 3 to GPIO 2 and In 4 to GPIO 15.<br>
Matrix Keypad: From left to right, the inputs are: GPIO 25, 26, 27 14, 13, 21, 22 and 23. <br>

<b>How To Run (Step by Step):</b> <br>
ESP32 code:<br>
Upload the .ino file to your ESP32 (or other micro controller).<br>
Physical Projector:<br>
Make sure that the first frame of your negative is the one in view.<br>
First input the number of frames, total, on your negative strip. <br>
End all inputs with a *.<br>
All numbers following will be the frame number to view.<br>
