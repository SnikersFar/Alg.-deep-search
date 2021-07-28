#include <iostream>
#include <queue> // очередь
#include <stack> // стек

using namespace std;

struct Edge {
    int begin;
    int end;
};

int main()
{
    system("chcp 1251");
    system("cls");
    queue<int> Queue;
    stack<Edge> Edges;
    int end = 3; // конец
   // Edge e;
    int mas[9][9] = {
    { 0, 2, 0, 0, 0, 0, 0, 3, 0 },
    { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 0, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 0, 1, 0, 1, 0 },
    { 0, 1, 1, 1, 0, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 1, 0 } };

    int nodes[9][9], // посещенные ячейки
        resloc[40][3], // навигатор
        now = 0,
        number = 0;
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            if (mas[i][k] == 2) {
                resloc[0][0] = i;
                resloc[0][1] = k;
                resloc[0][2] = 1; // 1 - нужная ячейка
                nodes[i][k] = 2;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {

            nodes[i][k] = 0;

        }
    }

    cout << endl << "Labirint: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {

            cout << mas[i][k] << "\t";

        }
        cout << endl;
    }
    cout << endl << "_________________________________________________________________" << endl;


    Queue.push(0); // помещаем в очередь первую вершину
    //while (!Queue.empty())
    bool b = true;
    int per = 0;
    while (b)
    {


        for (int i = 0; i < 9 && b == true; i++) {

            for (int k = 0; k < 9 && b == true; k++) {
  

                if (mas[i][k] != 0) {
                    if (nodes[i][k] == 0) //&&  // проверяем не посещали ли мы эту ячейку
                    {


                        // проверяем, прилегает-ли эта ячейка к предыдущей
                        if ( (resloc[number][0] == i && (resloc[number][1] + 1 == k || resloc[number][1] - 1 == k))     ||   (    resloc[number][1] == k && ( resloc[number][0] + 1 == i || resloc[number][0] - 1 == i )  ))
                        {
                            per--;
                            number++;
                            resloc[number][0] = i;
                            resloc[number][1] = k;
                            nodes[i][k] = 2;
                 


                            if (mas[i][k] == 3) {

                                    std::cout << "\n Na-Vi completed \n";
                                    

                                b = false;
                                break;


                            }

                        }


                    }
                    if (per == 100 && b == true) {
                        resloc[number][0] = 0;
                        resloc[number][1] = 0;
                        number--;
                        per = 0;

                    }
                }

            }
        }


        per++;
       // cout << per << "\n";
    }
    for (int i = 1; i < number; i++) {
            mas[resloc[i][0]][resloc[i][1]] = 8;

    }

    cout << endl << "_________________________________________________________________" << endl;
    cout << endl << "Navigation: " << endl;
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
      
            cout << mas[i][k] << "\t";
        
        }
        cout << endl;
    }


}
    
    