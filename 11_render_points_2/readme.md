# Advanced Rendering: Point renderer (Shaders)

In the previous project we've optimized the transfer of data from cpu to gpu using ofVbo. In this project we'll add features to the ``RenderPoints`` class to have more control over the appearance of our particles. 

We'll do this adding additional buffers to our ``vbo`` and using shaders.

Shaders are programs that run on the GPU. The code inside a shader is executed in parallel for every vertex (vertex shaders) or pixel (fragment shaders).

``ofVbo`` is still in charge of transfering data to the GPU, but we are going to add two more buffers for ``mass`` and ``life`` data. This buffers are called vertex attributes. 

We can read vertex attributes inside shaders to affect the appearance of particles:
- change the color based on age
- change the size based on mass


### What has changed from the previous exercise:
- Created a new folder for the shaders at ``bin/data/shaders``
- Modified ``main.cpp`` to enable programmable renderer (OpenGL version 3.2)


### Resources:
https://openframeworks.cc/ofBook/chapters/shaders.html
https://thebookofshaders.com/