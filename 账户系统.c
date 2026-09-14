#pragma comment(lib, "shell32.lib")
/* 本C程序用Microsoft VS code编写,微软大战代码 */
#include <stdio.h>     //标准C接口
#include <Windows.h>   //用WindowsAPI
#include <string.h>   //用字符串
#include <shellapi.h>

int main(void) {
    char appsystem[16];   //APP的最高权限账户
    char appsystempasd[32] = "Ks_a!2@3nj!9aA;^";  //最高权限账户的密码
    char HEAD[16];   //命令提示符用户输入的部分

    while (1) { //循环的开始
        printf("A:\\SYSTEM>:~$ ");  //命令提示符
        if (scanf("%s", HEAD) != 1) 
        break;

        if (strcmp(HEAD, "help") == 0) {   //输入help后提示
            printf("You need Sign Up\n1, enter 'signup'\n2, enter your name\n3, Enter your 'Enter'.\n");
            getchar();
        } else if (strcmp(HEAD, "signup") == 0) {  //登录
            printf("Please enter the Administrator's name:\n");
            char adminusername[128];  //设置管理员名字
            scanf("%127s", adminusername);  //输入管理员名字
            Sleep(1000);

            char adminuserpassword[256];  //设置管理员密码
            printf("Please enter the %s Administrator's password:\n", adminusername);   //请求输入管理员密码
            scanf("%255s", adminuserpassword);  //输入管理员密码
            Sleep(1000);

            printf("Again:\n");  //再次请求输入管理员密码
            int registered = 0;   //判断对错
            while (!registered) { //如果不正确
                char adminuserpassword2FA[256];  //请求再次输入管理管密码
                scanf("%255s", adminuserpassword2FA);  //输入管理员密码
                if (strcmp(adminuserpassword2FA, adminuserpassword) == 0) {  //如果对了
                    printf("You are succeeding! Welcome\n");  //打印欢迎
                    registered = 1;  //登录成功
                } else {  //否则
                    printf("Try again\n");   //打印再试一次
                }
            }

            /* 注册成功后的登录循环 */
            while (1) {
                char adminuserpasswordlogin[256];   //请求登录时确认管理员登录密码
                printf("A:\\User\\System>~$ ");  //命令提示符
                printf("Enter your Administrator password:\n");  //请求输入
                scanf("%255s", adminuserpasswordlogin);          //输入管理员密码

                if (strcmp(adminuserpasswordlogin, adminuserpassword) == 0) {    //判断密码是否正确
                    printf("Welcome\n");   //欢迎
                    printf("Hi, welcome my login system! Enter 'exit' to exit! 'ok' for Thank You List!\n");   //欢迎
                    ShellExecuteA(  //Rickrollllllllllllllllllllllllllllllllll
                        NULL,
                        "open",
                        "https://www.bilibili.com/video/BV1NGua6oE2X/",
                        NULL,
                        NULL,
                        SW_SHOWNORMAL
                    );
                    break;  /* 登录成功后跳出登录循环，回到主菜单 */
                } else {
                    printf("Try again\n");
                }
            }
        } else {
            printf("NOT FOUND.\n");   //输入的啥也不是
        }
    }

    return 0;  //退出
}