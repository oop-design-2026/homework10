/*
 * Problem 3: Multiple Template Parameters
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * Template Parameter 가 하나인 경우 서로 다른 타입의 인수를 처리할 수 없다는
 * 한계를 확인하고, 두 개의 Template Parameter (T, U) 와 auto 반환 타입을
 * 이용하여 해결하세요.
 *
 * [활용 개념]
 *   - Multiple Type Parameters (T, U)
 *   - 서로 다른 자료형의 Function Arguments
 *   - auto Return Type Deduction (C++14)
 *
 * [add 호출 예시]
 *   add(5, 2.5)   → 7.5   (T=int, U=double)
 *   add(2.5, 5)   → 7.5   (T=double, U=int)
 *
 * [subtract 호출 예시]
 *   subtract(5, 2.5)   →  2.5   (T=int, U=double)
 *   subtract(2.5, 5)   → -2.5   (T=double, U=int)
 *
 * runner 함수(runProblem3)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

namespace {

// ── 여기서부터 구현하세요 ──────────────────────────────────────

// TODO: add — 두 개의 Template Parameter (T, U), auto 반환 타입
//   add(5, 2.5) → 7.5   (T=int, U=double)
//   add(2.5, 5) → 7.5   (T=double, U=int)


// TODO: subtract — 두 개의 Template Parameter (T, U), auto 반환 타입
//   subtract(5, 2.5) →  2.5   (T=int, U=double)
//   subtract(2.5, 5) → -2.5   (T=double, U=int)


} // namespace

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem3(istream& in) {
    int a;
    double b;
    in >> a >> b;

    cout << "=== Problem 3: Multiple Template Parameters ===" << "\n";

    cout << "[Part 1] Single Type Parameter (limitation)" << "\n";
    cout << "[NOTE] add<T>(" << a << ", " << b
         << ") → Compile Error: T cannot be both int and double" << "\n";

    cout << "[Part 2] Two Type Parameters (T, U)" << "\n";
    cout << "add(" << a << ", " << b << ") = " << add(a, b)
         << "  [T=int, U=double]" << "\n";
    cout << "add(" << b << ", " << a << ") = " << add(b, a)
         << "  [T=double, U=int]" << "\n";

    cout << "[Part 3] auto Return Type Deduction" << "\n";
    cout << "subtract(" << a << ", " << b << ") = " << subtract(a, b)
         << "  [auto → double]" << "\n";
    cout << "subtract(" << b << ", " << a << ") = " << subtract(b, a)
         << "  [auto → double]" << "\n";
}
// ─────────────────────────────────────────────────────────────
