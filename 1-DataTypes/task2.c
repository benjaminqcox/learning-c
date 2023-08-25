#include <stdio.h>

float celcToFaren(float c) {
    return c * (9/5) + 32;
}

float celcToKelv(float c) {
    return c + 273.15;
}

int main()
{
    float tempC = 18.4;
    printf("Celsius: %.2f°C\nFarenheit: %.2f°F\nKelvin: %.2fK\n", tempC, celcToFaren(tempC), celcToKelv(tempC));
    return 0;
}