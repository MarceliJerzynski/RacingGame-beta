#ifndef CAR_H
#define CAR_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "shaderprogram.h"

const float max_wheel_angle = 45;


class Car
{
    public:
        Car();
        void loadFromPath(string pathBody,string pathFLW,string pathFRW,string pathRLW,string pathRRW, float apower, float abpower,vec3 aposition,
            float rotX, float rotY, float rotZ, float ascale);
        vec3 getPosition();
        float getRotation();
        void render(mat4 V, mat4 P, ShaderProgram *sp);
        void turn(float rot);
        int isMoving(); //1 - do przodu, -1 - do tylu, 0 - stoi
        void move(int going);   //0 - nie klika nic, 1 - trzyma W, 2 - trzyma S
    protected:
        Object *body;
        Object *FLW,*FRW,*RLW,*RRW;
        float wheel_angle = 0;
        float Power;
        float backPower;
        float temporaryPower;
        float v;
        float a;
        bool goForward;
        bool goBackward;
    private:
};

#endif // CAR_H