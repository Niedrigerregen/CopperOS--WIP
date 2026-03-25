# CopperOS
I wanted to understand operating systems, so I (the coolest guy ever) started building one.

![demo](https://private-user-images.githubusercontent.com/210904552/569336544-5fbf724d-d943-4137-98b9-70a703f26223.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NzQ0NzMwODEsIm5iZiI6MTc3NDQ3Mjc4MSwicGF0aCI6Ii8yMTA5MDQ1NTIvNTY5MzM2NTQ0LTVmYmY3MjRkLWQ5NDMtNDEzNy05OGI5LTcwYTcwM2YyNjIyMy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjYwMzI1JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI2MDMyNVQyMTA2MjFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT02NzAzZjAwNjYwMDdlYjE1NTIyNjI3NTljNzQxMmFmZjU5NTFjYjcwYTEzZTBhOGNkMzU1ZGU4Njc0NTQ1YjU1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.-GOp_HT8IxFqiWbAyQKfYNTorwFdJb_gv1PScVEEv2o)

## What makes it Special?
It's very similar to MS-DOS as it's just a custom shell OS but with the feature of a built-in search engine

## Limits
Obviously as it's all text based it only supports TUI so websites like Youtube sadly won't be supported

## Future
At this point i am customizing the OS right now but in the future i will somehow build a connection with the internet with the linux kernel and from that point on i will

- Make my own package Manager and repo with fully TUI programs
- Add a search engine with the "search" command (possibly without an API key like DuckDuckGo's
- Add a shortcut to any wikipedia page with the "wiki" command
- Make a built-in USB Image Writer just for fun

## How things are right now
The first pre-release version is out and it can show you commands with the "help" command and clear your mess with the "clear" command, which doesn't remove the Ascii Art in the beginning.

### What it can't do
Well, i didn't tell you that help and clear are also the only working commands as they are built into the shell for modifiability but the linkers on the other commands did really compile well. Or it's some other reason i didn't check it thouroghly
It's also going to be a Live OS/VM OS for a long while and somehow can't boot with any VM BUT QEMU and i accept that.
