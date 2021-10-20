//
// Created by Deblur on 2021-10-21.
//

#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

using namespace std;

class UI {
    static int decision;
    static int option;
    static int index;
public:
    UI() {
        cout << "그래픽 에디터입니다." << endl;
    }

    static int getDecision() {
        while (true) {
            cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
            cin >> decision;

            if (decision >= 1 && decision <= 4) {
                return decision;
            } else {
                cout << "올바르지 않은 입력입니다." << endl;
            }
        }
    }

    static int getOption() {
        while (true) {
            cout << "선:1, 원:2, 사각형:3 >>";
            cin >> option;

            if (option >= 1 && option <= 3) {
                return option;
            } else {
                cout << "올바르지 않은 입력입니다." << endl;
            }
        }
    }

    static int getDeleteIndex() {
        cout << "삭제하고자 하는 도형의 인덱스 >>";
        cin >> index;
        return index;
    }

    static void showList(Shape *pStart) {
        Shape *temp = pStart->getNext();

        int index = 0;

        while (temp->getNext() != NULL) {
            cout << index << ": ";
            temp->paint();
            temp = temp->getNext();
        }
    }
};

int UI::decision;
int UI::option;
int UI::index;

class GraphicEditor {
    Shape *pStart = NULL;
    Shape *pLast = NULL;
public:
    GraphicEditor() {
        UI *ui = new UI();
        int deleteIndex = -1;

        while (true) {
            switch (ui->getDecision()) {
                case 1:
                    switch (ui->getOption()) {
                        case 1:
                            insertion(1);
                            break;
                        case 2:
                            insertion(2);
                            break;
                        case 3:
                            insertion(3);
                            break;
                        default:
                            continue;
                    }
                    break;
                case 2:
                    deleteIndex = ui->getDeleteIndex();
                    deletion(deleteIndex);
                    break;
                case 3:
                    ui->showList(pStart);
                    break;
                case 4:
                    delete ui;
                    return;
                default:
                    continue;
            }
        }
    }

    void insertion(int option) {
        Shape *newNode;

        switch (option) {
            case 1: {
                newNode = new Line();
                break;
            }

            case 2: {
                newNode = new Circle();
                break;
            }

            case 3: {
                newNode = new Rect();
                break;
            }
        }

        if (pStart->getNext() == NULL) {
            pStart->add(newNode);
            pLast->add(newNode);
        } else {
            Shape *temp = pStart;

            while (temp->getNext() != NULL) {
                temp = temp->getNext();
            }

            temp->add(newNode);
            pLast = temp->getNext();
        }
    }

    void deletion(int index) {
        int maxLength = 0;
        Shape *temp = pStart;

        while (temp->getNext() != NULL || maxLength - 1 != index) {
            maxLength++;
            temp = temp->getNext();
        }

        if (maxLength - 1 == index) {
            if (pStart->getNext() == temp) { // 맨 앞부분 노드 삭제
                delete pStart;
                pStart->add(temp);
            }
        }

        if (index > maxLength - 1) {
            cout << "삭제 오류 : 인덱스가 범위 밖에 있음" << endl;
            return;
        }


    }

    void show() {

    }
};

int main() {
    return 0;
}