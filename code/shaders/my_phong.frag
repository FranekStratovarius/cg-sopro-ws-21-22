#sginclude "://shaders/commonlight.vert.inc"

in vec3 viewPosition;
in vec3 viewDirection;
in vec3 viewNormal;

out vec4 fragColor;

void main(){
	vec3 vertexColor = phong(viewPosition, viewDirection, normalize(viewNormal), vec3(1.0));
	fragColor = vec4(vertexColor + material.emission.rgb, computeMaterialAlpha());
}
