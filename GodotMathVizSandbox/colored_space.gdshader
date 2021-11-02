shader_type spatial;
render_mode world_vertex_coords;
render_mode unshaded;
uniform vec3 some_color;
void vertex() {
		//VERTEX.y = 0.0;
}

void fragment()
{ 
	ALBEDO = (vec4(VERTEX, 1.0) * CAMERA_MATRIX).xyz;
}

