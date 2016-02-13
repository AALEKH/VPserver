# VPserver
VelocyPack Server

## VelocyStream Strcuture:
```
|-------------------------------------------|
| length | chunk | isFirstChunk | messageID | 
|-------------------------------------------|
|               Vpack-1                     |
|               Vpack-2                     |
|               Vpack-3                     |
|                 .                         |
|                 .                         |
|               Vpack-n                     |
---------------------------------------------
```

Thanks for Initial Help (LinuxHowTo's): http://www.linuxhowtos.org/C_C++/socket.htm 
