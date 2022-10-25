
#ifndef __Joust__Shelf__
#define __Joust__Shelf__

#include "Game.h"

using namespace tcg;

class Shelf {

    friend class Game;
    vec2 shelf_bbox[2];
    std::vector <vec2> shelf_vert;
    std::vector <vec2> shelf_uv;
  
    std::vector < vec2 > outline;

    std::vector<unsigned char> shelf_im;
    unsigned shelf_im_width, shelf_im_height;

    struct {
        vec2 position;
        bool direction; // left=True, right=False
        bool isFlying;
        bool isFalling;
        bool isMoving;
        bool isSquatting;
    } state;

    struct {
        GLuint vao;           //Vertex array object
        GLuint program;       //shader program
        GLuint buffer;        //Vertex buffer objects
        GLuint vertex_shader, fragment_shader;  //Shaders
        GLint vpos_location, vtex_location;   //reference to pos and color in shaders
        GLint M_location;     //Reference to matrix in shader
        GLuint shelf_texture;
        GLuint shelf_t_texture;
        GLuint left_texture;
        GLuint right_texture;
        GLuint left_t_texture;
        GLuint right_t_texture;
    } GLvars;

    public:
        Shelf(vec2);

        void draw(mat4 proj);

        void gl_init();
        void initShaders();
        void initBuffers();
        void initTexture();

};

#endif