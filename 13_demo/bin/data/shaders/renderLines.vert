#version 150

// uniforms:  same for all vertices
// -----------------------------------------------

// default uniform, defined by oF
uniform mat4  modelViewProjectionMatrix;
// custom uniforms, defined by us
uniform vec4  colorBorn;
uniform vec4  colorDead;

// vertex attributes:  different for every vertex
// -----------------------------------------------

// default attribute, defined by oF
in vec4 position;
// custom attributes, defined by us
in float lifePct;

// output to fragment shader
// -----------------------------------------------

out vec4 v_color;


// main
// -----------------------------------------------

void main()
{
    v_color = mix(colorBorn, colorDead, lifePct);
    gl_Position = modelViewProjectionMatrix * position;
}
