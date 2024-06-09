#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages and frame size: ");
    scanf("%d%d", &n, &f);

    int frame[f];
    int page[n];
    int pageFaults = 0;
    int index = 0; 

    printf("Enter page sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    for (int j = 0; j < f; j++) {
        frame[j] = -1; 
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;

       
        for (int j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag = 1; 
                break;
            }
        }

        if (flag == 0) {
            
            frame[index] = page[i];
            index = (index + 1) % f; 
            pageFaults++; 
        }

        
        printf("Frame status after page %d: ", page[i]);
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
