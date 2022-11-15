// #include <box2d/b2_body.h>
// #include <box2d/b2_fixture.h>
// #include <box2d/b2_math.h>
// #include <box2d/b2_polygon_shape.h>
// #include <box2d/b2_world.h>

// #include <iostream>

// int main(int, char **) {
//     b2Vec2 gravity(0.0f, -9.81f);

//     b2World world(gravity);

//     b2BodyDef groundBodyDef;
//     groundBodyDef.position.Set(0.0f, -10.0f);

//     b2Body *groundBody = world.CreateBody(&groundBodyDef);

//     b2PolygonShape groundBox;
//     groundBox.SetAsBox(50.0f, 10.0f);  // half-width & half-height

//     groundBody->CreateFixture(&groundBox, 0.0f);

//     // Creating a dynamic body
//     b2BodyDef bodyDef;
//     bodyDef.type = b2_dynamicBody;
//     bodyDef.position.Set(0.0f, 4.0f);
//     b2Body *body = world.CreateBody(&bodyDef);

//     b2PolygonShape dynamicBox;
//     dynamicBox.SetAsBox(1.0f, 1.0f);

//     b2FixtureDef fixtureDef;
//     fixtureDef.shape = &dynamicBox;
//     fixtureDef.density = 1.0f;
//     fixtureDef.friction = 0.3f;

//     body->CreateFixture(&fixtureDef);

//     // simulation

//     float timestep = 1.0f / 60.0f;

//     int32 velocityIterations = 6;
//     int32 positionIterations = 2;

//     for (int32 i = 0; i < 60; ++i) {
//         world.Step(timestep, velocityIterations, positionIterations);
//         b2Vec2 position = body->GetPosition();
//         float angle = body->GetAngle();
//         printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
//     }
// }


// Include standard headers
#include <cstdio>
// #include <cstdlib>

// Include GLEW & GLFW
#include <GL/glew.h>
#include <GLFW/glfw3.h>


GLFWwindow *window;

// Include GLM
// #include <glm/glm.hpp>


// using namespace glm;

int main() {
    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow(1024, 768, "Tutorial 01", nullptr, nullptr);
    if (window == nullptr) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    do {
        // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.

        glClear(GL_COLOR_BUFFER_BIT);

        // Draw nothing, see you in tutorial 2 !


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
