#include <stdio.h>

int main() {
    int n, f;
    printf("Enter number of pages and frame size: ");
    scanf("%d%d", &n, &f);

    int frame[f];
    int page[n];
    int pageFaults = 0;
    int index = 0; // Points to the next frame slot to be replaced in FIFO manner

    printf("Enter page sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    for (int j = 0; j < f; j++) {
        frame[j] = -1; // Initialize frame slots to -1 indicating empty
    }

    for (int i = 0; i < n; i++) {
        int flag = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < f; j++) {
            if (frame[j] == page[i]) {
                flag = 1; // Page is already in frame, no page fault
                break;
            }
        }

        if (flag == 0) {
            // Page is not in frame, replace the page in FIFO order
            frame[index] = page[i];
            index = (index + 1) % f; // Update index in circular manner
            pageFaults++; // Increment page fault count
        }

        // Print frame status after each page insertion
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
