#include "Camera.h"

//
//  Camera.cpp
//  DrawEngine
//
// This class is based on a video playlist by Jamie King.
// https://www.youtube.com/playlist?list=PLRwVmtr-pp06qT6ckboaOhnm9FxmzHpbY
//

#include <iostream>
#include "Camera.h"


/*===============================
 * Camera
 * @description: the view point of the user.
 *===============================*/

Camera::Camera() : viewDirection(0.0f, 0.0f, -1.0f), up(0.0f, 1.0f, 0.0f){

}

Camera::Camera(QVector3D newPos) : viewDirection(0.0f, 0.0f, -1.0f), up(0.0f, 1.0f, 0.0f){
    this->position = newPos;
}

QMatrix4x4 Camera::getWorldToViewMatrix() {
   //return glm::lookAt(position, position + viewDirection, up);
    QMatrix4x4 worldToView;
    worldToView.lookAt(position, position + viewDirection, up);
    return worldToView;
}

/*
 * MoveForward
 * Moves the Camera forward
 */
void Camera::moveForward(){
    position += 5.0f * viewDirection;
}

/*
 * MoveBackward
 * Moves the Camera backward
 */
void Camera::moveBackward(){
    position += -5.0f * viewDirection;
}

/*
 * MoveUp
 * Moves the Camera upward
 */
void Camera::moveUp(){
    position += 5.0f * up;
}

/*
 * MoveDown
 * Moves the Camera downward
 */
void Camera::moveDown(){
    position += -5.0f * up;
}

/*
 * LookLeft
 * Rotates the Camera to the left
 */
void Camera::lookLeft(){
    //viewDirection = glm::mat3(glm::rotate(0.1f, up)) * viewDirection;
    QMatrix4x4 rotation;
    rotation.rotate(qreal(0.1f), up);

    viewDirection = rotation * viewDirection;
}

/*
 * LookRight
 * Rotates the Camera to the left
 */
void Camera::lookRight(){
    //viewDirection = glm::mat3(glm::rotate(-0.1f, up)) * viewDirection;
    QMatrix4x4 rotation;
    rotation.rotate(qreal(-0.1f), up);

    viewDirection = rotation * viewDirection;
}

/*
 * LookRight
 * Rotates the Camera to the left
 */
void Camera::strafeLeft(){
    //glm::vec3 strafeDirection = glm::cross(viewDirection, up);
    //position += -5.0f * strafeDirection;

    QVector3D strafeDirection = QVector3D::crossProduct(viewDirection, up);
    position += -5.0f * strafeDirection;
}

/*
 * StrafeRight
 * Moves the Camera to the right
 */
void Camera::strafeRight(){
    //glm::vec3 strafeDirection = glm::cross(viewDirection, up);
    //position += 5.0f * strafeDirection;

    QVector3D strafeDirection = QVector3D::crossProduct(viewDirection, up);
    position += 5.0f * strafeDirection;
}

/*
 * LookUp
 * Rotates the Camera upward
 */
void Camera::lookUp(){
    //glm::vec3 toRotateAround = glm::cross(viewDirection, up);
    //viewDirection = glm::mat3(glm::rotate(0.1f, toRotateAround)) * viewDirection;

    QVector3D toRotateAround = QVector3D::crossProduct(viewDirection, up);
    QMatrix4x4 rotation;
    rotation.rotate(qreal(0.1f), toRotateAround);

    viewDirection = rotation * viewDirection;
}

/*
 * LookUp
 * Rotates the Camera downward
 */
void Camera::lookDown(){
    //glm::vec3 toRotateAround = glm::cross(viewDirection, up);
    //viewDirection = glm::mat3(glm::rotate(-0.1f, toRotateAround)) * viewDirection;

    QVector3D toRotateAround = QVector3D::crossProduct(viewDirection, up);
    QMatrix4x4 rotation;
    rotation.rotate(qreal(-0.1f), toRotateAround);

    viewDirection = rotation * viewDirection;
}
