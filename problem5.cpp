/*
 * Problem 5: Function Template Overloading
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * describe(int), describe<T>(), printN<N>() 는 이미 구현되어 있습니다.
 * 아래 기대 출력이 나오도록 main() 안에서 올바르게 호출하세요.
 * 같은 이름의 일반 함수와 Function Template 이 공존할 때
 * Overload Resolution 에 따라 어떤 함수가 선택되는지 확인하세요.
 *
 * [활용 개념]
 *   - Function Template 과 Ordinary Function 의 공존
 *   - Overload Resolution (일반 함수 우선)
 *   - Explicit Template Arguments 로 Template 강제 호출
 *   - Default Template Arguments (C++11)
 *
 * [기대 출력]
 *   === Problem 5: Function Template Overloading ===
 *   [Part 1] Overload Resolution
 *   [int overload] value = 42
 *   [template] value = 3.14
 *   [template] value = hello
 *   [Part 2] Explicit Template Argument forces Template
 *   [template] value = 42
 *   [template] value = 42
 *   [Part 3] Default Template Argument (C++11)
 *   N = 10
 *   N = 5
 *   N = 20
 *
 * main 함수 안의 TODO 부분만 채우세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
#include <string>
using namespace std;

// ── 제공됨, 수정하지 마세요 ───────────────────────────────────
void describe(int value) {
    cout << "[int overload] value = " << value << "\n";
}

template<typename T>
void describe(T value) {
    cout << "[template] value = " << value << "\n";
}

template<int N = 10>
void printN() {
    cout << "N = " << N << "\n";
}
// ─────────────────────────────────────────────────────────────

int main() {
    cout << "=== Problem 5: Function Template Overloading ===" << "\n";

    cout << "[Part 1] Overload Resolution" << "\n";
    // TODO: 아래 출력이 나오도록 describe() 를 호출하세요.


    cout << "[Part 2] Explicit Template Argument forces Template" << "\n";
    // TODO: Explicit Template Argument 를 이용해 Template 을 강제 호출하세요.


    cout << "[Part 3] Default Template Argument (C++11)" << "\n";
    // TODO: printN() 을 아래 출력에 맞게 호출하세요.


    return 0;
}
// ─────────────────────────────────────────────────────────────
