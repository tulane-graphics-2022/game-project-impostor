//
//  main.cpp
//  JOUST
//
//  Created by Maddie Wisinski and Bennett Hermanoff 
//
//
#include "Game.h"

GLFWwindow* window;
Game *game;

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  // p1
   // press
  if (key == GLFW_KEY_W && action == GLFW_PRESS)
    game->p2->fly();
  if (key == GLFW_KEY_A && action == GLFW_PRESS)
    game->p2->moveLeft();
  if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
    game->p2->turnLeft();
  if (key == GLFW_KEY_D && action == GLFW_PRESS)
    game->p2->moveRight();
  if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
    game->p2->turnRight();
  if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
    game->p2->drop();
  // release
  if (key == GLFW_KEY_W && action == GLFW_RELEASE)
    game->p2->undrop();
  if (key == GLFW_KEY_A && action == GLFW_RELEASE)
    game->p2->moveRight();
  if (key == GLFW_KEY_D && action == GLFW_RELEASE)
    game->p2->moveLeft();
  // TODO: more keys and functions, need to sketch out functions better
  
  // p2
    // press
  if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    game->p1->fly();
  if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    game->p1->moveLeft();
  if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
    game->p1->turnLeft();
  if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    game->p1->moveRight();
  if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) 
    game->p1->turnRight();
  if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
    game->p1->drop();
  // release
  if (key == GLFW_KEY_UP && action == GLFW_RELEASE)
    game->p1->undrop();
  if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE)
    game->p1->moveRight();
  if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE)
    game->p1->moveLeft();
}

void init(){
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glHint (GL_LINE_SMOOTH_HINT, GL_NICEST);
  glHint (GL_POINT_SMOOTH_HINT, GL_NICEST);
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  
  int width, height;
  glfwGetWindowSize(window, &width, &height);
  game->screen_extents[0] = -1*(float)width/(float)height;
  game->screen_extents[1] = 1*(float)width/(float)height;
  game->screen_extents[2] = -1.0;
  game->screen_extents[3] = 1.0;
  
  game->init();
  
}

//Call update function 30 times a second
void animate(){
  if(glfwGetTime() > 0.033){
    glfwSetTime(0.0);
    
    game->update();
    
  }
}

int main(void)
{
  
  srand (time(NULL));
  
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_SAMPLES, 10);
  
  window = glfwCreateWindow(1024, 768, "JOUST", NULL, NULL);
  game = new Game();

  if (!window){
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  glfwSetKeyCallback(window, key_callback);
  
  glfwMakeContextCurrent(window);
  gladLoadGL(glfwGetProcAddress);
  glfwSwapInterval(1);
  

  init();
  
  while (!glfwWindowShouldClose(window)){
    
    int FB_width, FB_height;
    glfwGetFramebufferSize(window, &FB_width, &FB_height);
    glViewport(0, 0, FB_width, FB_height);
    
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    game->screen_extents[0] = -1*(float)width/(float)height;
    game->screen_extents[1] = 1*(float)width/(float)height;
    game->screen_extents[2] = -1.0;
    game->screen_extents[3] = 1.0;
    
    //(left, right, bottom, top)        
    mat4 proj = Ortho2D(game->screen_extents[0],game->screen_extents[1],
                        game->screen_extents[2],game->screen_extents[3]);
    
    animate();
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    game->draw(proj);

    glfwSwapBuffers(window);
    glfwPollEvents();
    
  }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  
  delete game;
  exit(EXIT_SUCCESS);
}