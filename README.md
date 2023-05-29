# Battle City

Little fun terminal-style game for MacOS.

## Project Structure
```
PROJECT_ROOT
├── assets/
│   ├── docs/
│   ├── imgs/
│   └── REFERENCE.md
├── bin/
│   └── main.out
├── include/
│   ├── direction.h
│   ├── game.h
│   ├── role.h
│   ├── rule.h
│   └── welcome.h
├── src/
│   ├── game_rule.cpp
│   ├── game.cpp
│   ├── main.cpp
│   ├── role.cpp
│   ├── rule.cpp
│   └── welcome.cpp
├── test/
│   ├──   :
│   └──   :
├── .gitignore
├── build.sh
├── LICENSE
└── README.md
```

## Installation
### With ssh
```shell
$ git clone git@github.com:1chooo/battle-city.git
```

## How to Compile and Run
### Use g++: 
```shell
g++ -Iinclude -lncurses src/*.cpp -o bin/main.out && ./bin/main.out
```

### Use shell scripts:
```shell
./build.sh      # with shell scripts.
```

#### How to generate `build.sh`

1. Modify the content in `build.sh`
    ```shell
    g++ -Iinclude -lncurses src/*.cpp -o bin/main.out && ./bin/main.out
    ```
2. Give permission to `build.sh` by:
    ```s
    $ chmod +x build.sh
    ```
3. Run in terminal:
    ```s
    $ ./build.sh
    ```
## [Reference](./assets/REFERENCE.md)

## License
Released under [MIT](./LICENSE) by @1chooo and @RobinHsieh.

This software can be modified and reused without restriction.
The original license must be included with any copies of this software.
If a significant portion of the source code is used, please provide a link back to this repository.