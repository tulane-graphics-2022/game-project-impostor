
#ifndef __Joust__Bird__
#define __Joust__Bird__

#include "Game.h"

using namespace tcg;

class Bird {

    friend class Game;
    float g;
    float max_vel;
    float accel;
    float damping;
    vec2 bird_bbox[2];
    std::vector <vec2> bird_vert;
    std::vector <vec2> bird_uv;
  
    std::vector < vec2 > outline;

    std::vector<unsigned char> bird_im;
    unsigned bird_im_width, bird_im_height;

    struct {
        
        vec2 velocity;
        vec2 position;
        
        bool direction; // left=True, right=False
        bool isFlying;
        bool isFalling;
        bool isMoving;
        bool isSquatting;
        bool onSurface;
        int jumps;
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
        
        void fall();

        void gl_init();
        void initShaders();
        void initBuffers();
        void initTexture();

        inline void fly() {
            state.velocity.y = 0.032;
            state.position.y +=0.02;
        }
        inline void drop() {
            state.isFlying = false;
            state.isFalling = true;
            // if surface is below, then SQUAT
            if (state.onSurface) {
                state.position.y-=0.04;
                state.velocity.y=-0.003;
            } else {
                state.isSquatting = true;
            }
        }
        inline void undrop() {
            state.isSquatting = false;
        }   
        inline bool isAbove(Bird b) { 
            return (state.position.y + bird_bbox[0].y < b.state.position.y + b.bird_bbox[1].y && // above
                    state.position.y + bird_bbox[0].y > b.state.position.y &&
                    bird_bbox[1].x + state.position.x > b.bird_bbox[0].x + b.state.position.x && // right edge overlap
                    bird_bbox[1].x + state.position.x < b.bird_bbox[1].x + b.state.position.x &&
                    bird_bbox[0].x + state.position.x > b.bird_bbox[0].x + b.state.position.x &&
                    bird_bbox[0].x + state.position.x < b.bird_bbox[1].x + b.state.position.x    // left edge overlap
                    );     
            }
        inline void turnLeft() { state.direction = true; state.isMoving = true; }
        inline void turnRight() { state.direction = false; state.isMoving = true;}
        inline void stop() { state.isMoving = false; }
        

};

#endif