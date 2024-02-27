import cmath;
import vector3struct;

float v3len2(vec3 l){
    return l.x*l.x + l.y*l.y + l.z*l.z;
}

float v3len(vec3 l){
    return sqrtf(v3len2(l));
}