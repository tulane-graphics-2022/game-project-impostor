
#ifndef __Joust__Platform__
#define __Joust__Platform__

#include "Game.h"

using namespace tcg;

class Platform {

    friend class Game;
    vec2 platform_bbox[2];
    std::vector <vec2> platform_vert;
    std::vector <vec2> platform_uv;
  
    std::vector < vec2 > outline;

    std::vector<unsigned char> platform_im;
    unsigned platform_im_width, platform_im_height;

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
        GLuint platform_texture;
        GLuint platform_t_texture;
        GLuint left_texture;
        GLuint right_texture;
        GLuint left_t_texture;
        GLuint right_t_texture;
    } GLvars;

    public:
        Platform(vec2);

        void draw(mat4 proj);

        void gl_init();
        void initShaders();
        void initBuffers();
        void initTexture();

};

#endif