#include "camera.h"

Camera::Camera()
{
    m_eye = 100;
}

void Camera::setEye(float eye)
{
    m_eye = eye;
}

float Camera::eye()
{
    return m_eye;
}
