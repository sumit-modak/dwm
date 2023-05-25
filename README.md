# My fork of dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X.

# Dependencies
In order to build dwm you need the Xlib header files.

# Installation
Edit config.mk to match your local setup (dwm is installed into the /usr/local namespace by default).
Afterwards enter the following command to build and install dwm
```
    sudo make clean install
```

# Running dwm
Add the following line to your .xinitrc to start dwm using startx
```
    exec dwm
```
In order to connect dwm to a specific display, make sure that the DISPLAY environment variable is set correctly, e.g.
```
    DISPLAY=foo.bar:1 exec dwm
```
This will start dwm on display :1 of the host foo.bar

# In order to display status info in the bar, add this script to your .xinitrc file 
https://github.com/sumit-modak/linux-rice/blob/master/.local/bin/setstatus

# For adding patches to dwm
Download the patch in the patches/ directory, and run the following command
```
    patch -p1 patches/<patch_file_name>
```
```
    rm config.h && sudo make clean install
```
Restart dwm to see the changes
