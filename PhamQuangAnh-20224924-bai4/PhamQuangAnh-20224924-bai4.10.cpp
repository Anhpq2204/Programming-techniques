#include <bits/stdc++.h>

using namespace std;

const int N = 10000;

vector<string> doc[N];  // Luu cac tu trong moi tai lieu
map<string, int> tf[N]; // Tan so tu trong moi tai lieu
map<string, int> df;    // Tan so tai lieu cua moi tu
int maxf[N], n;         // Tan so toi da cua tu trong moi tai lieu va so luong tai lieu

// Ham tinh TF (Term Frequency)
double calcTF(const string& t, int d) {
    if (tf[d][t] == 0) return 0;
    return 0.5 + 0.5 * tf[d][t] / maxf[d];
}

// Ham tinh IDF (Inverse Document Frequency)
double calcIDF(const string& t) {
    return log2(1.0 * n / df[t]);
}

// Ham tinh diem cua tu trong tai lieu
double calcScore(const string& t, int d) {
    if (df.count(t) == 0) return 0;
    return calcTF(t, d) * calcIDF(t);
}

int main() {
    cin >> n;
    cin.ignore(); // Loai bo ky tu xuong dong sau khi doc so luong tai lieu

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); // Doc tung dong tai lieu
        stringstream ss(line);
        string word;
        map<string, int> doc_tf;

        // Tach tu trong tai lieu bang dau phay
        while (getline(ss, word, ',')) {
            doc_tf[word]++;
            if (doc_tf[word] == 1) df[word]++;
            doc[i].push_back(word);
            tf[i][word]++;
        }

        // Tim tan so toi da cua tu trong tai lieu
        for (const auto& term : tf[i]) {
            maxf[i] = max(maxf[i], term.second);
        }
    }

    int q;
    cin >> q;
    cin.ignore(); // Loai bo ky tu xuong dong sau khi doc so luong truy van

    while (q--) {
        string line;
        getline(cin, line); // Doc tung dong truy van
        stringstream ss(line);
        string word;
        vector<string> query;

        // Tach tu trong truy van bang dau phay
        while (getline(ss, word, ',')) {
            query.push_back(word);
        }

        double bestScore = -1e9;
        int bestDoc = -1;

        // Tinh diem cho tung tai lieu
        for (int d = 0; d < n; d++) {
            double totalScore = 0;

            // Tinh diem cho tung tu trong truy van
            for (const string& term : query) {
                totalScore += calcScore(term, d);
            }

            // Cap nhat tai lieu co diem cao nhat
            if (totalScore > bestScore) {
                bestScore = totalScore;
                bestDoc = d;
            }
        }

        // Xuat ket qua la tai lieu co diem cao nhat
        cout << bestDoc + 1 << endl;
    }

    return 0;
}
