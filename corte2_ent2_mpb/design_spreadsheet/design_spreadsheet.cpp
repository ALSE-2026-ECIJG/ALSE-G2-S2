#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

/**
 * @class Spreadsheet
 * @brief Hoja de cálculo mínima con 26 columnas ('A'-'Z') y `rows` filas,
 *        que permite asignar/reiniciar celdas y evaluar fórmulas simples
 *        de suma de dos operandos ("=X+Y"), donde X e Y son cada uno una
 *        referencia a celda o un entero no negativo literal.
 *
 * Las celdas se almacenan de forma dispersa (sparse): una celda no
 * establecida se considera 0 sin necesidad de estar presente en el mapa,
 * por lo que el uso de memoria es proporcional a la cantidad de celdas
 * realmente escritas, no a rows * 26.
 */
class Spreadsheet {
public:
    /**
     * @brief Inicializa una hoja de cálculo vacía (todas las celdas en 0).
     * @param rows Número de filas disponibles (los números de fila
     *             1-indexados en las referencias de celda deben estar
     *             entre 1 y este valor).
     * @note rows no es necesario para el almacenamiento en sí (las
     *       celdas se guardan de forma dispersa por su referencia en
     *       texto), pero se conserva como parámetro para respetar la
     *       firma del constructor requerida.
     */
    Spreadsheet(int rows) {
        (void)rows; // no se necesita con almacenamiento disperso
    }
    
    /**
     * @brief Fija el valor de una celda.
     * @param cell  Referencia de celda en formato "AX" (p. ej. "A1", "B10").
     * @param value Nuevo valor de la celda, 0 <= value <= 10^5.
     */
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    /**
     * @brief Reinicia una celda a 0 (la elimina del almacenamiento disperso).
     * @param cell Referencia de celda en formato "AX".
     */
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    /**
     * @brief Evalúa una fórmula de la forma "=X+Y".
     * @param formula X e Y son cada uno una referencia a celda o un
     *                entero no negativo literal.
     * @return La suma de los dos operandos resueltos.
     */
    int getValue(string formula) {
        string expr = formula.substr(1);       // quitar el '=' inicial
        size_t plusPos = expr.find('+');
        string x = expr.substr(0, plusPos);
        string y = expr.substr(plusPos + 1);
        return resolverOperando(x) + resolverOperando(y);
    }

private:
    /// Almacenamiento disperso de celdas: referencia (p. ej. "A1") -> valor.
    unordered_map<string, int> cells;

    /**
     * @brief Resuelve un único operando de la fórmula.
     * @param token Una referencia de celda (empieza con 'A'-'Z') o un
     *              entero literal.
     * @return El valor de la celda (0 si nunca se estableció), o el
     *         entero interpretado.
     */
    int resolverOperando(const string& token) const {
        if (!token.empty() && isupper(static_cast<unsigned char>(token[0]))) {
            auto it = cells.find(token);
            return it != cells.end() ? it->second : 0;
        }
        return stoi(token);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
