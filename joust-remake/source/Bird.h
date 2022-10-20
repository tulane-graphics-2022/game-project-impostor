
#ifndef __Joust__Bird__
#define __Joust__Bird__

#include "Game.h"

using namespace tcg;

class Bird {

    friend class Game;

    float accel;
    vec2 bird_bbox[2];
    std::vector <vec2> bird_vert;
    std::vector <vec2> bird_uv;

    std::vector<unsigned char> bird_im;
    unsigned im_width, im_height;
    struct {
        
        vec2 velocity;
        vec2 position;
        
        bool direction; // left=True, right=False
        bool isFlying;
        bool isFalling;
    } state;

    struct {
        GLuint vao;           //Vertex array object
        GLuint program;       //shader program
        GLuint buffer;        //Vertex buffer objects
        GLuint vertex_shader, fragment_shader;  //Shaders
        GLint vpos_location, vtex_location;   //reference to pos and color in shaders
        GLint M_location;     //Reference to matrix in shader
        GLuint bird_texture;
        GLuint bird_t_texture;
        GLuint left_texture;
        GLuint right_texture;
        GLuint left_t_texture;
        GLuint right_t_texture;
    } GLvars;

    public:
        Bird();

        void draw(mat4 proj);
        void update(vec4 extents);
        void reset();
        bool isAbove(Bird b);

        void gl_init();
        void initShaders();
        void initBuffers();
        void initTexture();

        inline void moving() {
            if (state.direction) {
                state.velocity.x -= accel;
            } else {
                state.velocity.x += accel;
            }
        }
        inline void turnLeft() { state.direction = true; }
        inline void turnRight() { state.direction = false; }
        

};

#endif