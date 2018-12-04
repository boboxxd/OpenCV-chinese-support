//
// Created by 徐旭东 on 2018/12/4.
//

#include <opencv2/opencv.hpp>
#include "Cv310Text.h"
#include <wchar.h>
using namespace cv;
using namespace std;

int toWchar(char* &src, wchar_t* &dest, const char *locale = "zh_CN.utf8"){
    if (src == NULL) {
        dest = NULL;
        return 0;
    }
    //根据环境变量设置locale
    setlocale(LC_CTYPE, locale);
    //得到转化为需要的宽字符大小
    int w_size = mbstowcs(NULL, src, 0) + 1;
    //w_size=0说明mbstowcs返回值为-1。即在运行过程中遇到了非法字符(很有可能使locale没有设置正确)
    if (w_size == 0) {
        dest = NULL;
        return -1;
    }
    //wcout << "w_size" << w_size << endl;
    dest = new wchar_t[w_size];
    if (!dest) return -1;
    int ret = mbstowcs(dest, src, strlen(src)+1);
    if (ret <= 0)return -1;
    return 0;
}

int main()
{
    cv::Mat img = imread("1.jpg");
    Cv310Text text("simfang.ttf");
    char *msg = "现在我支持向图像中写入中文了,哈哈哈哈:)";
    wchar_t *w_msg ;
    toWchar(msg,w_msg);
    float p = 0.9;
    CvScalar fontSize={22,0.5,0.1,0};
    bool isUnderLine=true;
    text.setFont(NULL, &fontSize, &isUnderLine, &p);
    text.putText(img, w_msg, cvPoint(10, 38), CV_RGB(255, 0, 0));
    imwrite("test_result.jpg",img);
    return 0;
}