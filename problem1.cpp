/*
 * Problem 1: Basic Function Template
 *
 * 학번:
 * 이름:
 *
 * ─────────────────────────────────────────────────────────────
 * 아래 runner 함수(runProblem1)가 올바르게 동작하도록
 * add 와 maxValue Function Template 을 구현하세요.
 *
 * [활용 개념]
 *   - template<typename T> 선언
 *   - Template Parameter 와 Template Argument
 *   - Function Template Instantiation
 *   - Explicit Template Arguments (add<int>, add<double>)
 *
 * [add 호출 예시]
 *   add(3, 7)       → 10
 *   add(1.5, 4.3)   → 5.8
 *
 * [maxValue 호출 예시]
 *   maxValue(3, 7)      → 7
 *   maxValue(1.5, 4.3)  → 4.3
 *
 * runner 함수(runProblem1)는 수정하지 마세요.
 * ─────────────────────────────────────────────────────────────
 */
#include <iostream>
using namespace std;

namespace {

// ── 여기서부터 구현하세요 ──────────────────────────────────────

// TODO: add Function Template 구현


// TODO: maxValue Function Template 구현


} // namespace

// ── runner (수정하지 마세요) ───────────────────────────────────
void runProblem1(istream& in) {
    int a, b;
    double c, d;
    in >> a >> b >> c >> d;

    cout << "=== Problem 1: Basic Function Template ===" << "\n";

    cout << "[add]" << "\n";
    cout << "add(" << a << ", " << b << ") = " << add(a, b) << "  [T deduced: int]" << "\n";
    cout << "add(" << c << ", " << d << ") = " << add(c, d) << "  [T deduced: double]" << "\n";
    cout << "add<int>(" << a << ", " << b << ") = " << add<int>(a, b) << "  [explicit: T = int]" << "\n";
    cout << "add<double>(" << a << ", " << b << ") = " << add<double>(a, b) << "  [explicit: T = double]" << "\n";

    cout << "[maxValue]" << "\n";
    cout << "maxValue(" << a << ", " << b << ") = " << maxValue(a, b) << "  [T deduced: int]" << "\n";
    cout << "maxValue(" << c << ", " << d << ") = " << maxValue(c, d) << "  [T deduced: double]" << "\n";
}
// ─────────────────────────────────────────────────────────────
