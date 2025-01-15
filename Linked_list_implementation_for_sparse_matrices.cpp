#include <iostream>
#include <vector>
using namespace std;

// Node structure for the linked list
struct Node {
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int val) : row(r), col(c), value(val), next(nullptr) {}
};


class SparseMatrixLinkedList {
private:
    int rows;
    int cols;
    Node* head; 

public:
    SparseMatrixLinkedList(int r, int c) : rows(r), cols(c), head(nullptr) {}

    // Function to add a non-zero element to the linked list
    void addElement(int r, int c, int val) {
        if (val != 0) {
            Node* newNode = new Node(r, c, val);
            if (!head) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next) {
                    current = current->next;
                }
                current->next = newNode;
            }
        }
    }

    // Function to create a sparse matrix from a given 2D matrix
    void createSparseMatrix(const vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                addElement(i, j, matrix[i][j]);
            }
        }
    }

    // Function to print the linked list 
    void print() {
        cout << "Linked list representation of the sparse matrix:\n";
        Node* current = head;
        while (current) {
            cout << "[" << current->row << "," << current->col << "," << current->value << "]";
            if (current->next) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << "\n";
    }

    
    ~SparseMatrixLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    if (rows <= 0) {
        cout << "Invalid input: Number of rows must be greater than 0.\n";
        return 1; 
    }

    cout << "Enter the number of columns: ";
    cin >> cols;
    if (cols <= 0) {
        cout << "Invalid input: Number of columns must be greater than 0.\n";
        return 1; 
    }

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix elements (row by row):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    SparseMatrixLinkedList sm(rows, cols);
    sm.createSparseMatrix(matrix);

    sm.print();

    return 0;
}
