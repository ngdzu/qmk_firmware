# Dzu's WhiteFox layout

This keymapping is designed with these in mind: 
- Minimize finger travel: 
  - The most natural positions of your hands on the keyboard is all fingers on the home row and thumbs on the space bar. This layout is designed so that you can rest your fingers at the home position while enable you to access the most used features.
  - In order not to move the  fingers too much, we need to take advantages of the most comfortable keys on the keyboard, which are E,S,D,F and I,J,K,L. In different layers, these key should have different functions, and they must be mapped to the most used functions such as IJKL keys to be used as the arrow keys.
  - We also need function keys to be at the most convient positions. Two of them are the caplock position and the spacebar position. In this layout, f1 is placed at the caplock position. While holding down f1, holding down the spacebar brings you to layer 2.

  - To access mouse key, hold down f1 key (below tab key) and another key which is around the home row:
    - f1 + s key: mouse left
    - f1 + f key: mouse right
    - f1 + e key: mouse up
    - f1 + d key: mouse down
    - f1 + g key: mouse button 2 (right click)
    - f1 + ' key: mouse button 1 (left click)
    
  - Mouse wheel:
    - f2 + e key: scroll up
    - f2 + d key: scroll down
    
  - Arrow keys, Home, End, Page Up, Page Down are also easily accessible around the home row. 
    - f1 + j key: left arrow
    - f1 + l key: right arrow
    - f1 + i key: up arrow
    - f1 + k key: down arrow
    
  - Layer 2 can be easily activated holding down f1 + space bar
    - f2 + j key: home
    - f2 + l key: end
    - f2 + i key: page up
    - f2 + k key: page down

- Support common Visual Studio debugger shortcut: 
    - f1 + right arrow : F10 step over
    - f1 + up arrow: shift + F11 step out
    - f1 + down arrow: F11 step in
    - f1 + left arrow: F5 continue
    - f2 + up arrow: move next execution line to the line above current line
    - f2 + down arrow: move next execution line to the line below current line
    - f2 + right arrow: move next execution line to the current line

## Building and flashing

1. Put your board in DFU mode with either the button on the bottom, or with a software key in your current firmware
2. Flash:
    ```bash
    $ make whitefox:dzu
    ```
