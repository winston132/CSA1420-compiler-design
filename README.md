# CSA14 - Compiler Design Laboratory

**Department of Computational Intelligence**  
**Saveetha School of Engineering**  
**Saveetha Institute of Medical and Technical Sciences (SIMATS)**

---

## 📖 Overview

This repository contains the complete, verified, and structured laboratory implementations for **CSA14 - Compiler Design**. All 41 experiments cover the entire syllabus, ranging from fundamental lexical analysis and parsing algorithms in C to practical scanners, validators, and analyzers using **LEX / FLEX**.

Every experiment includes:
- Complete, standard-compliant source code (`main.c` or `main.l`).
- Sample input datasets and test files.
- Algorithmic explanations, input/output specifications, and step-by-step logic in individual `README.md` documentation.
- High-resolution, dark-themed terminal execution screenshots (`output.png`).

---

## 📋 Comprehensive Experiment Index (41 Experiments)

### Section A: C Language Implementations (Experiments 01 - 18)

| Exp # | Experiment Title | Language | Folder Link | Status |
| :---: | :--- | :---: | :--- | :---: |
| **01** | Lexical Analyzer (Identifiers, Constants, Operators) | C | [Exp-01-Lexical-Analyzer-C](./Exp-01-Lexical-Analyzer-C/) | ✅ Completed |
| **02** | Comment Checker (`//` single-line and `/* */` multi-line) | C | [Exp-02-Comment-Checker-C](./Exp-02-Comment-Checker-C/) | ✅ Completed |
| **03** | Redundant Space, Tab, and Comment Stripper | C | [Exp-03-Redundant-Space-Comment-Stripper-C](./Exp-03-Redundant-Space-Comment-Stripper-C/) | ✅ Completed |
| **04** | Arithmetic Operator Validator (`+`, `-`, `*`, `/`) | C | [Exp-04-Arithmetic-Operator-Validator-C](./Exp-04-Arithmetic-Operator-Validator-C/) | ✅ Completed |
| **05** | Whitespace and Newline Counter | C | [Exp-05-Whitespace-Newline-Counter-C](./Exp-05-Whitespace-Newline-Counter-C/) | ✅ Completed |
| **06** | C Identifier Syntax Validator | C | [Exp-06-Identifier-Validator-C](./Exp-06-Identifier-Validator-C/) | ✅ Completed |
| **07** | FIRST() Set Computation for Predictive Parser | C | [Exp-07-Predictive-Parser-FIRST-C](./Exp-07-Predictive-Parser-FIRST-C/) | ✅ Completed |
| **08** | FOLLOW() Set Computation for Predictive Parser | C | [Exp-08-Predictive-Parser-FOLLOW-C](./Exp-08-Predictive-Parser-FOLLOW-C/) | ✅ Completed |
| **09** | Elimination of Left Recursion from Context-Free Grammar | C | [Exp-09-Eliminate-Left-Recursion-C](./Exp-09-Eliminate-Left-Recursion-C/) | ✅ Completed |
| **10** | Elimination of Left Factoring from Context-Free Grammar | C | [Exp-10-Eliminate-Left-Factoring-C](./Exp-10-Eliminate-Left-Factoring-C/) | ✅ Completed |
| **11** | Symbol Table Operations (Insert, Search, Display, Delete) | C | [Exp-11-Symbol-Table-Operations-C](./Exp-11-Symbol-Table-Operations-C/) | ✅ Completed |
| **12** | Recursive Descent Predictive Parser for Arithmetic Grammar | C | [Exp-12-Recursive-Descent-Parser-C](./Exp-12-Recursive-Descent-Parser-C/) | ✅ Completed |
| **13** | Shift-Reduce Bottom-Up Parser / Syntax Checker | C | [Exp-13-Shift-Reduce-Parser-C](./Exp-13-Shift-Reduce-Parser-C/) | ✅ Completed |
| **14** | Intermediate Code Generator: Three Address Code (3AC) | C | [Exp-14-Three-Address-Code-Generator-C](./Exp-14-Three-Address-Code-Generator-C/) | ✅ Completed |
| **15** | File Metrics Counter (Characters, Words, Lines) | C | [Exp-15-File-Metrics-Counter-C](./Exp-15-File-Metrics-Counter-C/) | ✅ Completed |
| **16** | Compiler Back-End: Target Assembly Code Generator (8086) | C | [Exp-16-Compiler-Backend-Code-Generator-C](./Exp-16-Compiler-Backend-Code-Generator-C/) | ✅ Completed |
| **17** | Operator Precedence Parser: LEADING() Computation | C | [Exp-17-Operator-Precedence-LEADING-C](./Exp-17-Operator-Precedence-LEADING-C/) | ✅ Completed |
| **18** | Operator Precedence Parser: TRAILING() Computation | C | [Exp-18-Operator-Precedence-TRAILING-C](./Exp-18-Operator-Precedence-TRAILING-C/) | ✅ Completed |

