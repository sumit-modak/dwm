# My fork of dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X

# Added Patches
- [`PerTag`](https://dwm.suckless.org/patches/pertag/) : It is the most used patch with dwm which enables you to use different layouts in different tags
- [`AttachBottom`](https://dwm.suckless.org/patches/attachbottom/) : By default, dwm adds new window to the top of the stack in master area. Sometimes this becomes quite annoying to work with. So, this patch fixes that issue by spawning new window in bottom of the stack
- [`AlwaysCenter`](https://dwm.suckless.org/patches/alwayscenter/) : By default, in floating layout mode dwm spawn new window in the leftmost side of the screen which is solved by adding this patch
- [`FullGaps`](https://dwm.suckless.org/patches/fullgaps/) : This patch enables you to change gaps between windows (works only in tiling mode)
- [`HideVacantTags`](https://dwm.suckless.org/patches/hide_vacant_tags/) : By default, dwm shows all the tags even if they are unused. So, to change that this patch is added.
- [`MoveStack`](https://dwm.suckless.org/patches/movestack/) : Dwm doesnt provides you the functionality to move a window (up or down) the stack. This patch fixes that issue by enabling the user to move windows freely.
- [`GaplessGrid`](https://dwm.suckless.org/patches/gaplessgrid/) : I added this layout instead of grid mode layout because it doesnt leaves extra gaps while spawning the window.
- [`PreserveOnRestart`](https://dwm.suckless.org/patches/preserveonrestart/) : This patch keeps the windows on their present tag after restarting dwm. By default, it moves all the windows to the first tag.

## Partially Patched
- [`BottomStack`](https://dwm.suckless.org/patches/bottomstack/) : There are two layouts in bottomstack patch (bstack & bstackhoriz) only the bstack layout is added.
- [`CenteredMaster`](https://dwm.suckless.org/patches/centeredmaster/) : There are two layouts in centeredmaster patch (centeredmaster & centeredfloatingmaster) only the centeredmaster layout is added.

## Mannually Patched
- `Added Title Bar Color Scheme`:The default bar in dwm doesnt provides a functionality to change background and foreground of the window title seperately. I mannually changed this issue by adding an extra color scheme
- `Weird Little Boxes Removed`: When there is an window open in some tag dwm represents with a small box at the top of the tag number. Which is removed because its looks dirty.

# How layouts are added
I tested out 13 different layouts for a week from them I added only 3 of them which I found really functional in some cases. List of those layouts are: [`BottomStack & BottomStackHoriz`](https://dwm.suckless.org/patches/bottomstack/), [`CenteredMaster & CenteredFlaoatingMaster`](https://dwm.suckless.org/patches/centeredmaster/), [`GaplessGrid`](https://dwm.suckless.org/patches/gaplessgrid/),[`GridMode`](https://dwm.suckless.org/patches/gridmode/), [`HorizGrid`](https://dwm.suckless.org/patches/horizgrid/), [`ThreeColumn`](https://dwm.suckless.org/patches/three-column/), [`Columns`](https://dwm.suckless.org/patches/columns/), [`TileWide`](https://dwm.suckless.org/patches/tilewide/), [`Tatami`](https://dwm.suckless.org/patches/tatami/), [`FibonacciSpiral & FibonacciDwindle`](https://dwm.suckless.org/patches/fibonacci/), [`Deck`](https://dwm.suckless.org/patches/deck/)

If you are trying to test these layouts you will find that few layouts are mostly same and few layouts lacks functionality.

# Dependencies
In order to build dwm you need the Xlib (`libX11`, `libXft`, `libXinerama` mainly because most of the time during server installation these are not downloaded) header files.

# Installation
```
git clone https://github.com/sumit-modak/dwm.git &&
cd dwm &&
sudo make clean install
```

# Running dwm
Add the following line to your `.xinitrc` to start dwm using startx
```
exec dwm
```
For restarting dwm add these lines instead of the upper one
```
while true; do
  dwm 2> ~/.cache/.dwm.log
done
```
### Multimonitor setup
In order to connect dwm to a specific display, make sure that the DISPLAY environment variable is set correctly, e.g.
```
DISPLAY=foo.bar:1 exec dwm
```
This will start dwm on display :1 of the host foo.bar

# Adding patches to dwm
Download the patch in the patches/ directory, and run the following command
```
patch -p1 patches/dwm-<patch_file_name>.diff
```
```
rm config.h && sudo make clean install
```
Restart dwm to see the changes

# For more information about dwm visit
https://wiki.archlinux.org/title/dwm