#include <iostream>
#include <vector>

std::vector<int> mergeSortedArrays(const std::vector<int>& A, const std::vector<int>& B) {
    int n1 = A.size();
    int n2 = B.size();

    std::vector<int> C(n1 + n2);

    int i = 0;
    int j = n2 - 1;
    int k = 0;

    while (i < n1 && j >= 0) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j--;
        }
        k++;
    }

    while (i < n1) {
        C[k] = A[i];
        i++;
        k++;
    }

    while (j >= 0) {
        C[k] = B[j];
        j--;
        k++;
    }

    return C;
}

int main() {
    std::vector<int> A = {1, 3, 5, 7, 9};
    std::vector<int> B = {10, 8, 6, 4, 2};

    std::vector<int> C = mergeSortedArrays(A, B);

    std::cout << "Sorted merged array C: ";
    for (int i = 0; i < C.size(); i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
