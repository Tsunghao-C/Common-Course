# 42 Common Core Project - Fract'ol

## Objective

1. This project is about creating interactable fractal images.
2. Learn how to create graphics using minilibX.

## Key concepts

1. Use of minilibX
2. How to interact with window?
3. How to put render image to window?
4. The ideal of FPS, FLOPS? Why we use image (with buffer) instead of draw pixel by pixel?

## Notes for minilibX

1. minilibX is a simplified X-window program created by school 42. It simplifies the command and makes it easier for beginners to learn how to do graphic projects.
2. If you take a look at library of minilibX, you will find out that it is more like a bridge and connect to the necessary variables in X-window server.

### Key ideas to know about how to use minilibX before starting the project

#### To start mlx

1. Create a typedef struct and added necessary data in it.
2. How to manage mlx pointer and window pointer (and destroy them properly without leaks).
3. How to put pixel with color on window?
4. Why we use image instead of mlx_pixel_put?

#### Event management

1. mlx uses ```mlx_loop(mlx_ptr)``` to keep the window alive.
2. When window is still alive, we use ```mlx_hook``` to configure how we can interact with the window.
3. Ways of interactions (or events)
	1. Keyboard press or release
	2. Mouse Button press or release
	3. Mouse movement
	4. etc...
4. The mlx_hook function ```void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)```
	- int x_evnet: The event number is what type of event you are detecting (ex. dectection for Keypress or Mouse motion, etc...)
	- int x_mask: to indicate whether to mask certain inputs (ex. only accept keyboard press)
	- int (*f)(): The reaction to certain input
	- void *param: The pointer (usually struct) that can be sent to the reaction function
5. The ```mlx_hook_loop(mlx_ptr, int (*rerender_func)(), void *param)``` is to call the rerender function repeatedly if there is no events.

