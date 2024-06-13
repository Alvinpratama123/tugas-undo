#include <iostream>
#include <stack>
#include <string>

using namespace std;

class UndoRedo {
private:
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void undo(const string& word) {
        undoStack.push(word);
    }

    void redo() {
        if (undoStack.empty()) {
            cout << "Data di hapus: --" << endl;
        } else {
            string word = undoStack.top();
            redoStack.push(word);
            undoStack.pop();
            cout << "Data di hapus: " << word << endl;
        }
    }

    void displayUndoStack() {
        if (undoStack.empty()) {
            cout << "Tidak ada data yang di undo" << endl;
        } else {
            stack<string> temp;
            cout << "Data yang di undo: ";
            while (!undoStack.empty()) {
                temp.push(undoStack.top());
                undoStack.pop();
            }
            while (!temp.empty()) {
                cout << temp.top() << " ";
                undoStack.push(temp.top());
                temp.pop();
            }
            cout << endl;
        }
    }

    void displayRedoStack() {
        if (redoStack.empty()) {
            cout << "Tidak ada data yang di redo" << endl;
        } else {
            stack<string> temp;
            cout << "Data yang sebelum nya di hapus: ";
            while (!redoStack.empty()) {
                temp.push(redoStack.top());
                redoStack.pop();
            }
            while (!temp.empty()) {
                cout << temp.top() << " ";
                redoStack.push(temp.top());
                temp.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    UndoRedo ur;
    int choice;
    string word;

    while (true) {
        cout << "1. undo" << endl;
        cout << "2. redo (hapus)" << endl;
        cout << "3. isEmptyUndo (tampilkan data)" << endl;
        cout << "4. isEmptyRedo (data yang di hapus)" << endl;
        cout << "Masukan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukan kata: ";
                cin >> word;
                ur.undo(word);
                break;
            case 2:
                ur.redo();
                break;
            case 3:
                ur.displayUndoStack();
                break;
            case 4:
                ur.displayRedoStack();
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}