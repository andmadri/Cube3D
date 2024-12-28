# CUBE3D
Inspired by Wolfenstein3D, this project goal was to render a "3D" dynamic view of a maze by casting rays. Wolfenstein3D, used "rays" to create a first-person shooter experience in a 2D environment, simulating a 3D view by projecting rays from the player's perspective to determine the visible walls and objects in the game. The "ray caster" gives the illusion of depth and perspective without using actual 3D models, allowing for fast and efficient rendering on early computer hardware.

![Untitledvideo-MadewithClipchamp1-ezgif com-video-to-gif-converter (1)](https://github.com/user-attachments/assets/3d0c190c-501a-4ca4-b63b-d7ba127c09ff)

## Build Instructions
First git clone it in your root directory with the name CUBE3D
```bash
git clone git@github.com:andmadri/CUBE3D.git CUBE3D
```

Afterwards move to CUBE3D and run make all, once it's done, you need the executable `cub3D` and a map, all available maps are inside the maps/ folder:
```bash
cd CUBE3D
make all
...
./cub3D maps/long.cub
```

## Maps
The program is design to parse a specific configuration in terms of how maps should be displayed

## Ray Caster Algorithm

## Textures


