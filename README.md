## 개요

C++ **Function Template** 의 선언, Instantiation, Argument Deduction, 그리고 Overloading 을 실습합니다.  
총 6문제로 구성되어 있으며, 각 `problem*.cpp` 파일에 Function Template 을 구현하세요.  
`main.cpp` 는 수정하지 않습니다.

- **Problem 1 ~ 3**: `main.cpp` + `problem1~3.cpp` 를 함께 컴파일하여 자동 채점됩니다.
- **Problem 4 ~ 6**: 각 파일을 단독으로 컴파일하며, 직접 채점합니다.

---

## 개발 환경 준비

g++ 컴파일러가 필요합니다. 이미 설치되어 있다면 다음 단계로 넘어가세요.

| 운영체제 | 설치 방법 |
|---|---|
| Windows | [MSYS2](https://www.msys2.org/) 설치 후 `pacman -S mingw-w64-ucrt-x86_64-gcc` |
| macOS | 터미널에서 `xcode-select --install` |
| Linux (Ubuntu) | `sudo apt install build-essential` |

설치 확인:
```bash
g++ --version
```

---

## 파일 구조

```
homework10/
├── main.cpp              ← 수정 금지. Problem 1~3 테스트 실행 로직.
├── problem1.cpp          ← Problem 1 구현 (Basic Function Template)
├── problem2.cpp          ← Problem 2 구현 (Template Argument Deduction)
├── problem3.cpp          ← Problem 3 구현 (Multiple Template Parameters)
├── problem4.cpp          ← Problem 4 구현 (Non-Type Template Parameters) — 단독 컴파일
├── problem5.cpp          ← Problem 5 구현 (Function Template Overloading) — 단독 컴파일
├── problem6.cpp          ← Problem 6 구현 (Integrated) — 단독 컴파일
├── test10.sh             ← 채점 스크립트 (macOS / Linux)
└── Test/
    ├── case1.txt         ← 테스트 케이스 1 입력 데이터
    ├── case2.txt         ← 테스트 케이스 2 입력 데이터
    ├── case3.txt         ← 테스트 케이스 3 입력 데이터
    ├── expected1.txt     ← 테스트 케이스 1 기대 출력
    ├── expected2.txt     ← 테스트 케이스 2 기대 출력
    └── expected3.txt     ← 테스트 케이스 3 기대 출력
```

---

## 문제 1 — Basic Function Template (`problem1.cpp`)

아래 호출 방식에 맞게 **Function Template 을 구현**하세요.  
같은 함수 하나로 `int`, `double` 등 여러 타입에 동작해야 합니다.

**활용 개념**

- `template<typename T>` 선언
- Template Parameter 와 Template Argument
- Function Template Instantiation
- Explicit Template Arguments (`add<int>`, `add<double>`)

**호출 방식 (problem1.cpp 주석 참고)**

```cpp
add(3, 7)           // T 가 int 로 자동 추론
add(1.5, 4.3)       // T 가 double 로 자동 추론
add<int>(3, 7)      // T = int 명시
add<double>(3, 7)   // T = double 명시
maxValue(3, 7)      // T 가 int 로 자동 추론
maxValue(1.5, 4.3)  // T 가 double 로 자동 추론
```

**기대 출력 — a=3, b=7, c=1.5, d=4.3 기준**

```
=== Problem 1: Basic Function Template ===
[add]
add(3, 7) = 10  [T deduced: int]
add(1.5, 4.3) = 5.8  [T deduced: double]
add<int>(3, 7) = 10  [explicit: T = int]
add<double>(3, 7) = 10  [explicit: T = double]
[maxValue]
maxValue(3, 7) = 7  [T deduced: int]
maxValue(1.5, 4.3) = 4.3  [T deduced: double]
```

---

## 문제 2 — Template Argument Deduction (`problem2.cpp`)

`add()` Function Template 은 이미 구현되어 있습니다.  
**아래 기대 출력이 나오도록 `add()` 를 올바르게 호출**하세요.  
어떤 인자를 전달해야 각 출력이 나오는지 생각하면서 T 가 추론되는 과정을 확인하세요.

**활용 개념**

- Template Argument Deduction (암묵적 추론)
- Explicit Template Arguments (`add<double>`)
- 혼합 타입 전달 시 Deduction 실패 → Explicit 로 해결
- Implicit Type Conversion

**기대 출력**

```
=== Problem 2: Template Argument Deduction ===
[1] Implicit Deduction — same type
add(3, 7) = 10  [T=int]
add(1.5, 2.3) = 3.8  [T=double]
[2] Explicit Template Argument
add(3, 7) = 10  [T=double]
[3] Mixed Types — Explicit 로 해결
add(3, 1.5) = 4.5  [T=double]
```

---

## 문제 3 — Multiple Template Parameters (`problem3.cpp`)

Template Parameter 가 하나인 경우 서로 다른 타입의 인수를 처리할 수 없다는 한계를 확인하고,  
**두 개의 Template Parameter (T, U) 와 auto 반환 타입**을 이용하여 해결하세요.

**활용 개념**

- Multiple Type Parameters (`T`, `U`)
- 서로 다른 자료형의 Function Arguments
- `auto` Return Type Deduction (C++14)

**호출 방식 (problem3.cpp 주석 참고)**

```cpp
add(5, 2.5)       // T=int, U=double 자동 추론
add(2.5, 5)       // T=double, U=int 자동 추론
subtract(5, 2.5)  // T=int, U=double 자동 추론
subtract(2.5, 5)  // T=double, U=int 자동 추론
```

**기대 출력 — a=5(int), b=2.5(double) 기준**

```
=== Problem 3: Multiple Template Parameters ===
[Part 1] Single Type Parameter (limitation)
[NOTE] add<T>(5, 2.5) → Compile Error: T cannot be both int and double
[Part 2] Two Type Parameters (T, U)
add(5, 2.5) = 7.5  [T=int, U=double]
add(2.5, 5) = 7.5  [T=double, U=int]
[Part 3] auto Return Type Deduction
subtract(5, 2.5) = 2.5  [auto → double]
subtract(2.5, 5) = -2.5  [auto → double]
```

---

## 문제 4 — Non-Type Template Parameters (`problem4.cpp`)

`scale()` 과 `scaleRuntime()` 은 이미 구현되어 있습니다.  
**아래 기대 출력이 나오도록 올바르게 호출**하세요.  
N 에 어떤 값을 넣어야 하는지, 왜 변수를 쓸 수 없는지 확인하세요.

**컴파일 및 실행**

```bash
g++ -std=c++17 -o problem4 problem4.cpp
./problem4
```

**활용 개념**

- Non-Type Template Parameters (NTTP)
- Compile-time Constant vs. Runtime Variable
- 서로 다른 N 값에 따른 별도 Function Instantiation

**기대 출력**

```
=== Problem 4: Non-Type Template Parameters ===
[Part 1] NTTP calls
scale<3>(10) = 30
scale<5>(10) = 50
scale<7>(6) = 42
[Part 2] Template Argument vs Function Argument
scale<3>(10) = 30
scaleRuntime(3, 10) = 30
[Part 3] Different N → Different Instantiation
scale<2>(5) = 10
scale<4>(5) = 20
scale<8>(5) = 40
```

---

## 문제 5 — Function Template Overloading (`problem5.cpp`)

같은 이름의 일반 함수(Ordinary Function)와 Function Template 이 공존할 때  
**Overload Resolution 에 따라 호출되는 함수가 결정되는 과정**을 확인하세요.

**컴파일 및 실행**

```bash
g++ -std=c++17 -o problem5 problem5.cpp
./problem5
```

**활용 개념**

- Function Template 과 Ordinary Function 의 공존
- Overload Resolution (일반 함수 우선)
- Explicit Template Arguments 로 Template 강제 호출
- Default Template Arguments (C++11)

**호출 방식 (problem5.cpp 주석 참고)**

```cpp
describe(42)           // → [int overload]   일반 함수 우선 선택
describe(3.14)         // → [template]       T=double 로 Template 선택
describe(string(...))  // → [template]       T=string 으로 Template 선택
describe<int>(42)      // → [template]       Explicit 로 Template 강제
describe<double>(42)   // → [template]       int → double 변환 후 Template
printN()               // → N = 10   기본값 사용
printN<5>()            // → N = 5    명시적 지정
```

**기대 출력**

```
=== Problem 5: Function Template Overloading ===
[Part 1] Overload Resolution
[int overload] value = 42
[template] value = 3.14
[template] value = hello
[Part 2] Explicit Template Argument forces Template
[template] value = 42
[template] value = 42
[Part 3] Default Template Argument (C++11)
N = 10
N = 5
N = 20
```

---

## 문제 6 — Integrated: Generic Calculator (`problem6.cpp`)

`add()` 와 `scaledAdd()` Function Template 은 이미 구현되어 있습니다.  
**아래 기대 출력이 나오도록 올바르게 호출**하세요.  
어떤 오버로드가 선택되는지, Scale 에 어떤 값을 넣어야 하는지 생각하면서 호출해 보세요.

**컴파일 및 실행**

```bash
g++ -std=c++17 -o problem6 problem6.cpp
./problem6
```

**활용 개념**

- Function Template Overloading (단일 타입 vs 두 타입 오버로드)
- Template Argument Deduction & Explicit Template Arguments
- Non-Type Template Parameters + Multiple Type Parameters 조합

**기대 출력**

```
=== Problem 6: Integrated — Generic Calculator ===
[Part 1] Function Template + Template Argument Deduction
add(3, 7) = 10
add(1.5, 2.3) = 3.8
add(3, 7) = 10
[Part 2] Multiple Template Parameters
add(5, 2.5) = 7.5
add(2.5, 5) = 7.5
[Part 3] Non-Type Template Parameter
scaledAdd<2>(3, 4) = 14
scaledAdd<3>(1.5, 2.3) = 11.4
[Part 4] NTTP + Multiple Type Parameters
scaledAdd<2>(3, 1.7) = 9.4
scaledAdd<3>(2, 0.5) = 7.5
```

---

## 테스트 방법 (Problem 1 ~ 6 자동 채점)

```bash
# macOS / Linux
bash test10.sh
```

```bat
rem Windows
test10.bat
```

문제별로 `PASS` / `FAIL` 을 출력합니다.  
`FAIL` 인 경우 기대 출력과 실제 출력의 차이를 함께 확인하세요.

| 문제 | 채점 방식 |
|---|---|
| Problem 1 ~ 3 | `main.cpp + problem1~3.cpp` 통합 컴파일, 테스트 케이스 3개 비교 |
| Problem 4 ~ 6 | 각 `problem{n}.cpp` 단독 컴파일, 고정 출력 비교 |

---

## 제출 방법 (git)

```bash
git add problem1.cpp problem2.cpp problem3.cpp problem4.cpp problem5.cpp problem6.cpp
git commit -m "학번 이름"
git push
```

- push 후 저장소의 **Actions 탭** 에서 자동 채점 결과를 확인할 수 있습니다.
- 마감 전까지 몇 번이든 다시 제출할 수 있습니다.
