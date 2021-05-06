# Advanced Rendering: Point renderer (VBOs)

So far we've used a simple but ineficient rendering technique: draw each particle as a circle.

This is suboptimal:
- Every time we call ``ofDrawCircle()`` the geometry is tranfered from CPU to GPU. Transfering data from CPU to GPU is very slow, and this happens per every particle.

How do we fix this issue?
- Using ``ofVbo`` we can speed up the transfer of data from CPU to GPU. This is more efficient, allowing us to render a larger number of particles.

**What is an VBO?**
Vertex Buffer Object. We can think about it as a collection of buffers that contain data associated with each vertex (position, color, size, etc). 
The VBO is in charge of managing the data from CPU to GPU. It makes data transfer much faster.


### What has changed from the previous project:
- Created render folder
- Created abstract ``Render`` class
- Created ``RenderPoints``
- ofApp: Added fps counter
- ofApp: Hide gui (in some computers can affect performance)


### Resources:
- [ofVbo documentation](https://openframeworks.cc/documentation/gl/ofVbo/)