#include "Header.h"               //Metodos generales

Camara::Camara(string path) {
    this->path = path;

}
Mat gris;
Mat hsv;
Mat lab;
Mat Ycb;
Mat frame;
int GRAY = 0;
//char* trackbar_type = "Type: /n 0: Binary /n 1: Binary Inverted /n 2: Truncate /n 3: To Zero /n 4: To Zero Inverted";

// Variable que almacena el valor del track bar (Contrast Stretching)


Mat imgTreshold;
Mat imgTresholdHSV;
void eventoTrackThreshold(int v, void* pP) {
    cout << "Nuevo valor: " << v << endl;

}
void mouseHandler(int e, int x, int y, int d, void* ptr) {
    Point* p = (Point*)ptr;
    p->x = x;
    p->y = y;
}


void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
       if(GRAY ==1){
        imwrite("gris1.png",gris);
       }

       if (GRAY == 2) {
           imwrite("hsv.png", hsv);
       }
       if (GRAY == 3) {
           imwrite("lab.png", lab);
       }
       if (GRAY == 4) {
           imwrite("ycb.png", Ycb);
       }
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }

}

void Camara::AbrirCamara() {
    VideoCapture video(0);
    if (video.isOpened()) {

        namedWindow("Video", WINDOW_AUTOSIZE);
        createTrackbar("Gray", "Video", &GRAY, 4, eventoTrackThreshold, NULL);

        while (3 == 3) {
            video >> frame;
            Point p;

            if (frame.rows <= 0 || frame.cols <= 0)
                break;

            if (GRAY == 1) {
                String title = "Escala de grises";
                namedWindow("Escala de grises", 1);
                cvtColor(frame, gris, COLOR_BGR2GRAY);
                setMouseCallback("Escala de grises", CallBackFunc);
                imshow("Escala de grises", gris);


            }

            if (GRAY == 2) {
                namedWindow("Escala de HSV", WINDOW_AUTOSIZE);
                cvtColor(frame, hsv, COLOR_BGR2HSV);
                setMouseCallback("Escala de HSV", CallBackFunc);
                imshow("Escala de HSV", hsv);
               

            }

            if (GRAY == 3) {
                namedWindow("Escala de Lab", WINDOW_AUTOSIZE);
                cvtColor(frame, lab, COLOR_BGR2Lab);
                setMouseCallback("Escala de Lab", CallBackFunc);
                imshow("Escala de Lab", lab);
               

            }

            if (GRAY == 4) {
                namedWindow("Escala de YCrCb", WINDOW_AUTOSIZE);
                cvtColor(frame, Ycb, COLOR_BGR2YCrCb);
                setMouseCallback("Escala de YCrCb", CallBackFunc);
                imshow("Escala de YCrCb", Ycb);
               

            }
            imshow("Video", frame);


            if (waitKey(23) == 27) //Pedimos que espere 23 milisegundos a que el usario presione la tecla escape
                break;
        }
        destroyAllWindows();
    }



    //return 0;
}


