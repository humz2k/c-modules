//#include <math.h>

import vector3struct;

vec3 v3add(vec3 l, vec3 r){
    vec3 out;
    out.x = l.x + r.x;
    out.y = l.y + r.y;
    out.z = l.z + r.z;
    return out;
}

vec3 v3sub(vec3 l, vec3 r){
    vec3 out;
    out.x = l.x - r.x;
    out.y = l.y - r.y;
    out.z = l.z - r.z;
    return out;
}

vec3 v3mul(vec3 l, vec3 r){
    vec3 out;
    out.x = l.x * r.x;
    out.y = l.y * r.y;
    out.z = l.z * r.z;
    return out;
}

vec3 v3div(vec3 l, vec3 r){
    vec3 out;
    out.x = l.x / r.x;
    out.y = l.y / r.y;
    out.z = l.z / r.z;
    return out;
}