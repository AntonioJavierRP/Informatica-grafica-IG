#include "file_ply_stl.h"
#include "O3D.h"

class PlyReader : public O3D{
public:
    PlyReader();
    PlyReader(char *file);
};
