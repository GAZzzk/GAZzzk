#include <Arduino.h>
#define PwmPin_LeftFront 32//左前腿
#define PwmPin_LeftFrontJoint 33//左前腿关节
#define PwmPin_RightFront 23//右前腿
#define PwmPin_RightFrontJoint 22//右前腿关节
#define PwmPin_LefThind 13//左后腿
#define PwmPin_LefThindJoint 12//左后腿关节
#define PwmPin_RighThind 2 //右后腿
#define PwmPin_RighThindJoint 15 //右后腿关节
int freq = 2000;    // 频率
int resolution = 10;   // 分辨率
/*
 * LEDC Chan to Group/Channel/Timer Mapping
** ledc: 0  => Group: 0, Channel: 0, Timer: 0
** ledc: 1  => Group: 0, Channel: 1, Timer: 0
** ledc: 2  => Group: 0, Channel: 2, Timer: 1
** ledc: 3  => Group: 0, Channel: 3, Timer: 1
** ledc: 4  => Group: 0, Channel: 4, Timer: 2
** ledc: 5  => Group: 0, Channel: 5, Timer: 2
** ledc: 6  => Group: 0, Channel: 6, Timer: 3
** ledc: 7  => Group: 0, Channel: 7, Timer: 3
** ledc: 8  => Group: 1, Channel: 0, Timer: 0
** ledc: 9  => Group: 1, Channel: 1, Timer: 0
** ledc: 10 => Group: 1, Channel: 2, Timer: 1
** ledc: 11 => Group: 1, Channel: 3, Timer: 1
** ledc: 12 => Group: 1, Channel: 4, Timer: 2
** ledc: 13 => Group: 1, Channel: 5, Timer: 2
** ledc: 14 => Group: 1, Channel: 6, Timer: 3
** ledc: 15 => Group: 1, Channel: 7, Timer: 3
*/
void Servo_Init()
{
    int i, j;
    for (i = 0; i <= 8; i++)
    {
        ledcSetup(i, freq, resolution); // 设置通道
    }

    ledcAttachPin(PwmPin_LeftFront, 0); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_LeftFrontJoint, 1); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_RightFront, 2); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_RightFrontJoint, 3); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_LefThind, 4); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_LefThindJoint, 5); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_RighThind, 6); // 将通道与对应的引脚连接,

    ledcAttachPin(PwmPin_RighThindJoint, 7); // 将通道与对应的引脚连接,

    for (j = 0; j <= 8; j++)
    {
        ledcWrite(j, 511);
    }
}
void Servo_SetAngle(int Channel,int Angle){
    //1023-180  0-0   511-90
    ledcWrite(Channel, Angle  );
}
