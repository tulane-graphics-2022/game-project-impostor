#include "Game.h"
#include "Bird.h"

#define MAX_SPEED 0.05f
#define DAMPING 0.009f
#define ACC 0.006f
#define G 0.0008f
#define MAX_FALL_SPEED 0.1f
#define BORDER 0.075f
Bird::Bird(int player){

    // instantiate position, velocity, etc
    
    player = player;
    // add vertices to create the shape of the bird
    state.isMoving = false;
    state.frame = 0;
    state.velocity = vec2(0.0f, 0.0f);
    bird_bbox[0] = vec2(-BORDER, -BORDER);
    bird_bbox[1] = vec2(BORDER,   BORDER);
    
    bird_vert.resize(8);
    bird_uv.resize(8);

    // facing left
    bird_vert[0] = (vec2(-BORDER,  BORDER)); bird_uv[0] = (vec2(0.0,0.0));
    bird_vert[1] = (vec2(-BORDER, -BORDER)); bird_uv[1] = (vec2(0.0,1.0));
    bird_vert[2] = (vec2(BORDER,   BORDER)); bird_uv[2] = (vec2(1.0,0.0));
    bird_vert[3] = (vec2(BORDER,  -BORDER)); bird_uv[3] = (vec2(1.0,1.0));
    
    // facing right
    bird_vert[4] = (vec2(-BORDER,  BORDER)); bird_uv[4] = (vec2(1.0,0.0));
    bird_vert[5] = (vec2(-BORDER, -BORDER)); bird_uv[5] = (vec2(1.0,1.0));
    bird_vert[6] = (vec2(BORDER,   BORDER)); bird_uv[6] = (vec2(0.0,0.0));
    bird_vert[7] = (vec2(BORDER,  -BORDER)); bird_uv[7] = (vec2(0.0,1.0));
    
    if (player == 1) {
        std::string file_location = source_path + "sprites/bird_1/inAirAndStanding.png";
        unsigned error = lodepng::decode(bird_im, bird_im_width, bird_im_height, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_1/walk1.png";
        error = lodepng::decode(bird_im_walk1, bird_im_width_walk1, bird_im_height_walk1, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_1/walk2.png";
        error = lodepng::decode(bird_im_walk2, bird_im_width_walk2, bird_im_height_walk2, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_1/fly.png";
        error = lodepng::decode(bird_im_fly, bird_im_width_fly, bird_im_height_fly, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";
    }
    else {
        std::string file_location = source_path + "sprites/bird_2/inAirAndStanding.png";
        unsigned error = lodepng::decode(bird_im, bird_im_width, bird_im_height, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_2/walk1.png";
        error = lodepng::decode(bird_im_walk1, bird_im_width_walk1, bird_im_height_walk1, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_2/walk2.png";
        error = lodepng::decode(bird_im_walk2, bird_im_width_walk2, bird_im_height_walk2, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";

        file_location = source_path + "sprites/bird_2/fly.png";
        error = lodepng::decode(bird_im_fly, bird_im_width_fly, bird_im_height_fly, file_location.c_str());
        std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";
    }
    // file_location = source_path + "sprites/bird/.png";
    // error = lodepng::decode(bird_im, bird_im_width, bird_im_height, file_location.c_str());
    // std::cout << bird_im_width << " X " << bird_im_height << " image loaded\n";


    
    // below is bird stuff (literally the bird)
    // if(index == 1){
    //     std::string file_location = source_path + "sprites/asteroid_1.png";
    //     unsigned error = lodepng::decode(asteroid_im, im_width, im_height, file_location.c_str());
    // }
    // if(index == 2){
    //     std::string file_location = source_path + "sprites/asteroid_2.png";
    //     unsigned error = lodepng::decode(asteroid_im, im_width, im_height, file_location.c_str());
    // }
    // std::cout << im_width << " X " << im_height << " image loaded\n";
    
    


  
};

void Bird::fall() {
    // if (!state.isFalling) {
    //     state.isFalling = true;
    //     resetJumps();
    // }
    if (state.velocity.y > -MAX_FALL_SPEED) {
        state.velocity.y -= G;
    }
}
void Bird::update(vec4 extents) {


    // update velocity

    if (state.isMoving) {
        if (state.direction) {
                state.velocity.x = abs(state.velocity.x - ACC) <= MAX_SPEED ? state.velocity.x - ACC : -MAX_SPEED; 
            } else {
                state.velocity.x = abs(state.velocity.x + ACC) <= MAX_SPEED ? state.velocity.x + ACC : MAX_SPEED;
            }
    } else {
        if (state.direction) { // facing left
            if (state.velocity.x > 0)
                state.velocity.x = state.velocity.x - DAMPING >= 0 ? state.velocity.x - DAMPING : 0;
            else
                state.velocity.x = state.velocity.x + DAMPING <= 0 ? state.velocity.x + DAMPING : 0;
        } else {
            if (state.velocity.x <0)
                state.velocity.x = state.velocity.x + DAMPING <= 0 ? state.velocity.x + DAMPING : 0;
            else
                state.velocity.x = state.velocity.x - DAMPING >= 0 ? state.velocity.x - DAMPING : 0;
        }
    }
    state.position.y = state.position.y + state.velocity.y;
    state.position.x = state.position.x + state.velocity.x;

    state.position.x = state.position.x + bird_bbox[1].x < extents[0] ? extents[1] : state.position.x;
    state.position.x = state.position.x + bird_bbox[0].x > extents[1] ? extents[0] : state.position.x;
    state.position.y = state.position.y - bird_bbox[1].y < extents[2] ? extents[2] + bird_bbox[1].y : state.position.y;
    if (state.position.y == extents[2] + bird_bbox[1].y) {
        state.velocity.y = 0;
    }
    state.position.y = state.position.y > extents[3] ? extents[3] : state.position.y;

    if (state.velocity.y < 0 || (state.onSurface && state.velocity.x == 0)) {
        state.frame = 0;
    }
    if ((state.frame == 17 || state.frame == 0) && state.onSurface && state.velocity != 0)
        state.frame = 1;
    if ((state.frame >= 1 && state.frame <= 16 && state.velocity.x != 0)) {
        state.frame = (state.frame+1)%16 + 1;
    }
    if (state.velocity.y > 0) {
        state.frame = 17;
    }
    
    

    // check isFalling, isFlying, direction
    // check for collision with enemy -> if !b1.isAbove(b2) -> dead
    // update position based on velocity and direction
    // check for collisions with screen edges
}

void Bird::gl_init() {
    // get the sizes of the position vector and color vector
    unsigned int bird_vert_size = bird_vert.size()*sizeof(vec2);
    unsigned int bird_uv_size = bird_uv.size()*sizeof(vec2);

    std::string vshader = source_path + "shaders/vshader_Texture.glsl";
    std::string fshader = source_path + "shaders/fshader_Texture.glsl";

    GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
    GLchar* fragment_shader_source = readShaderSource(fshader.c_str());

    GLvars.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(GLvars.vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
    glCompileShader(GLvars.vertex_shader);
    check_shader_compilation(vshader, GLvars.vertex_shader);

    GLvars.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(GLvars.fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
    glCompileShader(GLvars.fragment_shader);
    check_shader_compilation(fshader, GLvars.fragment_shader);

    GLvars.program = glCreateProgram();
    glAttachShader(GLvars.program, GLvars.vertex_shader);
    glAttachShader(GLvars.program, GLvars.fragment_shader);

    glLinkProgram(GLvars.program);
    check_program_link(GLvars.program);
    
    glGenTextures( 1, &GLvars.bird_texture );
    glGenTextures( 1, &GLvars.bird_texture_walk1 );
    glGenTextures( 1, &GLvars.bird_texture_walk2 );
    glGenTextures( 1, &GLvars.bird_texture_fly );

    glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bird_im_width, bird_im_height,
                0, GL_RGBA, GL_UNSIGNED_BYTE, &bird_im[0]);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_walk1 );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bird_im_width_walk1, bird_im_height_walk1,
                0, GL_RGBA, GL_UNSIGNED_BYTE, &bird_im_walk1[0]);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );  

    glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_walk2);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bird_im_width_walk2, bird_im_height_walk2,
                0, GL_RGBA, GL_UNSIGNED_BYTE, &bird_im_walk2[0]);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_fly );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, bird_im_width_fly, bird_im_height_fly,
                0, GL_RGBA, GL_UNSIGNED_BYTE, &bird_im_fly[0]);
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );


    glBindFragDataLocation(GLvars.program, 0, "fragColor");

    GLvars.vpos_location   = glGetAttribLocation(GLvars.program, "vPos");
    GLvars.vtex_location = glGetAttribLocation(GLvars.program, "vTexCoord" );
    GLvars.M_location = glGetUniformLocation(GLvars.program, "M" );

    // Create a vertex array object
    glGenVertexArrays( 1, &GLvars.vao );
    //Set GL state to use vertex array object
    glBindVertexArray( GLvars.vao );

    //Generate buffer to hold our vertex data
    glGenBuffers( 1, &GLvars.buffer );
    //Set GL state to use this buffer
    glBindBuffer( GL_ARRAY_BUFFER, GLvars.buffer );

    //Create GPU buffer to hold vertices and color
    glBufferData( GL_ARRAY_BUFFER, bird_vert_size + bird_uv_size, NULL, GL_STATIC_DRAW );
    //First part of array holds vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, bird_vert_size, &bird_vert[0] );
    //Second part of array hold colors (offset by sizeof(triangle))
    glBufferSubData( GL_ARRAY_BUFFER, bird_vert_size, bird_uv_size, &bird_uv[0] );

    glEnableVertexAttribArray(GLvars.vpos_location);
    glEnableVertexAttribArray(GLvars.vtex_location );

    glVertexAttribPointer( GLvars.vpos_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( GLvars.vtex_location, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(bird_vert_size) );

    glBindVertexArray(0);

}

void Bird::draw(mat4 Projection){
  glUseProgram( GLvars.program );
  glBindVertexArray( GLvars.vao );
  
                 
  mat4  ModelView = Translate(state.position.x, state.position.y, 0.0); // no rotation because bird no go upside down
  
  glUniformMatrix4fv( GLvars.M_location, 1, GL_TRUE, Projection*ModelView);
  
  
  glLineWidth(1.2);
  
    if (state.frame == 0) 
        glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture );
    else if (state.frame >= 1 && state.frame<=8 )
        glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_walk1 );
    else if (state.frame >= 9 && state.frame <= 16)
        glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_walk2);
    else if (state.frame == 17)
        glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture_fly);
  if (state.direction) 
    glDrawArrays( GL_TRIANGLE_STRIP, 0, 4);
  else
    glDrawArrays( GL_TRIANGLE_STRIP, 4, 4);
  
  glBindVertexArray(0);
  glUseProgram(0);
  
}