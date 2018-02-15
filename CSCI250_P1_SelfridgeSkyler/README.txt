String Art 2/14/18
Programmer: Skyler Selfridge

stringArt.cpp can be added to a new VS project and can be rebuilt directly from there. 
However, glut.h,glut32.dll,glut32.lib all must be included in the launching directory.

Alternatively the StringArt application may be launched directly from this folder, so long as
glut.h,glut32.dll,glut32.lib are all included.


By rebuilding the solution, multiple customizations may be achieved such as changing the number of
sections (represented by the variable "divisions"), changing the number of red strings per section
(represented by the constant "STRINGS_ONE"), and changing the number of green strings per section
(represented by the constant "STRINGS_TWO")