/*
 * Problem 6: Integrated — Generic Calculator
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * add 와 scaledAdd Function Template 은 이미 구현되어 있습니다.
 * 아래 기대 출력이 나오도록 makeCalls() 안에서 올바르게 호출하세요.
 * 어떤 오버로드가 선택되는지, Scale 에 어떤 값을 넣어야 하는지
 * 생각하면서 호출해 보세요.
 *
 * [활용 개념]
 *   - Function Template Overloading (단일 타입 vs 두 타입 오버로드)
 *   - Template Argument Deduction & Explicit Template Arguments
 *   - Non-Type Template Parameters + Multiple Type Parameters 조합
 *
 * [기대 출력]
 *   === Problem 6: Integrated — Generic Calculator ===
 *   [Part 1] Function Template + Template Argument Deduction
 *   add(3, 7) = 10
 *   add(1.5, 2.3) = 3.8
 *   add(3, 7) = 10
 *   [Part 2] Multiple Template Parameters
 *   add(5, 2.5) = 7.5
 *   add(2.5, 5) = 7.5
 *   [Part 3] Non-Type Template Parameter
 *   scaledAdd<2>(3, 4) = 14
 *   scaledAdd<3>(1.5, 2.3) = 11.4
 *   [Part 4] NTTP + Multiple Type Parameters
 *   scaledAdd<2>(3, 1.7) = 9.4
 *   scaledAdd<3>(2, 0.5) = 7.5
 *
 * main 함수는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

// ── 제공됨, 수정하지 마세요 ───────────────────────────────────
template<typename T>
void add(T a, T b) {
    cout << "add(" << a << ", " << b << ") = " << (a + b) << "\n";
}

template<typename T, typename U>
void add(T a, U b) {
    cout << "add(" << a << ", " << b << ") = " << (a + b) << "\n";
}

template<int Scale, typename T>
void scaledAdd(T a, T b) {
    cout << "scaledAdd<" << Scale << ">(" << a << ", " << b << ") = "
         << ((a + b) * Scale) << "\n";
}

template<int Scale, typename T, typename U>
void scaledAdd(T a, U b) {
    cout << "scaledAdd<" << Scale << ">(" << a << ", " << b << ") = "
         << ((a + b) * Scale) << "\n";
}
// ─────────────────────────────────────────────────────────────

void makeCalls() {
    // TODO: 아래 주석을 참고하여 add() 와 scaledAdd() 를 올바르게 호출하세요.

    cout << "[Part 1] Function Template + Template Argument Deduction" << "\n";


    cout << "[Part 2] Multiple Template Parameters" << "\n";


    cout << "[Part 3] Non-Type Template Parameter" << "\n";


    cout << "[Part 4] NTTP + Multiple Type Parameters" << "\n";

}

// ── main (수정하지 마세요) ───────────────────────────────────
int main() {
    cout << "=== Problem 6: Integrated — Generic Calculator ===" << "\n";
    makeCalls();
    return 0;
}
// ─────────────────────────────────────────────────────────────
