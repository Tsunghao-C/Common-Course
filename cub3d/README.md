# 42 Common Core Project - CUB3D

## Objective

1. This is an advanced graphical project that we create a simplified 3D game.
2. The goal is to learn a rendering techniqe called Ray Casting.

## Key Concepts

1. Parsing Maps, Wall texture paths, and initialize images.
2. Use a recursive function (floodfill) to check if a Map is valid that the player will never go out side of bound.
3. Building a vector library for all the vector calculations (optional)
4. What is Raycasting and how it helps to make 3D rendering efficient?
5. What is DDA algorithm? Why it helps to optimize the rendering?
6. Rendering resized images (Wall rendering)
6. Creating multiple images and put in in the same window (Mini map, Sprite)
7. Creating a script of frames and generate animation effects (Animation)

## Notes of this big and challenging project

Link to our minishell git repo: https://github.com/Haliris/cub3d.git

### Shout out
- First of all, great shout out to my teammate Jean. He had a brilliant idea of using the theme in the cluser of 42 MADE campus in Paris. Our original idea was to role play the school cat Moulinette who always wandering among the clusters. She is super chill. Jean also had some experiences in developing video games, so he could debug very quickly whenever we had an issue.
- Second shout out to the tutorial of Lode's Computer Graphics Tutorial. (https://lodev.org/cgtutor/raycasting.html) It breaks down all the necessary steps to build a RC 3D game.
- Third shout out to a youtube video explaining the DDA algorithm. Without watching this video, I could had stuck for more days to understand how to realize DDA into codes. (https://youtu.be/NbSee-XM7WA?si=taWsY2doGi90ieGD)
### Cooperation
- I was lucky again to had a really nice co-working experience with Jean. I learned a lot of usefull tips on how to co-work and use githup properly. Before this project, I didn't know how to create a branch and make a pull request. Thanks to Jean, I now know some basic stuffs of using git and github.
- One rule of thumb is that the main branch should always be able to compile to run without any issue. If there are several developers working / maintaining a program, good pratices are:
	- Set up checkers and rules to prevent changing main branch directly
	- Always create a branch to work on tests and changes
	- Set up pull request rules and pull branch to main only when every co-workers have reviewed
	- Define a reasonable and clear scope for each branch
	- Make good uses of the Issues and Comments features on github
### Notes
1. This time we used git clone mlx in the Makefile, so every time when you try to launch, you check whether the mlx library exists or not. If not, you download it.
2. I built a library for all the vector operations and the structure definition. For me it is very useful later when I need to deal with vectors like shifting or rotation.
3. I learned from a senior student that you can create a script of frames. Later I got the idea of using linked list to generate all the frames in a linked list. It is super usefull.
4. A sprite is acutally a moveable object other than the background. It is independent to the background rendering (Wall, Ceiling, Floor, etc.). In theory we didn't create any sprite and we combined the animation with the door, which is part of the background.
5. Another thing to consider is when to load the assets of textures or images. In a real big game like Fallout or TombRaider, it is impossible to load all the images at the moment. You just load the images or assets that could be used in a certain area. However, since it is just a simple 3D game, we loaded every assets at the beginning.
