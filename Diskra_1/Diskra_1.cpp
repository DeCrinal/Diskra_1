#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"myMultiset.h"
#include<cstdio>
#include<string>
int main()
{
    while (true) {
        int capacityOfUniv;
        myMultiset mM1, mM2;
        char answer[300];
        cout << "Input capacity of Universum" << endl;
        fgets(answer, sizeof(answer), stdin);
        while (sscanf(answer, "%d", &capacityOfUniv) != 1 || capacityOfUniv < 0 || capacityOfUniv >= 20) {
            cout << "Incorrect input data, input again:" << endl;
            fgets(answer, sizeof(answer), stdin);
        }
        fflush(stdin);
        toFillUniversum_WithGray(capacityOfUniv);
        print_Universum();
        if(powerOfUn!=0)
            cout << "Do you want to fill first multiset by your own? Y/N" << endl;
        do {
            if (powerOfUn != 0)
            {
                cin >> answer;
                cin.clear();
                cin.sync();
            }
            else
                strcpy(answer, "n");
        } while (answer[0] != 'n' && answer[0] != 'N' && answer[0] != 'y' && answer[0] != 'Y');
        if (answer[0] == 'N' || answer[0] == 'n') {
            int card1;
            if (powerOfUn != 0)
            {
                cout << "Input cardinal power of multiset #1:" << endl;
                fflush(stdin);
                fgets(answer, sizeof(answer), stdin);
                fgets(answer, sizeof(answer), stdin);
                while (sscanf(answer, "%d", &card1) != 1 || card1 < 0||card1>powerOfUn) {
                    cout << "Incorrect input data, input again:" << endl;
                    fflush(stdin);
                    fgets(answer, sizeof(answer), stdin);
                }
                fflush(stdin);
            }
            else
                card1 = 0;
            mM1.initialize_auto(card1);
            cout << mM1;
        }
        else if (answer[0] == 'Y' || answer[0] == 'y') {
            int card1;
            cout << "Input cardinal power of multiset #1:" << endl;
            fflush(stdin);
            fgets(answer, sizeof(answer), stdin);
            fgets(answer, sizeof(answer), stdin);
            while (sscanf(answer, "%d", &card1) != 1 || card1 < 0||card1>powerOfUn) {
                cout << "Incorrect input data, input again:" << endl;
                fflush(stdin);
                fgets(answer, sizeof(answer), stdin);
            }
            fflush(stdin);
            mM1.initialize_handly(card1);
            cout << mM1;
        }
        if(powerOfUn!=0)
            cout << "Do you want to fill second multiset by your own? Y/N" << endl;
        do {
            fflush(stdin);
            if (powerOfUn != 0)
                cin >> answer;
            else
                strcpy(answer, "n");
            if (answer[0] == 'n' || answer[0] == 'N' || answer[0] == 'y' || answer[0] == 'Y') {
                break;
            }
            else
                cout << "Incorrect data" << endl;
        } while (true);
        if (answer[0] == 'N' || answer[0] == 'n') {
            int card2;
            if (powerOfUn != 0) {
                cout << "Input cardinal power of multiset #2:" << endl;
                fflush(stdin);
                fgets(answer, sizeof(answer), stdin);
                fgets(answer, sizeof(answer), stdin);
                while (sscanf(answer, "%d", &card2) != 1 || card2 < 0||card2>powerOfUn) {
                    cout << "Incorrect input data, input cardinal again:" << endl;
                    fflush(stdin);
                    fgets(answer, sizeof(answer), stdin);
                }
                fflush(stdin);
            }
            else
                card2 = 0;
            mM2.initialize_auto(card2);
            cout << mM2;
        }
        else if (answer[0] == 'Y' || answer[0] == 'y') {
            int card2;
            cout << "Input cardinal power of multiset #2:" << endl;
            fflush(stdin);
            fgets(answer, sizeof(answer), stdin);
            fgets(answer, sizeof(answer), stdin);
            while (sscanf(answer, "%d", &card2) != 1 || card2 < 0||card2>powerOfUn) {
                cout << "Incorrect input data, input cardinal again:" << endl;
                fflush(stdin);
                fgets(answer, sizeof(answer), stdin);
            }
            fflush(stdin);
            mM2.initialize_handly(card2);
            cout << mM2;
        }
        cout << endl << "Integration of multisets: " << endl;
        cout << integrateWith(mM1, mM2);
        cout << endl << "Intersection: " << endl;
        cout << intersection(mM1, mM2);
        cout << endl << "Arithmetic sum: " << endl;
        cout << arithmeticSum(mM1, mM2);
        cout << endl << "Arithmetic subtraction: " << endl;
        cout << arithmeticSub(mM1, mM2);
        cout << endl << "Symmetric subtraction: " << endl;
        cout << symmetricSub(mM1, mM2);
        cout << endl << "Additional to Universum: " << endl;
        cout << additionToUniv(mM1);
        cout << endl << "Arithmetic multiplication: " << endl;
        cout << arithmeticMultip(mM1, mM2);
        cout << endl << "Substraction of multisets: " << endl;
        cout << subOfmMs(mM1, mM2);
        cout << endl << "Arithmetic division: " << endl;
        cout << arithmeticDiv(mM1, mM2);
        cout << endl << "Setting in power: " << endl;
        cout << powerSet(mM1, 2);
    }
    return 0;
}

