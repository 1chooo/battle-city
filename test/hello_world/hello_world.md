With ChatGPT to make the screen to show "Hello World!"

## Note

```cpp
// to initialize the window
initscr();

// to print the words in screen.
mvprintw();

// 
refresh();

// detect KeyCaps q to leave
while (getch() != 'q')
    ;

// close the window
endwin();
```