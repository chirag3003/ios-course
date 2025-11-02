#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 10

void printFrames(int frames[], int nFrames, int pageFault);

int main() {
  int nFrames;
  int nReferences;
  printf("Enter the number of frames: ");
  scanf("%d", &nFrames);
  printf("Enter the number of references: ");
  scanf("%d", &nReferences);
  int frames[nFrames];
  int lastUsed[nFrames];

  for(int i = 0 ; i < nFrames; i++){
    frames[i] = -1;
    lastUsed[i] = -1;
  }

  for(int i = 0; i < nReferences; i++){
    int frame;
    printf("Enter the frame number %d: ", i + 1);
    scanf("%d", &frame);
    
    int indexToChange = 0;
    for(int j = 0 ; j < nFrames; j++){
      if(lastUsed[j] < lastUsed[indexToChange]){
        indexToChange = j;
      }
      if(frame == frames[j]){
        lastUsed[j]=i;
        indexToChange = -1;
        break;
        printf("Frame %d is already in use\n", frame);
      }
    }
    
    int pageFault = 0;
    // If the frame is not in use, then add it to the list
    if(indexToChange != -1){
      frames[indexToChange] = frame;
      lastUsed[indexToChange] = i;
      pageFault = 1;
    }
    printFrames(frames, nFrames, pageFault);

  }

  int pageFaults = 0;

  return 0;
}

void printFrames(int frames[], int nFrames, int pageFault) {
  for (int i = 0; i < nFrames; i++) {
    printf("%d ", frames[i]);
  }
  if(pageFault){
    printf("Page fault");
  }
  printf("\n");
}
