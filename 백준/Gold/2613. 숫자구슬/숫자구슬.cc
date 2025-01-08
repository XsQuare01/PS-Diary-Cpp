#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 주어진 최대 합으로 M개의 그룹을 만들 수 있는지 확인
bool isValid(vector<int>& arr, int n, int m, int maxSum) {
    int groups = 1, currentSum = 0;
    for (int i = 0; i < n; ++i) {
        if (currentSum + arr[i] > maxSum) {
            groups++;
            currentSum = arr[i];
            if (groups > m) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

// 그룹 구성을 찾는 함수
vector<int> findGroupSizes(vector<int>& arr, int n, int m, int maxSum) {
    vector<int> sizes;
    int currentSum = 0, currentSize = 0;

    for (int i = 0; i < n; ++i) {
        if (currentSum + arr[i] > maxSum) {
            sizes.push_back(currentSize);
            currentSum = arr[i];
            currentSize = 1;
            m--; // 그룹 하나를 채움
        } else {
            currentSum += arr[i];
            currentSize++;
        }

        // 남은 그룹의 수가 남은 구슬의 수와 같다면, 나머지는 모두 1씩 배분
        if (n - i == m) {
            sizes.push_back(currentSize);
            for (int j = i + 1; j < n; ++j) sizes.push_back(1);
            break;
        }
    }

    return sizes;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    int maxElement = 0, totalSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
        totalSum += arr[i];
    }

    // 이진 탐색 범위 설정
    int low = maxElement, high = totalSum, result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isValid(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 결과를 바탕으로 그룹 구성을 계산
    vector<int> groupSizes = findGroupSizes(arr, n, m, result);

    // 출력
    cout << result << '\n';
    for (int size : groupSizes) {
        cout << size << " ";
    }

    return 0;
}
