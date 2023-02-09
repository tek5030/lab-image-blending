# Step 1: Get an overview
Compared to the previous lab, this project is slightly more complex. 
The code is now distributed over a few more files to keep the logic parts of the program separated.
We will therefore start by introducing the contents of this project. 

## Introduction to the project source files
- *CMakeLists.txt*

  The cmake project file.
  Defines the project name, and which source files that are part of the project.
  It also lets us set compiler options and define which libraries we want find and link to.

- *main.cpp*

  Starts the lab, catches any exceptions and prints their error messages on the console.

- *lab_image_blending.{h,cpp}*

  Runs the lab and displays the results on screen.
  
- *linear_blending.{h,cpp}*

  Contains a function which performs linear blending of two images using a provided mask with weights.
  
- *laplace_blending.{h,cpp}*

  - Contains a function which performs laplace blending of two images using a provided mask with weights.
  - Contains helper functions for the laplace blending, that is the construction of Gaussian and Laplacian pyramids and a function that collapses a pyramid.
  
- Images that we will use for blending:
  - lion.png
  - tiger.png
  - white_tiger.png
  
## `runImageBlendingLab()`
First, take a look at the `runImageBlendingLab()` function in [*lab_image_blending.cpp*](https://github.com/tek5030/lab-image-blending/blob/master/lab_image_blending.cpp).
Try to understand the steps taken here, and please ask one of the instructors if you are uncertain.

Then build and run the project. 
You should see some output to the console, but the program doesn't do anything interesting - yet!

Please continue to the [next step](2-implement-image-blending.md) to get started with the interesting stuff!
