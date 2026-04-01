# CopperOS
I wanted to understand operating systems, so I (the coolest guy ever) started building one.

![demo]<img width="1920" height="1028" alt="CopperOS_v 0 2 0" src="https://github.com/user-attachments/assets/15689647-9061-446f-b5d0-22342076819b" />

## What makes it Special?
It's very similar to MS-DOS as it's just a custom shell OS but with the feature of a built-in search engine

## Current stand 
Right now as it's still in beta it isn't really special with some commands and an Ascii logo but as soon as i add internet connection, the first full release will be out too

# How to install/run
First you'll need to clone this repository into your system by pasting this command in your terminal: `git clone https://github.com/Niedrigerregen/CopperOS.git`

After that you'll need to open the Folder in your Terminal with `cd CopperOS` and install the requiered packages

## How to install the required packages
You have to call a different installation file based on which package manager you have. If you have the apt package manager just run `bash bash/apt_install.sh` 
there are also scripts for the dnf manager and the pacman manager where you just have to insert your package manager in the placeholder "name" `bash bash/name_install.sh`

## Compiling the OS
This step is not really necessary as my latest binaries are also comitted into the repository if you want to use them. Anyways if you want to compile it yourself, don't worry about my existing binaries as you
can just overwrite my binaries with your new ones by inserting `bash bash/make.sh` after opening the CopperOS folder if you didn't already

## Optional: Generating a .iso image
There already are .iso images in the releases but if you want to generate your own .iso image you can do it with `grub-mkrescue -o CopperOS.iso iso`

> Note: 
> If you're on Fedora or your package manager is dnf, there might be problems with generating the .iso image with grub, which is why i recommend using a Debian/Ubuntu based system to generate your image

## Running CopperOS
This is also pretty easy with `bash bash/run.sh` which runs the OS in the terminal. Now you're finished!

## Future
At this point i am customizing the OS right now but in the future i will somehow build a connection with the internet with the linux kernel and from that point on i will

- Make my own package Manager and repo with fully TUI programs
- Add a search engine with the "search" command (possibly without an API key like DuckDuckGo's)
- Add a shortcut to any wikipedia page with the "wiki" command
- Make a built-in USB Image Writer just for fun
