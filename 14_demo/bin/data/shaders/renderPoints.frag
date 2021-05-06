#version 150

// input from vertex shader
// -----------------------------------------------
in vec4 v_color;

// output color
// -----------------------------------------------

out vec4 out_color;


// main
// -----------------------------------------------

void main()
{
    out_color = v_color;
}
