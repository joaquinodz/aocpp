# Argentum Online C++
MMORPG Video Game of the year 1999 created in Visual Basic 6.0 by Pablo Marquez (Morgolock), this game is open source under the "GNU General Public License".  

I have translated in C++ under SDL2, this game would be your base client, it would be necessary to implement the multiplayer with your server.

# How to compile
Clone the repository, remember to also clone the submodules.
```
git clone --recursive https://github.com/joaquinodz/aocpp
```

First, you need to **configure** the Project.

- On Windows: `cmake --preset windows-debug-x64`
- On Linux: `cmake --preset linux-debug-x64`

Then, you can **compile** it
- On Windows: `cmake --build --preset windows-debug-x64`
- On Linux: `cmake -build --preset linux-debug-x64`

Steps for windows:
http://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php

# Images
![a](https://user-images.githubusercontent.com/82490615/141686424-f6b579a0-5c03-4aa9-826d-0d4c0d9ed17f.png)
![asd](https://user-images.githubusercontent.com/82490615/141686445-5df67c70-f752-4ccb-83f5-f9eb0905c2e7.png)

# Thanks to:
Pablo Marquez (Morgolock) creator of Argentum Online

The GS-Zone people: http://gs-zone.org/

Lazy Foo' Productions and their tutorials: http://lazyfoo.net/tutorials/SDL/index.php#Hello%20SDL
