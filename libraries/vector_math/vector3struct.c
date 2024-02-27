typedef struct vec3{
    float x;
    float y;
    float z;
} vec3;


vec3 v3make(float x, float y, float z){
    vec3 out;
    out.x = x;
    out.y = y;
    out.z = z;
    return out;
}