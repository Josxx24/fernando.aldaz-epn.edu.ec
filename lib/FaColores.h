#include<stdio.h>
#include <Windows.h>
#include <math.h>


void faSetColor(int Background, int Text){ 
    int colorTexto= Text + (Background * 16);         
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   
    SetConsoleTextAttribute(terminal, colorTexto); 
}