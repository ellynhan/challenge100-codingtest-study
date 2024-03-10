//
//  25206.cpp
//  main
//
//  Created by wi_seong on 3/5/24.
//

/*
 [Input]
 ObjectOrientedProgramming1 3.0 A+
 IntroductiontoComputerEngineering 3.0 A+
 ObjectOrientedProgramming2 3.0 A0
 CreativeComputerEngineeringDesign 3.0 A+
 AssemblyLanguage 3.0 A+
 InternetProgramming 3.0 B0
 ApplicationProgramminginJava 3.0 A0
 SystemProgramming 3.0 B0
 OperatingSystem 3.0 B0
 WirelessCommunicationsandNetworking 3.0 C+
 LogicCircuits 3.0 B0
 DataStructure 4.0 A+
 MicroprocessorApplication 3.0 B+
 EmbeddedSoftware 3.0 C0
 ComputerSecurity 3.0 D+
 Database 3.0 C+
 Algorithm 3.0 B0
 CapstoneDesigninCSE 3.0 B+
 CompilerDesign 3.0 D0
 ProblemSolving 4.0 P
 [Output]
 3.284483
 */
// 시간복잡도: O(n)
// 최악시간: 20
// 난이도: Silver 5
// Timer: 12m
// Url: https://www.acmicpc.net/problem/25206

#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, double> m {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0.0},
};
string subject, grade;
double val, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(6);
    cout << fixed;

    int t = 20;
    double sum = 0;
    while(t--) {
        cin >> subject >> val >> grade;
        if(grade == "P") continue;
        cnt += val;
        sum += val * m[grade];
    }
    cout << sum / cnt;

	return 0;
}
