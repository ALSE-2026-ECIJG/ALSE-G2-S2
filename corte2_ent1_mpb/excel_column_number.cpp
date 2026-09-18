class Solution {
public:
    int titleToNumber(string columnTitle) {
        int resultado = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            int valor = columnTitle[i] - 'A' + 1;
            resultado = resultado * 26 + valor;
        }
        return resultado;
    }
};
