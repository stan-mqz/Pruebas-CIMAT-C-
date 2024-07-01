#include <iostream>
#include <iomanip>
#include <wchar.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    double salario, isss, afp, renta, tablaretencion, vacaciones, recargo, div, indemnizacion, year, incapacidad, hnocturnas, hferiados, total;
    int opcion;
    bool fin = false;

    do {
        for (;;) {
            wcout << L"******************" << endl;
            wcout << L"Ingrese su salario" << endl;
            wcout << L"******************" << endl;
            cin >> salario;

            if (salario > 0) {
                break;
            } else {
                wcout << L"***********************" << endl;
                wcout << L"Ingrese un valor válido" << endl;
                wcout << L"***********************" << endl;
            }
        }

        wcout << L"************************************" << endl;
        wcout << L"Ingrese la opción que desea calcular" << endl;
        wcout << L"0. Salir" << endl;
        wcout << L"1. ISSS" << endl;
        wcout << L"2. AFP" << endl;
        wcout << L"3. Renta del 10%" << endl;
        wcout << L"4. Renta con retención" << endl;
        wcout << L"5. Vacaciones anual" << endl;
        wcout << L"6. Indemnización" << endl;
        wcout << L"7. Incapacidad (3 días o más)" << endl;
        wcout << L"8. Horas extras nocturnas" << endl;
        wcout << L"9. Horas extras en días feriados" << endl;
        wcout << L"************************************" << endl;
        cin >> opcion;

        if (opcion == 0) {
            wcout << L"****************************" << endl;
            wcout << L"Usted ha salido del programa" << endl;
            wcout << L"****************************" << endl;
            fin = true;
        } else {
            fin = false;
        }

        switch (opcion) {
            case 1:
                if (salario < 1000) {
                    isss = salario * 0.03;
                    total = salario - isss;
                    wcout << fixed << setprecision(2) << L" Su ISSS es: " << isss << endl;
                    wcout << fixed << setprecision(2) << L" Su salario restando el ISSS es: " << total << endl;
                    break;
                } else {
                    isss = 30;
                    total = salario - isss;
                    wcout << fixed << setprecision(2) << L" Su ISSS es: " << isss << endl;
                    wcout << fixed << setprecision(2) << L" Su salario restando el ISSS es: " << total << endl;
                    break;
                }

            case 2:
                if (salario < 7028.29) {
                    afp = salario * 0.0725;
                    total = salario - afp;
                    wcout << fixed << setprecision(2) << L" Su AFP es: " << afp << endl;
                    wcout << fixed << setprecision(2) << L" Su salario restando el AFP es: " << total << endl;
                    break;
                } else {
                    afp = 725;
                    total = salario - afp;
                    wcout << fixed << setprecision(2) << L" Su AFP es: " << afp << endl;
                    wcout << fixed << setprecision(2) << L" Su salario restando el AFP es: " << total << endl;
                    break;
                }

            case 3:
                renta = salario * 0.10;
                total = salario - renta;
                wcout << fixed << setprecision(2) << L" Su renta es de: " << renta << endl;
                wcout << fixed << setprecision(2) << L" Su salario restando la renta es de: " << total << endl;
                break;

            case 4:
                afp = salario * 0.0725;
                total = salario - afp;

                if (total <= 0.01 || total <= 472) {
                    wcout << fixed << setprecision(2) << L"Su salario no tiene retención" << endl;
                    break;
                } else {
                    if (total >= 472.01 || total <= 895.24) {
                        tablaretencion = (total - 472) * 0.1 + 17.67;
                        wcout << fixed << setprecision(2) << L" Su ISR es de: " << tablaretencion << endl;
                        break;
                    } else {
                        if (total >= 895.25 || total <= 2038.10) {
                            tablaretencion = (total - 895.24) * 0.20 + 60;
                            wcout << fixed << setprecision(2) << L" Su ISR es de: " << tablaretencion << endl;
                            break;
                        } else {
                            if (total >= 2038.11) {
                                tablaretencion = (total - 2038.10) * 0.30 + 288.57;
                                wcout << fixed << setprecision(2) << L" Su ISR es de: " << tablaretencion << endl;
                                break;
                            }
                        }
                    }
                }
                break;

            case 5:
                div = salario / 30;
                vacaciones = div * 15;
                recargo = vacaciones * 0.30;
                total = vacaciones + recargo;
                wcout << fixed << setprecision(2) << L"Su paga en vacaciones es de: " << total << endl;
                break;

            case 6:
                wcout << L"¿Cuántos años lleva trabajando?" << endl;
                cin >> year;

                for (;;) {
                    wcout << L"¿Qué porcentaje de indemnización le entregó la empresa donde trabaja?" << endl;
                    cin >> recargo;

                    if (recargo < 0 || recargo > 100) {
                        wcout << L"Ingrese un porcentaje válido" << endl;
                        break;
                    } else {
                        indemnizacion = (salario * year) * recargo / 100;
                        wcout << fixed << setprecision(2) << L"Su indemnización es de: " << indemnizacion << endl;
                        break;
                    }
                }
                break;

            case 7:
                wcout << L"¿Cuántos días tiene de incapacidad?" << endl;
                cin >> incapacidad;

                if (incapacidad >= 3) {
                    total = salario * 0.75;
                    wcout << fixed << setprecision(2) << L" Su salario devengado durante sus días de incapacidad es: " << total << endl;
                } else {
                    wcout << L"No tiene los suficientes días de incapacidad para realizar el cálculo" << endl;
                }
                break;

            case 8:
                wcout << L"¿Cuántas horas nocturnas ha trabajado?" << endl;
                cin >> hnocturnas;

                div = (salario / 30) / 8;
                total = (((hnocturnas * div) * 2) * 1.25);
                wcout << fixed << setprecision(2) << L"Su sueldo con horas nocturnas de trabajo es: " << total << endl;
                break;

            case 9:
                wcout << L"¿Cuántas horas feriadas ha trabajado?" << endl;
                cin >> hferiados;

                div = (salario / 30) / 8;
                total = ((hferiados * div) * 2);
                wcout << fixed << setprecision(2) << L"Su sueldo con horas feriadas de trabajo es: " << total << endl;
                break;
        }

    } while (!fin);

    return 0;
}