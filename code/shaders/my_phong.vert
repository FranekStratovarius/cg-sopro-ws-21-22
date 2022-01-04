#sginclude "://shaders/commonlight.vert.inc"

out vec3 viewPosition;
out vec3 viewDirection;
out vec3 viewNormal;

void main(){
    viewPosition = eyePosition().xyz;
    viewDirection = -normalize(viewPosition);
	viewNormal = eyeNormalVec().xyz;

    gl_Position = vPos();
}
