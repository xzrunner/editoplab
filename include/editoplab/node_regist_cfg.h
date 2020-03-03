#ifndef EXE_FILEPATH
#error "You must define EXE_FILEPATH macro before include this file"
#endif

// io

#define PARM_NODE_CLASS Context
#define PARM_NODE_NAME context
#include EXE_FILEPATH

#define PARM_NODE_CLASS Operation
#define PARM_NODE_NAME operation
#include EXE_FILEPATH

// math

#define PARM_NODE_CLASS Plane
#define PARM_NODE_NAME plane
#include EXE_FILEPATH

#define PARM_NODE_CLASS Ray
#define PARM_NODE_NAME ray
#include EXE_FILEPATH

#define PARM_NODE_CLASS RayPlaneIntersect
#define PARM_NODE_NAME ray_plane_intersect
#include EXE_FILEPATH
