//
//  Game.h
//  Asteroids
//
//  Created by Brian Summa on 9/7/15.
//
//

#ifndef Joust_Game_h
#define Joust_Game_h

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include <list>
#include <vector>
#include <utils/shader_process.h>
#include <path/path.h>

#include <utils/vec.h>
#include <utils/mat.h>
#include <utils/lodepng.h>
#include <utils/loadTexture.h>

#include "Bird.h"
#include "Platform.h"

class Game{

public:
  Bird *p1;
  Bird *p2;
  std::vector <Platform *> platforms;


  //left right bottom top of window
  vec4 screen_extents;
  
private:
  
  int cooldown;
  bool game_over;
  int p1score;
  int p2score;
  
  std::vector<unsigned char> game_over_im;
  unsigned go_width, go_height;

  struct {
    GLuint vao;           //Vertex array object
    GLuint program;       //shader program
    GLuint buffer;        //Vertex buffer objects
    GLuint vertex_shader, fragment_shader;  //Shaders
    GLint vpos_location, vtex_location;   //reference to pos and color in shaders
    GLint M_location;     //Reference to matrix in shader
    GLuint texture;
  } GOGLvars;

  
public:
  Game();
  
  ~Game(){
    delete p1;
    delete p2;
  }
  
  void init(){
    p1->gl_init();
    p2->gl_init();
    for (int j = 0; j < platforms.size(); j++){
      platforms[j]->gl_init();
    }
    gl_init();
  }
  
  void draw(mat4 proj){
    p1->draw(proj);
    p2->draw(proj);
    for (int j = 0; j < platforms.size(); j++){
      platforms[j]->draw(proj);
    }
    if(game_over){
      draw_game_over(proj);
    }
  }
  
  void update(){
    cooldown = cooldown > 0 ? cooldown - 1 : 0;
    testIntersections(p1);
    testIntersections(p2);
    p1->update(screen_extents);
    p2->update(screen_extents);
    if (p1->isAbove(*p2)) {
      resetCooldown();
      p1score+=10;
      }
    if (p2->isAbove(*p1)) {
      resetCooldown();
      p2score+=10;
      }
    game_over = false;
    
  }
  
private:
  inline void resetCooldown() {cooldown = 20;}
  void gl_init();
  void draw_game_over(mat4 proj); 
  void testIntersections(Bird *b);
  
};


#endif