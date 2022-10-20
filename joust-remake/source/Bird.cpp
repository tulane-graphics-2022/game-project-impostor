#include "Game.h"
#include "Bird.h"

#define _MAX_SPEED 0.05f
#define _DAMPING 0.98f
#define _ACC 0.008f

Bird::Bird(){

    // instantiate position, velocity, etc
    
    
    // add vertices to create the shape of the bird

    accel = 0.1;
    bird_bbox[0] = vec2(-0.15, -0.15);
    bird_bbox[1] = vec2(0.15,   0.15);
    

    bird_vert.push_back(vec2(-0.15, -0.15)); bird_uv.push_back(vec2(0.0,0.0));
    bird_vert.push_back(vec2(-0.15,  0.15)); bird_uv.push_back(vec2(0.0,1.0));
    bird_vert.push_back(vec2(0.15,  -0.15)); bird_uv.push_back(vec2(1.0,0.0));
    bird_vert.push_back(vec2(0.15,   0.15)); bird_uv.push_back(vec2(1.0,1.0));
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

bool Bird::isAbove(Bird b) {
    if (state.position.y > b.state.position.y) {
        return true;
    }
    return false;
}

void Bird::update(vec4 extents) {
    // update velocity
    
    // check isFalling, isFlying, direction
    // check for collision with enemy -> if !b1.isAbove(b2) -> dead
    // update position based on velocity and direction
    // check for collisions with screen edges
}
// void Asteroid::update_state(vec4 extents){

//   state.cur_location+=state.velocity;
//   state.angle += angle_increment;

//   if(state.cur_location.x < extents[0] || state.cur_location.x > extents[1]){
//     state.cur_location.x = -state.cur_location.x;
//   }
//   if(state.cur_location.y < extents[2] ||state.cur_location.y > extents[3]){
//     state.cur_location.y = -state.cur_location.y;
//   }

// }

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

    glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, im_width, im_height,
                0, GL_RGBA, GL_UNSIGNED_BYTE, &bird_im[0]);
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
  
  glBindTexture( GL_TEXTURE_2D, GLvars.bird_texture );
  glDrawArrays( GL_TRIANGLE_STRIP, 0, bird_vert.size() );
  
  
  glBindVertexArray(0);
  glUseProgram(0);
  
}