---

### Section B: LEX & FLEX Implementations (Experiments 19 - 41)

| Exp # | Experiment Title | Tool | Folder Link | Status |
| :---: | :--- | :---: | :--- | :---: |
| **19** | Count Characters, Words, and Lines in C Source | LEX | [Exp-19-Count-Words-Lines-Chars-LEX](./Exp-19-Count-Words-Lines-Chars-LEX/) | ✅ Completed |
| **20** | Extract and Print All Constants in C Source | LEX | [Exp-20-Print-Constants-LEX](./Exp-20-Print-Constants-LEX/) | ✅ Completed |
| **21** | Count `#define` Macros and `#include` Headers | LEX | [Exp-21-Count-Macros-Header-Files-LEX](./Exp-21-Count-Macros-Header-Files-LEX/) | ✅ Completed |
| **22** | Count Vowels and Consonants in Sentence | LEX | [Exp-22-Count-Vowels-Sentence-LEX](./Exp-22-Count-Vowels-Sentence-LEX/) | ✅ Completed |
| **23** | Extract and Print All HTML Tags from Web Document | LEX | [Exp-23-Print-HTML-Tags-LEX](./Exp-23-Print-HTML-Tags-LEX/) | ✅ Completed |
| **24** | Add Formatted Line Numbers to C Source Code | LEX | [Exp-24-Add-Line-Numbers-LEX](./Exp-24-Add-Line-Numbers-LEX/) | ✅ Completed |
| **25** | Count and Strip Comments from Source to Output File | LEX | [Exp-25-Count-Eliminate-Comments-LEX](./Exp-25-Count-Eliminate-Comments-LEX/) | ✅ Completed |
| **26** | Identify Capital Words from Input Stream | LEX | [Exp-26-Identify-Capital-Words-LEX](./Exp-26-Identify-Capital-Words-LEX/) | ✅ Completed |
| **27** | Email Address Syntax Validator | LEX | [Exp-27-Validate-Email-Address-LEX](./Exp-27-Validate-Email-Address-LEX/) | ✅ Completed |
| **28** | Replace Substring occurrence `abc` with `ABC` | LEX | [Exp-28-Convert-Substring-abc-to-ABC-LEX](./Exp-28-Convert-Substring-abc-to-ABC-LEX/) | ✅ Completed |
| **29** | Employee Mobile Phone Number Validator (10 Digits) | LEX | [Exp-29-Mobile-Number-Validator-LEX](./Exp-29-Mobile-Number-Validator-LEX/) | ✅ Completed |
| **30** | C Token Separation with Captions | LEX | [Exp-30-Token-Separation-Captions-LEX](./Exp-30-Token-Separation-Captions-LEX/) | ✅ Completed |
| **31** | Count Consonants in an English Sentence | LEX | [Exp-31-Count-Consonants-Sentence-LEX](./Exp-31-Count-Consonants-Sentence-LEX/) | ✅ Completed |
| **32** | Separate 32 C Keywords and Identifiers | LEX | [Exp-32-Separate-Keywords-Identifiers-LEX](./Exp-32-Separate-Keywords-Identifiers-LEX/) | ✅ Completed |
| **33** | Count Positive and Negative Numbers (Integers & Floats) | LEX | [Exp-33-Count-Positive-Negative-Numbers-LEX](./Exp-33-Count-Positive-Negative-Numbers-LEX/) | ✅ Completed |
| **34** | Validate Network URL Addresses | LEX | [Exp-34-Validate-URL-LEX](./Exp-34-Validate-URL-LEX/) | ✅ Completed |
| **35** | Validate Student Date of Birth (Calendar & Leap Year) | LEX | [Exp-35-Validate-DOB-LEX](./Exp-35-Validate-DOB-LEX/) | ✅ Completed |
| **36** | Check Whether Input Token is Single/Multi Digit | LEX | [Exp-36-Check-Digit-LEX](./Exp-36-Check-Digit-LEX/) | ✅ Completed |
| **37** | Arithmetic Expression Calculator (`+`, `-`, `*`, `/`, `%`) | LEX | [Exp-37-Arithmetic-Calculator-LEX](./Exp-37-Arithmetic-Calculator-LEX/) | ✅ Completed |
| **38** | Target Word Frequency Counter in Text | LEX | [Exp-38-Word-Frequency-Counter-LEX](./Exp-38-Word-Frequency-Counter-LEX/) | ✅ Completed |
| **39** | Identify Longest Word and Character Length in Text | LEX | [Exp-39-Longest-Word-Finder-LEX](./Exp-39-Longest-Word-Finder-LEX/) | ✅ Completed |
| **40** | Replace Word Occurrences in File with Target Word | LEX | [Exp-40-Replace-Word-In-File-LEX](./Exp-40-Replace-Word-In-File-LEX/) | ✅ Completed |
| **41** | Fast Lexical Analyzer (FLEX) Token Separation with Captions | FLEX | [Exp-41-Token-Separation-FLEX](./Exp-41-Token-Separation-FLEX/) | ✅ Completed |

