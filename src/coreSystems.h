

#ifndef coresys
#define coresys

void getNormalOfPlane(double**);

/** This class is for 3D object data. **/
class C_3DObjData{
public:
    unsigned int ID;            /** 3D object's ID number **/
    double* verts;              /** groups of three, 'xyzxyzxyzxyzxyz... etc.' **/
    double* normals;            /** each face has a precomputed normal, 'xyzxyzxyzxyzxyz... etc.' **/
    unsigned int* faces;        /** each face has three verts, '1 2 3 1 4 2 5 2 1... etc' **/
    unsigned int numOfFaces;    /** Total number of faces. **/
    /** Memory constructor **/
    C_3DObjData(int vertcnt, int facecnt, int idInput){
        verts = new double [vertcnt * 3];
        normals = new double [facecnt * 3];
        faces = new unsigned int [facecnt * 3];
        ID = idInput;
    }
};

class C_3DObjClone{
public:
    unsigned int ID;              /** ID of 3D object to use. **/
    char*   ObjName;              /** Name of object **/
    unsigned int TeamID;          /** Team number to use. **/
    unsigned int OwnerID;         /** Player owner ID number **/
    bool    Visibility;           /** Render the object or no? **/
    bool    Physics;              /** Process physics or no? **/
    double  xPos;
    double  yPos;
    double  zPos;
    double  xRot;
    double  yRot;
    double  zRot;
    /** Memory constructor **/
    C_3DObjClone(char* nameLength, unsigned int idInput, unsigned int tID, unsigned int ownID){
        ObjName = new char [strlen(nameLength)];
        ObjName = nameLength;
        ID = idInput;
        TeamID = tID;
        OwnerID = ownID;
        Visibility = 0;
        Physics = 0;
        xPos = 0;
        yPos = 0;
        zPos = 0;
        xRot = 0;
        yRot = 0;
        zRot = 0;
    }
};

/** Put these functions into their own class so we can safely create more than one to support multi-threaded processing. **/
class C_nCalc{
public:
    void normalsCalc(C_3DObjData*, int, int);
};

class C_vTranslate{
public:                              /** compPriority/xPos/yPos/zPos/xRot/yRot/zRot **/
    void vTranslate(C_3DObjData*, int, int, int, float, float, float, float, float, float);
};

/** Class for the camera viewport **/
class C_camera{
public:
    double cameraPos[3];        /** xyz **/
    double cameraFocalLength;
    double cameraAngle[2];      /** xy and yz **/
};

#endif // ggah
