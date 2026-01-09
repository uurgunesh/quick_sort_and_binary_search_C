// UGUR GUNES
// 2420161143
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=dx1hlMBmPw


#include <stdio.h>
#define N 8
// Bu dizide Hoare'den "Quick Sort" Algoritmasini kullanacagim.
// Dizide 8 adet sayi bulunacaktir
// ilk ve son indisin belirlenmesinde rol alacak ve aynı zamanda diziyi yazdıracak fonk.

void print_array(int array[], int first_ind, int last_ind) {
    int i;
    for (i = first_ind; i <= last_ind; i++) {
        printf(" %2d", array[i]);
    }
    printf("\n");
}

// Geçici Takas İşlemleri Bu Fonksiyonda Gerçekleşecek

void exchange(int *ap, int *bp) {
    int temp = *ap;
    *ap = *bp;
    *bp = temp;
}

// Bölümleme fonksiyonu (Hoare Partition)

int partition(int array[], int first_ind, int last_ind) {

    int mid_ind = (first_ind + last_ind) / 2;
    int pivot = array[mid_ind];
    int i = first_ind;
    int j = last_ind;

    printf("\n( pivot -------> %d )\n", pivot);

    while (i <= j) {

        // Soldan arama
        while (array[i] < pivot) {
            i++;
        }

        // Sağdan arama
        while (array[j] > pivot) {
            j--;
        }

        // Takas işlemi
        if (i <= j) {
            exchange(&array[i], &array[j]);
            i++;
            j--;
            print_array(array, 0, N - 1);
        }
    }

    return i;
}

// Sıralama işlemi

void quick_sort(int array[], int first_ind, int last_ind) {

    if (first_ind < last_ind) {

        int position = partition(array, first_ind, last_ind);

        // Sol alt dizi
        if (first_ind < position - 1) {
            quick_sort(array, first_ind, position - 1);
        }

        // Sağ alt dizi
        if (position < last_ind) {
            quick_sort(array, position, last_ind);
        }
    }
}

// İkili Arama ( Binary Search ) Fonksiyonu

int binary_search(int array[], int size, int target, int first_ind, int last_ind) {

    int mid_ind = (first_ind + last_ind) / 2;

    // Aranan deger orta indisteyse
    if (target == array[mid_ind]) {
        return mid_ind;
    }
    // Aranan deger ortadakinden BUYUK ise
    else if (target > array[mid_ind] && (last_ind - first_ind) > 0) {
        return binary_search(array, size, target, mid_ind + 1, last_ind);
    }
    // Aranan deger ortadakinden KUCUK
    else if (target < array[mid_ind] && (last_ind - first_ind) > 0) {
        return binary_search(array, size, target, first_ind, mid_ind - 1);
    }
    // Aranan deger yoksa
    else {
        return -1;
    }
}

int main() {

    int A[N] = {42, 7, 29, 15, 88, 3, 64, 21};

    // Girilen diziyi yazdırma
    printf("Orijinal dizi:\n");
    print_array(A, 0, N - 1);

    // Quick Sort işlemi
    quick_sort(A, 0, N - 1);

    // Sıralı dizi
    printf(" \n Sirali dizi:\n ");
    print_array(A, 0, N - 1);

    int target, result;

printf("\n Aramak istediginiz deger:  ");
scanf("%d", &target);

result = binary_search(A, N, target, 0, N - 1);

if (result == -1) {
    printf(" Aradiginiz deger %d, dizide yok! \n", target);
}
else {
    printf(" Aradiginiz deger %d, dizinin %d. indisinde bulundu! \n", target, result);
}

    return 0;
}
