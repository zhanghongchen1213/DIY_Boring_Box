#include "EM_JQ8400.h"

EM_JQ8400 JQ8400_Device(8, A1); //实例化一个JQ8X00对象,忙检测IO引脚为2号，关闭忙检测功能。注意：忙检测功能为关闭状态将不会配置忙检测引脚
void setup()
{
  uint8_t MakeUp_buffer[2] = {2, 1};          //组合播放内容
  Serial.begin(9600);                         //必须初始化串口，波特率固定为9600不可更改
  delay(500);                                 //上电延时一段时间等待模块稳定之后字发送控制指令
  JQ8400_Device.Command_Data(SetVolume, 30);  //设定音量为30
  delay(10);                                  //连续通信加入一定的延时等待模块处理完上一条指令
//  JQ8X00_Device.MakeUpPlay(MakeUp_buffer, 2); //组合播放指令，依次播放ZH文件夹下的02 01 音频
}

void loop()
{
  JQ8400_Device.Command(Play);
  delay(5000);
  // put your main code here, to run repeatedly:
}
