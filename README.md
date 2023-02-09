# Image blending with OpenCV
Welcome to this lab in the computer vision course [TEK5030](https://www.uio.no/studier/emner/matnat/its/TEK5030/) at the University of Oslo.
We are here going to play with image blending using Laplacian pyramids with OpenCV.

Start by cloning this repository on your machine and set up your project using conan (see below). 
Then open the lab project in you editor.

The lab is carried out by following these steps:
1. [Get an overview](lab-guide/1-get-an-overview.md)
2. [Implement image blending](lab-guide/2-implement-image-blending.md)

You will find our proposed solution at https://github.com/tek5030/solution-image-blending.
But please try to solve the lab with help from others instead of just jumping straight to the solution ;)

Start the lab by going to the [first step](lab-guide/1-get-an-overview.md).


## Prerequisites
- [Ensure Conan is installed on your system](https://tek5030.github.io/tutorial/conan.html), unless you are not on a lab computer.
- Install project dependencies using conan:

   ```bash
   # git clone git@github.com:tek5030/lab-image-blending.git
   # cd lab-image-blending

   conan install . --install-folder=build --build=missing
   ```
- When you configure the project in CLion, remember to set `build` as the _Build directory_, as described in [lab_intro](https://github.com/tek5030/lab-intro/blob/master/cpp/lab-guide/1-open-project-in-clion.md#6-configure-project).
