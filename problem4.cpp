/*
 * Problem 4: Non-Type Template Parameters
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * scale 과 scaleRuntime 은 이미 구현되어 있습니다.
 * 아래 기대 출력이 나오도록 makeCalls() 안에서 올바르게 호출하세요.
 * N 에 어떤 값을 넣어야 하는지, 왜 변수를 쓸 수 없는지 확인하세요.
 *
 * [활용 개념]
 *   - Non-Type Template Parameters (NTTP)
 *   - Compile-time Constant vs. Runtime Variable
 *   - 서로 다른 N 값에 따른 별도 Function Instantiation
 *
 * [기대 출력]
 *   === Problem 4: Non-Type Template Parameters ===
 *   [Part 1] NTTP calls
 *   scale<3>(10) = 30
 *   scale<5>(10) = 50
 *   scale<7>(6) = 42
 *   [Part 2] Template Argument vs Function Argument
 *   scale<3>(10) = 30
 *   scaleRuntime(3, 10) = 30
 *   [Part 3] Different N → Different Instantiation
 *   scale<2>(5) = 10
 *   scale<4>(5) = 20
 *   scale<8>(5) = 40
 *
 * main 함수는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

// ── 제공됨, 수정하지 마세요 ───────────────────────────────────
template<int N>
void scale(int x) {
    cout << "scale<" << N << ">(" << x << ") = " << (x * N) << "\n";
}

void scaleRuntime(int n, int x) {
    cout << "scaleRuntime(" << n << ", " << x << ") = " << (x * n) << "\n";
}
// ─────────────────────────────────────────────────────────────

void makeCalls() {
    // TODO: 아래 주석을 참고하여 scale<N>() 과 scaleRuntime() 을 올바르게 호출하세요.

    cout << "[Part 1] NTTP calls" << "\n";


    cout << "[Part 2] Template Argument vs Function Argument" << "\n";


    cout << "[Part 3] Different N → Different Instantiation" << "\n";

}

// ── main (수정하지 마세요) ───────────────────────────────────
int main() {
    cout << "=== Problem 4: Non-Type Template Parameters ===" << "\n";
    makeCalls();
    return 0;
}
// ─────────────────────────────────────────────────────────────
