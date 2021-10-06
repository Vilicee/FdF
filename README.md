# FdF
Hive School Project FdF

This project is about creating a simplified 3D graphic representation of a relief landscape. It is made for macos and requires Xquartz to work.

This project comes with a makefile with the following rules:
1. make, this compiles the program and gives you an executable called fdf
2. make clean, removes .o files
3. make fclean, removes .o files .a files and the executable fdf
4. make re, does make fclean ; make

Usage:
./fdf <map> (you can find a bunch of test maps in the test_maps folder)

Controls once the map opens.
1. Move with arrow keys
2. Zoom in '+', zoom out '-'
3. Change view '1', and '2'
4. Make moving and zooming faster, 'f'
5. Make moving and zooming slower 's'
