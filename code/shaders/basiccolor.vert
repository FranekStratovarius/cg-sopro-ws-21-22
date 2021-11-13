layout (location = 0) in vec4 vertexPosition;
in vec4 vertexColor;

out vec4 outputColor;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
mat4 modelViewMatrix = viewMatrix*modelMatrix;

uniform mat3 normalMatrix;

uniform vec4 color;

#define COLOR_STEP 18

void main()
{
     outputColor = vertexColor;

    // Calculate the vertex position
    gl_Position = projectionMatrix * modelViewMatrix * vertexPosition;
}