---

## 🛠️ Toolchain and Environment Setup

### Required Tools
- **C Compiler**: MinGW GCC 4.9.2 or GCC 9+ (`gcc`)
- **Lexical Analyzer Generator**: GnuWin32 Flex 2.5.4 or modern Flex (`flex`)
- **Shell**: PowerShell, Git Bash, or Linux Terminal

### Compiling and Running

#### 1. C Programs (Exps 01 to 18)
```bash
# Navigate to experiment directory
cd Exp-01-Lexical-Analyzer-C

# Compile using GCC (C99 standard)
gcc -std=c99 main.c -o program

# Execute
./program
```

#### 2. LEX / FLEX Programs (Exps 19 to 41)
```bash
# Navigate to experiment directory
cd Exp-31-Count-Consonants-Sentence-LEX

# Generate lexical analyzer C code
flex main.l

# Compile generated lex.yy.c
gcc -std=c99 lex.yy.c -o program

# Execute with input file
./program sentence.txt
```

---

## 📁 Repository Directory Structure

```plaintext
CSA1420-compiler-design/
├── Exp-01-Lexical-Analyzer-C/
│   ├── main.c
│   ├── input.txt
│   ├── output.png
│   └── README.md
├── ...
├── Exp-18-Operator-Precedence-TRAILING-C/
│   ├── main.c
│   ├── output.png
│   └── README.md
├── Exp-19-Count-Words-Lines-Chars-LEX/
│   ├── main.l
│   ├── sample.c
│   ├── output.png
│   └── README.md
├── ...
├── Exp-41-Token-Separation-FLEX/
│   ├── main.l
│   ├── sample.c
│   ├── output.png
│   └── README.md
└── README.md
```

---

## 👨‍💻 Author & Course Details

- **Institution**: Saveetha School of Engineering, SIMATS
- **Department**: Department of Computational Intelligence
- **Course**: CSA14 - Compiler Design Laboratory
- **GitHub Repository**: [winston132/CSA1420-compiler-design](https://github.com/winston132/CSA1420-compiler-design)