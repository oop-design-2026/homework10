/*
 * Problem 2: Template Argument Deduction
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * add Function Template 과 typeTag 는 이미 구현되어 있습니다.
 * 아래 기대 출력이 나오도록 makeCalls() 안에서 add() 를 올바르게 호출하세요.
 * 어떤 인자를 전달해야 각 출력이 나오는지, T 가 어떻게 추론되는지 생각해 보세요.
 *
 * [활용 개념]
 *   - Template Argument Deduction (암묵적 추론)
 *   - Explicit Template Arguments (add<double>)
 *   - 혼합 타입 전달 시 Deduction 실패 → Explicit 로 해결
 *   - Implicit Type Conversion
 *
 * [기대 출력]
 *   [1] Implicit Deduction — same type
 *   add(3, 7) = 10  [T=int]
 *   add(1.5, 2.3) = 3.8  [T=double]
 *   [2] Explicit Template Argument
 *   add(3, 7) = 10  [T=double]
 *   [3] Mixed Types — Explicit 로 해결
 *   add(3, 1.5) = 4.5  [T=double]
 *
 * runner 함수(runProblem2)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

namespace {

// ── 제공됨, 수정하지 마세요 ───────────────────────────────────
template<typename T> const char* typeTag();
template<> const char* typeTag<int>()    { return "int"; }
template<> const char* typeTag<double>() { return "double"; }

template<typename T>
void add(T a, T b) {
    cout << "add(" << a << ", " << b << ") = " << (a + b)
         << "  [T=" << typeTag<T>() << "]" << "\n";
}
// ─────────────────────────────────────────────────────────────

void makeCalls() {
    // TODO: 아래 주석을 참고하여 add() 를 올바르게 호출하세요.

    cout << "[1] Implicit Deduction — same type" << "\n";


    cout << "[2] Explicit Template Argument" << "\n";


    cout << "[3] Mixed Types — Explicit 로 해결" << "\n";
    // add(3, 1.5) 는 Compile Error (T 를 int 와 double 로 동시에 추론 불가)
    // → Explicit Template Argument 로 해결하세요.

}

} // namespace

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem2(istream&) {
    cout << "=== Problem 2: Template Argument Deduction ===" << "\n";
    makeCalls();
}
// ─────────────────────────────────────────────────────────────
