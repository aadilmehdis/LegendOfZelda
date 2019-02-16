#include "main.h"
#include "timer.h"
#include "jet.h"
#include "sea.h"
#include "missile.h"
#include "bomb.h"
#include "compass.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Jet jet;
Compass compass;
Missile missile;

std::vector<Missile> missiles;
std::vector<Bomb> bombs;
long long int game_timer = 0;

int missile_timer = 10;
int bomb_timer = 10;


// spawn functions
void spawn_missile();
void spawn_bombs();
void update_timers();
//

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle1 = 0;
float helicopZoom = 0;
// float camera_rotation_angle2 = 0;

bool mouseDown = false;
int mousetimer = 0;
glm::vec3 cameraRotationVector1 = glm::vec3(20,0,0);
glm::vec3 cameraRotationVector2 = glm::vec3(20,0,0);

vector<Sea> seaTiles;

glm::vec3 eye = glm::vec3(0,0,18);
glm::vec3 target;
glm::vec3 up;

glm::vec3 eye2 = glm::vec3(-100, -100, 0);
glm::vec3 target2 = glm::vec3(-100, -100, -100);;
glm::vec3 up2 = glm::vec3(0,1,0);

double mouseXPos, mouseYPos, mouseXPosOld, mouseYPosOld;

Timer t60(1.0 / 60);

/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // glm::vec3 eye ( eyepos_x, eyepos_y, eyepos_z);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    // glm::vec3 target (targetpos_x, targetpos_y, targetpos_z);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    // glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    Matrices.view2 = glm::lookAt( eye2, target2, up2 ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    glm::mat4 VP2 = Matrices.projection2 * Matrices.view2;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    jet.draw(VP);
    compass.draw(VP2);
    for(int i=0;i<seaTiles.size();++i)
    {
        seaTiles[i].draw(VP);
    }
    for(int i=0 ;i<missiles.size();++i)
    {
        missiles[i].draw(VP);
    }
    for(int i=0 ;i<bombs.size();++i)
    {
        bombs[i].draw(VP);
    }
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int upk  = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int a = glfwGetKey(window, GLFW_KEY_A);
    int d = glfwGetKey(window, GLFW_KEY_D);
    int f = glfwGetKey(window, GLFW_KEY_F);
    int g = glfwGetKey(window, GLFW_KEY_G);

    int missile = glfwGetKey(window, GLFW_KEY_M);
    int bomb = glfwGetKey(window, GLFW_KEY_N);

    int followCamView           = glfwGetKey(window, GLFW_KEY_Z);
    int towerView               = glfwGetKey(window, GLFW_KEY_X);
    int helicopterView          = glfwGetKey(window, GLFW_KEY_C);
    int topView                 = glfwGetKey(window, GLFW_KEY_V);
    int jetView                 = glfwGetKey(window, GLFW_KEY_B);

    if(jetView)
    {
        eye = jet.position + jet.zLocal * -5.0f;
        target = jet.position + jet.zLocal * -1000.0f;
        up = jet.yLocal;
    }
    else if(topView)
    {
        eye = jet.position + glm::vec3(1,30,0);
        target = jet.position;
        up = glm::vec3(0,0,-1);
    }
    else if(helicopterView)
    {
        camera_rotation_angle1 = 0;
        if(mouseDown == true)
        {
            glfwGetCursorPos(window, &mouseXPos, &mouseYPos);
            if(mouseXPos  > mouseXPosOld)
            {
                camera_rotation_angle1 -= 2;
            }
            else if(mouseXPos  < mouseXPosOld)
            {
                camera_rotation_angle1 += 2;
            }
        }
        cout<<"Cam Rot Angl : "<<camera_rotation_angle1<<"\n";
        glm::mat4 rotate = glm::rotate((float) (camera_rotation_angle1 * M_PI / 180.0f), glm::vec3(0,-1,0));
	    cameraRotationVector1 = glm::vec3(rotate * glm::vec4(cameraRotationVector1,0.0));
        eye = jet.position + cameraRotationVector1;
        target = jet.position;
        glm::vec3 zDir = target - eye;
        eye = eye + helicopZoom * glm::normalize(zDir);
    }
    else if(towerView)
    {
        eye = jet.position + glm::vec3(40,20,10);
        target = jet.position;
        up = glm::vec3(0,1,0);
    }
    else if(followCamView || true)
    {
        eye = jet.position + jet.zLocal*30.0f + jet.yLocal*10.0f;
        up = jet.yLocal;
        target = jet.position;
    }

    if (left) {
        jet.yawLeft();
        compass.rotation += compass.rotation_speed;
    }
    if(right)
    {
        jet.yawRight();
        compass.rotation -= compass.rotation_speed;

    }
    if(upk)
    {
        jet.pitchUp();
    }
    if(down)
    {
        jet.pitchDown();
    }
    if(a)
    {
        jet.rollACC();
    }
    if(d)
    {
        jet.rollCC();
    }

    if(missile && game_timer % missile_timer == 0)
    {
        spawn_missile();
    }

    if(bomb && game_timer % bomb_timer == 0)
    {
        spawn_bombs();
    }
}

void tick_elements() {
    jet.tick();
    for(int i=0;i<missiles.size();++i)
    {
        missiles[i].tick();
    }
    for(int i=0;i<bombs.size();++i)
    {
        bombs[i].tick();
    }
    mousetimer++;
    
    if(mousetimer%3==0)
    {
        glfwGetCursorPos(window, &mouseXPosOld, &mouseYPosOld);
    }
    cout<<"HELIPCOP OOM : "<<helicopZoom<<endl;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    jet       = Jet(0, 0, COLOR_RED);

    compass     = Compass(glm::vec3(-100,-97, -50 ));

    eye = jet.position + jet.zLocal*30.0f + jet.yLocal*10.0f;

    target = jet.position;

    for(int i=-10;i<10;++i)
    {
        for(int j=-10;j<10;++j)
        {
            seaTiles.push_back(Sea(i*100.0, -1.0, j* -100.0,COLOR_BACKGROUND));
        }
    }

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);
    glfwSetMouseButtonCallback(window, mouseButtonCallBack);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            update_timers();


            // cout<<eyepos_x<<" "<<eyepos_y<<" "<<eyepos_z<<"\n";
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    // Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
    Matrices.projection2 = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}


void mouseButtonCallBack(GLFWwindow *window, int button, int action, int mods) {

    if(button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if(GLFW_PRESS == action)
        {
            mouseDown = true;
            cout<<"Down\n";
        }
        else 
        {
            mouseDown = false;
            cout<<"Up\n";
        }
    }
}

void spawn_missile() 
{
    glm::mat4 rotate;
	rotate[0] = glm::vec4(jet.xLocal,0);
	rotate[1] = glm::vec4(jet.yLocal,0);
	rotate[2] = glm::vec4(jet.zLocal,0);
	rotate[3] = glm::vec4(0,0,0,1);
    missiles.push_back(Missile(jet.position, jet.zLocal, rotate));
}


void spawn_bombs() 
{
    glm::mat4 rotate;
	rotate[0] = glm::vec4(jet.xLocal,0);
	rotate[1] = glm::vec4(jet.yLocal,0);
	rotate[2] = glm::vec4(jet.zLocal,0);
	rotate[3] = glm::vec4(0,0,0,1);
    bombs.push_back(Bomb(jet.position, jet.velocity, rotate));
}

void update_timers()
{
    game_timer++;
}