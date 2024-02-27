import cmath;
import vector3struct;
import vector3arith;

float v3len2(vec3 l){
    return l.x*l.x + l.y*l.y + l.z*l.z;
}

float v3len(vec3 l){
    return sqrtf(v3len2(l));
}

float v3dist(vec3 l, vec3 r){
    return v3len(v3sub(l,r));
}

float v3dist2(vec3 l, vec3 r){
    return v3len2(v3sub(l,r));
}