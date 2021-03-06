/*
 Quick sort
 
 It works on a idea that if all elements before  pivot is smaller and after the elements is greater and this process called partition 
 or we can say QuickSort is a Divide and Conquer algorithm ; 
 or quick sort is the partitionary process to sort the elements;
 pivot --> which element is going to find your palce that element is called pivot.
 
 for example-:
  suppose  we have 3 list of elements:-
1)  10,30,20,70,4,90,80 in this  element 10 is at sorted place.
2)  80,70,40,30,20,10,90 in this 90 is at sorted place .
3)  40,30,20,50,90,70,80 in this   50 is at sorted place.
   question is that on what basis  we cann say that 50 is sorted ?
   because all the elements before 50 is smaller than 50 and elements after then 50 are greater .(and this is  the idea of quick sort )
  
  eg:--
   50 70 60 90 40 80 10 20 30 ..end of the list
   
 step 1->  50 --> pivot
   50 70 60 90 40 80 10 20 30 ..end of the list
   i                          j                    i= looking for greater than pivot i.e 50;
                                                    j = looking for smaller than pivot or equal to pivot ;
                                 
   
step 2->  if (i < pivot) then swap if not then move forward 
   50 70 60 90 40 80 10 20 30 ..end of the list
       i                   j 
step 3->if (i < pivot) then swap 

   50 30 60 90 40 80 10 20 70
          i              j

step 4->if (i < pivot) then swap...

    50 30 20 90 40 80 10 60 70
              i        j
step 5->
     50 30 20 10 40 80 90 60 70    till now we traverse the list ....
                  i     j
step 6 ->
    50 30 20 10 40 80 90 60 70
                j   i

now we check (j<pivot)= swap

   after swap -->  40 30 20 10 50 80 90 60 70 
   as per the the idea of quick sort we fixed the one element now we perform
   the same steps on smaller then 50 or greater to the sort the list properly;
   
  ( 40 30 20 10 )50 (80 90 60 70 ..end of the list)
     i            j   i              j

  for smaller pivot is 40   and end of the list is 50;
  and for greater pivot is  80  and  end of the list  is same end of the list 
  
  
  
  time complexity ---> for best case is O(nlogn); 
                       for worst case is O(n^2);
                       for average case is O(nlogn);

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
void insert(int[], int);
int partition(int[], int, int);
void quickSort(int[], int, int);
void display(int[], int);
int main()
{
    int size;
    printf("\nEnter the number of elements...");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter %d elements...", size);
    insert(arr, size);
    printf("\nElements of unsorted array are...\n");
    display(arr, size);
    quickSort(arr, 0, size); //call quick sort function
    printf("\nElements of sorted array are...\n");

    display(arr, size); // call display function
    return 0;
}
void insert(int arr[], int size) // insert function
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
} //end of insert

void display(int arr[], int size) // display function
{
    int i;
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
} //end of display

int partition(int arr[], int low, int high) //partition function
{
    int left, right, pivot, temp;
    pivot = arr[low];
    left = low;
    right = high;
    while (left < right)
    {
        while (arr[left] <= pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left < right)
        {
            temp = arr[left];
            arr[left] = arr[right]; ///swaping
            arr[right] = temp;
        }
    }
    arr[low] = arr[right];
    arr[right] = pivot;
    return right;
}
void quickSort(int arr[], int left, int right) //quickSort function
{
    int q;
    if (left < right)
    {
        q = partition(arr, left, right);
        quickSort(arr, left, q - 1);
        quickSort(arr, q + 1, right);
    }
}