#include "RSA.h"

vector < int > RSA::go(int e, int n, vector < int > m) {
    for (int i = 0; i < m.size(); i++) {
        //Calculate m[i]**e mod n mod
        for (int j = 0, m_i = m[i]; j < e - 1; j++) {
            m[i] = (m[i] * m_i) % n;
        }
    }
    return m;
}
