# Read Game Title/ID from WBFS File
Say you backed up your Wii game in WBFS format to a flash drive, and you renamed it for storage and don't know which WBFS is which. Getting the title & ID from the file is the most convenient solution. This is a console application to demonstrate doing just that. There could be a proper guide by its creator / someone else out there, but making this was a fun little exercise.

# Building
I built it with Visual Studio 2013, target system: Windows 32-bit<br>
No additional libs/dependencies, super short & sweet


# Using this release
Once the file name is in the console, press enter to get its title & ID. I recommend dragging & dropping the file from Windows Explorer onto the console, which will put the full file name & path info the console (surrounded by quotes, which are accepted by the program).<br>
Type 'q' and press enter to close the console program when done.


[Here is a quick description on where the data is/how large it is in the file](https://shytyger.blogspot.com/2023/02/where-to-find-game-id-in-wbfs-file.html)<br>
Source.cpp is pretty small and sums it up pretty nicely though.

Happy Wiilaxing~~
