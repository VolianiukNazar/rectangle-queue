#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

struct Point {
    int x, y;
};

class Rectangles {
private:
    Point topLeft, topRight, bottomRight, bottomLeft;
    int id;
public:
    Rectangles(int id, Point tl, Point tr, Point br, Point bl)
        : id(id), topLeft(tl), topRight(tr), bottomRight(br), bottomLeft(bl) {
    }

    void print() const {
        cout << "Rectangle #" << id
            << " | Top-left: (" << topLeft.x << ", " << topLeft.y << ")"
            << " | Top-right: (" << topRight.x << ", " << topRight.y << ")"
            << " | Bottom-right: (" << bottomRight.x << ", " << bottomRight.y << ")"
            << " | Bottom-left: (" << bottomLeft.x << ", " << bottomLeft.y << ")\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    queue<Rectangles> rectQueue;

    // Add rectangles with all four corners
    rectQueue.push(Rectangles(1, { 0, 10 }, { 5, 10 }, { 5, 0 }, { 0, 0 }));
    rectQueue.push(Rectangles(2, { 2, 8 }, { 7, 8 }, { 7, 3 }, { 2, 3 }));
    rectQueue.push(Rectangles(3, { 1, 5 }, { 4, 5 }, { 4, 2 }, { 1, 2 }));

    // View all rectangles in the queue
    cout << "Queue contents:\n";
    queue<Rectangles> temp = rectQueue;
    while (!temp.empty()) {
        temp.front().print();
        temp.pop();
    }

    // Remove the first rectangle
    cout << "\nRemoving the first element...\n";
    rectQueue.pop();

    // Updated queue contents
    cout << "\nUpdated queue contents:\n";
    temp = rectQueue;
    while (!temp.empty()) {
        temp.front().print();
        temp.pop();
    }

    system("pause");
    return 0;
}
