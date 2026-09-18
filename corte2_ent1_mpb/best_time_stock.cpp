class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int precioMinimo = prices[0];
        int gananciaMaxima = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < precioMinimo) {
                precioMinimo = prices[i];
            } else {
                int gananciaHoy = prices[i] - precioMinimo;
                if (gananciaHoy > gananciaMaxima) {
                    gananciaMaxima = gananciaHoy;
                }
            }
        }

        return gananciaMaxima;
    }
};
